# Robot C++ Code Wiki

> 项目代号：**robot** — 一个 C++ 学习与实验仓库  
> 构建系统：**CMake ≥ 3.9**  
> 编程语言：**C++11**  
> 操作系统：**Linux**  

---

## 🏠 Wiki 导航

| 文档 | 说明 |
|------|------|
| [01-项目总览与架构](01-OVERVIEW.md) | 项目定位、目录结构、整体架构 |
| [02-projectTemplate 模块](02-PROJECT_TEMPLATE.md) | CMake 项目模板，面向对象继承示例 |
| [03-sellticket 模块](03-SELLTICKET.md) | 多线程售票系统，7 种互斥锁用法对比 |
| [04-code/test 模块](04-CODE_TEST.md) | Git 练习与版本控制测试文件 |
| [05-依赖关系与构建](05-DEPENDENCIES.md) | 第三方依赖、编译运行方式 |

---

## 📁 仓库结构速览

```
/workspace/
├── projectTemplate/       # 🧱 CMake 项目模板（主项目）
│   ├── CMakeLists.txt
│   ├── include/
│   │   ├── Fruit.h        # 抽象基类
│   │   └── Apple.h        # 子类：苹果
│   ├── src/
│   │   ├── main.cpp       # 程序入口
│   │   └── Apple.cpp      # Apple 实现
│   └── build/             # 编译产物（已构建）
├── code/
│   ├── sellticket/
│   │   └── sellticket.cpp # 🎟️ 多线程售票示例
│   ├── stringtest/
│   │   └── 1.txt
│   └── test/              # Git 练习文件
├── README.md              # 项目简介（极简）
└── addtestingithub
```

---

## 🎯 学习主题索引

| 主题 | 位置 |
|------|------|
| **CMake 构建系统** | `projectTemplate/CMakeLists.txt` |
| **面向对象 / 虚函数 / 抽象类** | `projectTemplate/include/Fruit.h` → `Apple.h` |
| **多线程基础（std::thread）** | `code/sellticket/sellticket.cpp` |
| **互斥锁（std::mutex）** | sellticket1 ~ sellticket7 |
| **lock_guard vs unique_lock** | sellticket5 ~ sellticket7 |
| **临界区与条件竞争** | sellticket2（有 bug）|
| **Git 基础操作** | `code/test/` |

---

*最后更新：2026-10-17*
