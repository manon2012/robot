# 05 · 依赖关系与构建

## 5.1 编译环境要求

| 依赖 | 最低版本 | 用途 |
|------|----------|------|
| **GCC / G++** | 4.8+ | C++11 编译（使用了 `std::thread`、lambda 等 C++11 特性）|
| **CMake** | 3.9 | projectTemplate 的构建系统 |
| **GNU Make** | 3.81+ | CMake 生成 Makefile 后的执行器 |
| **POSIX 线程库** | - | `pthread`，提供 `std::thread` 和 `std::mutex` 的底层实现 |
| **Git** | 任意 | 版本控制 |

### 推荐环境（Linux）

```bash
# Debian / Ubuntu 一键安装
sudo apt update
sudo apt install build-essential cmake git
```

`build-essential` 包包含 gcc、g++、make、libc-dev 等核心编译工具链。

---

## 5.2 C++ 标准库依赖

两个模块均只使用 **C++11 标准库**，无第三方库：

| 头文件 | 用途 | 使用位置 |
|--------|------|----------|
| `<iostream>` | 输入输出流 | main.cpp, Apple.cpp, sellticket.cpp |
| `<thread>` | 多线程 | main.cpp, sellticket.cpp |
| `<mutex>` | 互斥锁 | main.cpp, sellticket.cpp |
| `<list>` | 双向链表（存 thread）| sellticket.cpp |
| `<string.h>` | C 字符串 | main.cpp（应替换为 `<cstring>`）|

---

## 5.3 外部库依赖

| 库 | 链接方式 | 说明 |
|----|----------|------|
| **libpthread** | `target_link_libraries(template2023 pthread)` | POSIX 线程，Linux 下需要显式链接 |

⚠️ **Windows 用户注意**：在 MinGW 环境下 pthread 通常已内置；MSVC 不使用 pthread，而是使用 Windows 原生线程 API。

---

## 5.4 模块构建说明

### 5.4.1 projectTemplate（CMake）

```bash
cd projectTemplate

# 生成构建文件
cmake -B build -S .

# 编译
cmake --build build
# 或者
cd build && make

# 运行
./build/template2023
```

**CMake 输出目录**：`projectTemplate/build/`（已存在，预构建状态）

### 5.4.2 sellticket（直接 g++）

```bash
# 编译
g++ -std=c++11 -pthread code/sellticket/sellticket.cpp -o sellticket

# 运行
./sellticket
```

**参数说明**：

| 参数 | 含义 |
|------|------|
| `-std=c++11` | 使用 C++11 标准（`std::thread` 从 C++11 开始才有）|
| `-pthread` | 编译 + 链接时启用 pthread 支持（有些系统可以只写 `-lpthread`）|
| `-o sellticket` | 指定输出文件名 |

---

## 5.5 依赖关系图

```
                    ┌──────────────┐
                    │  C++11 标准库  │
                    │ (iostream,   │
                    │  thread,     │
                    │  mutex,      │
                    │  list)       │
                    └──────┬───────┘
                           │ 包含
              ┌────────────┼────────────┐
              ▼            ▼            ▼
     ┌────────────┐ ┌───────────┐ ┌──────────┐
     │ project-    │ │ sellticket│ │  纯文本   │
     │ Template    │ │           │ │ test 文件 │
     └─────┬──────┘ └─────┬─────┘ └──────────┘
           │              │
           │              │ 链接
           ▼              ▼
     ┌─────────────────────────┐
     │     libpthread.so       │   (Linux POSIX 线程)
     └─────────────────────────┘
           ▲
           │
           │ CMake / g++ 链接
     ┌─────┴────────┐
     │  GCC + Make   │
     │  (工具链)      │
     └──────────────┘
```

---

## 5.6 VS Code 调试配置

仓库注释中提到了 VS Code 的配置（projectTemplate/src/main.cpp 的注释）：

**launch.json** 关键配置：
```json
{
    "program": "${workspaceFolder}/projectTemplate/build/template2023",
    "configuration": "g++"
}
```

---

## 5.7 一键脚本（可参考）

```bash
#!/bin/bash
# build.sh — 一键编译

set -e

echo "=== 构建 projectTemplate ==="
cd projectTemplate
cmake -B build -S .
cmake --build build
echo "✅ template2023 编译完成"

echo ""
echo "=== 构建 sellticket ==="
cd ../
g++ -std=c++11 -pthread code/sellticket/sellticket.cpp -o sellticket
echo "✅ sellticket 编译完成"

echo ""
echo "=== 运行 projectTemplate ==="
./projectTemplate/build/template2023

echo ""
echo "=== 运行 sellticket ==="
./sellticket
```

---

[→ 返回首页](00-HOME.md) | [→ 上一章：code/test](04-CODE_TEST.md)

---

## 📚 完整 Wiki 索引

| # | 文档 |
|---|------|
| 🏠 | [00 · HOME 首页](00-HOME.md) |
| 1 | [01 · 项目总览与架构](01-OVERVIEW.md) |
| 2 | [02 · projectTemplate 模块](02-PROJECT_TEMPLATE.md) |
| 3 | [03 · sellticket 模块](03-SELLTICKET.md) |
| 4 | [04 · code/test 模块](04-CODE_TEST.md) |
| 5 | [05 · 依赖关系与构建](05-DEPENDENCIES.md) |
