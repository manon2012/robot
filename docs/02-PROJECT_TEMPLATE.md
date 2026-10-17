# 02 · projectTemplate 模块详解

## 2.1 模块概述

**projectTemplate** 是本仓库的核心工程项目，提供了一个最小可运行的 CMake + C++11 项目骨架，演示：

- CMake 构建脚本的基本写法
- 头文件（`include/`）与实现文件（`src/`）的分离
- C++ 面向对象中的 **抽象基类 + 具体子类** 模式
- POSIX 线程库（pthread）的链接方式

---

## 2.2 文件清单

| 文件 | 类型 | 职责 |
|------|------|------|
| `CMakeLists.txt` | 构建脚本 | 定义项目名、编译器要求、生成目标、链接库 |
| `include/Fruit.h` | 头文件 | 抽象基类 `Fruit` 的接口声明 |
| `include/Apple.h` | 头文件 | 子类 `Apple` 的声明，继承 `Fruit` |
| `src/main.cpp` | 源文件 | 程序入口，打印 hello world |
| `src/Apple.cpp` | 源文件 | `Apple::show()` 的具体实现 |

---

## 2.3 构建脚本 CMakeLists.txt

### 完整源码与逐行解析

```cmake
# ────────────────────────────────────────────────────────
# 最低 CMake 版本要求
# ────────────────────────────────────────────────────────
cmake_minimum_required(VERSION 3.9)


# ────────────────────────────────────────────────────────
# 项目名（内部标识）与版本号
# ────────────────────────────────────────────────────────
project(projecttemplate VERSION 1.0)


# ────────────────────────────────────────────────────────
# 生成可执行文件：目标名 template2023，源文件 src/main.cpp
# ⚠️ 注意：Apple.cpp 未被包含！Apple 类目前未被使用
# ────────────────────────────────────────────────────────
add_executable(template2023 src/main.cpp)


# ────────────────────────────────────────────────────────
# 设置构建类型为 Debug（带调试符号，不优化）
# ────────────────────────────────────────────────────────
set(CMAKE_BUILD_TYPE "Debug")


# ────────────────────────────────────────────────────────
# 链接 pthread 库（POSIX 线程支持）
# main.cpp 中 include 了 <thread> 和 <mutex>，需要此库
# ────────────────────────────────────────────────────────
target_link_libraries(template2023 pthread)
```

### 潜在问题

| 问题 | 描述 |
|------|------|
| **Apple.cpp 未编译** | `add_executable` 只包含了 `main.cpp`，`Apple.cpp` 没有被加入构建目标。Fruit/Apple 体系目前未使用 |
| **include 路径未声明** | CMakeLists.txt 没有 `include_directories(include/)`，main.cpp 使用相对路径 `"../include/Apple.h"` 来引入头文件，不够规范 |
| **冗余/注释代码** | 文件底部保留了大量被注释的旧写法（如 `Threads::Threads`、`CMAKE_CXX_FLAGS` 设置）|

---

## 2.4 类与函数详解

### 2.4.1 Fruit 类 — 抽象基类

**文件**：`include/Fruit.h`  
**职责**：定义"水果"的统一接口，是一个纯虚类（接口类）

```cpp
#pragma once          // 防止头文件重复包含
#ifndef FRUIT_H
#define FRUIT_H

class Fruit
{
 public:
   virtual void show() = 0;   // 纯虚函数：= 0 表示没有默认实现
                              // 任何继承 Fruit 的子类必须实现 show()
                              // Fruit 因此成为抽象类，无法直接实例化
};

#endif // !FRUIT_H
```

**设计要点**：

| 要点 | 说明 |
|------|------|
| `virtual` 关键字 | 启用多态，允许通过基类指针调用子类重写的方法 |
| `= 0` 纯虚函数 | 使得 Fruit 成为抽象类，不能 `new Fruit()` |
| 双重保护 | 同时使用 `#pragma once` 和传统 `#ifndef/#define`，兼容性更好 |

---

### 2.4.2 Apple 类 — 具体子类

**文件**：`include/Apple.h` + `src/Apple.cpp`  
**职责**：继承 Fruit 抽象类，实现 Apple 类型的 `show()` 方法

#### 头文件 Apple.h

