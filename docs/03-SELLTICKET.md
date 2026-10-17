# 03 · sellticket 模块详解

## 3.1 模块概述

**sellticket** 是一个 **多线程售票系统** 的学习示例文件，通过 **7 种不同的互斥锁（mutex）使用方式** 展示 C++ 多线程编程的正确范式与常见陷阱。

**核心问题**：3 个售票窗口（线程）并发卖出 10 张票，如何保证票数不会被超卖（不会出现负数）？

---

## 3.2 源码位置

```
code/sellticket/sellticket.cpp    ← 全部代码在这一个文件中（147 行）
```

---

## 3.3 全局状态

```cpp
#include <iostream>
#include <thread>        // std::thread
#include <list>          // std::list<thread>
#include <mutex>         // std::mutex, lock_guard, unique_lock
using namespace std;

mutex mtx;               // 🔒 全局互斥锁，保护临界区
int gcount = 10;         // 🎫 全局票数（共享资源，有竞争）
```

| 变量 | 类型 | 作用 |
|------|------|------|
| `mtx` | `std::mutex` | 全局互斥锁，所有线程共用这一把锁保护 `gcount` |
| `gcount` | `int` | 初始 10 张票，被多个线程读写，**必须加锁保护** |

---

## 3.4 七种售票函数对比

### 📊 总览表

| 函数 | 加锁位置 | 加锁方式 | 票数检查 | 睡眠位置 | 是否安全 | 窗口并发 |
|------|----------|----------|----------|----------|----------|----------|
| sellticket1 | while 外面 | `lock()/unlock()` | ❌ 无 | 锁外 | ❌ 设计差 | ❌ 单窗口卖完 |
| sellticket2 | 循环内部 | `lock()/unlock()` | ❌ 无 | 锁外 | ❌ **有 bug** | ✅ 有并发但会超卖 |
| sellticket3 | 循环内部 | `lock()/unlock()` | ✅ 有 | 无 | ✅ 安全 | ❌ 单窗口卖完 |
| sellticket4 | 循环内部 | `lock()/unlock()` | ✅ 有 | 锁外 | ✅ 安全 | ✅ **正确的手动锁** |
| sellticket5 | 循环内部 | `lock_guard` 循环级 | ✅ 有 | **锁内** | ✅ 安全但差 | ❌ 单窗口卖完 |
| sellticket6 | 循环内部 | `lock_guard` 块级 | ✅ 有 | 锁外 | ✅ **安全推荐** | ✅ **正确的 lock_guard** |
| sellticket7 | 循环内部 | `unique_lock` 块级 | ✅ 有 | 锁外 | ✅ **安全灵活** | ✅ **最推荐** |

---

### 🔍 逐个详解

---

#### ✅ sellticket1 — 锁在外层（错误示范）

```cpp
void sellticket1(int index)
{
    mtx.lock();              // 🚩 锁在 while 外面
    while (gcount > 0)
    { 
        cout << "sellticket" << index << ":" << gcount << endl;
        gcount--;
    }
    mtx.unlock();
    this_thread::sleep_for(chrono::microseconds(10));
}
```

**问题**：锁从 while 外面就加了，导致一个线程进入后一直持有锁，把 10 张票全部卖完才释放。其他线程根本没有机会进入。

**运行结果**（单窗口垄断）：
```
sellticket1:10 → 9 → 8 → 7 → 6 → 5 → 4 → 3 → 2 → 1
```

---

#### ❌ sellticket2 — 锁在内部但没有双重检查（有 bug）

```cpp
void sellticket2(int index)
{
    while (gcount > 0)       // 🚩 检查在锁外面！
    {
        mtx.lock();
        cout << "sellticket" << index << ":" << gcount << endl;
        gcount--;
        mtx.unlock();
    }
    this_thread::sleep_for(chrono::microseconds(10));
}
```

**经典 bug — 条件竞争**：

1. 线程 A 进入 while，`gcount` 此时是 1
2. **线程切换**，线程 B 进入 while，`gcount` 还是 1
3. 线程 A 加锁，打印 `1`，`gcount--` 变 0，解锁
4. 线程 B 加锁，打印 `0`，`gcount--` 变 **-1**，解锁 ← 💥 **超卖了！**

**运行结果**（出现负数）：
```
sellticket2 : 0     ← 已经没票了还在卖
sellticket1 : -1    ← 甚至卖成负数
```

---

#### ⚠️ sellticket3 — 锁内有检查但没睡眠

```cpp
void sellticket3(int index)
{
    while (gcount > 0)
    {
        mtx.lock();
        if (gcount > 0)          // ✅ 双重检查（锁内再检查一次）
        {
            cout << "sellticket" << index << ":" << gcount << endl;
            gcount--;
        }
        mtx.unlock();
    }
    // 没有 sleep，CPU 会被一个线程空转占满
}
```

**分析**：锁内加了 `if (gcount > 0)` 双重检查，**安全性没问题**。但没有 `sleep`，加上每轮只卖 1 张，一个线程会很快地一轮轮循环，在票数变成 0 之前可能完全占据 CPU。

---

#### ✅ sellticket4 — 手动锁 + 双重检查 + 正确睡眠（可用）

```cpp
void sellticket4(int index)
{
    while (gcount > 0)
    {
        mtx.lock();
        if (gcount > 0)
        {
            cout << "sellticket" << index << ":" << gcount << endl;
            gcount--;
        }
        mtx.unlock();
        this_thread::sleep_for(chrono::microseconds(10));  // 🔑 睡眠在锁外面
    }
}
```

**正确做法**：
- ✅ 锁内双重检查 `if (gcount > 0)`
- ✅ 锁外 `sleep_for`，不阻塞其他线程
- ⚠️ 手动 `lock()/unlock()` 容易忘记 unlock（异常安全差）

