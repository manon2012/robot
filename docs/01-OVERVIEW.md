# 01 · 项目总览与架构

## 1.1 项目定位

本仓库（代号 **robot**）是一个 **C++ 学习与实验仓库**，并非商业项目。其核心价值在于：

- ✅ 提供一个最小可运行的 **CMake 项目模板**，方便快速启动 C++ 工程
- ✅ 系统演示 **C++ 多线程编程**中互斥锁的 7 种使用范式（含反例）
- ✅ 作为 **Git 版本控制**的练习场

---

## 1.2 目录结构详解

```
/workspace/
│
├── projectTemplate/                    🧱 主项目 — CMake 模板
│   ├── CMakeLists.txt                  ⬅️ 构建脚本（入口）
│   ├── include/                        ⬅️ 公共头文件
│   │   ├── Fruit.h                     抽象基类（接口）
│   │   └── Apple.h                     具体子类（实现）
│   ├── src/                            ⬅️ 源代码
│   │   ├── main.cpp                    程序入口（极简 hello world）
│   │   └── Apple.cpp                   Apple::show() 实现
│   └── build/                          ⬅️ 编译产物目录
│       ├── Makefile                    由 cmake 生成
│       ├── template2023                编译好的可执行文件
│       └── CMakeFiles/...              CMake 中间文件
│
├── code/                               📚 学习代码合集
│   ├── sellticket/
│   │   └── sellticket.cpp              🎟️ 多线程售票示例（147行）
│   ├── stringtest/
│   │   └── 1.txt                       字符串测试文件
│   └── test/                           Git 练习目录
│       ├── helloworld.txt
│       ├── local.txt
│       ├── localadd.txt
│       ├── github
│       └── afterlocaladd
│
├── README.md                           顶层简介（仅一行 "# robot"）
├── addtestingithub                     Git 测试文件
└── .git/                                Git 仓库数据
```

---

## 1.3 整体架构

### 架构风格

仓库并非一个统一的大型应用，而是 **多个独立学习单元的集合**。使用以下两种组织模式：

| 模块 | 组织模式 | 构建方式 |
|------|----------|----------|
| projectTemplate | 标准 CMake 工程（include/ + src/ 分离） | CMake + Make |
| sellticket | 单文件独立示例 | g++ 直接编译 |
| code/test | 纯文本数据 | 无需构建 |

### 模块依赖关系图

```
┌─────────────────────────────────────────────────────────────────────┐
│                          仓库根目录                                 │
├─────────────────────────────────────────────────────────────────────┤
│                                                                     │
│   ┌──────────────────────────────┐                                 │
│   │     projectTemplate          │                                 │
│   │                              │                                 │
│   │   Fruit.h ◄── Apple.h        │  继承关系                       │
│   │      ▲          ▲            │                                 │
│   │      │          │            │                                 │
│   │   Apple.cpp  main.cpp        │                                 │
│   │         └────┬───┘           │                                 │
│   │              ▼               │                                 │
│   │         template2023         │  可执行文件                      │
│   └──────────────────────────────┘                                 │
│                                                                     │
│   ┌──────────────────────────────┐                                 │
│   │   code/sellticket/           │                                 │
│   │   sellticket.cpp (独立)       │  无模块内依赖                    │
│   └──────────────────────────────┘                                 │
│                                                                     │
│   ┌──────────────────────────────┐                                 │
│   │   code/test/                  │                                 │
│   │   Git 练习文件 (独立)         │  无代码依赖                      │
│   └──────────────────────────────┘                                 │
│                                                                     │
└─────────────────────────────────────────────────────────────────────┘
```

### projectTemplate 内部类图

```cpp
class Fruit {              // 抽象基类（接口）
public:
    virtual void show() = 0;   // 纯虚函数
};

class Apple : public Fruit {   // 具体实现
public:
    void show();               // 重写虚函数
};
```

---

## 1.4 技术栈

| 维度 | 技术选型 |
|------|----------|
| 语言标准 | C++11 |
| 编译器 | GCC（Linux 默认）/ MinGW（Windows）|
| 构建系统 | CMake ≥ 3.9 |
| 链接库 | pthread（POSIX 线程）|
| 版本控制 | Git |
| 调试器 | GDB / VS Code Debugger |

---

## 1.5 代码规模

| 模块 | 文件数 | 代码行数（约） |
|------|--------|----------------|
| projectTemplate/include | 2 | 30 |
| projectTemplate/src | 2 | 40 |
| code/sellticket | 1 | 147 |
| build 产物 | ~50+ | -（自动生成）|

---

[→ 返回首页](00-HOME.md) | [→ 下一章：projectTemplate 模块](02-PROJECT_TEMPLATE.md)