```cpp
#pragma once
#ifndef APPLE
#define APPLE
#include "Fruit.h"              // 引入基类定义

class Apple : public Fruit     // public 继承：基类的 public 在子类中仍是 public
{
 public:
   void show();                 // 重写 Fruit::show()，这里不加 virtual 也可以
};

#endif // !APPLE
```

#### 实现 Apple.cpp

```cpp
#include "../include/Apple.h"
using namespace std;
#include <iostream>

void Apple::show()
{
    cout << "Apple come" << endl;
}
```

#### 关键点

| 要点 | 说明 |
|------|------|
| 继承关系 | `Apple : public Fruit` 表示是"是一个"（is-a）关系 |
| 头文件包含方式 | `../include/Apple.h` 使用相对路径，不够规范。建议在 CMakeLists.txt 中声明 `include_directories(include/)`，然后在源码中直接 `#include "Apple.h"` |
| 当前状态 | Apple 类**未被 main.cpp 使用**，也未被 CMakeLists.txt 加入编译。整个 Fruit/Apple 体系属于预留/学习性质的代码 |

---

### 2.4.3 main.cpp — 程序入口

**文件**：`src/main.cpp`  
**职责**：程序主入口，目前仅打印 hello world

```cpp
#include <iostream>
#include <thread>        // 预留：多线程支持
#include <mutex>         // 预留：互斥锁
#include <string.h>      // C 风格字符串（C++ 应使用 <cstring>）
#include "../include/Apple.h"

using namespace std;

int main()
{
   cout << "hello,world! tempalte2013" << endl;
   return 0;
}
```

**观察**：

- main 函数极其简单，`#include` 了 `<thread>` 和 `<mutex>` 但实际并未使用
- 引入了 `Apple.h` 但没有实例化 Apple 对象
- `string.h` 是 C 头文件，C++ 中应使用 `<cstring>`
- 字符串 `"tempalte2013"` 疑似拼写错误（应为 template2023）

---

## 2.5 编译与运行

### 标准 CMake 流程

```bash
cd projectTemplate

# 1. 创建 build 目录（已存在可跳过）
mkdir -p build && cd build

# 2. 生成 Makefile（仅第一次或 CMakeLists.txt 变更后需要）
cmake ..

# 3. 编译
make

# 4. 运行
./template2023
```

### 当前输出

```
hello,world! tempalte2013
```

### 扩展：如果要编译 Apple.cpp

修改 `CMakeLists.txt` 的 `add_executable` 行为：

```cmake
add_executable(template2023
    src/main.cpp
    src/Apple.cpp          # ← 新增
)
include_directories(include)  # ← 新增，规范头文件查找
```

然后 main.cpp 中可以这样使用：

```cpp
Apple apple;
Fruit* fruit = &apple;     // 基类指针指向子类对象
fruit->show();             // 输出 "Apple come"（多态）
```

---

## 2.6 类继承关系图

```
          ┌─────────────┐
          │    Fruit     │  ← 抽象基类（接口）
          │  (abstract)  │
          ├─────────────┤
          │virtual show()│  ← 纯虚函数 = 0
          └──────┬──────┘
                 │ public 继承
                 ▼
          ┌─────────────┐
          │    Apple     │  ← 具体实现类
          ├─────────────┤
          │   show()     │  ← 具体实现：cout << "Apple come"
          └─────────────┘
```

---

## 2.7 改进建议

| 优先级 | 建议 |
|--------|------|
| 🔴 高 | 在 `add_executable` 中加入 `src/Apple.cpp` 并在 main 中实际使用 Fruit/Apple 演示多态 |
| 🔴 高 | 在 CMakeLists.txt 添加 `include_directories(include/)`，main.cpp 改用 `#include "Apple.h"` |
| 🟡 中 | 将 `string.h` 替换为 C++ 标准 `<cstring>` 或 `<string>` |
| 🟡 中 | 修正拼写 `tempalte2013` → `template2023` |
| 🟢 低 | 清理注释掉的旧 CMake 代码 |

---

[→ 返回首页](00-HOME.md) | [→ 上一章：项目总览](01-OVERVIEW.md) | [→ 下一章：sellticket 模块](03-SELLTICKET.md)