**运行结果**：
```
sellticket0:10 → sellticket1:9 → sellticket2:8 → sellticket0:7 → ...
```
窗口交替卖票，票数安全。

---

#### ✅ sellticket5 — lock_guard 但睡眠在锁内（错误的用法）

```cpp
void sellticket5(int index)
{
    while (gcount > 0)
    {
        lock_guard<mutex> lock(mtx);      // 🚩 lock_guard 作用于整个 while 迭代
        if (gcount > 0)
        {
            cout << "sellticket" << index << ":" << gcount << endl;
            gcount--;
        }
        this_thread::sleep_for(chrono::microseconds(10));  // 🚩 睡眠在锁内！
    }
}
```

**问题**：`lock_guard` 构造时加锁，**到作用域结束才解锁**。sleep 在 lock_guard 的作用域内，意味着持锁时在睡眠，其他线程被阻塞 10 秒（实际 10 微秒，但原理一样）。

---

#### ✅ sellticket6 — lock_guard + 块级作用域（推荐）

```cpp
void sellticket6(int index)
{
    while (gcount > 0)
    {
        {                                           // 🔑 额外的作用域块
            lock_guard<mutex> lock(mtx);
            if (gcount > 0)
            {
                cout << "sellticket" << index << ":" << gcount << endl;
                gcount--;
            }
        }                                           // 🔑 lock_guard 在这里析构 → 解锁
        this_thread::sleep_for(chrono::microseconds(10));  // ✅ 锁外睡眠
    }
}
```

**⭐ 推荐写法**：
- ✅ RAII（Resource Acquisition Is Initialization）自动加锁/解锁，无异常安全问题
- ✅ 通过 `{}` 创建局部作用域，精确控制锁的生命周期
- ✅ 锁外 sleep，不阻塞其他线程

**lock_guard 限制**：
- ❌ 不可拷贝、不可移动（注释中有说明）
- ❌ 不能提前 unlock（必须等到作用域结束）
- ❌ 不能用于条件变量等待（`cv.wait(lck)` 需要 unique_lock）

---

#### ✅ sellticket7 — unique_lock + 块级作用域（最灵活，main 实际调用）

```cpp
void sellticket7(int index)
{
    while (gcount > 0)
    {
        {
            unique_lock<mutex> lck(mtx);    // 🔑 可以移动赋值
            if (gcount > 0)
            {
                cout << "sellticket" << index << ":" << gcount << endl;
                gcount--;
            }
        }
        this_thread::sleep_for(chrono::microseconds(10));
    }
}
```

**⭐⭐ 最推荐**：

| 特性 | lock_guard | unique_lock |
|------|-----------|-------------|
| 自动加锁 | ✅ | ✅ |
| 自动解锁 | ✅ | ✅ |
| 可移动 | ❌ | ✅ |
| 可提前 unlock | ❌ | ✅ (`lck.unlock()`) |
| 可重新 lock | ❌ | ✅ |
| 支持条件变量 | ❌ | ✅（必需）|
| 开销 | 稍小 | 稍大（内部有状态）|

文件注释补充了条件变量配合 unique_lock 的使用范式：

```cpp
unique_lock<mutex> lck(mtx);
cv.wait(lck);          // 1. 线程进入等待状态
                        // 2. lck.unlock() 释放 mtx（其他线程可进入）
                        // 被唤醒后自动重新 lock

cv.notify_all();        // 唤醒所有在 cv 上等待的线程
```

---

## 3.5 main 函数

```cpp
int main()
{
    list<thread> tlist;                    // 线程列表
    for (int i = 0; i < 3; i++)            // 创建 3 个售票窗口
    {
        tlist.push_back(thread(sellticket7, i));   // 启动线程，传入窗口编号
    }

    for (auto& t : tlist)                  // 等待所有线程完成
    {
        t.join();                          // 阻塞直到该线程执行结束
    }

    std::cout << "Hello World!\n";         // 所有线程结束后才会执行到这里
}
```

**关键点**：
- `thread(sellticket7, i)` 用函数地址 + 参数构造线程对象
- `join()` 是必须的：如果 main 先于子线程结束，程序崩溃
- main 实际调用的是 **sellticket7**（unique_lock 版本）

---

## 3.6 编译与运行

```bash
# 编译（直接用 g++，不需要 CMake）
g++ -std=c++11 -pthread code/sellticket/sellticket.cpp -o sellticket

# 运行
./sellticket
```

**典型输出**（sellticket7）：
```
sellticket1:10
sellticket0:9
sellticket2:8
sellticket0:7
sellticket1:6
sellticket2:5
sellticket1:4
sellticket0:3
sellticket2:2
sellticket0:1
Hello World!
```

---

## 3.7 多线程最佳实践总结

| # | 原则 | 反例 |
|---|------|------|
| 1 | **双重检查**：循环条件检查 + 锁内 `if` 检查 | sellticket2（只锁外检查）|
| 2 | **锁粒度最小化**：只保护必要代码 | sellticket1（锁太大）|
| 3 | **锁外 sleep**：不要持锁睡眠 | sellticket5 |
| 4 | **RAII 管理锁**：用 lock_guard/unique_lock，别手动 lock/unlock | sellticket1-4（手动）|
| 5 | **unique_lock 用于条件变量** | - |
| 6 | **线程必须 join 或 detach** | 不 join 直接退出 → abort |

---

[→ 返回首页](00-HOME.md) | [→ 上一章：projectTemplate](02-PROJECT_TEMPLATE.md) | [→ 下一章：code/test 模块](04-CODE_TEST.md)
