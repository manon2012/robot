#include <iostream>
#include <string>
using namespace std;

// class Fruit
// {
// public:
//     virtual void show() const = 0;
// };

// class Apple : public Fruit
// {
// public:
//     void show() const
//     {
//         std::cout << "Apple show" << std::endl;
//     }
// };

// class Banana : public Fruit
// {
// public:
//     void show() const
//     {
//         std::cout << "Banana show" << std::endl;
//     }
// };

// class FruitFactory
// {
// public:
//     virtual Fruit *createFruit() = 0;
// };

// class AppleFactory : public FruitFactory
// {
// public:
//     Fruit *createFruit()
//     {
//         return new Apple;
//     }
// };

// class BananaFactory : public FruitFactory
// {
// public:
//     Fruit *createFruit()
//     {
//         return new Banana;
//     }
// };

// class SimpleFactory
// {
// public:
//     static Fruit *createFruit(string abc)
//     {
//         Fruit *fp = nullptr;
//         if (abc == "apple")
//         {
//             fp = new Apple;
//         }
//         else if (abc == "Banana")
//         {
//             fp = new Banana;
//         }
//         else
//         {
//             fp = new Apple;
//         }
//         return fp;
//     }
// };

// class Animal
// {
// public:
//     virtual void show() const = 0;
// };

// class Cat : public Animal
// {
// public:
//     void show() const
//     {
//         std::cout << "miao" << std::endl;
//     }
// };

// class Dog : public Animal
// {
// public:
//     void show() const
//     {
//         std::cout << "dd" << std::endl;
//     }
// };

// class CDocument
// {
// public:
//     void onFileOpen()
//     {
//         open();
//         serialize();
//         close();
//     }
//     void open()
//     {
//     }
//     virtual void serialize() = 0;
//     void close()
//     {
//     }
// };

// class myDocuments : public CDocument
// {
// public:
//     void serialize()
//     {
//         std::cout << "serialize documents" << std::endl;
//     }
// };

// class CMCC
// {
// public:
//     void onCharge(int x)
//     {
//         std::cout << "onCharge done: " << x << std::endl;
//     }
// };

// class CMCCProxy : public CMCC
// {
// public:
//     void onCharge(int x)
//     {
//         if (x < 100)
//         {
//             std::cout << "need more than 100" << std::endl;
//             return;
//         }
//         else
//         {
//             if (m_cmcc)
//             {
//                 m_cmcc->onCharge(x);
//             }
//             else
//             {
//                 m_cmcc = new CMCC;
//                 m_cmcc->onCharge(x);
//                 delete m_cmcc;
//             }
//         }
//     }

// private:
//     CMCC *m_cmcc;
// };

// class Weapon
// {
// public:
//     virtual void doit() = 0;
// };

// class AK47 : public Weapon
// {
// public:
//     void doit()
//     {
//         std::cout << "AK47..." << std::endl;
//     };
// };

// class Knife : public Weapon
// {
// public:
//     void doit()
//     {
//         std::cout << "Knife..." << std::endl;
//     }
// };

// class character
// {
// public:
//     character(Weapon *p = nullptr) {}
//     void setWeapon(Weapon *p)
//     {
//         m_weapon = p;
//     }
//     void useit()
//     {
//         m_weapon->doit();
//     }

// private:
//     Weapon *m_weapon;
// };

// #include <list>
// class Subject;

// class Observer
// {
// public:
//     void update(int x)
//     {
//         std::cout << "update to : " << x << std::endl;
//     }

// private:
// };

// class Subject
// {
// public:
//     void addit(Observer *observer)
//     {
//         m_observers.push_back(observer);
//     }
//     void removeit(Observer *observer)
//     {
//         m_observers.remove(observer);
//     }

//     void notify(int x)
//     {
//         m_int = x;

//         for (auto &observer : m_observers)
//         {

//             observer->update(x);
//         }
//     }

// private:
//     list<Observer *> m_observers;
//     int m_int;
// };

// class component
// {
// public:
//     virtual void process() = 0;
//     virtual void addNode() {}
//     virtual void removeNode() {}
// };

// class composite : public component
// {
// public:
//     composite(string abc) : m_name(abc) {}
//     void process()
//     {
//         std::cout << "Composite do process:" << m_name << std::endl;
//         for (auto &x : m_list)
//         {
//             x->process();
//         }
//     }

//     void addComponent(component *c)
//     {
//         m_list.push_back(c);
//     }

//     void removeComponent(component *c)
//     {
//         m_list.remove(c);
//     }

// private:
//     list<component *> m_list;
//     string m_name;
// };

// class leaf : public component
// {
// public:
//     leaf(string name) : m_name(name) {}
//     void process()
//     {
//         std::cout << "leaf process: " << m_name << std::endl;
//     }

// private:
//     string m_name;
// };

// class ITarget
// {
// public:
//     virtual void process() = 0;
// };

// class IAdaptee
// {
// public:
//     virtual void foo(int x) = 0;
//     virtual int bar() = 0;
// };

// class oldclass : public IAdaptee
// {
// public:
//     void foo(int x) { std::cout << "foo in oldclass" << std::endl; }
//     int bar() { std::cout << "bar in oldclass" << std::endl; }
// };

// class Adpater : public ITarget
// {

// public:
//     Adpater(IAdaptee *adaptee) : IA(adaptee) {}
//     void process()
//     {
//         std::cout << "Processing in Adapter" << std::endl;
//         int x = IA->bar();
//         IA->foo(x);
//     }

// private:
//     IAdaptee *IA;
// };

// class Receiver
// {
// public:
//     void action()
//     {
//         std::cout << "action" << std::endl;
//     }
// };

// class Command
// {
// public:
//     virtual void execute() = 0;
// };

// class ConcreteCommand : public Command
// {
// public:
//     ConcreteCommand(Receiver *receiver) : rec(receiver) {}
//     void execute()
//     {
//         rec->action();
//     }

// private:
//     Receiver *rec;
// };

// class Invoke
// {
// public:
//     Invoke(Command *command = nullptr) : cmd(command) {}
//     void setCommand(Command *c)
//     {
//         cmd = c;
//     }
//     void IVoke()
//     {
//         cmd->execute();
//     }

// private:
//     Command *cmd;
// };

// class ABsHero
// {
// public:
//     virtual void update() = 0;
// };

// class ChinaHero : public ABsHero
// {
// public:
//     void update()
//     {
//         std::cout << "ChinaHero update..." << std::endl;
//     }
// };

// class JpnHero : public ABsHero
// {
// public:
//     void update()
//     {
//         std::cout << "JpnHero update..." << std::endl;
//     }
// };

// class ABsBoss
// {
// public:
//     virtual void addHero(ABsHero *b) = 0;
//     virtual void removeHero(ABsHero *b) = 0;
//     virtual void notify() = 0;

//     list<ABsHero *> m_list;
// };

// class wtoBoss : public ABsBoss
// {
// public:
//     void addHero(ABsHero *b)
//     {
//         m_list.push_back(b);
//     }
//     void removeHero(ABsHero *b)
//     {
//         m_list.remove(b);
//     }
//     void notify()
//     {
//         for (auto *x : m_list)
//         {
//             x->update();
//         }
//     }
// };

// class Fruit
// {
// public:
//     virtual void show() = 0;
//     virtual ~Fruit() {}
// };

// class Apple : public Fruit
// {
// public:
//     void show()
//     {
//         cout << "Apple" << endl;
//     }
// };

// class Banana : public Fruit
// {
// public:
//     void show()
//     {
//         cout << "Banana" << endl;
//     }
// };

// class FruitFactory
// {
// public:
//     virtual Fruit *createFruit() = 0;
//     virtual ~FruitFactory() = 0;

// private:
// };

// class AppleFactory : public FruitFactory
// {
// public:
//     Fruit *createFruit()
//     {
//         return new Apple();
//     }
// };

// class BananaFactory : public FruitFactory
// {
// public:
//     Fruit *createFruit()
//     {
//         return new Banana();
//     }
// };

// class SimpleFactory
// {
// public:
//     static Fruit *createFruit(string fruit)
//     {
//         // static Fruit *f;
//         if (fruit == "Apple")
//         {
//             f = new Apple();
//         }
//         else if (fruit == "Banana")
//         {
//             f = new Banana();
//         }
//         else
//         {
//             f = nullptr;
//         }
//         return f;
//     }

// private:
//     static Fruit *f;
// };

// class Target
// {
// public:
//     virtual void process() = 0;
// };

// class Iadaptee
// {
// public:
//     virtual int foo() = 0;
//     virtual void bar(int) = 0;
// };

// class oldclass : public Iadaptee
// {
// public:
//     int foo()
//     {
//         std::cout << "foo old class" << std::endl;
//         return 10;
//     }
//     void bar(int)
//     {
//         std::cout << "bar old class" << std::endl;
//     }
// };
// class adapter : public Target
// {
// public:
//     adapter(Iadaptee *t = 0) : ida(t) {}
//     void process()
//     {
//         int abc = ida->foo();
//         ida->bar(abc);
//     }

// private:
//     Iadaptee *ida;
// };

// class weapon
// {
// public:
//     virtual void function() = 0;
// };

// class AK47 : public weapon
// {
// public:
//     void function()
//     {
//         cout << "AK47" << endl;
//     }
// };

// class knife : public weapon
// {
// public:
//     void function()
//     {
//         cout << "knife" << endl;
//     }
// };

// class character
// {
// public:
//     character(weapon *weapon = nullptr) : ws(weapon) {}
//     void setws(weapon *weapon)
//     {
//         ws = weapon;
//     }
//     void doit()
//     {
//         ws->function();
//     }

// private:
//     weapon *ws;
// };

// class CDocument
// {
// public:
//     void onFileOpen()
//     {
//         open();
//         Serialize();
//         Close();
//     }
//     void open()
//     {
//         cout << "open" << endl;
//     }
//     void Close()
//     {
//         cout << "close" << endl;
//     }

// protected:
//     virtual void Serialize() = 0;
// };

// #include <list>
// class MyDocument : public CDocument
// {
// public:
//     void Serialize()
//     {
//         cout << "MyDocument Serialize" << endl;
//     }
// };

// class component
// {
// public:
//     virtual void process() = 0;
//     virtual void AddNode() {}
//     virtual void RemoveNode() {}
// };

// class composite : public component
// {
// public:
//     composite(string name) : m_name(name) {}
//     void process()
//     {
//         cout << "Composite process " << m_name << endl;
//         for (auto &x : m_list)
//         {
//             x->process();
//         }
//     };
//     void AddNode(component *c) { m_list.push_back(c); }
//     void RemoveNode(component *c) { m_list.remove(c); }

// private:
//     list<component *> m_list;
//     string m_name;
// };

// class leaf : public component
// {
// public:
//     leaf(string name) : m_name(name) {}
//     void process()
//     {
//         cout << "lefe processing " << m_name << endl;
//     }

// private:
//     string m_name;
// };

// class Receiver
// {
// public:
//     void action() { cout << "Receiver action" << endl; }
// };

// class command
// {
// public:
//     virtual void execute() = 0;
// };

// class concroCommand : public command
// {
// public:
//     concroCommand(Receiver *x) : r(x) {}
//     void execute()
//     {
//         cout << "ConcronCommand executed" << endl;
//         r->action();
//     }

// private:
//     Receiver *r;
// };

// class Invoke
// {
// public:
//     Invoke(command *c = nullptr) : cmd(c) {}

//     void setCommand(command *c)
//     {
//         cmd = c;
//     }

//     void Ivoke()
//     {
//         cmd->execute();
//     }

// private:
//     command *cmd;
// };

// class Subject;
// class Observer
// {
// public:
//     void update()
//     {
//         cout << "Observer update" << endl;
//     }
// };

// class Subject
// {
// public:
//     void addObs(Observer *obs)
//     {
//         m_list.push_back(obs);
//     }
//     void removeObs(Observer *obs)
//     {
//         m_list.remove(obs);
//     }
//     void notify()
//     {
//         for (auto &x : m_list)
//         {
//             x->update();
//         }
//     }

// private:
//     list<Observer *> m_list;
// };

// class Business
// {
// public:
//     virtual void charge(int x) = 0;
// };

// class CMCC : public Business
// {
// public:
//     void charge(int x)
//     {
//         cout << "charge " << x << endl;
//     }
// };

// class CMCCProxy : public Business
// {
// public:
//     void charge(int x)
//     {
//         if (x < 100)
//         {
//             cout << "x<100 " << endl;
//         }
//         else
//         {
//             if (m_CMCC == nullptr)
//             {
//                 CMCC *m_CMCC = new CMCC;
//                 m_CMCC->charge(x);
//                 delete m_CMCC;
//             }
//         }
//     }

// private:
//     CMCC *m_CMCC;
// };

// class singleton
// {
// public:
//     static singleton *getInstance();
//     static singleton *m_Instance;
//     void show()
//     {
//         cout << "Singleton show" << endl;
//     }

// private:
//     singleton() = default;
//     singleton(const singleton &x);
// };

// singleton *singleton::getInstance()
// {
//     if (m_Instance == nullptr)
//     {
//         m_Instance = new singleton();
//     }
//     return m_Instance;
// }
// singleton *singleton::m_Instance = nullptr;

// class singleton
// {
// public:
//     static singleton *m_Instance;
//     static singleton *getInstance();
//     void show()

//     {
//         std::cout << "show" << std::endl;
//     }

// private:
//     singleton() {}
//     singleton(const singleton &obj) {}
// };

// singleton *singleton::m_Instance = nullptr;

// singleton *singleton::getInstance()
// {
//     if (m_Instance == nullptr)
//     {
//         m_Instance = new singleton;
//     }
//     return m_Instance;
// }

// class hungrysingleton
// {
// public:
//     static hungrysingleton *getInstance()
//     {
//         return p;
//     }
//     void show()
//     {
//         cout << "hungrysingleton show" << endl;
//     }

// private:
//     static hungrysingleton *p;
//     hungrysingleton() {}
// };

// hungrysingleton *hungrysingleton::p = new hungrysingleton();

// class Business2025
// {
// public:
//     virtual ~Business2025() {}
//     virtual void charge(int x) = 0;
// };

// class CMCC2025 : public Business2025
// {
// public:
//     void charge(int x)
//     {
//         cout << "CMCC2025 charge " << x << endl;
//     }
// };

// class CMCC2025Proxy : public Business2025
// {
// public:
//     void charge(int x)
//     {
//         if (x < 100)
//         {
//             cout << "x need more than 100" << endl;
//         }
//         else
//         {
//             if (m_CMCC == nullptr)
//             {
//                 m_CMCC = new CMCC2025;
//                 m_CMCC->charge(x);
//                 delete m_CMCC;
//             }
//         }
//     }

// private:
//     CMCC2025 *m_CMCC;

// };

// class ITarget
// {
// public:
//     virtual void process() = 0;
// };

// class Iadaptee
// {
// public:
//     virtual int foo() = 0;
//     virtual void bar(int x) = 0;
// };

// class oldclass : public Iadaptee
// {
// public:
//     int foo()
//     {
//         cout << "foo in oldclass" << endl;
//         return 2025;
//     }

//     void bar(int x)
//     {
//         cout << "bar in oldclass" << endl;
//     }
// };

// class Adapter : public ITarget
// {
// public:
//     Adapter(Iadaptee *ada) : IA(ada) {}
//     void process()
//     {
//         int t = IA->foo();
//         IA->bar(t);
//     }

// private:
//     Iadaptee *IA;
// };

// class T1
// {
// public:
//     explicit T1(int x) : m_t(x) {}
//     void show()
//     {
//         cout << "t show" << endl;
//     }

// private:
//     int m_t;
// };

// template <class T>
// T add(T a, T b)
// {
//     return a + b;
// }

// #include <list>
// class component
// {
// public:
//     virtual ~component() {}
//     virtual void process() = 0;
//     virtual void addNode(component *obj) {}
//     virtual void removeNode(component *obj) {}

// private:
// };

// class composite : public component
// {
// public:
//     composite(string name) : m_name(name) {}
//     void process()
//     {
//         cout << " composite process " << m_name << endl;
//         for (auto &x : m_list)
//         {
//             x->process();
//         }
//     }
//     void addNode(component *obj)
//     {
//         // cout << " composite add" << endl;
//         m_list.push_back(obj);
//     }
//     void removeNode(component *obj)
//     {
//         cout << " composite remove " << endl;
//         m_list.remove(obj);
//     }

// private:
//     list<component *> m_list;
//     string m_name;
// };

// class leaf : public component
// {
// public:
//     leaf(string name) : m_name(name) {}
//     void process()
//     {
//         cout << "leaf process" << m_name << endl;
//     }

// private:
//     string m_name;
// };

// class Animal
// {
// public:
//     virtual ~Animal() {}
//     virtual void show() = 0;
// };

// class Cat : public Animal
// {
// public:
//     void show()
//     {
//         cout << "cat" << endl;
//     }
// };

// class Dog : public Animal
// {
// public:
//     void show()
//     {
//         cout << "dog" << endl;
//     }
// };

// #include <string.h>
// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }
//     CATString(const CATString &obj)
//     {
//         m_data = new char[strlen(obj.m_data) + 1];
//         strcpy(m_data, obj.m_data);
//     }

//     CATString &operator=(const CATString &obj)
//     {
//         if (this != &obj)
//         {
//             delete[] m_data;
//             m_data = new char[strlen(obj.m_data) + 1];
//             strcpy(m_data, obj.m_data);
//         }
//         return *this;
//     }

//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &os, const CATString &obj);
// };

// ostream &operator<<(ostream &os, const CATString &obj)
// {
//     os << obj.m_data;
//     return os;
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         cout << y << endl;
//     }
// }
// typedef void (*func)(int, string);
// class caller
// {
// public:
//     void setfun(func f)
//     {
//         m_func = f;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     func m_func;
// };

// using namespace std;
// #include <iostream>
// #include <vector>
// #include <future>

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(3));

//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// class ITarget
// {
// public:
//     virtual ~ITarget() {};
//     virtual void process() = 0;
// };

// class Iadaptee
// {
// public:
//     virtual ~Iadaptee() {};
//     virtual int foo() = 0;
//     virtual void bar(int x) = 0;
// };

// class oldclass : public Iadaptee
// {
// public:
//     int foo()
//     {
//         cout << "foo in oldclass" << endl;
//         return 2025;
//     }
//     void bar(int x)
//     {
//         cout << "bar in oldclass" << endl;
//     }
// };

// class Adapter : public ITarget
// {
// public:
//     Adapter(Iadaptee *ada) : adaptee(ada) {}
//     void process()
//     {
//         int x = adaptee->foo();
//         adaptee->bar(x);
//     }

// private:
//     Iadaptee *adaptee;
// };

// https : // zhuanlan.zhihu.com/p/450583728
// #include <stdio.h>
// #include <string>
// #include <iostream>
// using namespace std;
// class Context; // 声明
// // 数据驱动模型：状态基类
// class IState
// {
// public:
//     /*行为方法*/
//     virtual void Handle(Context *context) = 0;
//     // 获得当前的状态
//     virtual void GetState() = 0;
// };
// // 状态管理类
// class Context
// {
// public:
//     // 初始化状态
//     Context(IState *state)
//     {
//         m_pState = state;
//     }
//     // 获得当前的状态
//     IState *GetState()
//     {
//         return m_pState;
//     }
//     // 改变当前的状态
//     void SetState(IState *state)
//     {
//         m_pState = state;
//     }
//     // 执行状态类实现的方法
//     void Request()
//     {
//         m_pState->Handle(this);
//     }
//     IState *m_pState;
// };
// // 具体的状态子类
// class ConcreteStateA : public IState
// {
// public:
//     void Handle(Context *context);
//     void GetState();
// };
// // 具体的状态子类
// class ConcreteStateB : public IState
// {
// public:
//     void Handle(Context *context);
//     void GetState();
// };
// // 具体的状态子类
// class ConcreteStateC : public IState
// {
// public:
//     void Handle(Context *context);
//     void GetState();
// };
// void ConcreteStateA::Handle(Context *context)
// {
//     // A->B
//     // Next:ConcreteStateB
//     context->m_pState = new ConcreteStateB;
//     cout << "当前状态是A，下一状态是B" << endl;
// }
// void ConcreteStateB::Handle(Context *context)
// {
//     // B->C
//     // Next:ConcreteStateC
//     context->m_pState = new ConcreteStateC;
//     cout << "当前状态是B，下一状态是C" << endl;
// }
// void ConcreteStateC::Handle(Context *context)
// {
//     // C->A
//     // Next:ConcreteStateA
//     context->m_pState = new ConcreteStateA;
//     cout << "当前状态是C，下一状态是A" << endl;
// }
// void ConcreteStateA::GetState()
// {
//     cout << "当前状态是A" << endl;
// }
// void ConcreteStateB::GetState()
// {
//     cout << "当前状态是B" << endl;
// }
// void ConcreteStateC::GetState()
// {
//     cout << "当前状态是B" << endl;
// }

// int test11()
// {
//     {
//         // 初始化A状态
//         Context *context = new Context(new ConcreteStateA);
//         context->Request(); // 由A驱动，Next=B
//         context->Request(); // 由B驱动，Next=C
//         context->Request(); // 由C驱动，Next=A
//         getchar();
//         return 0;
//     }
// }

// class singleton
// {
// public:
//     static singleton *getInstance()
//     {
//         if (m_instance == nullptr)
//         {
//             m_instance = new singleton();
//         }
//         return m_instance;
//     }
//     void show()
//     {
//         cout << "singleton show" << endl;
//     }

// private:
//     singleton() {}
//     singleton(const singleton &other) {}
//     static singleton *m_instance;
// };

// singleton *singleton::m_instance = nullptr;

// class hungrysingleton
// {
// public:
//     static hungrysingleton *getInstance()
//     {
//         return m_instance;
//     }
//     void show()
//     {
//         cout << "hungrysingleton show" << endl;
//     }

// private:
//     static hungrysingleton *m_instance;
// };

// hungrysingleton *hungrysingleton::m_instance = new hungrysingleton;

// class Istate
// {
// public:
//     virtual void Handle() = 0;
//     virtual void getstate() = 0;
// };

// class Context
// {
// public:
//     Istate *m_state;
//     void Request()
//     {
//         m_state->Handle();
//     }
//     void setstate(Istate *st)
//     {
//         m_state = st;
//     }
// };

// class ConcreteStateA : public Istate
// {
// public:
//     void Handle()
//     {
//     }
// };

// class ConcreteStateB : public Istate
// {

// public:
//     void Handle()
//     {
//     }
// };

// class Fruit
// {
// public:
//     virtual void show() = 0;
// };

// class Apple : public Fruit
// {
// public:
//     void show()
//     {
//         cout << "Apple" << endl;
//     }
// };

// class simpleFactory
// {
// public:
//     static Fruit *createFruit(string name)
//     {
//         static Fruit *p = nullptr;
//         if (name == "Apple")
//         {
//             p = new Apple;
//         }
//         return p;
//     }

// private:
// };

// class ISplit
// {
// public:
//     virtual ~ISplit() {}
//     virtual void split() = 0;
// };

// class BinarySplit : public ISplit
// {
// public:
//     void split()
//     {
//         cout << "Splitting binary" << endl;
//     }
// };

// class FileSplit : public ISplit
// {
// public:
//     void split()
//     {
//         cout << "Splitting file" << endl;
//     }
// };

// class SplitFactory
// {
// public:
//     virtual ~SplitFactory() {}
//     virtual ISplit *createsplit() = 0;
// };

// class FileSplitFactory : public SplitFactory
// {
// public:
//     ISplit *createsplit()
//     {
//         return new FileSplit;
//     }
// };

// class BinarySplitFactory : public SplitFactory
// {
// public:
//     ISplit *createsplit()
//     {
//         return new BinarySplit;
//     }
// };

// class Form
// {
// public:
//     Form(SplitFactory *fac) : factor(fac) {}

//     void click()
//     {
//         ISplit *isp = factor->createsplit();
//         isp->split();
//     }

// private:
//     SplitFactory *factor;
// };

// class ITarget
// {
// public:
//     virtual ~ITarget() {}
//     virtual void process() = 0;
// };

// class IAdaptee
// {
// public:
//     virtual ~IAdaptee() {}
//     virtual int foo() = 0;
//     virtual void bar(int) = 0;
// };

// class oldclass : public IAdaptee
// {
// public:
//     int foo()
//     {
//         cout << "old class foo" << endl;
//         return 2025;
//     }
//     void bar(int x)
//     {
//         cout << "old class bar" << endl;
//         cout << x << endl;
//     }
// };

// class Adapter : public ITarget // here lost public:
// {
// public:
//     Adapter(IAdaptee *adaptee) : ada(adaptee) {}
//     void process()
//     {
//         int x = ada->foo();
//         ada->bar(x);
//     }

// private:
//     IAdaptee *ada;
// // };
// class Context;

// class IState
// {
// public:
//     // virtual ~IState() {}
//     virtual void Handle(Context *con) = 0;
//     virtual void GetState() = 0;
// };

// class Context
// {
// public:
//     Context(IState *is) : m_pState(is) {}
//     IState *GetState() { return m_pState; }

//     void SetState(IState *st)
//     {
//         m_pState = st;
//     }
//     void Request()
//     {
//         m_pState->Handle(this);
//     }
//     IState *m_pState;
// };

// class ConcreteStateA : public IState
// {
// public:
//     void Handle(Context *contest);

//     void GetState()
//     {
//         cout << "ConcreteStateA now" << endl;
//     }
// };

// class ConcreteStateB : public IState
// {
// public:
//     void Handle(Context *contest);
//     void GetState()
//     {
//         cout << "ConcreteStateB now" << endl;
//     }
// };

// class ConcreteStateC : public IState
// {
// public:
//     void Handle(Context *contest);
//     void GetState()
//     {
//         cout << "ConcreteStateC now" << endl;
//     }
// };

// void ConcreteStateA::Handle(Context *context)
// {
//     cout << "ConcreteStateA doing..." << endl;
//     context->m_pState = new ConcreteStateB;
// }

// void ConcreteStateB::Handle(Context *context)
// {
//     cout << "ConcreteStateB doing..." << endl;
//     context->m_pState = new ConcreteStateC;
// }

// void ConcreteStateC::Handle(Context *context)
// {
//     cout << "ConcreteStateC doing..." << endl;
//     context->m_pState = new ConcreteStateA;
// }

// class Apple;
// class Banana;

// class Fruit
// {
// public:
//     virtual ~Fruit() {}
//     virtual Fruit *show() = 0;
// };

// class Apple : public Fruit
// {
// public:
//     Fruit *show()
//     {
//         return new Banana;
//     }
// };

// class Banana : public Fruit
// {
// public:
//     Fruit *show()
//     {
//         return new Apple;
//     }
// };

// Fruit *Apple::show()
// {
//     cout << "Apple" << endl;
//     return new Apple;
// }

// Fruit *Banana::show()
// {
//     cout << "Banana" << endl;
//     return new Banana;
// }

// class Fruit
// {
// public:
//     virtual ~Fruit() {}
//     virtual Fruit *show() = 0;
// };

// class Apple : public Fruit
// {
// public:
//     Fruit *show()
//     {
//         return new Banana;
//     }
// };

// class Banana : public Fruit
// {
// public:
//     Fruit *show()
//     {
//         return new Apple;
//     }
// };
// class Context;
// class IState
// {
// public:
//     virtual ~IState() {}
//     virtual void Handle(Context *context) = 0;
// };

// class Context
// {
// public:
//     IState *m_pstate;

//     Context(IState *state) : m_pstate(state) {}
//     void Request()
//     {
//         m_pstate->Handle(this);
//     }
//     IState *GetState()
//     {
//         return m_pstate;
//     }
//     void setState(IState *state)
//     {
//         m_pstate = state;
//     }
// };

// class ConcreteStateA : public IState
// {
// public:
//     void Handle(Context *context);
// };

// class ConcreteStateB : public IState
// {
// public:
//     void Handle(Context *context);
// };

// void ConcreteStateA::Handle(Context *context)
// {
//     cout << "ConcreteState A now" << endl;
//     context->m_pstate = new ConcreteStateB;
// }

// void ConcreteStateB::Handle(Context *context)
// {
//     cout << "ConcreteState B now" << endl;
//     context->m_pstate = new ConcreteStateA;
// }

// class shape
// {
// public:
//     virtual ~shape() {}
//     virtual void draw() = 0;
// };

// class circle : public shape
// {
// public:
//     void draw()
//     {
//         cout << "drawing circle" << endl;
//     }
// };

// class rectanc : public shape
// {
// public:
//     void draw()
//     {
//         cout << "drawing rectanc" << endl;
//     }
// };

// class shapeDecorator : public shape
// {
// public:
//     void draw()
//     {
//         sp->draw();
//     }
//     shapeDecorator(shape *s) : sp(s) {}

// protected:
//     shape *sp;
// };

// class shapeDecoratorAdd123 : public shapeDecorator
// {
// public:
//     shapeDecoratorAdd123(shape *s) : shapeDecorator(s) {}
//     void draw()
//     {
//         sp->draw();
//         cout << "add123" << endl;
//     }
// };

// class shapeDecoratorAddabc : public shapeDecorator
// {
// public:
//     void draw()
//     {
//         sp->draw();
//         cout << "addabc" << endl;
//     }
// };

// class Fruit
// {
// public:
//     virtual ~Fruit() {}
//     virtual void show() = 0;
// };
// class Apple : public Fruit
// {
// public:
//     void show()
//     {
//         cout << "Apple" << endl;
//     }
// };

// class simpleFactory
// {
// public:
//     // static Fruit *fp;
//     static Fruit *CreateFruit(string name)
//     {
//         static Fruit *fp;
//         if (name == "Apple")
//         {
//             fp = new Apple;
//         }
//         return fp;
//     }
// };
// // Fruit *simpleFactory::fp = nullptr;

// class FruitFactory
// {
// public:
//     virtual Fruit *createFruit() = 0;
// };

// class AppleFactory : public FruitFactory
// {
// public:
//     Fruit *createFruit()
//     {
//         return new Apple;
//     }
// };

// class Context;
// class Istate
// {
// public:
//     virtual void Handle(Context *context) = 0;
//     // virtual void GetState() = 0;
// };

// class Context
// {
// public:
//     Istate *m_pstat;
//     Context(Istate *pstat) : m_pstat(pstat) {}
//     void setState(Istate *p)
//     {
//         m_pstat = p;
//     }
//     Istate *getState()
//     {
//         return m_pstat;
//     }
//     void Request()
//     {
//         m_pstat->Handle(this);
//     }
// };

// class ConcreteStateA : public Istate
// {
// public:
//     void Handle(Context *context);
//     // void GetState()
//     // {
//     //   return m_p
//     // }
// };

// class ConcreteStateB : public Istate
// {
// public:
//     void Handle(Context *context);
//     // void GetState()
//     // {
//     //   return m_p
//     // }
// };

// void ConcreteStateA::Handle(Context *context)
// {
//     cout << "ConcreteStateA now" << endl;
//     context->m_pstat = new ConcreteStateB;
// }

// void ConcreteStateB::Handle(Context *context)
// {
//     cout << "ConcreteStateB now" << endl;
//     context->m_pstat = new ConcreteStateA;
// }

// class Apple;
// class Banana;
// class Fruit
// {
// public:
//     virtual ~Fruit() {}
//     virtual Fruit *show() = 0;
// };

// class Apple : public Fruit
// {
// public:
//     Fruit *show()
//     {
//         return new Banana();
//     }
// };

// class Banana : public Fruit
// {
// public:
//     Fruit *show()
//     {
//         return new Apple;
//     }
// };

// Fruit *Apple::show()
// {
//     return new Banana;
// }
// Fruit *Banana::show()
// {
//     return new Apple;
// }

// class Context;
// class IState
// {
// public:
//     virtual ~IState() {}
//     virtual void Handle(Context *context) = 0;
// };

// class Context
// {
// public:
//     IState *m_pState;
//     Context(IState *state) : m_pState(state) {}
//     IState *getstate()
//     {
//         return m_pState;
//     }
//     void setstate(IState *state)
//     {
//         m_pState = state;
//     }

//     void Request()
//     {
//         m_pState->Handle(this);
//     }
// };

// class ConcreteStateA : public IState
// {
// public:
//     void Handle(Context *context);
// };
// class ConcreteStateB : public IState
// {
// public:
//     void Handle(Context *context);
// };

// void ConcreteStateA::Handle(Context *context)
// {
//     cout << "ConcreteStateA now" << endl;
//     context->m_pState = new ConcreteStateB;
// }

// void ConcreteStateB::Handle(Context *context)
// {
//     cout << "ConcreteStateB now" << endl;
//     context->m_pState = new ConcreteStateA;
// }

// class ITarget
// {
// public:
//     virtual void process() = 0;
// };

// class Iadaptee
// {
// public:
//     virtual ~Iadaptee() {}
//     virtual int foo() = 0;
//     virtual void bar(int x) = 0;
// };

// class oldclass : public Iadaptee
// {
// public:
//     int foo()
//     {
//         cout << "foo in oldclass" << endl;
//         return 2025;
//     }
//     void bar(int x)
//     {
//         cout << "bar in oldclass " << x << endl;
//     }
// };

// class Adapter : public ITarget
// {
// public:
//     Adapter(Iadaptee *ada) : adaptee(ada) {}

//     void process()
//     {
//         int x = adaptee->foo();
//         adaptee->bar(x);
//     }

// private:
//     Iadaptee *adaptee;
// };

// class Business
// {
// public:
//     virtual ~Business() {}
//     virtual void charge(int x) = 0;
// };

// class CMCC : public Business
// {
// public:
//     void charge(int x)
//     {
//         cout << "Charge " << x << endl;
//     }
// };

// class CMCCProxy : public Business
// {
// public:
//     void charge(int x)
//     {
//         if (x < 100)
//         {
//             cout << "Charge need big than 100." << x << endl;
//         }
//         else
//         {
//             if (m_cmcc == nullptr)
//             {
//                 m_cmcc = new CMCC;
//                 m_cmcc->charge(x);
//                 delete m_cmcc;
//             }
//         }
//     }

// private:
//     CMCC *m_cmcc;
// }; // here need ;

// add line 1
// add line 2
// #include <future>
// #include <chrono>

// class CDocument
// {
// public:
//     void OnFileOpen()
//     {
//         open();
//         serialize();
//         close();
//     }

//     void open()
//     {
//         cout << "open CDoc" << endl;
//     }
//     virtual void serialize() = 0;
//     void close()
//     {
//         cout << "close CDoc" << endl;
//     }
// };

// class MyDoc : public CDocument
// {
// public:
//     void serialize()
//     {
//         cout << "serialize in MyDoc" << endl;
//     }
// };

// class Context;
// class IState
// {
// public:
//     virtual ~IState() {}
//     virtual void Handle(Context *context) = 0;
// };

// class Context
// {
// public:
//     Context(IState *mp) : m_pstate(mp) {}
//     void Request()
//     {
//         m_pstate->Handle(this);
//     }
//     IState *getState()
//     {
//         return m_pstate;
//     }

//     void setState(IState *mp)
//     {
//         m_pstate = mp;
//     }

//     IState *m_pstate;
// };

// class ConcreteStateA : public IState
// {
// public:
//     void Handle(Context *context);
// };

// class ConcreteStateB : public IState
// {
// public:
//     void Handle(Context *context);
// };

// void ConcreteStateA::Handle(Context *context)
// {
//     cout << "ConcreteStateA now" << endl;
//     context->m_pstate = new ConcreteStateB;
// }

// void ConcreteStateB::Handle(Context *context)
// {
//     cout << "ConcreteStateB now" << endl;
//     context->m_pstate = new ConcreteStateA;
// }

// #include <iostream>

// class Fruit
// {
// public:
//     virtual ~Fruit() {}
//     virtual Fruit *show() = 0;
// };

// class Banana : public Fruit
// {
// public:
//     Fruit *show() override
//     {
//         return new Apple;
//     }
// };

// class Apple : public Fruit
// {
// public:
//     Fruit *show() override
//     {
//         return new Banana;
//     }
// };

// class Business

// {
// public:
//     virtual void charge(int x) = 0;
// };

// class CMCC : public Business
// {
// public:
//     void charge(int x)
//     {
//         cout << "charge done:" << x << std::endl;
//     }
// };

// class CMCCProxy : public CMCC
// {
// public:
//     void charge(int x)
//     {
//         if (x < 100)
//         {
//         std:
//             cout << "need more than 100" << std::endl;
//         }

//         else
//         {
//             std::cout << "m_cmcc: " << m_cmcc << std::endl;
//             if (m_cmcc == nullptr)
//             {
//                 m_cmcc = new CMCC;
//                 m_cmcc->charge(x);
//                 delete m_cmcc;
//             }
//         }
//     }

// private:
//     CMCC *m_cmcc;
// };

// class ITarget
// {
// public:
//     virtual ~ITarget() {}
//     virtual void process() = 0;
// };

// class Iadaptee
// {
// public:
//     virtual int foo() = 0;
//     virtual void bar(int x) = 0;
// };

// class oldclass : public Iadaptee
// {
// public:
//     int foo()
//     {
//         cout << "foo in oldclass" << endl;
//         return 2025;
//     }
//     void bar(int x)
//     {
//         cout << "bar in oldclass" << endl;
//         cout << x << endl;
//     }
// };

// class Adapter : public ITarget
// {
// public:
//     Adapter(Iadaptee *ada) : adaptee(ada) {}
//     void process()
//     {
//         int x = adaptee->foo();
//         adaptee->bar(x);
//     }

// private:
//     Iadaptee *adaptee;
// };

// #include <string.h>
// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }
//     CATString(const CATString &obj)
//     {
//         m_data = new char[strlen(obj.m_data) + 1];
//         strcpy(m_data, obj.m_data);
//     }
//     CATString &operator=(const CATString &obj)
//     {
//         if (this != &obj)
//         {
//             delete[] m_data;
//             m_data = new char[strlen(obj.m_data) + 1];
//             strcpy(m_data, obj.m_data);
//         }
//         return *this;
//     }
//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &os, const CATString &obj);
// };

// ostream &operator<<(ostream &os, const CATString &obj)
// {
//     os << obj.m_data;
//     return os;
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         std::cout << y << std::endl;
//     }
// }

// typedef void (*pfunc)(int, string);
// class caller
// {
// public:
//     void setfunc(pfunc func)
//     {
//         m_func = func;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// #include <chrono>
// #include <future>
// #include <vector>
// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;

//     int m_result;
// };

// class Context;
// class IState
// {
// public:
//     virtual ~IState() {}
//     virtual void Handle(Context *context) = 0;
// };

// class Context
// {

// public:
//     IState *m_pstate;
//     Context(IState *pstate) : m_pstate(pstate) {}
//     void Request()
//     {
//         m_pstate->Handle(this);
//     }
//     IState *getState()
//     {
//         return m_pstate;
//     }
// };

// class ConcreteStateA : public IState
// {
// public:
//     void Handle(Context *context);
// };

// class ConcreteStateB : public IState
// {
// public:
//     void Handle(Context *context);
// };

// void ConcreteStateA::Handle(Context *context)
// {
//     std::cout << "ConcreteStateA now" << std::endl;
//     context->m_pstate = new ConcreteStateB;
//     std::cout << "changed to ConcreteStateB" << std::endl;
// }

// void ConcreteStateB::Handle(Context *context)
// {
//     std::cout << "ConcreteStatBe now" << std::endl;
//     context->m_pstate = new ConcreteStateA;
//     std::cout << "changed to ConcreteStateA" << std::endl;
// }

// class Context;
// class IState
// {
// public:
//     ~IState() {}
//     virtual void Handle(Context *context) = 0;
// };

// class Context
// {
// public:
//     IState *state;
//     Context(IState *pstate) : state(pstate) {}
//     IState *getstate()
//     {
//         return state;
//     }

//     void request()
//     {
//         state->Handle(this);
//     }
// };

// class ConcreteStateA : public IState
// {
// public:
//     void Handle(Context *context);
// };

// class ConcreteStateB : public IState
// {
// public:
//     void Handle(Context *context);
// };

// void ConcreteStateA::Handle(Context *context)
// {
//     std::cout << "ConcreteStateA now" << std::endl;
//     context->state = new ConcreteStateA;
//     std::cout << "ConcreteStateB next..." << std::endl;
// }

// void ConcreteStateB::Handle(Context *context)
// {
//     std::cout << "ConcreteStateB now" << std::endl;
//     context->state = new ConcreteStateA;
//     std::cout << "ConcreteStateA next..." << std::endl;
// }

// class ITarget
// {
// public:
//     virtual ~ITarget() {}
//     virtual void process() = 0;
// };

// class Adaptee
// {
// public:
//     virtual ~Adaptee() {}
//     virtual int foo() = 0;
//     virtual void bar(int x) = 0;
// };

// class oldclass : public Adaptee
// {
// public:
//     int foo()
//     {
//         std::cout << "foo oldclass" << std::endl;
//         return 2025;
//     }

//     void bar(int x)
//     {
//         std::cout << "bar oldclass" << std::endl;
//         std::cout << x << std::endl;
//     }
// };

// class Adapter : public ITarget
// {
// public:
//     Adapter(Adaptee *adaptee) : ada(adaptee) {}
//     void process()
//     {
//         int x = ada->foo();
//         ada->bar(x);
//     }

// private:
//     Adaptee *ada;
// };

// class Business
// {
// public:
//     virtual void charge(int x) = 0;
// };

// class CMCC : public Business
// {
// public:
//     void charge(int x)
//     {
//         x += 1;
//         cout << "charge test" << x << std::endl;
//     }
// };

// class CMCCProxy : public Business
// {
// public:
//     void charge(int x)
//     {
//         if (x < 100)
//         {
//             std::cout << "need more than 100" << std::endl;
//         }
//         else
//         {
//             if (m_CMCC == nullptr)
//             {
//                 m_CMCC = new CMCC;
//                 m_CMCC->charge(x);
//                 delete m_CMCC;
//             }
//         }
//     }

// private:
//     CMCC *m_CMCC;
// };

// class Context;
// class IState
// {
// public:
//     virtual ~IState() {}
//     virtual void Handle(Context *context) = 0;
// };

// class Context
// {
// public:
//     IState *m_state;
//     Context(IState *state) : m_state(state) {}
//     void Request()
//     {
//         m_state->Handle(this);
//     }
// };

// class ConcreteStateA : public IState
// {

// public:
//     void Handle(Context *context);
// };

// class ConcreteStateB : public IState
// {

// public:
//     void Handle(Context *context);
// };

// void ConcreteStateA::Handle(Context *context)
// {
//     cout << "ConcreteStateA now, next ConcreteStateB" << endl;
//     context->m_state = new ConcreteStateB;
// }

// void ConcreteStateB::Handle(Context *context)
// {
//     cout << "ConcreteStateB now, next ConcreteStateA" << endl;
//     context->m_state = new ConcreteStateA;
// }

// class CDocument
// {
// public:
//     void onFileOpen()
//     {
//         open();
//         serialize();
//         close();
//     }
//     void open()
//     {
//         cout << "CDocument open" << endl;
//     }
//     virtual void serialize() = 0;
//     void close()
//     {
//         cout << "CDocument close" << endl;
//     }
// };

// class myDocument : public CDocument
// {

// public:
//     void serialize()
//     {
//         cout << "myDocument serialize" << endl;
//     }
// };
// #include <list>
// class component
// {
// public:
//     virtual void addNode(component *c) {}
//     virtual void removeNode(component *c) {}
//     virtual void process() = 0;

// protected:
//     list<component *> m_list;
// };

// class composite : public component
// {
// public:
//     composite(string abc) : name(abc) {}
//     void addNode(component *c)
//     {
//         m_list.push_back(c);
//     }
//     void removeNode(component *c)
//     {
//         m_list.remove(c);
//     }
//     void process()
//     {
//         cout << "process " << name << endl;
//         for (auto &x : m_list)

//         {
//             x->process();
//         }
//     }

// private:
//     string name;
// };

// class leaf : public component
// {
// public:
//     leaf(string abc) : name(abc) {}
//     void process()
//     {
//         cout << "process " << name << endl;
//     }

// private:
//     string name;
// };

// class weapon
// {
// public:
//     virtual ~weapon() {}
//     virtual void process() = 0;
// };

// class ak47 : public weapon
// {

// public:
//     void process()
//     {
//         cout << "ak47 " << endl;
//     }
// };

// class knife : public weapon
// {
// public:
//     void process()
//     {
//         cout << "knife " << endl;
//     }
// };

// class character
// {

// public:
//     character(weapon *ws = nullptr) : m_ws(ws) {}
//     void setWeapon(weapon *ws)
//     {
//         m_ws = ws;
//     }
//     void onFire()
//     {
//         m_ws->process();
//     }

// private:
//     weapon *m_ws;
// };

// class Fruit
// {
// public:
//     virtual void show() = 0;
// };

// class Apple : public Fruit
// {
// public:
//     void show()
//     {
//         cout << "Apple show" << endl;
//     }
// };

// class Banana : public Fruit
// {
// public:
//     void show()
//     {
//         cout << "Banana show" << endl;
//     }
// };

// class FruitFactory
// {
// public:
//     virtual Fruit *CreateFruit() = 0;
// };

// class AppleFactory : public FruitFactory
// {
// public:
//     Fruit *CreateFruit()
//     {
//         return new Apple;
//     }
// };

// class BananaFactory : public FruitFactory
// {
// public:
//     Fruit *CreateFruit()
//     {
//         return new Banana;
//     }
// };

// class SimpleFactory
// {

// public:
//     static Fruit *CreateFruit(string name)
//     {
//         static Fruit *pf = nullptr;
//         if (name == "Apple")
//         {
//             pf = new Apple;
//         }
//         else if (name == "Banana")
//         {
//             pf = new Banana;
//         }
//         return pf;
//     }
// };

// class singleton
// {

// public:
//     static singleton *getInstance()
//     {
//         return m_instance;
//     }
//     void show()
//     {
//         cout << "show" << endl;
//     }

// private:
//     static singleton *m_instance;
//     singleton() {}
//     singleton(const singleton &obj) {}
// };

// singleton *singleton::m_instance = new singleton;

// class lazysingleton
// {

// public:
//     static lazysingleton *getInstance()
//     {
//         if (m_instance == nullptr)
//         {
//             return m_instance = new lazysingleton;
//         }
//     }

// private:
//     lazysingleton() {}
//     lazysingleton(const lazysingleton &obj) {}
//     static lazysingleton *m_instance;
// };

// class Text
// {

// public:
//     virtual ~Text() {}
//     virtual string render() = 0;
// };

// class PlainText : public Text
// {
// private:
//     string content;

// public:
//     PlainText(string abc) : content(abc) {}
//     string render()
//     {
//         return content;
//     }
// };

// class DecoratorText : public Text
// {
// public:
//     Text *text;
//     DecoratorText(Text *text) : text(text) {}
//     // string render()
//     // {
//     //     text->render();
//     // }
//     virtual ~DecoratorText()
//     {
//         delete text;
//     }
// };

// class DecoratorTextBold : public DecoratorText
// {

// public:
//     DecoratorTextBold(Text *abc) : DecoratorText(abc) {}
//     string render()
//     {
//         return "Bold" + text->render() + "Bold";
//     }
// };

// class DecoratorTextUnderline : public DecoratorText
// {

// public:
//     DecoratorTextUnderline(Text *abc) : DecoratorText(abc) {}
//     string render()
//     {
//         return "abc" + text->render() + "abc";
//     }
// };

// class Text
// {
// public:
//     virtual ~Text() {}
//     virtual string render() = 0;
// };

// class PlaneText : public Text
// {
// public:
//     PlaneText(string str) : content(str) {}
//     string render()
//     {
//         return content;
//     }

// private:
//     string content;
// };

// class Decoratortext : public Text
// {
// public:
//     Decoratortext(Text *t) : text(t) {}

// protected:
//     Text *text;
// };

// class DecoratortextOnBold : public Decoratortext
// {
// public:
//     DecoratortextOnBold(Text *t) : Decoratortext(t) {}
//     string render()
//     {
//         return text->render() + "Bold";
//     }
// };

// class Text
// {
// public:
//     virtual ~Text() {}
//     virtual string render() = 0;
// };

// class planeText : public Text
// {
// public:
//     planeText(string abc) : content(abc) {}
//     string render()
//     {
//         return content;
//     }

// private:
//     string content;
// };

// class DecoratorText : public Text
// {

// public:
//     DecoratorText(Text *t) : text(t) {}

// protected:
//     Text *text;
// };

// class DecoratorTextBold : public DecoratorText
// {
// public:
//     DecoratorTextBold(Text *t) : DecoratorText(t) {}
//     string render()
//     {
//         return "bold" + text->render();
//     }
// };

// class Context;
// class IState
// {
// public:
//     virtual ~IState() {}
//     virtual void Handle(Context *context) = 0;
// };

// class Context
// {
// public:
//     IState *m_pstate;
//     Context(IState *st) : m_pstate(st) {}
//     void Request()
//     {
//         m_pstate->Handle(this);
//     }
// };

// class ConcreteStateA : public IState
// {
// public:
//     void Handle(Context *context);
// };

// class ConcreteStateB : public IState
// {
// public:
//     void Handle(Context *context);
// };

// void ConcreteStateA::Handle(Context *context)
// {
//     cout << "ConcreteStateA now, next ConcreteStateB" << endl;
//     context->m_pstate = new ConcreteStateB;
// }

// void ConcreteStateB::Handle(Context *context)
// {
//     cout << "ConcreteStateB now, next ConcreteStateA" << endl;
//     context->m_pstate = new ConcreteStateA;
// }

// class ITarget
// {

// public:
//     virtual void process() = 0;
// };

// class IAdaptee
// {
// public:
//     virtual int foo() = 0;
//     virtual void bar(int x) = 0;
// };

// class oldclass : public IAdaptee
// {
// public:
//     int foo()
//     {
//         return 2025;
//     }
//     void bar(int x)
//     {
//         cout << x << endl;
//     }
// };

// class Adapter : public ITarget
// {
// public:
//     Adapter(IAdaptee *tee) : ia(tee) {}
//     void process()
//     {
//         int x = ia->foo();
//         ia->bar(x);
//     }

// private:
//     IAdaptee *ia;
// };

// class Text
// {
// public:
//     virtual string render() = 0;
// };

// class PlaneText : public Text
// {
// public:
//     PlaneText(string c) : content(c) {}
//     string render()
//     {
//         return content;
//     }

// private:
//     string content;
// };

// class DecorateText : public Text
// {
// public:
//     DecorateText(Text *t) : text(t) {}
//     ~DecorateText()
//     {

//         delete text;
//     }

// protected:
//     Text *text;
// };

// class DecorateTextBold : public DecorateText
// {
// public:
//     DecorateTextBold(Text *t) : DecorateText(t) {}
//     string render()
//     {
//         return text->render() + "Bold";
//     }
// };

// class DecorateTextUnderline : public DecorateText
// {
// public:
//     DecorateTextUnderline(Text *t) : DecorateText(t) {}
//     string render()
//     {
//         return text->render() + "__";
//     }
// // };
// class Context;

// class IState
// {
// public:
//     virtual ~IState() {}
//     virtual void Handle(Context *context) = 0;
// };

// class Context
// {
// public:
//     IState *st;

//     Context(IState *state) : st(state) {}
//     void Request()
//     {

//         st->Handle(this);
//     }
// };

// class ConcreteStateA : public IState
// {

// public:
//     void Handle(Context *context);
// };

// class ConcreteStateB : public IState
// {

// public:
//     void Handle(Context *context);
// };

// void ConcreteStateA::Handle(Context *context)
// {
//     context->st = new ConcreteStateB;
// }

// void ConcreteStateB::Handle(Context *context)
// {
//     context->st = new ConcreteStateA;
// }

// class Text
// {
// public:
//     virtual ~Text() {}
//     virtual string render() = 0;
// };

// class PlaneText : public Text
// {
// public:
//     PlaneText(string abc) : content(abc) {}
//     string render()
//     {
//         return content;
//     }

// private:
//     string content;
// };

// class DecoratorText : public Text
// {
// public:
//     Text *text;
//     DecoratorText(Text *text) : text(text) {}
// };

// class DecoratorTextBold : public DecoratorText
// {
// public:
//     DecoratorTextBold(Text *text) : DecoratorText(text) {}
//     string render()
//     {
//         return text->render() + "Bold";
//     }
// };

// class DecoratorTextUnderline : public DecoratorText
// {
// public:
//     DecoratorTextUnderline(Text *text) : DecoratorText(text) {}
//     string render()
//     {
//         return text->render() + "Underline";
//     }
// };

// class Text
// {
// public:
//     virtual ~Text() {}
//     virtual string render() = 0;
// };

// class PlaneText : public Text
// {
// public:
//     PlaneText(string abc) : content(abc) {}
//     string render()
//     {
//         return content;
//     }

// private:
//     string content;
// };

// class DecoratorText : public Text
// {
// public:
//     DecoratorText(Text *t) : text(t) {}

// protected:
//     Text *text;
// };

// class DecoratorTextBold : public DecoratorText
// {
// public:
//     DecoratorTextBold(Text *t) : DecoratorText(t) {}
//     string render()
//     {
//         return text->render() + "Bold";
//     }
// };

// class Context;
// class IState
// {
// public:
//     virtual ~IState() {}
//     virtual void Handle(Context *context) = 0;
// };

// class Context
// {
// public:
//     Context(IState *is) : state(is) {}
//     void Request()
//     {
//         state->Handle(this);
//     }

//     // protected:
// public:
//     IState *state;
// };

// class ConreteStateA : public IState
// {
// public:
//     void Handle(Context *context);
// };

// class ConreteStateB : public IState
// {
// public:
//     void Handle(Context *context);
// };

// void ConreteStateA::Handle(Context *context)
// {

//     context->state = new ConreteStateB;
// }

// void ConreteStateB::Handle(Context *context)
// {

//     context->state = new ConreteStateA;
// }

// class Text
// {
// public:
//     virtual ~Text() {}
//     virtual string render() = 0;
// };

// class PlaneText : public Text
// {
// private:
//     string content;

// public:
//     PlaneText(string abc) : content(abc) {}
//     string render()
//     {
//         return content;
//     }
// };

// class DecoratorText : public Text
// {
// public:
//     Text *text;
//     DecoratorText(Text *abc) : text(abc) {}
//     // string render()
//     // {
//     // }
// };

// class DecoratorTextBold : public DecoratorText

// {
// public:
//     DecoratorTextBold(Text *text) : DecoratorText(text) {}
//     string render()
//     {

//         return text->render() + "Bold";
//     }
// };

// class Context;

// class IState
// {
// public:
//     virtual ~IState() {}
//     virtual void Handle(Context *context) = 0;
// };

// class Context
// {
// public:
//     IState *m_pstate;
//     Context(IState *pstate) : m_pstate(pstate) {}
//     void Request()
//     {
//         m_pstate->Handle(this);
//     }
// };

// class ConcreteStateA : public IState
// {
// public:
//     void Handle(Context *context);
// };

// class ConcreteStateB : public IState
// {
// public:
//     void Handle(Context *context);
// };

// void ConcreteStateA::Handle(Context *context)
// {
//     context->m_pstate = new ConcreteStateB;
//     cout << "ConcreteStateA now, changed to B" << endl;
// }
// void ConcreteStateB::Handle(Context *context)
// {
//     context->m_pstate = new ConcreteStateA;
//     cout << "ConcreteStateB now, changed to A" << endl;
// }

// class Text
// {
// public:
//     virtual ~Text() {}
//     virtual string render() = 0;
// };

// class PlaneText : public Text
// {
// public:
//     PlaneText(string abc) : content(abc) {}
//     string render()
//     {
//         return content;
//     }

// private:
//     string content;
// };

// class DecoratorText : public Text
// {
// public:
//     Text *text;
//     DecoratorText(Text *t) : text(t) {}
// };

// class DecoratorTextBold : public DecoratorText
// {
// public:
//     DecoratorTextBold(Text *t) : DecoratorText(t) {}
//     string render()
//     {
//         return text->render() + "Bold";
//     }
// };

// class Context;
// class IState
// {
// public:
//     virtual void Handle(Context *context) = 0;
// };

// class Context
// {
// public:
//     IState *m_pstate;
//     Context(IState *st) : m_pstate(st) {}
//     virtual void Request()
//     {
//         m_pstate->Handle(this);
//     }
//     virtual IState *getState()
//     {
//         return m_pstate;
//     }
// };

// class ConcreteStateA : public IState
// {
// public:
//     void Handle(Context *context);
// };

// class ConcreteStateB : public IState
// {
// public:
//     void Handle(Context *context);
// };

// void ConcreteStateA::Handle(Context *context)
// {
//     std::cout << "do job in StateA. ";
//     context->m_pstate = new ConcreteStateB;
//     std::cout << "changed to StateB." << std::endl;
// }

// void ConcreteStateB::Handle(Context *context)
// {
//     std::cout << "do job in StateB. ";
//     context->m_pstate = new ConcreteStateA;
//     std::cout << "changed to StateA." << std::endl;
// }

// class Text
// {
// public:
//     virtual string render() = 0;
// };

// class PlaneText : public Text
// {
// public:
//     string render()
//     {
//         return content;
//     }
//     PlaneText(string abc) : content(abc) {}

// private:
//     string content;
// };

// class DecoratorText : public Text
// {
// public:
//     DecoratorText(Text *t) : text(t) {}

// protected:
//     Text *text;
// };

// class DecoratortextBold : public DecoratorText
// {
// public:
//     DecoratortextBold(Text *test) : DecoratorText(test) {}
//     string render()
//     {
//         return text->render() + "Bold";
//     }
// };

// class Text
// {
// public:
//     virtual string render() = 0;
// };

// class PlaneText : public Text
// {
// public:
//     PlaneText(string abc) : content(abc) {}
//     string render()
//     {
//         return content;
//     }

// private:
//     string content;
// };

// class DecoratorText : public Text
// {
// protected:
//     Text *t;

// public:
//     DecoratorText(Text *abc) : t(abc) {}
// };

// class DecoratorTextBold : public DecoratorText
// {
// public:
//     DecoratorTextBold(Text *abc) : DecoratorText(abc) {}
//     string render()
//     {
//         return t->render() + "Bold";
//     }
// };

// class component
// {
// public:
//     virtual ~component() {}
//     virtual void operation() {};
// };

// class concretecomponentA : public component
// {
// public:
//     concretecomponentA() {}
//     ~concretecomponentA() {}
//     void operation()
//     {
//         cout << "op in A" << endl;
//     }
// };

// class concretecomponentB : public component
// {
// public:
//     concretecomponentB() {}
//     ~concretecomponentB() {}
//     void operation()
//     {
//         cout << "op in B" << endl;
//     }
// };

// class Decorator : public component
// {
// public:
//     Decorator() : m_component(nullptr) {}
//     ~Decorator() {}

//     void setcomponent(component *pcomponnet)
//     {
//         m_component = pcomponnet;
//     }

//     void operaton()
//     {
//         if (m_component)
//         {
//             m_component->operation();
//         }
//     }

// protected:
//     component *m_component;
// };

// class concreteDecoratorE : public Decorator
// {
// public:
//     concreteDecoratorE() {}
//     ~concreteDecoratorE() {}
//     void addBehavior()
//     {
//         cout << "Behavior in E" << endl;
//         m_component->operation();
//     }
// };

// class Context;

// class IState
// {
// public:
//     virtual void Handle(Context *context) = 0;
// };

// class Context
// {
// public:
//     Context(IState *x) : m_pstate(x) {}
//     IState *m_pstate;
//     virtual void Request()
//     {
//         m_pstate->Handle(this);
//     }
// };

// class ConcreStateA : public IState
// {

// public:
//     void Handle(Context *context);
// };

// class ConcreStateB : public IState
// {

// public:
//     void Handle(Context *context);
// };

// void ConcreStateA::Handle(Context *context)
// {
//     context->m_pstate = new ConcreStateB;
//     std::cout << "changed to B" << std::endl;
// }

// void ConcreStateB::Handle(Context *context)
// {
//     context->m_pstate = new ConcreStateA;
//     std::cout << "changed to A" << std::endl;
// }

// class Text
// {
// public:
//     virtual string Render() = 0;
//     // Text(string abc) : content(abc) {}

//     // protected:
//     //     string content;
// };

// class PlaneText : public Text
// {

// public:
//     PlaneText(string abc) : content(abc) {}
//     string Render()
//     {
//         return content;
//     }

// protected:
//     string content;
// };

// class DecoratorText : public Text
// {
// public:
//     Text *text;
//     DecoratorText(Text *x) : text(x) {}
// };

// class DecoratorTextBold : public DecoratorText
// {
// public:
//     string Render()
//     {
//         return text->Render() + "Bold";
//     }
//     DecoratorTextBold(Text *t) : DecoratorText(t) {}
// };

// class Text
// {
// public:
//     virtual string Render() = 0;
// };

// class PlaneText : public Text
// {
// public:
//     PlaneText(string abc) : content(abc) {}
//     string Render()
//     {
//         return content;
//     }

// private:
//     string content;
// };

// class DecoratorText : public Text
// {
// public:
//     DecoratorText(Text *t) : text(t) {}

// protected:
//     Text *text;
// };

// class DecoratorTextBold : public DecoratorText
// {
// public:
//     string Render()
//     {
//         return text->Render() + "Bold";
//     }
//     DecoratorTextBold(Text *t) : DecoratorText(t) {}
// };

// class DecoratorTextUnderline : public DecoratorText
// {
// public:
//     string Render()
//     {
//         return text->Render() + "Underline";
//     }
//     DecoratorTextUnderline(Text *t) : DecoratorText(t) {}
// };

// class Context;
// class IState
// {
// public:
//     virtual void Handle(Context *context) = 0;
// };

// class Context
// {
// public:
//     Context(IState *x) : m_pstate(x) {}
//     virtual void Request()
//     {
//         m_pstate->Handle(this);
//     }
//     IState *m_pstate;
// };

// class ConcreteStateA : public IState
// {

// public:
//     void Handle(Context *context);
// };

// class ConcreteStateB : public IState
// {
// public:
//     void Handle(Context *context);
// };

// void ConcreteStateA::Handle(Context *context)
// {
//     std::cout << "stateA now ";
//     context->m_pstate = new ConcreteStateB;
//     std::cout << "changed to stateB " << std::endl;
// }

// void ConcreteStateB::Handle(Context *context)
// {
//     std::cout << "stateB now ";
//     context->m_pstate = new ConcreteStateA;
//     std::cout << "changed to stateA " << std::endl;
// }

// class Text
// {
// public:
//     virtual string Render() = 0;
// };

// class PlaneText : public Text
// {
// public:
//     PlaneText(string abc) : content(abc) {}
//     string Render()
//     {
//         return content;
//     }

// private:
//     string content;
// };

// class DecoratorText : public Text
// {
// public:
//     Text *text;
//     DecoratorText(Text *t) : text(t) {}
// };

// class DecoratorTextBold : public DecoratorText
// {
// public:
//     DecoratorTextBold(Text *t) : DecoratorText(t) {}
//     string Render()
//     {
//         return text->Render() + "Bold";
//     }
// };

// class DecoratorTextUnderline : public DecoratorText
// {
// public:
//     DecoratorTextUnderline(Text *t) : DecoratorText(t) {}
//     string Render()
//     {
//         return text->Render() + "_";
//     }
// };

// class Context;
// class IState
// {
// public:
//     virtual void Handle(Context *context) = 0;
// };

// class Context
// {
// public:
//     IState *m_pstate;
//     void Request()
//     {
//         m_pstate->Handle(this);
//     }
// };

// class ConcreteStateA : public IState
// {
// public:
//     void Handle(Context *context);
// };

// class ConcreteStateB : public IState
// {
// public:
//     void Handle(Context *context);
// };

// void ConcreteStateA::Handle(Context *text)
// {
// }

// #include <iostream>
// void foo(); // Declaration

// class Text
// {
// public:
//     virtual string Render() = 0;
// };

// class PlaneText : public Text
// {

// public:
//     string Render()
//     {
//         return content;
//     }
//     PlaneText(string abc) : content(abc) {}

// private:
//     string content;
// };

// class DecoratorText : public Text
// {
// public:
//     DecoratorText(Text *t) : text(t) {}

// protected:
//     Text *text;
// };

// class DecoratorTextBold : public DecoratorText
// {
// public:
//     DecoratorTextBold(Text *t) : DecoratorText(t) {}
//     string Render()
//     {
//         return text->Render() + "Bold";
//     }
// };

// class DecoratorTextUnderline : public DecoratorText
// {
// public:
//     DecoratorTextUnderline(Text *t) : DecoratorText(t) {}
//     string Render()
//     {
//         return text->Render() + "Underline";
//     }
// };

// class Context;

// class IState
// {
// public:
//     virtual void Handle(Context *context) = 0;
// };

// class Context
// {
// public:
//     IState *m_pstate;
//     Context(IState *is) : m_pstate(is) {}
//     void Request()
//     {
//         m_pstate->Handle(this);
//     }
// };

// class ConcreteStateA : public IState
// {
// public:
//     void Handle(Context *context);
// };

// class ConcreteStateB : public IState
// {
// public:
//     void Handle(Context *context);
// };

// void ConcreteStateA::Handle(Context *context)
// {
//     cout << "state A now ";
//     context->m_pstate = new ConcreteStateB;
//     cout << "changed to state B" << std::endl;
// }

// void ConcreteStateB::Handle(Context *context)
// {
//     cout << "state b now ";
//     context->m_pstate = new ConcreteStateA;
//     cout << "changed to state A" << std::endl;
// }

// void Test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         cout << y << endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class Caller
// {

// public:
//     void setfunc(pfunc xx)
//     {
//         m_func = xx;
//     }
//     void letrun(int a, string b)
//     {
//         m_func(a, b);
//     }

// private:
//     pfunc m_func;
// };

// #include <chrono>
// #include <vector>
// #include <future>
// using namespace std;
// class Task
// {

// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// class Text
// {
// public:
//     virtual string Render() = 0;
// };

// class PlaneText : public Text
// {
// public:
//     string Render()
//     {
//         return content;
//     }
//     PlaneText(string abc) : content(abc) {}

// private:
//     string content;
// };

// class DecoratorText : public Text
// {
// public:
//     Text *text;
//     DecoratorText(Text *t) : text(t) {}
// };

// class DecoratorTextBold : public DecoratorText
// {
// public:
//     DecoratorTextBold(Text *t) : DecoratorText(t) {}
//     string Render()
//     {
//         return text->Render() + "Bold";
//     }
// };

// class DecoratorTextUnderline : public DecoratorText
// {
// public:
//     DecoratorTextUnderline(Text *t) : DecoratorText(t) {}
//     string Render()
//     {
//         return text->Render() + "_";
//     }
// };

// class Context;
// class IState
// {
// public:
//     virtual void Handle(Context *context) = 0;
// };

// class Context
// {
// public:
//     IState *m_pstate;
//     Context(IState *state) : m_pstate(state) {}

//     void Request()
//     {
//         m_pstate->Handle(this);
//     }
// };

// class ConcreteStateA : public IState
// {
// public:
//     void Handle(Context *context);
// };

// class ConcreteStateB : public IState
// {
// public:
//     void Handle(Context *context);
// };

// void ConcreteStateA ::Handle(Context *context)
// {
//     context->m_pstate = new ConcreteStateB;
//     cout << "change to StateB" << endl;
// }

// void ConcreteStateB ::Handle(Context *context)
// {
//     context->m_pstate = new ConcreteStateA;
//     cout << "change to StateA" << endl;
// }

// #include <vector>

// class Text
// {
// public:
//     virtual string Render() = 0;
// };

// class PlaneText : public Text
// {
// public:
//     string Render()
//     {
//         return content;
//     }
//     PlaneText(string abc) : content(abc) {}

// private:
//     string content;
// };

// class DecoratorText : public Text
// {

// public:
//     Text *text;
//     DecoratorText(Text *t) : text(t) {}
// };

// class DecoratorTextBold : public DecoratorText
// {
// public:
//     DecoratorTextBold(Text *t) : DecoratorText(t) {}
//     string Render()
//     {
//         return text->Render() + "Bold";
//     }
// };

// class DecoratorTextUnderline : public DecoratorText
// {
// public:
//     DecoratorTextUnderline(Text *t) : DecoratorText(t) {}
//     string Render()
//     {
//         return text->Render() + "Underline_";
//     }
// };

// class Context;

// class IState
// {
// public:
//     virtual void Handle(Context *context) = 0;
// };

// class Context
// {
// public:
//     IState *m_pstate;
//     Context(IState *state) : m_pstate(state) {}
//     void Request()
//     {
//         m_pstate->Handle(this);
//     }
// };

// class ConcreteStateA : public IState
// {

// public:
//     void Handle(Context *context);
// };

// class ConcreteStateB : public IState
// {

// public:
//     void Handle(Context *context);
// };

// void ConcreteStateA::Handle(Context *context)
// {
//     context->m_pstate = new ConcreteStateB;
//     cout << "change to state B" << endl;
// }

// void ConcreteStateB::Handle(Context *context)
// {
//     context->m_pstate = new ConcreteStateA;
//     cout << "change to state A" << endl;
// }

// class Text
// {
// public:
//     virtual string Render() = 0;
// };

// class PlaneText : public Text
// {
// public:
//     PlaneText(string abc) : content(abc) {}
//     string Render()
//     {
//         return content;
//     }

// private:
//     string content;
// };

// class DecoratorText : public Text
// {
// public:
//     Text *text;
//     DecoratorText(Text *t) : text(t) {}
// };

// class DecortatorTextBold : public DecoratorText
// {
// public:
//     DecortatorTextBold(Text *t) : DecoratorText(t) {}
//     string Render()
//     {
//         return text->Render() + "Bold";
//     }
// };

// class Context;
// class IState
// {
// public:
//     virtual void Handle(Context *context) = 0;
// };

// class Context
// {
// public:
//     IState *m_pstate;
//     Context(IState *state) : m_pstate(state) {}
//     void Request()
//     {
//         m_pstate->Handle(this);
//     }
// };

// class ConcreteStateA : public IState
// {
// public:
//     void Handle(Context *context);
// };

// class ConcreteStateB : public IState
// {
// public:
//     void Handle(Context *context);
// };

// void ConcreteStateA::Handle(Context *context)
// {
//     context->m_pstate = new ConcreteStateB;
//     cout << "change to B" << endl;
// }

// void ConcreteStateB::Handle(Context *context)
// {
//     context->m_pstate = new ConcreteStateB;
//     cout << "change to A" << endl;
// }

// typedef int (*func)(int x, int y);
// int callback(func f)
// {
//     return f(1, 1);
// }

// void Test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         cout << y << endl;
//     }
// }

// typedef void (*pfunc)(int, string);
// class caller
// {
// public:
//     void setfunc(pfunc f)
//     {
//         m_func = f;
//     }

//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// using namespace std;
// #include <iostream>
// #include <vector>
// #include <future>

// #include <chrono>
// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::milliseconds(2000));
//         return m_result = m_id * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// template <typename Func>

// int a = 1;
// int b = 1;
// auto f = [](int x, int y)
// { return x + y; };
// void func(auto f)
// {
//     cout << f(a, b) << endl;
// }

// template <typename Func>
// void processFunc(Func &&f)
// {
//     f();
// }

// template <typename Func>
// void preocesFunc(Func f)
// {
//     f();
// }

// template<typename Func> ?
// void processFunc(Func f)
// {
//     f();
// }
// int a = 2000;
// int b = 1;

// template <typename Func>
// int callback(Func f)
// {
//     return f(int x, int y);
// }

// template <typename Func>
// int processFunc(Func f)
// {
//     f(int x, int y);
// }

// template <typename Func>
// int processFunc(Func f)
// {
//     return f();
// }
// template <typename Func>
// int processFuncwithparams(Func f)
// {
//     int x = 1, y = 2;
//     return f(x, y);
// }

// #include <vector>
// #include <algorithm>
// void printvector(vector<int> &v)
// {
//     for (int i = 0; i < v.size(); i++)
//     {
//         cout << v[i];
//     }
// }
#include <functional>
#include <vector>
// int addint(int a, int b)
// {

//     return a + b;
// }

// void processFunc(vector<int> &v, std::function<void(int)> f)
// {
//     for (auto &x : v)
//     {
//         f(x);
//     }
// }

// class Adder
// {
// public:
//     int operator()(int a, int b)
//     {
//         return a + b;
//     }
// };

// class Counter
// {
//     int count = 0;

// public:
//     int operator()()
//     {
//         return ++count;
//     }
// };

// class Multiple
// {
//     int factor;

// public:
//     Multiple(int x) : factor(x) {}
//     int operator()(int y)
//     {
//         return factor * y;
//     }
// };

// class Greater
// {

// };

// class Text
// {
// public:
//     virtual string Render() = 0;
// };

// class PlaneText : public Text
// {
// public:
//     PlaneText(string abc) : content(abc) {}
//     string Render()
//     {
//         return content;
//     }

// private:
//     string content;
// };

// class DecoratorText : public Text
// {
// public:
//     Text *text;
//     DecoratorText(Text *t) : text(t) {}
// };

// class DecoratorTextBold : public DecoratorText
// {
// public:
//     DecoratorTextBold(Text *t) : DecoratorText(t) {}
//     string Render()
//     {
//         return text->Render() + "Bold";
//     }
// };

// class Context;
// class IState
// {
// public:
//     virtual void Handle(Context *context) = 0;
// };

// class Context
// {
// public:
//     IState *m_pstate;
//     Context(IState *s) : m_pstate(s) {}
//     void Request()
//     {

//         m_pstate->Handle(this);
//     }
// };

// class ConcreteStateA : public IState
// {
// public:
//     void Handle(Context *context);
// };

// class ConcreteStateB : public IState
// {
// public:
//     void Handle(Context *context);
// };

// void ConcreteStateA::Handle(Context *context)
// {
//     context->m_pstate = new ConcreteStateB;
//     cout << "changed to stateB" << endl;
// }

// void ConcreteStateB::Handle(Context *context)
// {
//     context->m_pstate = new ConcreteStateB;
//     cout << "changed to stateA" << endl;
// }

// class adder
// {
//     public:
//     int operator()(int x, int y)
//     {
//         return x + y;
//     }
// };

// template <typename Func>
// void processFunc(Func f)
// {
//     f();
// }

// template <typename Func>
// int processFunc1(Func c)
// {
//     int a = 1;
//     int b = 2;
//     c(a, b);
// }

// #include <vector>
// #include <functional>

// void processit(vector<int> &v, std::function<void(int)> f)
// {
//     for (auto &x : v)
//     {

//         f(x);
//     }
// }

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         cout << y << endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfunc(pfunc f)
//     {
//         m_fun = f;
//     }
//     void letrun(int x, string y)

//     {
//         m_fun(x, y);
//     }

// private:
//     pfunc m_fun;
// };

// class adder
// {

// public:
//     int operator()(int x, int y)
//     {
//         return x + y;
//     }
// };

#include <chrono>
using namespace std;
#include <future>

// class Task
// {

// public:
//     Task(int x) : m_id(x) {}
//     int operator()(int x)
//     {
//         std::this_thread::sleep_for(std::chrono::milliseconds(2000));
//         return m_result = (m_id + x) * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// void processFunc(vector<int> &v, std::function<void(int)> processor)
// {
//     for (auto &x : v)
//     {
//         processor(x);
//     }
// }

// class adder
// {

//     public:
//     int operator()(int a, int b)
//     {
//         return a + b;
//     }
// };

// #include <future>
// #include <chrono>
// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()(int x)
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));

//         return m_result = (m_id + x) * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()(int x)
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = (m_id + x) * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// int task(int x)
// {
//     return x * x;
// }

// template <typename Func>
// void processFunc(Func f)
// {
//     f();
// }

// template <typename Func>
// int processFunc1(Func f)
// {
//     return f();
// }

// template <typename Func>
// int processFunc2(Func f)
// {
//     int x = 1;
//     int y = 1;
//     return f(x, y);
// }

// template <typename Func>
// auto processFunc(Func f)
// {
//     int a = 1;
//     int b = 1;
//     // return f(a, b);
//     return [a, b, f]()
//     {
//         return f(a, b);
//     };
// }

#include <functional>
#include <vector>
// void processFunc(vector<int> &v, std::function<void(int)> processNum)
// {
//     for (auto &x : v)
//     {
//         processNum(x);
//     }
// }

// void Test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         cout << y << endl;
//     }
// }

// typedef void (*pFunc)(int, string);

// class Caller
// {
// public:
//     void setFunc(pFunc c)
//     {
//         m_func = c;
//     }

//     void letRun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pFunc m_func;
// };

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()(int x)
//     {
//         std::this_thread::sleep_for(std::chrono::milliseconds(2000));
//         return m_result = (m_id + x) * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// void processFunc(vector<int> &v, std::function<void(int)> func)
// {

//     for (auto &x : v)
//     {
//         func(x);
//     }
// }

// void processFunc(vector<double> &v, std::function<void(double)> func)
// {
//     for (auto &x : v)
//     {
//         func(x);
//     }
// }

// template <typename Func>
// int processFunc(Func f)
// {
//     return f();
// }

// template <typename Func>
// void processFuncNew(Func f)
// {
//     int a = 1;
//     int b = 2;
//     return f(a, b);
// }

// template <typename func>
// void process(vector<int> &v, std::function<void(int)> f)
// {
//     for (auto &x : v)
//     {
//         f(x);
//     }
// }

// template <typename T>
// T addT(T a, T b)
// {
//     return a + b;
// }

// #include <string.h>
// class CATString
// {

// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }
//     CATString(const CATString &obj)
//     {
//         m_data = new char[strlen(obj.m_data) + 1];
//         strcpy(m_data, obj.m_data);
//     }

//     CATString &operator=(const CATString &obj)
//     {
//         if (this != &obj)
//         {
//             delete[] this->m_data;
//             m_data = new char[strlen(obj.m_data) + 1];
//             strcpy(m_data, obj.m_data);
//         }
//         return *this;
//     }

//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &os, const CATString &obj);
// };

// ostream &operator<<(ostream &os, const CATString &obj)
// {
//     os << obj.m_data;
//     return os;
// }

// void processFunc(vector<int> &v, std::function<void(int)> func)
// {

//     for (auto x : v)
//     {
//         func(x);
//     }
// }

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()(int x)
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = (m_id + x) * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// class Text
// {
// public:
//     virtual string Render() = 0;
// };

// class PlaneText : public Text
// {
// public:
//     PlaneText(string abc) : content(abc) {}
//     string Render()
//     {
//         return content;
//     }

// private:
//     string content;
// };

// class DecoratorText : public Text
// {
// public:
//     Text *text;
//     DecoratorText(Text *t) : text(t) {}
// };

// class DecoratorTextBold : public DecoratorText
// {

// public:
//     DecoratorTextBold(Text *t) : DecoratorText(t) {}
//     string Render()
//     {
//         return text->Render() + "Bold";
//     }
// };

// class Context;
// class IState
// {
// public:
//     virtual void Handle(Context *context) = 0;
// };

// class Context
// {
// public:
//     Context(IState *state) : m_pstate(state) {}
//     void Request()
//     {
//         m_pstate->Handle(this);
//     }

//     // protected:
//     IState *m_pstate;
// };

// class ConcreteStateA : public IState
// {
// public:
//     void Handle(Context *context);
// };

// class ConcreteStateB : public IState
// {
// public:
//     void Handle(Context *context);
// };

// void ConcreteStateA::Handle(Context *context)
// {
//     context->m_pstate = new ConcreteStateB;
// }

// void ConcreteStateB::Handle(Context *context)
// {
//     context->m_pstate = new ConcreteStateA;
// }

// template <typename Func>
// auto processFunc(Func f)
// {

//     return f();
// }

// void print_num(int x)
// {
//     cout << x << endl;
// }

// class Foo
// {
// public:
//     Foo(int x = 0) : m_id(x) {}
//     void print_num(int x) const
//     {
//         cout << m_id + x << endl;
//     }

//     // private:
//     int m_id;
// };

// struct Foo
// {
//     Foo(int num) : num_(num) {}
//     void print_add(int i) const { std::cout << num_ + i << '\n'; }
//     int num_;
// };

// #include <functional>
// void processFunc(vector<int> &v, std::function<void(int)> f)
// {
//     for (auto &x : v)
//     {
//         f(x);
//     }
// }

// void f(int x)
// {
// }

// class adder
// {
// public:
//     int operator()()
//     {
//         return 2000;
//     }
// };

// void processfunc(vector<int> &v, std::function<void(int)> f)
// {
//     for (auto x : v)
//     {
//         f(x);
//     }
// }

// class Task
// {
// public:
//     Task(int x) : m_id(x)
//     {
//     }
//     int operator()(int x)
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = (m_id + x) * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// void processFunc(vector<int> &v, std::function<void(int)> f)
// {
//     for (auto &x : v)
//     {
//         f(x);
//     }
// }

// int addit(int x, int y)
// {
//     return x + y;
// }

// void processFun(vector<int> &v, std::function<void(int)> f)
// {
//     for (auto &x : v)
//     {
//         f(x);
//     }
// }

// void swap1(int x, int y)
// {
//     cout << x << endl;
//     cout << y << endl;

//     int temp = x;
//     x = y;
//     y = temp;
//     cout << x << endl;
//     cout << y << endl;
// }

// void swap2(int *x, int *y)
// {

//     int *temp = nullptr;

//     *temp = *x;
//     *x = *y;
//     *y = *temp;
// }

// void processFunc(vector<int> &v, std::function<void(int)> f)
// {
//     for (auto &x : v)
//     {
//         f(x);
//     }
// }

// class adder
// {
// public:
//     void operator()()
//     {
//         cout << "op" << endl;
//     }
// };

// class Text
// {
// public:
//     virtual string Render() = 0;
// };

// class PlaneText : public Text
// {
// public:
//     PlaneText(string abc) : content(abc) {}
//     string Render()
//     {
//         return content;
//     }

// private:
//     string content;
// };

// class Decorator : public Text
// {
// public:
//     Text *text;
//     Decorator(Text *t) : text(t) {}
// };

// class DecoratorBold : public Decorator
// {
// public:
//     DecoratorBold(Text *t) : Decorator(t) {}
//     string Render()
//     {
//         return text->Render() + "Bold";
//     }
// };

// class Context;
// class IState
// {
// public:
//     virtual void Handle(Context *context) = 0;
// };

// class Context
// {
// public:
//     Context(IState *s) : m_pstate(s) {}
//     IState *m_pstate;
//     void Request()
//     {
//         m_pstate->Handle(this);
//     }
// };

// class ConcreateStateA : public IState
// {
// public:
//     void Handle(Context *context);
// };

// class ConcreateStateB : public IState
// {
// public:
//     void Handle(Context *context);
// };

// void ConcreateStateA::Handle(Context *context)
// {

//     context->m_pstate = new ConcreateStateB;
//     cout << "changed to stateB now" << endl;
// }

// void ConcreateStateB::Handle(Context *context)
// {

//     context->m_pstate = new ConcreateStateA;
//     cout << "changed to stateA now" << endl;
// }

// void processFunc(vector<int> &v, std::function<void(int)> f)
// {
//     for (auto &x : v)
//     {
//         f(x);
//     }
// }

// void processFun(std::function<void()> f)
// {
//     f();
// }

// int processFun2(std::function<int(int, int)> f)
// {
//     int a = 1;
//     int b = 1;
//     return f(a, b);
// }

// void processFunc(vector<int> &v, std::function<void(int)> f)
// {
//     for (auto &x : v)
//     {
//         f(x);
//     }
// }

// template <typename Func>
// void processfunc(Func f)
// {

//     f();
// }

// template <typename Func>
// void processfunc2(Func f)
// {
//     int a = 1;
//     int b = 2;
//     f(a, b);
// }

// void processFunc(vector<int> &v, std::function<void(int x)> f)
// {
//     for (auto &x : v)
//     {
//         f(x);
//     }
// }

// template <typename Func>
// void processFun(Func f)
// {
//     f();
// }

// template <typename Func>
// void processFunc2(Func f)
// {
//     int a = 1;
//     int b = 2;
//     f(a, b);
// }

void printstr()
{
    cout << "printstr" << endl;
}

class obj
{
public:
    void operator()() const
    {
        cout << "op" << endl;
    }
};

int add2(int x, int y)
{
    return x + y;
}

// void printHello(const string &abc, int xyz)
// {
//     cout << abc << xyz << endl;
// }
// void printMessage(const std::string &message, int value)
// {
//     std::cout << message << ": " << value << std::endl;
// }

// void printMessage(const string &mess, int value)
// {

//     cout << mess << value << endl;
// }
// void addit(int x)
// {
//     cout << x + 1 << endl;
// }

// void processFunc(vector<int> &v, std::function<void(int)> f)
// {
//     for (auto &x : v)
//     {
//         f(x);
//     }
// }

// class top
// {
// public:
//     void
//     operator()()
//     {
//         cout << "top" << endl;
//     }
// };

// void print123()
// {
//     cout << "print123" << endl;
// }

// void printmessage(const string &mess, int value)
// {
//     cout << mess << value << endl;
// }

// template <typename Func>
// void processFunc(Func f)
// {
//     f();
// }

// template <typename Func>
// void processFunc2(Func f)
// {
//     int a = 1;
//     int b = 2;
//     f(a, b);
// }

// void test(int x, string abc)
// {
//     while (x-- > 0)
//     {
//         cout << abc;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfunc(pfunc f)
//     {
//         m_func = f;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// class Task
// {
// public:
//     Task(int x) : m_id(x)
//     {
//     }
//     int operator()(int x)
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_result = (m_id + x) * 2;
//     }

// private:
//     int m_id;
//     int m_result;
// };

// void processFunc(vector<int> &v, std::function<void(int)> f)
// {
//     for (auto &x : v)
//     {
//         f(x);
//     }
// }

// void printMessage(const string &mess, int value)
// {
//     cout << mess << value << endl;
// }

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()(int x)
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return (m_id + x) * 2;
//     }

// private:
//     int m_id;
// };

// class Text
// {
// public:
//     virtual string Render() = 0;
// };

// class PlaneText : public Text
// {

// public:
//     PlaneText(string abc) : content(abc) {}
//     string Render()
//     {
//         return content;
//     }

// private:
//     string content;
// };

// class DecoratorText : public Text
// {

// public:
//     Text *text;
//     DecoratorText(Text *t) : text(t) {}
// };

// class DecortatorTextBold : public DecoratorText
// {
// public:
//     DecortatorTextBold(Text *t) : DecoratorText(t) {}
//     string Render()
//     {
//         return text->Render() + "bold";
//     }
// };

// class Context;

// class IState
// {
// public:
//     virtual void Handle(Context *context) = 0;
// };

// class Context
// {
// public:
//     IState *state;
//     void Request()
//     {
//         state->Handle(this);
//     }
//     Context(IState *s) : state(s) {}
// };

// class ConcreteStateA : public IState
// {
// public:
//     void Handle(Context *context);
// };

// class ConcreteStateB : public IState
// {
// public:
//     void Handle(Context *context);
// };

// void ConcreteStateA::Handle(Context *context)
// {
//     context->state = new ConcreteStateB;
//     cout << "changed to B now" << endl;
// }

// void ConcreteStateB::Handle(Context *context)
// {
//     context->state = new ConcreteStateA;
//     cout << "changed to A now" << endl;
// }

// class print123
// {
// public:
//     void operator()()
//     {
//         cout << 123 << endl;
//     }
// };

// void print111()
// {
//     cout << 111 << endl;
// }

// template <typename Func>
// void processFunc(Func f)
// {
//     f();
// }

// template <typename Func>
// void processfunc1(Func f)
// {
//     int a = 1;
//     int b = 1;
//     f(a, b);
// }

// std::function<void(int x)> processFunc(vector<int> &v, std::function<void(int x)> f)
// {
//     return [&v, f](int abc)
//     {
//         for (auto &x : v)
//         {
//             f(x + abc);
//         }
//     };
// }
using namespace std;
#include <map>
#include <iostream>
#include <utility>

// void processFunc(vector<int> &v, std::function<void(int)> f)
// {
//     for (auto &x : v)
//     {
//         f(x);
//     }
// }

// class test
// {
// public:
//     void operator()()

//     {
//         cout << "OP " << endl;
//     }
// };

// void printit()
// {
//     cout << "hello" << endl;
// }

// template <typename Func>
// void processFun(Func f)
// {
//     f();
// }

// template <typename func>
// void processFun2(func f)
// {
//     int a = 1;
//     int b = 2;
//     f(a, b);
// }

// template <typename T>
// void add(T a, T b)
// {
//     cout << a + b << endl;
// // }

// void Test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         cout << y << endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfunc(pfunc p)
//     {
//         m_func = p;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()(int x)
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return (m_id + x) * 2;
//     }

// private:
//     int m_id;
// };

// template <typename func>
// void processFunc(func f)
// {
//     f();
// }

// template <typename func2>
// void processFunc2(func2 f)
// {
//     int x = 1;
//     int y = 1;
//     f(x, y);
// }

// class Context;

// class IState
// {
// public:
//     virtual void Handle(Context *context) = 0;
// };

// class Context
// {
// public:
//     Context(IState *st) : m_state(st) {}
//     IState *m_state;
//     void Request()
//     {
//         m_state->Handle(this);
//     }
// };

// class ConcreteStateA : public IState
// {
// public:
//     void Handle(Context *context);
// };

// class ConcreteStateB : public IState
// {
// public:
//     void Handle(Context *context);
// };

// void ConcreteStateA::Handle(Context *context)
// {
//     context->m_state = new ConcreteStateB;
//     cout << "changed to stateB now" << endl;
// }

// void ConcreteStateB::Handle(Context *context)
// {
//     context->m_state = new ConcreteStateA;
//     cout << "changed to stateA now" << endl;
// }

// class Text
// {
// public:
//     virtual string Render() = 0;
// };

// class PlaneText : public Text
// {
// public:
//     PlaneText(string abc) : content(abc) {}
//     string Render()
//     {
//         return content;
//     }

// private:
//     string content;
// };

// class DecoratorText : public Text
// {
// public:
//     Text *text;
//     DecoratorText(Text *t) : text(t) {}
// };

// class DecoratorTextBold : public DecoratorText
// {

// public:
//     DecoratorTextBold(Text *t) : DecoratorText(t) {}
//     string Render()
//     {
//         return text->Render() + "Bold";
//     }
// };

// void processFunc(vector<int> &v, std::function<void(int)> p)
// {
//     for (auto &x : v)
//     {
//         p(x);
//     }
// }

// void test()
// {
//     cout << "test";
// }

// class test
// {
// public:
//     void operator()()
//     {
//         cout << "call OP" << endl;
//     }
// };

// #include <string.h>
// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }

//     CATString(const CATString &obj)
//     {
//         m_data = new char[strlen(obj.m_data) + 1];
//         strcpy(m_data, obj.m_data);
//     }

//     CATString &operator=(const CATString &obj)
//     {
//         if (this != &obj)
//         {

//             delete[] m_data;
//             m_data = new char[strlen(obj.m_data) + 1];
//             strcpy(m_data, obj.m_data);
//         }
//         return *this;
//     }
//     ~CATString()
//     {
//         if (m_data)
//         {

//             delete[] m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &os, const CATString &obj);
// };

// ostream &operator<<(ostream &os, const CATString &obj)
// {
//     os << obj.m_data;
//     return os;
// }

// void processFun(vector<int> &v, std::function<void(int)> func)
// {
//     for (auto &x : v)
//     {
//         func(x);
//     }
// }

// template <typename Func>
// void processFunc(Func f)
// {

//     f();
// }

// template <typename Func>
// void processFunc2(Func f)
// {
//     int a = 1;
//     int b = 1;
//     f(a, b);
// }

// void processFunc3(vector<int> &v, std::function<void(int)> f)
// {
//     for (const auto &x : v)
//     {

//         f(x);
//     }
// // }
// void test123()
// {

//     cout << "test123" << endl;
// }

// class test
// {
// public:
//     void operator()()
//     {
//         cout << "test()" << endl;
//     }
// };

// class Task
// {
// public:

// };

// void processFunc(vector<int> &v, std::function<void(int)> f)
// {

//     for (auto &x : v)
//     {
//         f(x);
//     }
// }

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()(int x)
//     {
//         return (m_id + x) * 2;
//     }

// private:
//     int m_id;
// };

// template <typename Func>
// void processFunc1(Func f)
// {
//     f();
// }

// auto f = []()
// { cout << "f lambda"; };

// template <typename Func>
// void processFunc2(Func f)
// {
//     int a = 1;
//     int b = 1;
//     f(a, b);
// }

// class Text
// {
// public:
//     virtual string Render() = 0;
// };

// class PlaneText : public Text
// {
// public:
//     PlaneText(string abc) : content(abc) {}
//     string Render()
//     {
//         return content;
//     }

// private:
//     string content;
// };

// class DecoratorText : public Text
// {
// public:
//     Text *text;
//     DecoratorText(Text *t) : text(t) {}
//     ~DecoratorText() { delete text; }
// };

// class DecoratorTextBold : public DecoratorText

// {
// public:
//     DecoratorTextBold(Text *t) : DecoratorText(t) {}
//     string Render() override
//     {
//         return "<b>" + text->Render() + "</b>";
//     }
// };

// void test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         cout << y << endl;
//     }
// }

// typedef void (*pfunc)(int, string);

// class caller
// {
// public:
//     void setfun(pfunc f)
//     {
//         m_func = f;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };

// void processFunc(vector<int> &v, std::function<void(int x)> f)
// {

//     for (auto &x : v)
//     {
//         f(x);
//     }
// }

// class Text
// {
// public:
//     virtual string Render() = 0;
// };

// class PlaneText : public Text
// {
// public:
//     string Render() override
//     {
//         return content;
//     }
//     PlaneText(string abc) : content(abc) {}

// private:
//     string content;
// };

// class DecoratorText : public Text
// {

// public:
//     Text *t;
//     DecoratorText(Text *x) : t(x) {}
//     ~DecoratorText() { delete t; }
// };

// class DecoratorTextBold : public DecoratorText
// {
// public:
//     DecoratorTextBold(Text *t) : DecoratorText(t) {}
//     string Render()
//     {
//         return t->Render() + "bold";
//     }
// };

// class Context;
// class IState
// {
// public:
//     virtual void Handle(Context *context) = 0;
// };

// class Context
// {
// public:
//     IState *m_state;
//     Context(IState *state) : m_state(state) {}
//     void Request()
//     {
//         m_state->Handle(this);
//     }
// };

// class ConcreteStateA : public IState
// {

// public:
//     void Handle(Context *context);
// };

// class ConcreteStateB : public IState
// {

// public:
//     void Handle(Context *context);
// };

// void ConcreteStateA::Handle(Context *context)
// {
//     context->m_state = new ConcreteStateB;
//     cout << "changed to B now" << endl;
// }

// void ConcreteStateB::Handle(Context *context)
// {
//     context->m_state = new ConcreteStateA;
//     cout << "changed to A now" << endl;
// }

// void processFunc(vector<int> &v, std::function<void(int x)> f)
// {
//     for (auto &x : v)
//     {
//         f(x);
//     }
// }

// void p1()
// {
//     cout << "p1" << endl;
// }
// class t
// {
// public:
//     void operator()()

//     {
//         cout << "t op" << endl;
//     }
//     void printit()
//     {
//         cout << "printit" << endl;
//     }
// };

// void processFunc(vector<int> &v, std::function<void(int x)> f)
// {
//     for (auto &x : v)
//     {
//         f(x);
//     }
// }

// void Task(int x, string y)
// {
//      while(x-->0)
//      {
//          cout << y << endl;
//      }
// }

// typedef void (*pFunc)(int, string);

// class caller
// {
//    public:
//      void setFunc(pFunc f)
//      {
//          m_func = f;
//      }

//      void letRun(int x, string y)
//      {
//          m_func(x, y);
//      }

//      private:
//      pFunc m_func;

// };

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()(int x)
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return (m_id + x) * 2;
//     }

// private:
//     int m_id;
// };

// class Text
// {

// public:
//     virtual string Render() = 0;
// };

// class PlaneText : public Text
// {

// public:
//     string Render()
//     {
//         return content;
//     }
//     PlaneText(string abc) : content(abc) {}

// private:
//     string content;
// };

// class DecoratorText : public Text
// {
// public:
//     Text *text;
//     DecoratorText(Text *t) : text(t) {}
//     ~DecoratorText()
//     {
//         delete text;
//     }
// };

// class DecoratorTextBold : public DecoratorText
// {
// public:
//     DecoratorTextBold(Text *t) : DecoratorText(t) {}
//     string Render() override
//     {
//         return text->Render() + "Bold";
//     }
// };

// class Context;
// class IState
// {
// public:
//     virtual void Handle(Context *context) = 0;
// };

// class Context
// {
// public:
//     IState *m_state;
//     Context(IState *state) : m_state(state) {}
//     void Request()
//     {
//         m_state->Handle(this);
//     }
// };

// class ConcreteStateA : public IState
// {
// public:
//     void Handle(Context *context);
// };

// class ConcreteStateB : public IState
// {
// public:
//     void Handle(Context *context);
// };

// void ConcreteStateA::Handle(Context *context)
// {
//     context->m_state = new ConcreteStateB;
//     cout << "changed to stateB" << endl;
// }

// void ConcreteStateB::Handle(Context *context)
// {
//     context->m_state = new ConcreteStateA;
//     cout << "changed to stateA" << endl;
// }

// void processFunc(vector<int> &v, std::function<void(int)> f)
// {

//     for (auto &x : v)
//     {
//         f(x);
//     }
// }

// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()(int x)
//     {

//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return (m_id + x) * 2;
//     }

// private:
//     int m_id;
// };

// class Text
// {
// public:
//     virtual string Render() = 0;
// };

// class PlaneText : public Text
// {
// public:
//     PlaneText(string abc) : content(abc) {}
//     string Render() override
//     {
//         return content;
//     }

// private:
//     string content;
// };

// class DecoratorText : public Text
// {
// public:
//     Text *text;
//     DecoratorText(Text *t) : text(t) {}
//     ~DecoratorText()
//     {
//         delete text;
//     }
// };

// class DecortatorTextBold : public DecoratorText
// {
// public:
//     DecortatorTextBold(Text *t) : DecoratorText(t) {}
//     string Render()
//     {
//         return text->Render() + "Bold";
//     }
// };

// class Context;
// class IState
// {
// public:
//     virtual void Handle(Context *context) = 0;
// };

// class Context
// {

// public:
//     IState *m_state;
//     Context(IState *s) : m_state(s) {}
//     void Request()
//     {
//         m_state->Handle(this);
//     }
// };

// class ConcreteStateA : public IState
// {

// public:
//     void Handle(Context *context);
// };

// class ConcreteStateB : public IState
// {

// public:
//     void Handle(Context *context);
// };

// void ConcreteStateA::Handle(Context *context)
// {
//     context->m_state = new ConcreteStateB;
//     cout << "changed to B " << endl;
// }

// void ConcreteStateB::Handle(Context *context)
// {
//     context->m_state = new ConcreteStateA;
//     cout << "changed to A " << endl;
// }

// void processFunc(vector<int> &v, std::function<void(int)> f)
// {

//     for (auto &x : v)
//     {

//         f(x);
//     }
// }

// void byref(int &x)
// {
//     x += 1;
// }

// class Context;
// class IState
// {
// public:
//     virtual void Handle(Context *context) = 0;
// };

// class Context
// {
// public:
//     IState *m_state;
//     void Request()
//     {
//         m_state->Handle(this);
//     }
//     Context(IState *st) : m_state(st) {}
// };

// class ConcreteStateA : public IState
// {
// public:
//     void Handle(Context *context);
// };

// class ConcreteStateB : public IState
// {
// public:
//     void Handle(Context *context);
// };

// void ConcreteStateA::Handle(Context *context)
// {
//     context->m_state = new ConcreteStateB;
//     std::cout << "changed state to B" << std::endl;
// }

// void ConcreteStateB::Handle(Context *context)
// {
//     context->m_state = new ConcreteStateA;
//     std::cout << "changed state to A" << std::endl;
// }

// class Text
// {
// public:
//     virtual string Render() = 0;
// };

// class PlaneText : public Text
// {

// public:
//     string Render()
//     {
//         return content;
//     }
//     PlaneText(string abc) : content(abc) {}

// private:
//     string content;
// };

// class DecoratorText : public Text
// {
// public:
//     Text *t;
//     DecoratorText(Text *text) : t(text) {}
// };

// class DecoratorTextBold : public DecoratorText
// {
// public:
//     DecoratorTextBold(Text *t) : DecoratorText(t) {}
//     string Render()
//     {
//         return t->Render() + "bold";
//     }
// };

// class CDocument
// {
// public:
//     void OnFileOpen()
//     {
//         open();
//         serialize();
//         close();
//     }
//     void open()
//     {
//         cout << "open" << endl;
//     }
//     virtual void serialize() = 0;
//     void close()
//     {
//         cout << "close" << endl;
//     }
// };

// class MyDoc : public CDocument
// {
// public:
//     void serialize()
//     {
//         cout << "mydoc serialize" << endl;
//     }
// };

// class Animal
// {
// public:
//     virtual void show() = 0;
// };

// class Cat : public Animal
// {

// public:
//     void show()
//     {
//         cout << "miao" << endl;
//     }
// };
// class Dog : public Animal
// {
// public:
//     void show()
//     {
//         cout << "wang" << endl;
//     }
// };

// class Weapon
// {
// public:
//     virtual void Fire() = 0;
// };
// class AK47 : public Weapon
// {
// public:
//     void Fire()
//     {
//         cout << "AK47" << endl;
//     }
// };

// class Knife : public Weapon
// {
// public:
//     void Fire()
//     {
//         cout << "knife" << endl;
//     }
// };

// class Person
// {
// public:
//     Person(Weapon *weapon) : w(weapon) {}

//     void setWeapon(Weapon *weapon)
//     {
//         w = weapon;
//     }
//     void OnFire()
//     {
//         w->Fire();
//     }

// private:
//     Weapon *w;
// };

// class Adaptee
// {
// public:
//     virtual int foo() = 0;
//     virtual void bar(int x) = 0;
// };

// class oldclass : public Adaptee
// {
// public:
//     int foo()
//     {
//         return 2025;
//     }

//     void bar(int x)
//     {
//         cout << x + 1 << endl;
//     }
// };

// class Target
// {
// public:
//     virtual void doprocess() = 0;
// };

// class Adapter : public Target
// {
// public:
//     Adapter(Adaptee *a) : ada(a) {}
//     void doprocess()
//     {
//         int x = ada->foo();
//         ada->bar(x);
//     }

// private:
//     Adaptee *ada;
// };

// class Fruit
// {
// public:
//     virtual void show() = 0;
// };

// class Apple : public Fruit
// {
// public:
//     void show()
//     {
//         cout << "apple" << endl;
//     }
// };
// class Banana : public Fruit
// {
// public:
//     void show()
//     {
//         cout << "Banana" << endl;
//     }
// };

// class SimpleFactory
// {

// public:
//     static Fruit *CreateFruit(string abc)
//     {
//         if (abc == "Apple")
//         {
//             return new Apple;
//         }
//         else if (abc == "Banana")
//         {
//             return new Banana;
//         }
//         else
//         {
//             return new Apple;
//         }
//     }
// };

// class FruitFactory
// {
// public:
//     virtual Fruit *CreateFruit() = 0;
// };

// class AppleFactory : public FruitFactory
// {
//     Fruit *CreateFruit()
//     {
//         return new Apple;
//     }
// };

// class BananaFactory : public FruitFactory
// {
//     Fruit *CreateFruit()
//     {
//         return new Banana;
//     }
// };
// #include <list>
// class Subject;
// class Observer
// {
// public:
//     void update()
//     {
//         cout << "update" << endl;
//     }
// };

// class Subject
// {
// public:
//     void addObs(Observer *obs)
//     {
//         m_list.push_back(obs);
//     }
//     void deleteObs(Observer *obs)
//     {
//         m_list.remove(obs);
//     }
//     Subject(int x) : id(x) {}
//     void changeid(int x)
//     {
//         id = x;
//         for (auto &x : m_list)
//         {
//             x->update();
//         }
//     }

// private:
//     list<Observer *> m_list;
//     int id;
// // };
// #include <string.h>
// class CATString
// {
// public:
//     CATString(const char *str = 0)
//     {
//         if (str)
//         {
//             m_data = new char[strlen(str) + 1];
//             strcpy(m_data, str);
//         }
//         else
//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }
//     CATString(const CATString &obj)
//     {
//         m_data = new char[strlen(obj.m_data) + 1];
//         strcpy(m_data, obj.m_data);
//     }

//     CATString &operator=(const CATString &obj)
//     {
//         if (this != &obj)
//         {
//             delete this->m_data;
//             m_data = new char[strlen(obj.m_data)];
//             strcpy(m_data, obj.m_data);
//         }
//         return *this;
//     }
//     ~CATString()
//     {
//         if (m_data)
//         {
//             delete m_data;
//             m_data = nullptr;
//         }
//     }

// private:
//     char *m_data;
//     friend ostream &operator<<(ostream &os, const CATString &obj);
// };

// ostream &operator<<(ostream &os, const CATString &obj)
// {
//     os << obj.m_data;
//     return os;
// }

// class Adaptee
// {
// public:
//     virtual int foo() = 0;
//     virtual void bar(int x) = 0;
// };

// class oldclass : public Adaptee
// {

// public:
//     int foo()
//     {
//         return 2025;
//     }

//     void bar(int x)
//     {
//         cout << x + 1 << endl;
//     }
// };

// class Adapter
// {

// public:
//     virtual void doprocess() = 0;

// };

// class Target : public Adapter
// {
// public:
//     void doprocess()
//     {
//         int x = ada->foo();
//         ada->bar(x);
//     }
//     Target(Adaptee *a) : ada(a) {}

// private:
//     Adaptee *ada;
// };

// class Adaptee
// {
// public:
//     virtual int foo() = 0;
//     virtual void bar(int x) = 0;
// };

// class oldclass : public Adaptee
// {
// public:
//     int foo()
//     {
//         return 2025;
//     }
//     void bar(int x)
//     {
//         cout << x + 1;
//     }
// };

// class Target
// {
// public:
//     virtual void doprocess() = 0;
// };

// class Adapter : public Target
// {
// public:
//     Adaptee *ada;
//     Adapter(Adaptee *a) : ada(a) {}
//     void doprocess()
//     {
//         int x = ada->foo();
//         ada->bar(x);
//     }
// };

// class ITarget
// {
// public:
//     virtual void doprocess() = 0;
// };

// class IAdaptee
// {
// public:
//     virtual int foo() = 0;
//     virtual void bar(int x) = 0;
// };

// class oldclass : public IAdaptee
// {
// public:
//     int foo()
//     {
//         return 2025;
//     }
//     void bar(int x)
//     {
//         cout << x + 1;
//     }
// };

// class Adapter : public ITarget
// {
// private:
//     IAdaptee *ada;

// public:
//     Adapter(IAdaptee *a) : ada(a) {}
//     void doprocess()
//     {
//         int x = ada->foo();
//         ada->bar(x);
//     }
// };

// class Business
// {
// public:
//     virtual void charge(int x) = 0;
// };

// class CMCC : public Business
// {
// public:
//     void charge(int x)
//     {
//         cout << "charge " << x << "done." << std::endl;
//     }
// };

// class CMCCProxy : public Business
// {
// public:
//     void charge(int x)
//     {
//         if (x < 50)
//         {
//             cout << "charge need >10" << std::endl;
//         }
//         else
//         {
//             if (m_cmcc == nullptr)
//             {
//                 m_cmcc = new CMCC;
//                 m_cmcc->charge(x);
//                 delete m_cmcc;
//             }
//         }
//     }

// private:
//     CMCC *m_cmcc;
// };

// class IAdaptee
// {
// public:
//     virtual int foo() = 0;
//     virtual void bar(int x) = 0;
// };

// class oldclass : public IAdaptee
// {

// public:
//     int foo()
//     {
//         return 2024;
//     }
//     void bar(int x)
//     {
//         cout << x + 1 << endl;
//     }
// };

// class ITarget
// {
// public:
//     virtual void doprocess() = 0;
// };

// class Adapter : public ITarget
// {

// public:
//     Adapter(IAdaptee *ia) : ad(ia) {}
//     void doprocess()
//     {
//         int x = ad->foo();
//         ad->bar(x);
//     }

// private:
//     IAdaptee *ad;
// };

// class Business
// {
// public:
//     virtual void charge(int x) = 0;
// };

// class CMCC : public Business
// {
// public:
//     void charge(int x)
//     {
//         cout << "charge " << x << endl;
//     }
// };

// class CMCCProxy : public Business
// {
// public:
//     CMCCProxy() : m_cmcc(nullptr) {}
//     void charge(int x)
//     {
//         if (x < 50)
//         {
//             cout << "need charge >50" << endl;
//         }
//         else
//         {
//             if (m_cmcc == nullptr)
//             {
//                 m_cmcc = new CMCC;
//             }
//             m_cmcc->charge(x);
//             //delete m_cmcc;
//         }
//     }
//     // ~CMCCProxy()
//     // {
//     //     if (m_cmcc != nullptr)
//     //     {
//     //         delete m_cmcc;
//     //     }
//     // }

// private:
//     CMCC *m_cmcc;
// };

// class Business
// {
// public:
//     virtual void charge(int x) = 0;
// };

// class CMCC : public Business
// {

// public:
//     void charge(int x)
//     {

//         cout << "charge " << x << endl;
//     }
// };

// class CMCCProxy : public Business
// {
// public:
//     CMCCProxy() : realCMCC(nullptr) {}
//     void charge(int x)
//     {
//         if (x < 10)

//         {
//             cout << "need >=10" << endl;
//             return;
//         }

//         if (realCMCC == nullptr)
//             realCMCC = new CMCC;

//         realCMCC->charge(x);
//     }
//     ~CMCCProxy()
//     {
//         if (realCMCC)
//             delete realCMCC;
//     }

// private:
//     CMCC *realCMCC;
// };

// class Business
// {
// public:
//     virtual void charge(int x) = 0;
// };

// class CMCC : public Business
// {
// public:
//     void charge(int x)
//     {
//         cout << "charge " << x << endl;
//     }
// };

// class CMCCProxy : public Business
// {
// public:
//     CMCCProxy() : realCMCC(nullptr) {}
//     void charge(int x)
//     {
//         if (x < 50)
//         {
//             cout << "need > 50" << endl;
//             return;
//         }
//         if (realCMCC == nullptr)
//         {
//             realCMCC = new CMCC;
//         }

//         std::cout << "[proxyStart]..." << std::endl;
//         realCMCC->charge(x);
//         std::cout << "[proxyEnd]..." << std::endl;
//     }
//     ~CMCCProxy()
//     {
//         if (realCMCC)
//         {
//             delete realCMCC;
//         }
//     }

// private:
//     CMCC *realCMCC;
// };

// class Image
// {
// public:
//     virtual void display() = 0;
//     virtual ~Image(){}
// };

// class RealImage : public Image
// {
// public:
//     RealImage(string abc) : filename(abc)
//     {
//         loadfromdisk();
//     }
//     void display()
//     {
//         cout << "dispaly image " << filename << std::endl;
//     }
//     ~RealImage() {}

// private:
//     string filename;
//     void loadfromdisk()
//     {
//         cout << "load file " << filename << std::endl;
//     }
// };

// class ProxyImage : public Image
// {
// public:
//     ProxyImage(string abc) : filename(abc) {}
//     void display()
//     {
//         if (realimage == nullptr)
//         {
//             realimage = new RealImage(filename);
//         }
//         realimage->display();
//     }
//     ~ProxyImage()
//     {
//         if (realimage)
//         {
//             delete realimage;
//         }
//     }

// private:
//     RealImage *realimage = nullptr;
//     string filename;
// };

// class Business
// {
// public:
//     virtual void charge(int x) = 0;
//     virtual ~Business() = default;
// };

// class RealCMCC : public Business
// {

// public:
//     void charge(int x)
//     {
//         cout << "charge " << x << endl;
//     }
// };

// class ProxyCMCC : public Business
// {
// public:
//     ProxyCMCC() : realcmcc(nullptr) {}
//     void charge(int x)
//     {
//         if (x < 50)
//         {
//             cout << "need >50" << endl;
//             return;
//         }
//         if (realcmcc == nullptr)
//         {
//             realcmcc = new RealCMCC;
//         }
//         realcmcc->charge(x);
//     }
//     ~ProxyCMCC()
//     {
//         delete realcmcc;
//     }

// private:
//     RealCMCC *realcmcc;
// };

// class Image
// {

// public:
//     virtual void display() = 0;
//     virtual ~Image() = default;
// };

// class RealImage : public Image
// {
// public:
//     void display()
//     {
//         cout << "display " << filename << endl;
//     }

//     RealImage(string abc) : filename(abc)
//     {
//         loadfile();
//     }

// private:
//     string filename;
//     void loadfile()
//     {
//         cout << "loadfile " << filename << endl;
//     }
// };

// class ProxyImage : public Image
// {
// public:
//     ProxyImage(string x) : abc(x) {}
//     void display()
//     {
//         if (realimage == nullptr)
//         {
//             realimage = new RealImage(abc);
//         }
//         realimage->display();
//     }
//     ~ProxyImage()
//     {
//         delete realimage;
//     }

// private:
//     RealImage *realimage = nullptr;
//     string abc;
// };

// class Image
// {
// public:
//     virtual void display() = 0;
//     virtual ~Image() = default;
// };

// class RealImage : public Image
// {
// public:
//     RealImage(string abc) : filename(abc)
//     {
//         loadfile();
//     }
//     void display()
//     {
//         cout << "display " << filename << endl;
//     }

// private:
//     string filename;
//     void loadfile()
//     {
//         cout << "loadfile: " << filename << endl;
//     }
// };

// class ProxyImage : public Image
// {
// public:
//     ProxyImage(string abc) : name(abc) {}
//     void display()
//     {
//         if (realimage == nullptr)
//         {
//             realimage = new RealImage(name);
//         }
//         realimage->display();
//     }

// private:
//     string name;
//     RealImage *realimage = nullptr;
// };

// // Car.h
// #include <memory>

// class Car {
// public:
//     Car();
//     ~Car();

//     void start();
//     void stop();
//     int getSpeed() const;

// private:
//     // Forward declaration of implementation class
//     struct Impl;

//     // Opaque pointer to implementation
//     std::unique_ptr<Impl> pImpl;
// };

// // Car.cpp
// #include <iostream>

// // Define the implementation class
// struct Car::Impl
// {
//     bool isRunning = false;
//     int currentSpeed = 0;

//     void engineSound()
//     {
//         std::cout << "Vroom vroom!" << std::endl;
//     }
// };

// // Implement public interface
// Car::Car() : pImpl(std::make_unique<Impl>()) {}

// Car::~Car() = default; // Must be in .cpp where Impl is complete

// void Car::start()
// {
//     pImpl->isRunning = true;
//     pImpl->engineSound();
//     pImpl->currentSpeed = 10;
// }

// void Car::stop()
// {
//     pImpl->isRunning = false;
//     pImpl->currentSpeed = 0;
//     std::cout << "Engine stopped" << std::endl;
// }

// int Car::getSpeed() const
// {
//     return pImpl->currentSpeed;
// }

// class Business
// {
// public:
//     virtual void charge(int x) = 0;
// };

// class RealCMCC : public Business
// {
// public:
//     void charge(int x)
//     {
//         cout << "charge " << x << endl;
//     }
// };

// class ProxyCMCC : public Business
// {
// public:
//     ProxyCMCC() : realcmcc(nullptr) {}
//     void charge(int x)
//     {

//         if (x < 50
// )
//         {
//             cout << "need >50" << endl;
//             return;
//         }
//         if (realcmcc == nullptr)
//         {
//             realcmcc = new RealCMCC;
//         }
//         realcmcc->charge(x);
//     }
//     ~ProxyCMCC()
//     {
//         delete realcmcc;
//     }

// private:
//     RealCMCC *realcmcc = nullptr;
// };

// class Image
// {
// public:
//     virtual void display() = 0;
//     virtual ~Image() = default;
// };

// class realImage : public Image
// {
// public:
//     realImage(string abc) : filename(abc)
//     {
//         loadfile();
//     }
//     void display()
//     {
//         cout << "display :" << filename << endl;
//     }

// private:
//     string filename;
//     void loadfile()
//     {
//         cout << "loadfile: " << filename << endl;
//     }
// };

// class ProxyImage : public Image
// {
// public:
//     ProxyImage(string abc):name(abc){}
//     void display()
//     {
//         if (realimage == nullptr)
//         {
//             realimage = new realImage(name);
//         }
//         realimage->display();
//     }

// private:
//     realImage *realimage = nullptr;
//     string name;
// };

// Widget.h - Public interface
// class Widget
// {
// public:
//     Widget();
//     ~Widget();
//     void publicMethod();

// private:
//     struct Impl;                 // Forward declaration
//     std::unique_ptr<Impl> pImpl; // Opaque pointer
// };

// // Widget.cpp - Implementation details
// struct Widget::Impl
// {
//     // All private data members and methods go here
//     int privateData;
//     void privateMethod();
// };

// Widget::Widget() : pImpl(std::make_unique<Impl>()) {}
// Widget::~Widget() = default; // Required for unique_ptr with incomplete type

// void Widget::publicMethod()
// {
//     pImpl->privateMethod(); // Delegate to implementation
// }
// #include <iostream>
// #include <memory>
// class Widget
// {
// public:
//     Widget();
//     void publicMethod()
//     {
//         std::cout << "publicMethod call..." << std::endl;
//         pImpl->privateMethod();
//     }

// private:
//     struct Impl;
//     std::unique_ptr<Impl> pImpl;
// };

// struct Widget::Impl
// {
//     int privteData;
//     void privateMethod()
//     {
//         cout << "privateMethod call...";
//     }
// };

// class Widget
// {
// public:
//     Widget();
//     void publicMethod();

// private:
//     struct Impl;
//     std::unique_ptr<Impl> pImpl;
// };

// Widget::Widget() : pImpl(make_unique<Impl>()) {}
// void Widget::publicMethod()
// {

//     cout << "publicmethod ..." << endl;
//     pImpl->privateMethod();
// }

// struct Widget::Impl
// {
//     int privateData;
//     void privateMethod()
//     {
//         cout << "privateMethod..." << endl;
//     }
// };

// class Widget
// {

// public:
//     void publicMethod();
//     Widget();

// private:
//     struct Impl;
//     std::unique_ptr<Impl> pImpl;
// };

// Widget::Widget() : pImpl(std::make_unique<Impl>()) {}
// struct Widget::Impl
// {
//     int privateData;
//     void privateMethod()
//     {
//         cout << "privateMethod ..." << endl;
//     }
// };

// void Widget::publicMethod()
// {
//     pImpl->privateMethod();
//     cout << "publicMethod..." << endl;
// }

// class Widget
// {

// public:
//     void publicMethod();
//     Widget();

// private:
//     struct Impl;
//     std::unique_ptr<Impl> pImpl;
// };

// struct Widget::Impl
// {
//     int privateData;
//     void privateMethod()
//     {
//         cout << "privateMethod..." << endl;
//     }
// };

// Widget::Widget() : pImpl(make_unique<Impl>()) {}
// void Widget::publicMethod()
// {
//     cout << "publieMethod..." << endl;
//     pImpl->privateMethod();
// }

// class Widget
// {

//     public:
//     void publicMethod();
//     Widget();

// private:
//    struct Impl;
//    std::unique_ptr<Impl> pImpl;
// };

// struct Widget::Impl
// {
//     int privateData;
//     void privateMethod()
//     {
//         cout << "privateMethod..." << endl;
//     }
// };

// Widget::Widget():pImpl(std::make_unique<Impl>()){}

// void Widget::publicMethod()
// {
//     cout<<"publicMethod..."<<endl;
//     pImpl->privateMethod();
// }

// class Widget
// {
// public:
//     Widget();
//     void publicMethod();

// private:
//     struct Impl;
//     std::unique_ptr<Impl> pImpl;
// };

// struct Widget::Impl
// {
//     int privateData;
//     void privateMethod()
//     {
//         cout << "privateMethod..." << endl;
//     }
// };

// Widget::Widget() : pImpl(std::make_unique<Impl>()) {}
// void Widget::publicMethod()
// {
//     cout << "publicMethod..." << endl;
//     pImpl->privateMethod();
// }

// class Widget
// {
// public:
//     Widget();
//     void publicMethod();

// private:
//     struct Impl;
//     unique_ptr<Impl> pImpl;
// };

// struct Widget::Impl
// {
//     int privateData;
//     void privateMethod()
//     {
//         cout << "privateMethod..." << endl;
//     }
// };

// Widget::Widget() : pImpl(make_unique<Impl>()) {}
// void Widget::publicMethod()
// {
//     cout << "publicMethod..." << endl;
//     pImpl->privateMethod();
// }

// class Widget
// {
// public:
//     Widget();
//     void publicMethod();

// private:
//     struct Impl;
//     std::unique_ptr<Impl> pImpl;
// };

// struct Widget::Impl
// {
//     int privatedata;
//     void privateMethod()
//     {
//         cout << "privateMethod..." << endl;
//     }
// };

// Widget::Widget() : pImpl(std::make_unique<Impl>()) {}
// void Widget::publicMethod()
// {
//     cout << "publicMethod..." << endl;
//     pImpl->privateMethod();
// }

// class Widget
// {

// public:
//     Widget();
//     void publicMethod();

// private:
//     struct Impl;
//     std::unique_ptr<Impl> pImpl;
// };

// struct Widget::Impl
// {

//     int privateData;
//     void privatemethod()
//     {
//         cout << "privtemethod..." << endl;
//     }
// };

// Widget::Widget() : pImpl(make_unique<Impl>()) {}

// void Widget::publicMethod()
// {
//     cout << "publicmethod..." << endl;
//     pImpl->privatemethod();
// }

// class Widget
// {
// public:
//     Widget();
//     void publicMethod();

// private:
//     struct Impl;
//     unique_ptr<Impl> pImpl;
// };

// struct Widget::Impl
// {
//     int privateData;
//     void privateMethod()
//     {
//         cout << "privateMethod..." << endl;
//     }
// };

// Widget::Widget() : pImpl(make_unique<Impl>()) {}
// void Widget::publicMethod()
// {
//     cout << "publicMethod..." << endl;
//     pImpl->privateMethod();
// }

// class Context;
// class IState
// {
// public:
//     virtual void Handle(Context *context) = 0;

// private:
// };

// class Context
// {
// public:
//     Context(IState *st) : state(st) {}
//     void Request()
//     {
//         state->Handle(this);
//     }
//     IState *state;
// };

// class ConcreteStateA : public IState
// {
// public:
//     void Handle(Context *context);
// };

// class ConcreteStateB : public IState
// {
// public:
//     void Handle(Context *context);
// };

// void ConcreteStateA::Handle(Context *context)
// {
//     context->state = new ConcreteStateB;
//     cout << "changed to B now" << endl;
// }

// void ConcreteStateB::Handle(Context *context)
// {
//     context->state = new ConcreteStateA;
//     cout << "changed to A now" << endl;
// }

// class Adaptee
// {
// public:
//     virtual int foo() = 0;

//     virtual void bar(int x) = 0;

// private:
// };

// class oldclass : public Adaptee
// {
// public:
//     int foo()
//     {
//         cout << "foo in old class" << endl;
//         return 2025;
//     }

//     void bar(int x)
//     {
//         cout << x + 1 << endl;
//     }
// };

// class Target
// {
// public:
//     virtual void process() = 0;
// };

// class Adapter : public Target
// {
// public:
//     void process()
//     {
//         int abc = ada->foo();
//         ada->bar(abc);
//     }
//     Adapter(Adaptee *a) : ada(a) {}

// private:
//     Adaptee *ada;
// };

// class Widget
// {
// public:
//     Widget();
//     void publicMethod();

// private:
//     struct Impl;
//     std::unique_ptr<Impl> pImpl;
// };

// struct Widget::Impl
// {
//     int privateData;
//     void privateMethod()
//     {
//         cout << "privateMethod..." << std::endl;
//     }
// };

// Widget::Widget() : pImpl(make_unique<Impl>()) {}
// void Widget::publicMethod()
// {
//     cout << "publicMethod..." << endl;
//     pImpl->privateMethod();
// }

// class Widget
// {
// public:
//     Widget();
//     void publicMethod();

// private:
//     struct Impl;
//     unique_ptr<Impl> pImpl;
// };

// struct Widget::Impl
// {
//     int privateData;
//     void privateMethod()
//     {
//         cout << "privateMathod..." << endl;
//     }
// };

// Widget::Widget() : pImpl(make_unique<Impl>()) {}
// void Widget::publicMethod()
// {
//     cout << "publicethod..."
//          << endl;

//     pImpl->privateMethod();
// }

// class Widget
// {
// public:
//     Widget();
//     void publicMethod();

// private:
//     struct Impl;
//     std::unique_ptr<Impl> pImpl;
// };

// struct Widget::Impl
// {
//     int privateData;
//     void privateMethod()
//     {
//         cout << "privateMethod..." << endl;
//     }
// };

// Widget::Widget() : pImpl(std::make_unique<Impl>()) {}
// void Widget::publicMethod()
// {
//     cout << "publieMethod..." << endl;
//     pImpl->privateMethod();
// }

// class Widget
// {
// public:
//     Widget();
//     void publicMethod();

// private:
//     struct Impl;
//     std::unique_ptr<Impl> pImpl;
// };

// struct Widget::Impl
// {
//     int privateData;
//     void privateMethod()
//     {
//         cout << "privteMethod..." << endl;
//     }
// };

// Widget::Widget() : pImpl(make_unique<Impl>()) {}
// void Widget::publicMethod()
// {
//     cout << "publicMethod..." << endl;
//     pImpl->privateMethod();
// }

// class Widget
// {
// public:
//     Widget();

//     void publicMethod();

// private:
//     struct Impl;
//     std::unique_ptr<Impl> pImpl;
// };

// struct Widget::Impl
// {
//     int privateData;
//     void privateMethod()
//     {
//         cout << "privateMethod..." << endl;
//     }
// };

// Widget::Widget() : pImpl(make_unique<Impl>()) {}
// void Widget::publicMethod()
// {
//     std::cout << "publicMethod..." << std::endl;
//     pImpl->privateMethod();
// }

// class Widget
// {
// public:
//     Widget();
//     void publicMethod();

// private:
//     struct Impl;
//     std::unique_ptr<Impl> pImpl;
// };

// struct Widget::Impl
// {
//     int privateData;
//     void privateMethod()
//     {
//         cout << "privateMethod..." << endl;
//     }
// };

// Widget::Widget() : pImpl(make_unique<Impl>()) {}
// void Widget ::publicMethod()
// {
//     cout << "publicMethod..." << endl;
//     pImpl->privateMethod();
// }

// class Widget
// {
// public:
//     Widget();
//     void publicMethod();

// private:
//     struct Impl;
//     std::unique_ptr<Impl> pImpl;
// };

// struct Widget::Impl
// {
//     int privateData;
//     void privateMethod()
//     {
//         cout << "privateMethod..." << endl;
//     }
// };

// Widget::Widget() : pImpl(make_unique<Impl>()) {}
// void Widget::publicMethod()
// {
//     cout << "publicMethod..." << endl;
//     pImpl->privateMethod();
// }

// class Adaptee
// {
// public:
//     virtual int foo() = 0;

//     virtual void bar(int x) = 0;

// private:
// };

// class oldclass : public Adaptee
// {
// public:
//     int foo()
//     {
//         return 2025;
//     }

//     void bar(int x)
//     {
//         cout << x << endl;
//     }
// };

// class Target
// {
// public:
//     virtual void doprocess() = 0;
// };

// class Adapter : public Target
// {
// public:
//     void doprocess()
//     {
//         int x = ada->foo();
//         ada->bar(x);
//     }
//     Adapter(Adaptee *ad) : ada(ad) {}

// private:
//     Adaptee *ada;
// };

// void Test(int x, string y)
// {
//     while (x-- > 0)
//     {
//         cout << y << endl;
//     }
// }

// typedef void (*pfunc)(int, string);
// class caller
// {
// public:
//     void setfunc(pfunc f)
//     {
//         m_func = f;
//     }
//     void letrun(int x, string y)
//     {
//         m_func(x, y);
//     }

// private:
//     pfunc m_func;
// };
// #include <thread>
// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()()
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_id * 2;
//     }

// private:
//     int m_id;
// };

// int a = 100;
// int b = 200;

// #include "thread"
// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()(int x)
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return m_id * (2 + x);
//     }

// private:
//     int m_id;
// };
// void printMessage(string abc, int x)
// {
//     cout << abc << x << endl;
// }

// void printMessage(string abc, int x)
// {
//     cout << abc << x << endl;
// // }
// #include <thread>
// class Task
// {
// public:
//     Task(int x) : m_id(x) {}
//     int operator()(int x)
//     {
//         std::this_thread::sleep_for(std::chrono::seconds(2));
//         return (m_id + x) * 2;
//     }

// private:
//     int m_id;
// };

// class CDocument
// {
// public:
//     void OnFileOpen()
//     {
//         open();
//         serilize();
//         close();
//     }
//     void open()
//     {
//         cout << "CDoc open..." << endl;
//     }
//     void close()
//     {
//         cout << "CDoc close..." << endl;
//     }
//     virtual void serilize() = 0;
// };

// class MyDoc : public CDocument
// {
// public:
//     void serilize()
//     {
//         cout << "Mydoc serilize..." << endl;
//     }
// };

// void printMessage(string y, int x)
// {
//     cout << x << y << endl;
// }

// void printMessage(string y, int x)
// {
//     cout << x << y << endl;
// }

// class Widget
// {
// public:
//     Widget();
//     void publicMethod();

// private:
//     struct Impl;
//     std::unique_ptr<Impl> pImpl;
// };

// struct Widget::Impl
// {
//     int privateData;
//     void privateMethod()
//     {
//         cout << "privateMthod..." << endl;
//     }
// };

// Widget::Widget() : pImpl(make_unique<Impl>()) {}
// void Widget::publicMethod()
// {
//     cout << "pubicMethod..." << endl;
//     pImpl->privateMethod();
// }




int main(int argc, char const *argv[])
{
    // Widget w;
    // w.publicMethod();
    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // std::sort(v.begin(), v.end(), [](int a, int b)
    //           { return a > b; });
    // for (auto &x : v)
    // {
    //     cout << x << endl;
    // }

    // int count = 100;
    // auto f = [=]() mutable
    // {
    //     count++;
    //     cout << count << endl;
    // };
    // f();
    // f();

    // int a = 100;
    // int b = 200;
    // auto f = [=]() -> int
    // { return a + b; };
    // cout << f() << endl;

    // auto func = std::bind(printMessage, "hello", std::placeholders::_1);
    // std::function<void(int)> f = func;
    // f(1000);

    // auto f = std::bind(std::ref(printMessage), "hello", std::placeholders::_1);
    // std::function<void(int)> ff = f;
    // ff(2000);

    // auto bind_task = std::bind(std::ref(printMessage), "hello", std::placeholders::_1);
    // std::function<void(int)> f = bind_task;
    // f(2000);

    // CDocument *cd = new MyDoc;
    // cd->OnFileOpen();
    // vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
    // vector<future<int>> futures;

    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // for (int i = 0; i < 5; i++)
    // {
    //     int dynamic_arg = i * 10;
    //     futures.push_back(std::async(std::launch::async, [&tasks, i, dynamic_arg]()
    //                                  { return tasks[i](dynamic_arg); }));
    // }

    // int argument = 2000;
    // for (auto &task : tasks)
    // {
    //     auto bind_task = std::bind(std ::ref(task), argument);
    //     // futures.push_back(std::async(std::launch::async, [&task, argument]()
    //     //                              { return task(argument); }));
    //     futures.push_back(std::async(std::launch::async, bind_task));
    // }

    // for (auto &future : futures)
    // {
    //     cout << future.get() << endl;
    // }
    // int count = 0;
    // auto x = [=]() mutable
    // {
    //     count++;
    //     cout << count << endl;
    // };
    // x();
    // x();

    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // std::sort(v.begin(), v.end(), [](int a, int b)
    //           { return a > b; });
    // for (auto &x : v)
    // {
    //     cout << x << endl;
    // }

    // int x = 100;
    // int y = 100;
    // auto f = [=]()
    // { return x + y; };
    // cout << f();

    // auto bind_task = std::bind(std::ref(printMessage), "hello", std::placeholders::_1);
    // std::function<void(int)> f = bind_task;
    // f(2000);

    // auto bind_task = std::bind(ref(printMessage), "hello", std::placeholders::_1);
    // std::function<void(int)> f = bind_task;
    // f(1000);

    // auto bind_task = std::bind(std::ref(printMessage), "Hello", std::placeholders::_1);
    // std::function<void(int)> f1 = bind_task;
    // f1(2000);

    // std::function<void()> f1 = []()
    // {
    //     cout << "lambda" << endl;
    // };

    // vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
    // vector<future<int>> futures;
    // for (auto &task : tasks)
    // {
    //     int x = 1000;
    //     auto f = std::bind(task, x);
    //     futures.push_back(std::async(std::launch::async, f));
    // }
    // for (auto &future : futures)
    // {
    //     std::cout << future.get() << endl;
    // }

    // int x = 5;

    // auto f = [x](int y)
    // {
    //     return x * y;
    // };

    // cout << f(3) << endl;

    // int count = 1;
    // auto x = [count]() mutable
    // {
    //     count++;
    //     cout << count << endl;
    // };
    // x();
    // x();

    // vector<int> v = {1, 2, 3, 4, 5};
    // std::sort(v.begin(), v.end(), [](int a, int b)
    //           { return a > b; });

    // for (auto &x : v)
    // {
    //     cout << x << endl;
    // }

    // auto f = [](int x, int y) -> int
    // { return x + y; };

    // cout << f(1, 2) << endl;

    // auto x = [=]()
    // {
    //     return a + b;
    // };
    // cout << x() << endl;

    // vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
    // vector<future<int>> futures;

    // for (auto &task : tasks)
    // {
    //     futures.push_back(std::async(std::launch::async, task));
    // }

    // for (auto &future : futures)
    // {
    //     std::cout << future.get() << std::endl;
    // }

    // caller c1;
    // c1.setfunc(Test);
    // c1.letrun(6, "hello");
    // Adaptee *ada = new oldclass;
    // Target *it = new Adapter(ada);
    // it->doprocess();

    // Widget w;
    // w.publicMethod();
    // Widget w;
    // w.publicMethod();
    // Widget w;
    // w.publicMethod();
    // Widget w1;
    // w1.publicMethod();
    // Adaptee *ada = new oldclass();
    // Target *it = new Adapter(ada);
    // it->process();

    // IState *state = new ConcreteStateA();
    // Context *context = new Context(state);
    // context->Request();
    // context->Request();
    // context->Request();

    // Widget w1;
    // w1.publicMethod();

    // Widget w1;
    // w1.publicMethod();

    // Widget w1;
    // w1.publicMethod();

    // Image * img = new ProxyImage("beauty");
    // img->display();
    // img->display();

    // Business *b = new ProxyCMCC;
    // b->charge(10);
    // b->charge(100);
    // b->charge(200);
    // Car myCar;
    // myCar.start();
    // std::cout << "Current speed: " << myCar.getSpeed() << std::endl;
    // myCar.stop();
    //  Image * image = new ProxyImage("beauty");
    //  image->display();
    //  image->display();

    // Image *ig = new ProxyImage("beauty");
    // ig->display();
    // ig->display();
    // delete ig;

    // Business *b = new ProxyCMCC;
    // b->charge(10);
    // b->charge(100);
    // b->charge(200);

    // Image *im = new ProxyImage("beauty");
    // im->display();
    // im->display();

    // Business *b = new CMCCProxy;
    // b->charge(10);
    // b->charge(100);
    // b->charge(200);

    //  Business * cmcc = new CMCC;
    //  cmcc->charge(10);

    // Business *b = new CMCCProxy;
    // b->charge(1);
    // b->charge(60);
    // b->charge(1000);

    // Business *p = new CMCCProxy();
    // p->charge(50);
    // p->charge(100);

    // IAdaptee *ia = new oldclass;
    // ITarget *it = new Adapter(ia);
    // it->doprocess();

    // Business *b = new CMCCProxy;
    // b->charge(10);

    // IAdaptee *a = new oldclass;
    // ITarget *t = new Adapter(a);
    // t->doprocess();
    // Adaptee *a = new oldclass;
    // Target *t = new Adapter(a);
    // t->doprocess();

    // Adaptee * a = new oldclass;
    // Adapter * ap = new Target(a);
    // ap->doprocess();

    // CATString c1;
    // CATString c2("hello");
    // CATString c3(c2);
    // CATString c4;
    // c4 = c3;
    // std::cout << c1 << std::endl;
    // std::cout << c2 << std::endl;
    // std::cout << c3 << std::endl;
    // std::cout << c4 << std::endl;

    // Observer *o1 = new Observer;
    // Observer *o2 = new Observer;
    // Subject *s = new Subject(10);
    // s->addObs(o1);
    // s->addObs(o2);
    // s->changeid(2025);

    // FruitFactory *ff = new AppleFactory;
    // Fruit *f = ff->CreateFruit();
    // f->show();

    // delete f;
    // delete ff;

    // ff = new BananaFactory;
    // f = ff->CreateFruit();
    // f->show();
    // Fruit *f = SimpleFactory::CreateFruit("Apple");
    // f->show();

    // f = SimpleFactory::CreateFruit("Banana");
    // f->show();

    // f = SimpleFactory::CreateFruit("haha");
    // f->show();
    // Adaptee *a = new oldclass;
    // Target *it = new Adapter(a);
    // it->doprocess();

    // Weapon *a = new AK47;
    // Weapon *b = new Knife;
    // Person *p = new Person(a);
    // p->OnFire();

    // p->setWeapon(b);
    // p->OnFire();

    // Animal *abc = new Cat;
    // abc->show();

    // abc = new Dog;
    // abc->show();
    // CDocument *doc = new MyDoc;
    // doc->OnFileOpen();

    // Text *t = new PlaneText("abc");
    // cout << t->Render();

    // t = new DecoratorTextBold(t);
    // cout << t->Render();
    // delete t;

    // IState *state = new ConcreteStateA;
    // Context *context = new Context(state);
    // context->Request();
    // context->Request();

    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // int x = 10;
    // processFunc(v, [](int abc)
    //             { cout << 2 * abc << endl; });

    // int xyz = 2000;
    // byref(xyz);
    // cout << xyz << endl;

    // IState *state = new ConcreteStateA;
    // Context *context = new Context(state);
    // context->Request();
    // context->Request();
    // context->Request();

    // Text *text = new PlaneText("abc");
    // text = new DecortatorTextBold(text);
    // cout << text->Render() << endl;

    // vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
    // vector<future<int>> futures;

    // for (auto &task : tasks)
    // {
    //     int argument = 2000;

    //     auto f = [&task, argument]()
    //     { return task(argument); };
    //     futures.push_back(std::async(std::launch::async, [&task, argument]()
    //                                  { return task(argument); }));
    //     futures.push_back(std::async(std::launch::async, f));
    // }
    // for (size_t i = 0; i < tasks.size(); i++)
    // {
    //     int argument = i * 10;
    //     futures.push_back(std::async(std::launch::async, [&tasks, i, argument]()
    //                                  { return tasks[i](argument); }));
    // }

    // for (auto &future : futures)
    // {
    //     cout << future.get() << endl;
    // }

    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // processFunc(v, [](int x)
    //             { cout << 2 * x << endl; });

    // IState * state = new ConcreteStateA;
    // Context* context = new Context(state);g
    // context->Request();
    // context->Request();
    // context->Request();
    // Text *t = new PlaneText("hello");
    // cout << t->Render();

    // t = new DecoratorTextBold(t);
    // cout << t->Render();
    // delete t;
    // vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
    // vector<future<int>> futures;

    // int arg = 1;
    // for (auto &task : tasks)
    // {
    //     // futures.push_back(std::async(std::launch::async, [&task, arg]()
    //     //                              { return task(arg); }));

    //     auto f = [&task, arg]()
    //     {
    //         return task(arg);
    //     };
    //     futures.push_back(std::async(std::launch::async, f));
    // }

    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // for (int i = 0; i < v.size(); i++)
    // {

    //     futures.push_back(std::async(std::launch::async, [&tasks, i, &v]()
    //                                  { return tasks[i](v[i]); }));
    // }

    // for(size_t i =0; i<tasks.size(); i++)
    // {
    //     int arg = i * 10;
    //     futures.push_back(std::async(std::launch::async, [&tasks, i, arg]()
    //                                  { return tasks[i](arg); }));
    // }

    // for (auto &future : futures)
    // {
    //     cout << future.get() << endl;
    // }

    // caller c1;
    // c1.setFunc(Task);
    // c1.letRun(6, "hello");

    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // auto f = [](int x)
    // {
    //     cout << 2 * x;
    // };

    // processFunc(v, [](int x)
    //             { cout << 2 * x << endl; });

    // processFunc(v, f);

    // std::function<void()> f1 = p1;
    // f1();

    // std::function<void()> f2 = []()
    // {
    //     cout << "f2" << endl;
    // };
    // f2();

    // t t1;
    // std::function<void()> f3 = t1;
    // f3();

    // std::function<void(t &)> f4 = &t::printit;
    // f4(t1);
    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // processFunc(v, [](int x)
    //             { cout << 2 * x << endl; });

    // auto f = [](int x)
    // {
    //     cout << 2 * x << endl;1
    // };
    // processFunc(v, f);

    // int *sp = new int(10);
    // std::shared_ptr<int> sp1(sp);
    // std::shared_ptr<int> sp2(sp1);
    // std::shared_ptr<int> sp3 = sp1;
    // cout << sp1.use_count() << endl;
    // sp1.reset();
    // cout << sp1.use_count() << endl;

    // cout << *sp1 << endl;

    // IState *state = new ConcreteStateA;
    // Context *context = new Context(state);
    // context->Request();
    // context->Request();
    // context->Request();

    // Text *text = new PlaneText("hello");
    // cout << text->Render();

    // text = new DecoratorTextBold(text);
    // cout << text->Render();
    // delete text;

    // int *ptr = new int(10);
    // std::shared_ptr<int> sp(ptr);
    // std::shared_ptr<int> sp1 = make_shared<int>(20);
    // std::shared_ptr<int> sp2(sp1);
    // std::shared_ptr<int> sp3 = sp1;

    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // processFunc(v, [](int x)
    //             { cout << 2 * x << endl; });

    // std::pair<string, int> student1 = {"A", 100};
    // std::pair<string, int> student11("A11", 111);
    // auto student2 = make_pair("B", 200);
    // // auto student3
    // cout << student1.first << student1.second << endl;
    // cout << student11.first << student11.second << endl;
    // cout << student2.first << student2.second << endl;

    // std::map<string, int> gradebook;
    // gradebook.insert(student1);
    // gradebook.emplace("C", 300);
    // gradebook.insert(make_pair("B", 200));

    // for (const auto &[name, age] : gradebook)
    // {
    //     cout << name << age << endl;
    // }

    // gradebook.erase(student1);

    // for (const auto &[name, age] : gradebook)
    // {
    //     cout << name << age << endl;
    // }

    // std::map<string, int> ageMap;
    // ageMap["A"] = 100;
    // ageMap.insert({"B", 200});
    // ageMap.emplace("C", 300);

    // for (const auto &[name, age] : ageMap)
    // {
    //     cout << name << age << endl;
    // }

    // ageMap.erase("C");
    // auto it = ageMap.find("B");
    // if (it != ageMap.end())
    // {
    //     ageMap.erase(it);
    // }
    // for (const auto pair : ageMap)

    // {
    //     cout << pair.first << pair.second << endl;
    // }

    // ageMap["A"] = 1000;
    // cout << ageMap["A"];

    // std::map<string, int> ap = {{"A",1},{"B",2}};
    // for(auto [name,age]:ap)
    // {
    //     cout << name << age << endl;
    // }

    // int *ptr = new int(2000);
    // std::shared_ptr<int> sp(ptr);
    // cout << sp.use_count() << endl;

    // std::shared_ptr<int> sp1(sp);
    // cout << sp1.use_count() << endl;

    // std::shared_ptr<int> sp2 = sp1;
    // cout << sp2.use_count() << endl;

    // std::shared_ptr<int> sp3 = make_shared<int>(123);

    // int *ptr = new int(10);
    // std::shared_ptr<int> sp(ptr);
    // std::shared_ptr<int> sp1 = make_shared<int>(20);
    // cout << *sp << endl;
    // cout << *sp1 << endl;

    // using Myint = int;
    // Myint abc = 20;
    // cout << abc << endl;

    // typedef int myint;
    // myint a = 1;
    // cout << a << endl;

    // int *ptr = new int(10);
    // std::shared_ptr<int> sp(ptr);
    // // std::shared_ptr<int> sp(ptr);
    // cout << sp.use_count() << endl;

    // std::shared_ptr<int> sp1(sp);
    // cout << sp1.use_count() << endl;
    // cout << sp.use_count() << endl;

    // cout << sp.get() << endl;
    // cout << *sp.get() << endl;
    // cout << *sp << endl;
    // sp.reset();
    // cout << sp.use_count() << endl;
    // cout << *sp << endl;

    // caller c1;
    // c1.setfun(test);
    // c1.letrun(6, "hello");
    // Text *t = new PlaneText("abc");
    // cout << t->Render() << endl;
    // t = new DecoratorTextBold(t);
    // cout << t->Render();
    // delete t;

    // std::pair<string, int> student1("A", 100);
    // auto student2 = make_pair("B", 200);
    // // std::pair student3("C", 300);

    // std::map<string, int> gradebook;
    // gradebook.insert(student1);
    // gradebook.insert(make_pair("C", 300));
    // gradebook.emplace(student2);

    // for (const auto &[name, age] : gradebook)
    // {
    //     cout << name << age << endl;
    // }

    // gradebook.erase("C");
    // auto it = gradebook.find("B");
    // if (it != gradebook.end())
    // {
    //     gradebook.erase(it);
    // }

    // cout << gradebook[student1.first] << endl;
    // gradebook[student1.first] = 1000;

    // for (const auto &pair : gradebook)
    // {
    //     cout << pair.first << pair.second << endl;
    // }

    // std::map<string, int> ageMap;
    // ageMap.insert({"A", 100});
    // ageMap.emplace("B", 200);
    // ageMap.insert(make_pair("C", 300));

    // for (const auto &[name, age] : ageMap)
    // {
    //     cout << name << age << endl;
    // }

    // for (const auto &pair : ageMap)
    // {
    //     cout << pair.first << pair.second << endl;
    // }

    // ageMap.erase("C");
    // auto it = ageMap.find("B");
    // if (it != ageMap.end())
    // {
    //     ageMap.erase(it);
    // }

    // for (const auto &pair : ageMap)
    // {
    //     cout << pair.first << pair.second << endl;
    // }

    // ageMap["A"] = 1000;
    // cout << ageMap.at("A") << endl;

    // processFunc1([]()
    //              { cout << "lambda" << endl; });

    // processFunc1(f);

    // processFunc2([](int a, int b)
    //              { cout << a + b << endl; });

    // vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
    // vector<future<int>> futures;

    // for (auto &task : tasks)
    // {
    //     int argument = 100;
    //     auto bind_task = std::bind(std::ref(task), argument);
    //     futures.push_back(std::async(std::launch::async, [&task, argument]()
    //                                  { return task(argument); }));
    // // }
    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // for (int i = 0; i < 6; i++)
    // {
    //     int argument = i * 10;
    //     futures.push_back(std::async(std::launch::async, [&tasks, argument, i]()
    //                                  { return tasks[i](argument); }));
    // }

    // for (auto &f : futures)
    // {
    //     cout << f.get() << std::endl;
    // }

    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // processFunc(v, [](int x)
    //             { cout << 2 * x << endl; });

    // std::function<void()> f1 = []()
    // {
    //     cout << "lambda" << endl;
    // };
    // std::function<void()> f2 = test123;
    // f2();
    // test t1;
    // std::function<void()> f3 = t1;
    // f3();
    // vector<int> v = {1, 2, 3, 4, 5, 6};

    // processFunc3(v, [](int x)
    //              { cout << 2 * x << endl; });

    // processFunc([]()
    //             { cout << "lambda" << endl; });

    // processFunc2([](int a, int b)
    //              { cout << a + b << endl; });

    // std::pair<string, int> student1("A", 100);
    // auto student2 = make_pair("B", 200);

    // // std::pair student3("C", 300);

    // std::map<string, int> gradebook;
    // gradebook.insert(student1);
    // gradebook.insert(make_pair("B", 200));
    // gradebook.emplace("C", 300);

    // for (const auto &pair : gradebook)
    // {
    //     cout << pair.first << pair.second << endl;
    // }

    // std::map<string, int> ageMap;
    // ageMap["A"] = 100;
    // ageMap.insert({"B", 200});
    // ageMap.emplace("C", 300);

    // for (const auto &[name, age] : ageMap)
    // {
    //     cout << name << age << endl;
    // }

    // for (auto &pair : ageMap)
    // {
    //     cout << pair.first << pair.second << endl;
    // }

    // ageMap["A"] = 1000;

    // auto it = ageMap.find("C");
    // if (it != ageMap.end())
    // {
    //     ageMap.erase(it);
    //     ageMap.erase("B");
    // }
    // for (auto &pair : ageMap)
    // {
    //     cout << pair.first << pair.second << endl;
    // }

    // vector<int> v = {
    //     1,
    //     2,
    //     3,
    //     4,
    //     5,
    //     6};

    // processFun(v, [](int x)
    //            { cout << x << endl; });
    // CATString c1;
    // CATString c2("hello");
    // CATString c3(c2);
    // CATString c4;
    // c4 = c3;
    // CATString c5 = c4;

    // cout << c1 << endl;
    // cout << c2 << endl;
    // cout << c3 << endl;
    // cout << c4 << endl;
    // cout << c5 << endl;

    // test t;
    // t();

    // std::pair<string, int> student1 = {"A", 100};
    // auto student2 = std::make_pair("B", 200);
    // // std::pair student3("C", 300);

    // std::cout << student1.first << student1.second << endl;
    // std::cout << student2.first << student2.second << endl;

    // std::map<string, int> gradebook;
    // gradebook.insert(student1);
    // gradebook.insert(student2);
    // gradebook.insert(make_pair("c", 300));

    // for (const auto &[name, age] : gradebook)
    // {
    //     cout << name << age << endl;
    // }

    // for (const auto &entry : gradebook)
    // {
    //     cout << entry.first << entry.second << endl;
    // }

    // std::pair<int, int> p1(1, 1), p2(1, 2);
    // if (p1 < p2)
    // {
    //     cout << "ok";
    // }

    // auto getMinMax = [](int a, int b) -> std::pair<int, int>
    // {
    //     return (a < b) ? std::pair<int, int>(a, b) : std::pair<int, int>(b, a);
    // };

    // auto r = getMinMax(1, 2);
    // cout << r.first << r.second << endl;

    // r = getMinMax(20, 10);
    // cout << r.first << r.second << endl;

    // std::map<string, int> ageMap = {

    //     {"A", 100},
    //     {"B", 200}};
    // for (const auto &[name, age] : ageMap)
    // {
    //     cout << name << age;
    // }

    // std::map<string, int> ageMap;
    // ageMap["A"] = 100;
    // ageMap.insert({"B", 200});
    // ageMap.emplace("C", 300);

    // for (const auto &[name, age] : ageMap)
    // {
    //     cout << name << age << endl;
    // }

    // for (auto &pair : ageMap)
    // {
    //     cout << pair.first << pair.second << endl;
    // }

    // ageMap.erase("C");
    // auto it = ageMap.find("B");
    // if (it != ageMap.end())
    // {
    //     cout << it->second;
    // }

    // ageMap["A"] = 1000;

    // it = ageMap.find("B");
    // if (it != ageMap.end())
    // {
    //     ageMap.erase(it);
    // }

    // for (const auto &[name, age] : ageMap)
    // {
    //     cout << name << age << endl;
    // }

    // std::function<void()> f1 = []()
    // {
    //     cout << "lambda" << endl;
    // };
    // f1();

    // std::function<void()>
    //     f2 = test;
    // f2();

    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // processFunc(v, [](int x)
    //             { cout << x << endl; });

    // Text *text = new PlaneText("hello");
    // cout << text->Render();

    // text = new DecoratorTextBold(text);
    // cout << text->Render();

    // IState *state = new ConcreteStateA;
    // Context *context = new Context(state);
    // context->Request();
    // context->Request();
    // context->Request();

    // processFunc([]()
    //             { cout << "lamnda" << endl; });

    // processFunc2([](int x, int y)
    //              { cout << x + y << endl; });

    // vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
    // vector<future<int>> futures;

    // int x = 1;
    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // for (int i = 0; i < tasks.size(); i++)
    // {
    //     // int argument = i * 10;
    //     futures.push_back(std::async(std::launch::async, [&tasks, v, i]()
    //                                  { return tasks[i](v[i]); }));
    // }

    // for (auto &task : tasks)
    // {
    //     // futures.push_back(std::async(std::launch::async, [&task, x]()
    //     //                              { return task(x); }));

    //     auto bind_task = std::bind(task, x);
    //     futures.push_back(std::async(std::launch::async, bind_task));
    // }

    // for (auto &future : futures)
    // {
    //     std::cout << future.get() << endl;
    // }

    // caller c1;
    // c1.setfunc(Test);
    // c1.letrun(6, "hello");
    // add(1, 2);

    // add(1.1, 2.2);

    // processFun([]()
    //            { cout << "lambda" << endl; });

    // processFun2([](int a, int b)
    //             { cout << a + b << endl; });

    // int x = 100, y = 200;
    // processFun2([=](int a, int b)
    //             { cout << a + b + x + y << endl; });

    // auto f1 = printit;
    // f1();

    // auto f2 = []()
    // {
    //     cout << "f2" << endl;
    // };

    // auto f3 = test();
    // f3();

    // vector<int> v = {1, 2, 3, 4, 5, 6};

    // auto f = [](int x)
    // {
    //     cout << 2 * x << endl;
    // };
    // processFunc(v, f);
    // std::pair<string, int> student1("A", 100);
    // auto student2 = make_pair("B", 200);
    // // std::pair student3("C", 30);

    // std::map<string, int> gradebook;
    // gradebook.insert(student1);
    // gradebook.insert(make_pair("B", 200));

    // for (const auto &pair : gradebook)
    // {
    //     cout << pair.first << pair.second << endl;
    // }

    // for (const auto &[name, id] : gradebook)
    // {

    //     cout << name << id << endl;
    // }

    // std::pair<int, int> point1(1, 2), point2(1, 3);
    // if (point1 < point2)
    // {
    //     cout << "ok" << endl;
    // }

    // auto getMinMax = [](int a, int b)
    // {
    //     return (a < b) ? std::pair<int, int>(a, b) : std::pair<int, int>(b, a);
    // };

    // auto f = getMinMax(2,1);
    // cout << f.first << f.second << endl;

    // std::map<string, int> ageMap = {

    //     {"A", 10},
    //     {"B", 20}
    // };

    // for(const auto&pair: ageMap)
    // {
    //     cout << pair.first << pair.second;
    // }

    // std::map<string, int> ageMap;
    // ageMap["A"] = 10;
    // ageMap.insert({"B", 20});
    // ageMap.emplace("C", 30);

    // for (const auto &pair : ageMap)
    // {
    //     cout << pair.first << pair.second << endl;
    // }

    // ageMap["test"] = 1000;
    // cout << ageMap.at("test");

    // ageMap.erase("test");
    // auto it = ageMap.find("A");
    // if(it!=ageMap.end())
    // {
    //     cout << it->second << endl;
    // }

    // for(const auto&[name,id]:ageMap)
    // {
    //     cout << name << id << endl;
    // }

    // std::map<string, int> ageMap;
    // ageMap["A"] = 100;
    // ageMap.insert({"B", 200});

    // std::pair<string, int> p1("p1", 1);
    // ageMap.insert(p1);

    // std::pair<string, int> student1("A", 1);
    // auto student2 = make_pair("B", 2);
    // std::pair<string, int> student3("C", 3);

    // std::map<string, int> gradebook;
    // gradebook.insert(student1);
    // gradebook.insert(student2);
    // gradebook.insert(make_pair("C", 3));

    // for (const auto &[name, id] : gradebook)
    // {
    //     cout << name << id << endl;
    // }

    // student1.second = 100;

    // std::map<string, int> ageMap;
    // ageMap["A"] = 100;
    // ageMap.insert({"B", 200});
    // ageMap.emplace("C", 300);

    // for (const auto &pair : ageMap)
    // {
    //     cout << pair.first << pair.second << endl;
    // }

    // for (const auto &[name, id] : ageMap)
    // {
    //     cout << name << id << endl;
    // }

    // auto it = ageMap.find("A");
    // if (it != ageMap.end())
    // {
    //     cout << it->second << endl;
    // }

    // ageMap.erase("B");
    // ageMap.erase(it);
    // ageMap["C"] = 2000;

    // for (auto &pair : ageMap)
    // {
    //     cout << pair.first << pair.second;
    // }

    // std::pair<string, int> student("A", 100);
    // auto student2 = make_pair("B", 200);
    // // std::pair student3("B", 300);

    // cout << student2.first << student.second << endl;

    // std::map<string, int> gradebook;
    // gradebook.insert(student2);

    // gradebook.insert(student);
    // gradebook.insert(make_pair("D", 400));

    // for (const auto &[name, id] : gradebook)
    // {
    //     cout << name << id << endl;
    // }

    // for (const auto &pair : gradebook)
    // {
    //     cout << pair.first << pair.second << endl;
    // }

    // std::pair<int, int> point1(1, 2), point2(1, 3);

    // if (point1 < point2)
    // {
    //     cout << "ok" << endl;
    // }

    // auto getMinMax = [](int a, int b)
    // {
    //     return (a < b) ? std::pair<int, int>(a, b) : std::pair<int, int>(b, a);
    // };

    // auto f = getMinMax(2, 1);
    // cout << f.first << f.second << endl;

    // cout << getMinMax(2, 1);

    // std::map<string, int> ageMap;
    // ageMap["A"] = 100;
    // ageMap.insert({"B", 200});
    // ageMap.emplace("C", 300);

    // for (const auto &pair : ageMap)
    // {
    //     cout << pair.first << pair.second << endl;
    // }

    // auto it = ageMap.find("C");
    // if (it != ageMap.end())
    // {
    //     cout << it->second;
    // }

    // ageMap["A"] = 1000;

    // ageMap.erase("A");

    // it = ageMap.find("C");
    // if (it != ageMap.end())
    // {
    //     ageMap.erase(it);
    // }

    // for (const auto &[name, id] : ageMap)
    // {
    //     cout << name << id;
    // }
    // for (const auto &pair : ageMap)
    // {
    //     cout << pair.first << pair.second;
    // }

    // vector<int> v = {1, 2, 3, 4, 5, 6};

    // for (auto i : v)
    // {

    //     cout << "------" << endl;
    //     if (i > 5)
    //     {
    //         cout << "i>5" << endl;
    //         break;
    //         cout << "after break" << endl;
    //     }
    // }
    // cout << "after for" << endl; //
    // std::pair<string, int> student1("A", 100);
    // auto student2 = make_pair("B", 200);
    // // std::pair student3("C", 300);

    // cout << student1.first << student1.second << endl;

    // cout << "loop..........." << endl;

    // std::map<string, int> gradebook;
    // gradebook.insert(student1);
    // gradebook.insert(student2);
    // gradebook.insert(make_pair("student3", 300));

    // for (const auto &st : gradebook)
    // {
    //     cout << st.first << st.second << endl;
    // }

    // std::pair<int, int> p1(1, 1), p2(1, 2);
    // if (p1 < p2)
    // {
    //     cout << "yes" << endl;
    // }

    // auto getMinMax = [](int a, int b) -> std::pair<int, int>
    // { return (a < b) ? pair(a, b) : std::pair(b, a); };

    // int a = 1;
    // int b = 2;
    // auto c = return (a < b) ? a : b;
    //}

    // for (const auto &[name, int] : gradebook)
    // {
    // }
    // std::map<string, int> ageMap;
    // ageMap["A"] = 1;
    // ageMap.insert({"B", 2});
    // ageMap.emplace("C", 3);

    // for (const auto &x : ageMap)
    // {
    //     cout << x.first << x.second << endl;
    // }

    // cout << "A" << ageMap["A"];
    // auto it = ageMap.find("B");
    // if (it != ageMap.end())
    // {
    //     cout << it->second << endl;
    // }

    // ageMap["A"] = 100;
    // cout << ageMap.at("A");

    // ageMap.erase("C");

    // it = ageMap.find("C");
    // if (it != ageMap.end())
    // {
    //     ageMap.erase(it);
    // }

    // cout << "loop" << endl;
    // for (const auto &[name, age] : ageMap)
    // {
    //     cout << name << age << endl;
    // }
    // for (const auto &map : ageMap)
    // {
    //     cout << map.first << map.second << endl;
    // }

    // std::pair<string, int> student1("A", 100);
    // auto student2 = make_pair("B", 1);
    // std::pair student3("C", 1);

    // vector<int> v = {1, 2, 3, 4, 5, 6};

    // auto f = processFunc(v, [](int x)
    //                      { cout << 2 * x; });
    // f(2000);

    // processfunc1([](int x, int y)
    //              { cout << x + y << endl; });

    // processFunc([]()
    //             { cout << "lambda" << endl; });
    // std::function<void()> f1 = []()
    // {
    //     cout << "f1" << endl;
    // };
    // f1();
    // std::function<void()> f2 = print111;
    // f2();

    // std::function<void()> f3 = print123();
    // f3();
    // IState *state = new ConcreteStateA;
    // Context *context = new Context(state);
    // context->Request();
    // context->Request();
    // context->Request();

    // Text *text = new PlaneText("abc");
    // cout << text->Render();

    // text = new DecortatorTextBold(text);
    // cout << text->Render();

    // vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};

    // vector<future<int>> futures;

    // vector<int> arguments = {1, 2, 3, 4, 5, 6};

    // for (int i = 0; i < tasks.size(); i++)
    // {
    //     futures.push_back(std::async(std::launch::async, [&tasks, i, arguments]()
    //                                  { return tasks[i](arguments[i]); }));

    // int argument = i * 10;
    //  futures.push_back(std::async(std::launch::async, [&tasks, i, argument]()
    //                               { return tasks[i](argument); }));
    // }

    // int argument = 1;
    // for (auto &task : tasks)
    //{

    // auto bind_task = std::bind(task, argument);
    // futures.push_back(std::async(std::launch::async, [&task, argument]()
    //                              { return task(argument); }));
    // futures.push_back(std::async(std::launch::async, bind_task));
    //}

    // for (auto &future : futures)
    // {
    //     cout << future.get() << endl;
    // }

    // auto bind_task = std::bind(std::ref(printMessage), "Hello", std::placeholders::_1);
    // std::function<void(int)> f1 = bind_task;
    // f1(2000);

    // std::function<void()> f1 = []()
    // {
    //     cout << "lambda" << endl;
    // };

    // vector<int> v = {1, 2, 3, 4, 5, 6};

    // std::function<void(int)> f2 = [](int x)
    // { cout << 2 * x << endl; };

    // processFunc(v, f2);

    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // processFunc(v, [](int x)
    //             { cout << 2 * x << endl; });
    // size_t count = 0;
    // while (1)
    // {
    //     cout << count << endl;
    //     return count++ < 10;
    //     };
    // cout << count << endl;

    // vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
    // vector<future<int>> futures;

    // vector<int> arguments = {1, 2, 3, 4, 5, 6};

    // for (auto i = 0; i < tasks.size(); i++)
    // {

    //     futures.push_back(std::async(std::launch::async, [&tasks, i, arguments]()
    //                                  { return tasks[1](arguments[i]); }));
    // }

    // int argument = 1;
    // for (int i = 0; i < tasks.size(); i++)
    // {
    //     futures.push_back(std::async(std::launch::async, [&tasks, i]
    //                                  { return tasks[i](i); }));
    // }
    // for (auto &x : tasks)
    //{
    //  futures.push_back(std::async(std::launch::async, [&x, argument]() -> int
    //                               { return x(argument); }));
    //  auto bind_task = std::bind(std::ref(x), argument);
    //  futures.push_back(std::async(std::launch::async, bind_task));
    //}

    // for (auto &f : futures)
    // {
    //     cout << f.get() << endl;
    // }
    // caller c1;
    // c1.setfunc(test);
    // c1.letrun(6, "hello");

    // processFunc2([](int a, int b)
    //              { cout << a + b << endl; });

    // int x = 10;
    // int y = 10;
    // processFunc2([=](int a, int b)
    //              { cout << a + b + x + y << endl; });

    // processFunc([]()
    //             { cout << "lambda" << endl; });

    // auto bind_task = std::bind(printmessage, "hello", std::placeholders::_1);
    // std::function<void(int)> f4 = bind_task;
    // f4(2025);

    // std::function<void()> f3 = top();
    // f3();

    // std::function<void()> f1 = print123;
    // f1();

    // std::function<void()> f2 = []()
    // {
    //     cout << "f2" << endl;
    // };
    // f2();

    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // processFunc(v, [](int x)
    //             { cout << 2 * x << endl; });

    // int argument = 1;
    // auto bind_task = std::bind(addit, argument);
    // bind_task(2000);
    // auto bind_task = std::bind(printMessage, "hello", std::placeholders::_1);
    // std::function<void(int)> fb = bind_task;
    // fb(100);

    // auto bind_task = std::bind(printHello, "Hello", std::placeholders);
    // std::function<void(int)> func = printHello;
    // func(42); // 输出 Hello: 42

    // auto printHello = std::bind(printMessage, "Hello", std::placeholders::_1);
    // std::function<void(int)> func = printHello;
    // func(42); // 输出 Hello: 42

    // std::function<int(int, int)>
    //     f00 = add2;
    // cout << f00(100, 100) << endl;

    // std::function<void()> f0 = obj();
    // f0();

    // std::function<void()> f = printstr;
    // f();

    // std::function<void()> f1 = []()
    // {
    //     cout << "lambda" << endl;
    // };

    // processFunc2([](int x, int y)
    //              { cout << x + y << endl; });

    // processFun([]()
    //            { cout << "lamnda" << endl; });
    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // processFunc(v, [](int x)
    //             { cout << 2 * x << endl; });

    // int x = 10;
    // int y = 10;
    // processfunc2([=](int a, int b)
    //              { cout << a + b + x + y << endl; });

    // processfunc([]()
    //             { cout << "lambda" << endl; });
    // processfunc2([](int x, int y)
    //              { cout << x + y << endl; });

    //  vector<int> v = {1, 2, 3, 4, 5, 6};
    //  processFunc(v, [](int x)
    //              { cout << 2 * x; });

    // cout
    //     << processFun2([](int a, int b)
    //                    { return a + b; });

    // processFun([]()
    //            { cout << "lambda" << endl; });

    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // processFunc(v, [](int x)
    //             { cout << 2 * x << endl; });

    // IState *state = new ConcreateStateA;
    // Context *context = new Context(state);
    // context->Request();
    // context->Request();

    // Text *text = new PlaneText("abc");
    // cout << text->Render();

    // text = new DecoratorBold(text);
    // cout << text->Render();

    //     adder a1;
    //     // a1();

    //     auto f = [&a1]()
    //     {
    //         return a1;
    //     };

    //     f();

    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // processFunc(v, [](int x)
    //             { cout << 2 * x; });

    // int a = 1;
    // int b = 2;

    // cout << a << endl;
    // cout << b << endl;

    // // swap1(a, b);
    // swap2(&a, &b);
    // cout << a << endl;
    // cout << b << endl;
    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // processFun(v, [](int x)
    //            { cout << 2 * x << endl; });

    // std::function<int(int, int)> f1 = addit;
    // cout << f1(1, 1) << endl;

    // std::function<void()> f2 = []()
    // {
    //     cout << "f2" << endl;
    // };

    // f2();

    // std::function<void(int, int)> f3 = std::bind(addit, x, y);

    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // processFunc(v, [](int x)
    //             { cout << x + 1 << endl; });

    // vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
    // vector<future<int>> futures;

    // int arg = 1;
    //  for (auto &task : tasks)
    //  {
    //      auto bound_task = std::bind(std::ref(task), arg);
    //      futures.push_back(std::async(std::launch::async, bound_task));
    //  }
    // vector<int> args = {1, 2, 3, 4, 5, 6};
    // for (int i = 0; i < tasks.size(); i++)
    // {
    //     // int arg = i * 10;
    //     // futures.push_back(std::async(std::launch::async, [&tasks, i, arg]()
    //     //                              { return tasks[i](arg); }));
    //     futures.push_back(std::async(std::launch::async, [&tasks, i, args]()
    //                                  { return tasks[i](args[i]); }));
    // }

    // for (auto &future : futures)
    // {
    //     cout << future.get() << endl;
    // }

    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // processfunc(v, [](int x)
    //             { cout << 2 * x << endl; });

    // adder a1;
    // cout << a1();

    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // processFunc(v, [](int x)
    //             { cout << 2 * x << endl; });

    // std::function<void(const Foo &, int)> f0 = &Foo::print_num;
    // const Foo foo(2000);
    // f0(foo, 1);
    // std::function<void(const Foo &, int)> f_add_display = &Foo::print_add;
    // const Foo foo(314159);
    // f_add_display(foo, 1);

    // std::function<void(int)> f = print_num;
    // f(1);

    // std::function<void()> f1 = []()
    // { return print_num(2); };
    // f1();

    // std::function<void()> f2 = std::bind(print_num, 3);
    // f2();

    // processFunc([]()
    //             { cout << "lambda" << endl; });

    // IState *state = new ConcreteStateA;
    // Context *context = new Context(state);
    // context->Request();
    // context->Request();
    // context->Request();

    // Text *text = new PlaneText("helo");
    // text = new DecoratorTextBold(text);
    // cout << text->Render();
    // vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
    // vector<future<int>> futures;

    // // int arg = 1;

    // // for (auto &task : tasks)
    // // {
    // //     auto bind_task = std::bind(std::ref(task), arg);
    // //     futures.push_back(std::async(std::launch::async, bind_task));
    // // }

    // vector<int> args = {1, 2, 3, 4, 5, 6};
    // for (int i = 0; i < tasks.size(); i++)
    // {
    //     futures.push_back(std::async(std::launch::async, [&tasks, i, &args]()
    //                                  { return tasks[i](args[i]); }));
    // }

    // for (auto &future : futures)
    // {
    //     cout << future.get() << endl;
    // }

    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // processFunc(v, [](int x)
    //             { cout << x + 1 << endl; });

    // CATString c1;
    // CATString c2("hello");
    // CATString c3(c2);
    // CATString c4;
    // c4 = c3;
    // cout << c1 << endl;
    // cout << c2 << endl;
    // cout << c3 << endl;
    // cout << c4 << endl;

    // int a = addT(1, 1);
    // cout << a << endl;

    // double b = addT(1.1, 1.1);
    // {
    //     cout << b << endl;
    // }
    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // process(v, [](int x)
    //         { cout << x + 1 << endl; });

    // int a = 1;
    // int b = 1;
    // auto r1 = processFunc([=]()
    //                       { return a + b; });
    // cout << r1 << endl;

    // auto r2 = processFuncNew([](int x, int y)
    //                          { return x + y; });
    // cout << r2 << endl;

    // vector<double> v = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};

    // processFunc(v, [](double x)
    //             { cout << x + 1 << endl; });

    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // processFunc(v, [](int x)
    //             { cout << x + 1 << endl; });

    // vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
    // vector<future<int>> futures;

    // for (auto &task : tasks)
    // {
    //     int arg = 1;
    //     auto bind_task = std::bind(std::ref(task), arg);
    //     futures.push_back(std::async(std::launch::async, bind_task));
    // }
    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // for (int i = 0; i < tasks.size(); i++)
    // {
    //     int arg = i * 10;
    //     futures.push_back(std::async(std::launch::async, [&tasks, i, arg]()
    //                                  { return tasks[i](arg); }));
    // }

    // for (auto &future : futures)
    // {
    //     cout << future.get() << endl;
    // }

    // Caller c1;
    // c1.setFunc(Test);
    // c1.letRun(6, "hello");
    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // processFunc(v, [](int x)
    //             { cout << 2 * x; });

    // // auto f = processFunc([](int a, int b) -> int
    // //                      { return a + b; });

    // auto f1 = processFunc([](int a, int b) -> int
    //                       { return a + b; });
    // cout << f1() << endl;

    // cout << f() << endl;
    //  int a = 3;
    //  int b = 3;
    //  auto r1 = processFunc1([=]()
    //                         { return a + b; });
    //  cout << r1 << endl;

    // auto r2 = processFunc2([](int x, int y)
    //                        { return x + y; });
    // cout << r2 << endl;

    // processFunc([]()
    //             { cout << "call"; });

    //     std::vector<std::future<int>> futures;

    //     // Launch multiple tasks
    //     for (int i = 0; i < 5; ++i)
    //     {
    //         futures.push_back(std::async(std::launch::async, task, i));
    //     }

    //     // Get results later
    //     for (auto &f : futures)
    //     {
    //         std::cout << f.get() << std::endl;
    //     }

    // vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
    // vector<future<int>> futures;

    // int arg = 1;

    // for (auto &task : tasks)
    // {
    //     auto bind_task = std::bind(std::ref(task), arg);
    //     futures.push_back(std::async(std::launch::async, bind_task));
    // }

    // for (auto &task : tasks)
    // {
    //     futures.push_back(std::async(std::launch::async, [&task, arg]()
    //                                  { return task(arg); }));
    // // }
    // vector<int> args = {1, 2, 3, 4, 5, 6};
    // for (int i = 0; i < tasks.size(); i++)
    // {
    //     futures.push_back(std::async(std::launch::async, [&tasks, i, &args]
    //                                  { return tasks[i](args[i]); }));
    // // }

    // for (int i = 0; i < tasks.size(); i++)
    // {
    //     int arg = i * 10;
    //     futures.push_back(std::async(std::launch::async, [&tasks, i, arg]()
    //                                  { return tasks[i](arg); }));
    // }

    // for (auto &future : futures)
    // {
    //     cout << future.get() << endl;
    // }

    // vector<Task> tasks = {Task(1),
    //                       Task(2),
    //                       Task(3),
    //                       Task(4),
    //                       Task(5),
    //                       Task(6)};
    // vector<future<int>> futures;
    // // int arg = 1;

    // vector<int> args = {1, 2, 3, 4, 5, 6};
    // for (int i = 0; i < tasks.size(); i++)
    // {
    //     int arg = i * 10;
    //     futures.push_back(std::async(std::launch::async, [&tasks, i, arg]()
    //                                  { return tasks[i](arg); }));
    // }

    // for (auto &task : tasks)
    // {
    //     futures.push_back(std::async(std::launch::async, ))
    //     // futures.push_back(std::async(std::launch::async, [&task, arg]()
    //     //{ return task(arg); }));
    //     //auto bind_task = std::bind(std::ref(task), arg);
    //     //futures.push_back(std::async(std::launch::async, bind_task));
    // }

    // for (auto &future : futures)
    // {
    //     cout << future.get() << std::endl;
    // }
    // adder a1;
    // cout << a1(1, 1) << endl;
    // vector<int> v = {1, 2, 3};
    // processFunc(v, [](int x)
    //             { cout << x + 1 << endl; });

    // vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
    // vector<future<int>> futures;
    // int argument = 1;

    // for (auto &task : tasks)
    // {
    //     futures.push_back(std::async(std::launch::async, [&task, argument]()
    //                                  { return task(argument); }));
    // }
    // for (auto &future : futures)
    // {
    //     cout << future.get() << endl;
    // }

    //     adder it;
    //     cout << it(1, 1) << endl;
    // caller c1;
    // c1.setfunc(test);
    // c1.letrun(6, "hello");

    // vector<int> v = {1, 2, 3, 4, 5, 6};
    // processit(v, [](int x)
    //           { cout << x * 2; });

    // cout << processFunc1([](int a, int b)
    //                      { return a + b; });

    // processFunc([]()
    //             { cout << "lambda here"; });
    // adder a1;
    // cout << a1(1, 1) << endl;
    // IState *state = new ConcreteStateA;
    // Context *context = new Context(state);
    // context->Request();
    // context->Request();
    // context->Request();

    // Text *t = new PlaneText("top");
    // t = new DecoratorTextBold(t);
    // cout << t->Render();
    // Multiple m1(5);
    // cout << m1(10) << endl;

    // Adder a1;
    // cout << a1(1, 1) << endl;

    // Counter count;
    // cout << count() << endl;
    // cout << count() << endl;
    // vector<int> v = {1, 2, 3};
    // processFunc(v, [](int n)
    //             { cout << n * 2; });

    // return 0;
    // std::function<int(int, int)>
    //     f = addint;
    // cout << f(1, 1);

    // std::function<int(int, int)> f1 = [](int x, int y)
    // { return x + y; };
    // cout << f1(1, 2);

    // int num[] = {1, 2, 3};
    // vector<int> vec(num, num + sizeof(num) / sizeof(num[0]));

    // for (auto &x : vec)
    // {
    //     cout << x << endl;
    // }
    // printvector(vec);
    // sort(vec.begin(), vec.end(), [](int x, int y)
    //      { return x > y; });

    // for (auto &x : vec)
    // {
    //     cout << x << endl;
    // }
    // printvector(vec);

    // return 0;

    // int a = 1;
    // int b = 1;
    // auto r1 = processFunc([=]() -> int
    //                       { return a + b; });
    // cout << r1 << endl;

    // auto r2 = processFuncwithparams([](int a, int b)
    //                                 { return a + b; });
    // cout << r2 << endl;

    // auto r3 = processFuncwithparams([=](int x, int y)
    //                                 { return a + b + x + y; });
    // cout << r3 << endl;
    // // int a = 1;
    // int b = 1;
    // processFunc([=]() -> int
    //             { return a + b; });
    // int a = 42;

    // auto f = [a]()
    // {
    //     return a;
    // };

    // a = 0;
    // auto b = f();
    // cout << b << endl;

    // cout << callback([](int a, int b) -> int
    //                  { return a + b; });

    // processFunc([]()
    //             { cout << "this is a lambda" << endl; });
    // preocesFunc([]()
    //             { cout << "haha"; });
    // /func(a, b);
    // processFunc([]()
    //             { cout << "this is a lambda" << endl; });

    //     vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
    //     vector<future<int>> futures;

    //     for (auto &task : tasks)
    //     {
    //         futures.push_back(std::async(std::launch::async, task));
    //     }
    //     for(auto & future: futures)
    //     {
    //         cout << future.get() << std::endl;
    //     }
    //  caller c1;
    //  c1.setfunc(Test);
    //  c1.letrun(6, "hello");

    // int a = callback([](int a, int b) -> int
    //                  { return a + b; });
    // cout << a << endl;

    // int a = 1;
    // int b = 1;
    // auto func = [](int x, int y) -> int
    // { return x + y; };

    // cout << func(a, b) << endl;

    // int z = [](int x, int y) -> int
    // { return x + y; }(a, b);
    // cout << z << endl;
    // IState *state = new ConcreteStateA;
    // Context *context = new Context(state);
    // context->Request();
    // context->Request();
    // context->Request();

    // Text *text = new PlaneText("hello");
    // text = new DecortatorTextBold(text);
    // cout << text->Render();

    // int a = 1;
    // int b = 2;
    // auto f = [](int x, int y) -> int
    // { return x + y; };

    // cout << f(a, b) << endl;

    // int z = [](int x, int y) -> int
    // { return x + y; }(a, b);
    // cout << z << endl;
    // IState *state = new ConcreteStateA;
    // Context *context = new Context(state);

    // context->Request();
    // context->Request();
    // context->Request();

    // Text *text = new PlaneText("abc");
    // cout << text->Render() << endl;

    // text = new DecoratorTextBold(text);
    // cout << text->Render() << endl;

    // text = new DecoratorTextUnderline(text);
    // cout << text->Render() << endl;

    // vector<string> t;
    // string abc = "hello";
    // t.push_back(abc);
    // cout << t[0] << endl;

    // t.push_back(std::move(abc));
    // std::cout << abc << std::endl;

    // cout << t[0] << endl;
    // cout << t[1] << endl;

    // IState *state = new ConcreteStateA;
    // Context *context = new Context(state);
    // context->Request();
    // context->Request();
    // context->Request();

    // Text *text = new PlaneText("abc");
    // cout << text->Render();

    // text = new DecoratorTextBold(text);
    // cout << text->Render();

    // text = new DecoratorTextUnderline(text);
    // cout << text->Render();

    // vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
    // vector<future<int>> futures;

    // for (auto &task : tasks)
    // {
    //     futures.push_back(std::async(std::launch::async, task));
    // }

    // for (auto &future : futures)
    // {
    //     std::cout << future.get() << std::endl;
    // }
    // Caller c1;
    // c1.setfunc(Test);
    // c1.letrun(6, "hello");

    // IState *state = new ConcreteStateA;
    // Context *context = new Context(state);
    // context->Request();
    // context->Request();

    // int a = 1;
    // int b = 2;
    // int c = [=](int x, int y) -> int
    // { return x + y; }(a, b);

    // auto f = [](int x, int y) -> int
    // { return x + y; };

    // int d = f(a, b);
    // cout << d << endl;

    // Text *text = new PlaneText("top");
    // cout << text->Render();

    // text = new DecoratorTextBold(text);
    // cout << text->Render();

    // text = new DecoratorTextUnderline(text);
    // cout << text->Render();

    // int a = 1, b = 2;
    // int z = [](int x, int y) -> int
    // { return x + y; }(a, b);

    // std::cout << z << std::endl;

    // foo();

    // Text *text = new PlaneText("top");
    // cout << text->Render();

    // text = new DecoratorTextBold(text);
    // text = new DecoratorTextUnderline(text);
    // cout << text->Render();

    // IState *is = new ConcreteStateA;
    // Context *context = new Context(is);
    // context->Request();
    // context->Request();

    // Text *text = new PlaneText("top");
    // cout << text->Render();

    // text = new DecoratorTextBold(text);
    // text = new DecoratorTextUnderline(text);
    // cout << text->Render();

    // Text *text = new PlaneText("abc");
    // std::cout << text->Render();

    // text = new DecoratorTextBold(text);
    // std::cout << text->Render();

    // IState *is = new ConcreStateA;
    // Context *context = new Context(is);
    // context->Request();
    // context->Request();

    // component *c = new concretecomponentA;
    // c->operation();

    // concreteDecoratorE obje;
    // obje.setcomponent(c);
    // obje.addBehavior();

    // Text *t = new PlaneText("apple");
    // cout << t->render();
    // DecoratorText *tt = new DecoratorTextBold(t);
    // cout << tt->render();

    // Text *t = new PlaneText("apple");
    // std::cout << t->render();

    // DecoratorText *tt = new DecoratortextBold(t);
    // std::cout << tt->render();

    // IState *state = new ConcreteStateA;
    // Context *context = new Context(state);
    // context->Request();
    // context->Request();
    // context->Request();

    // Text *text = new PlaneText("apple");
    // cout << text->render();

    // text = new DecoratorTextBold(text);
    // cout << text->render();

    // IState *state = new ConcreteStateA;
    // Context *context = new Context(state);
    // context->Request();
    // context->Request();
    // context->Request();

    // Text *text = new PlaneText("apple");
    // text = new DecoratorTextBold(text);
    // cout << text->render() << endl;

    // IState *st = new ConreteStateA;
    // Context *con = new Context(st);
    // con->Request();
    // con->Request();

    // Text *text = new PlaneText("apple");
    // text = new DecoratorTextBold(text);
    // cout << text->render() << endl;

    // Text *text = new PlaneText("apple");
    // text = new DecoratorTextBold(text);
    // std::cout << text->render() << std::endl;
    // Text *test = new PlaneText("hello");
    // cout << test->render() << endl;
    // IState *state = new ConcreteStateA();
    // Context *context = new Context(state);
    // context->Request();
    // context->Request();

    // Text *text = new PlaneText("Apple");
    // text = new DecorateTextBold(text);
    // text = new DecorateTextUnderline(text);
    // cout << text->render() << endl;

    // std::cout << 123 << std::endl;
    //  IAdaptee *it = new oldclass;
    //  ITarget *target = new Adapter(it);
    //  target->process();

    // IState *state = new ConcreteStateA();
    // Context *context = new Context(state);
    // context->Request();
    // context->Request();
    // context->Request();

    // Text *text = new planeText("hello");
    // std::cout << text->render() << std::endl;
    // text = new DecoratorTextBold(text);
    // std::cout << text->render() << std::endl;

    // Text *text = new PlaneText("hello");
    // text = new DecoratortextOnBold(text);
    // std::cout << text->render();

    // Text *t = new Decoratortext;

    // Text *text = new PlainText("hello");
    // text = new DecoratorTextBold(text);
    // text = new DecoratorTextUnderline(text);
    // std::cout << text->render() << std::endl;

    // delete text;

    // singleton *lazy = singleton::getInstance();
    // lazy->show();

    // singleton *lazynew = singleton::getInstance();
    // lazynew->show();

    // std::cout << lazy << std::endl;
    // std::cout << lazynew << std::endl;

    // singleton *one = singleton::getInstance();
    // one->show();

    // singleton *two = singleton::getInstance();
    // two->show();

    // std::cout << one << std::endl;
    // std::cout << two << std::endl;
    // Fruit *f = SimpleFactory::CreateFruit("Apple");
    // std::cout << f << std::endl;
    // f->show();

    // f = SimpleFactory::CreateFruit("Banana");
    // f->show();

    // FruitFactory *ff = new AppleFactory();
    // Fruit *f = ff->CreateFruit();
    // f->show();

    // delete ff;
    // ff = new BananaFactory();
    // f = ff->CreateFruit();
    // f->show();

    // weapon *w1 = new ak47;
    // weapon *w2 = new knife;
    // character c;
    // c.setWeapon(w1);
    // c.onFire();

    // c.setWeapon(w2);
    // c.onFire();

    // component *root = new composite("root");
    // component *node1 = new composite("node1");
    // component *node2 = new composite("node2");
    // component *leaf1 = new leaf("leaf1");
    // component *leaf2 = new leaf("leaf2");

    // root->addNode(node1);
    // root->addNode(node2);
    // node1->addNode(leaf1);
    // node1->addNode(leaf2);
    // root->process();

    // CDocument *cd = new myDocument();
    // cd->onFileOpen();

    // IState *state = new ConcreteStateA();
    // Context *context = new Context(state);
    // context->Request();
    // context->Request();
    // context->Request();

    // Business *business = new CMCCProxy;
    // business->charge(1);
    // business->charge(200);
    // Adaptee *ada = new oldclass;
    // ITarget *a = new Adapter(ada);
    // a->process();
    // IState *st = new ConcreteStateA;
    // Context *c = new Context(st);
    // c->request();
    // c->request();
    // c->request();

    // IState *state = new ConcreteStateA;
    // Context *context = new Context(state);
    // context->Request();
    // context->Request();
    // context->Request();

    // vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
    // vector<future<int>> futures;

    // for (auto &task : tasks)
    // {
    //     futures.push_back(std::async(std::launch::async, task));
    // }
    // for (auto &future : futures)
    // {
    //     std::cout << future.get() << std::endl;
    // }

    // caller c1;
    // c1.setfunc(test);
    // c1.letrun(6, "hello");

    // CATString c1;
    // CATString c2("hello");
    // CATString c3(c2);
    // CATString c4;
    // c4 = c3;
    // std::cout << c1 << std::endl;
    // std::cout << c2 << std::endl;
    // std::cout << c3 << std::endl;
    // std::cout << c4 << std::endl;

    // Iadaptee *adaptee = new oldclass;
    // ITarget *target = new Adapter(adaptee);
    // target->process();

    // Business *abc = new CMCCProxy;
    // abc->charge(1);
    // abc->charge(200);

    // Context *context = new Context(new ConcreteStateA);
    // context->Request();
    // context->Request();
    // context->Request();
    // // CDocument *doc = new MyDoc;
    // doc->OnFileOpen();

    // int a = 1;
    // int &b = a;
    // std::cout << &a << std::endl;
    // std::cout << &b << std::endl;

    // int n = 10000;
    // int i = 0;

    // // Declare an array of pointers to integers
    // int **p = new int *[n];

    // // Loop to allocate memory for each element
    // while (1)
    // {
    //     for (i = 0; i < n; ++i)
    //     {
    //         p[i] = new int[10000]; // Allocate memory for an array of 10000 integers
    //         std::cout << "p[" << i << "][0] = " << p[i][0] << std::endl;
    //         // if (i == 3333)
    //         // {
    //         //     std::this_thread::sleep_for(std::chrono::seconds(100));
    //         // }
    //     }
    // }

    // // Example usage: Initialize the first element of each allocated array
    // for (i = 0; i < n; ++i)
    // {
    //     p[i][0] = i; // Initialize the first element with the index value
    //     std::cout << "p[" << i << "][0] = " << p[i][0] << std::endl;
    // }

    // int n = 10000;
    // int i = 0;
    // string p = "pointer";
    // for (int i = 0; i < n; i++)
    // {
    //     string x = p + to_string(i);
    //     cout << x << std::endl;
    //     // int *x = new int[10000];
    //     // std::this_thread::sleep_for(std::chrono::milliseconds(1));
    // }
    // Business *business = new CMCCProxy;
    // business->charge(10);
    // business->charge(100);

    // Iadaptee *adaptee = new oldclass;
    // ITarget *ada = new Adapter(adaptee);
    // ada->process();
    // Context *context = new Context(new ConcreteStateA());
    // context->Request();
    // context->Request();
    // context->Request();

    // FruitFactory *ff = new AppleFactory;
    // Fruit *f = ff->createFruit();
    // f->show();
    // Fruit *f = simpleFactory::CreateFruit("Apple");
    // f->show();
    // shape *cir = new circle;
    // // shapeDecorator *decorator = new shapeDecorator(cir);
    // // decorator->draw();

    // shapeDecorator *add123 = new shapeDecoratorAdd123(cir);
    // add123->draw();

    // IState *state = new ConcreteStateA;
    // Context *context = new Context(state);
    // context->Request();
    // context->Request();
    // context->Request();

    // IState *A = new ConcreteStateA;
    // Context *context = new Context(A);
    // context->Request();
    // context->Request();
    // context->Request();

    // IAdaptee *adaptee = new oldclass;
    // ITarget *adapter = new Adapter(adaptee);
    // adapter->process();
    // char st[] = "hello world";
    // char st1[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    // cout << st << endl;
    // cout << st1 << endl;
    // SplitFactory *factor = new FileSplitFactory;
    // Form *f = new Form(factor);
    // f->click();

    // ISplit *splitter = new BinarySplit;
    // splitter->split();
    // SplitFactory *factory = new FileSplitFactory;
    // ISplit *splitter = factory->createsplit();
    // splitter->split();

    // Fruit *p = simpleFactory::createFruit("Apple");
    // p->show();
    // singleton *p = singleton::getInstance();
    // p->show();

    // hungrysingleton *hp = hungrysingleton::getInstance();
    // hp->show();

    // test11();
    //  Iadaptee *ada = new oldclass;
    //  ITarget *it = new Adapter(ada);
    //  it->process();
    //  vector<Task> tasks = {Task(1), Task(2), Task(3), Task(4), Task(5), Task(6)};
    //  vector<future<int>> futures;
    //  for (auto &task : tasks)
    //  {
    //      futures.push_back(std::async(std::launch::async, task));
    //  }

    // for (auto &future : futures)
    // {
    //     std::cout << future.get() << std::endl;
    // }

    // caller c1;
    // c1.setfun(test);
    // c1.letrun(6, "hello world");

    // CATString c1;
    // CATString c2("hello");
    // CATString c3("world");
    // CATString c4(c3);
    // CATString c5;
    // c5 = c3;

    // cout << c1 << endl;
    // cout << c2 << endl;
    // cout << c3 << endl;
    // cout << c4 << endl;
    // cout << c5 << endl;

    // Animal *p = new Cat;
    // p->show();

    // p = new Dog;
    // p->show();
    // component *root = new composite("root");
    // component *node1 = new composite("node1");
    // component *node2 = new composite("node2");
    // component *leaf1 = new composite("leaf1");
    // component *leaf2 = new composite("leaf2");

    // root->addNode(node1);
    // root->addNode(node2);
    // node1->addNode(leaf1);
    // node1->addNode(leaf2);
    // root->process();

    // int a = 1;
    // int b = 1;
    // std::cout << add(a, b);
    // std::cout << add("a", "b");
    // char st1[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    // char st2[] = "world";
    // std::cout << st1 << std::endl;
    // std::cout << st2 << std::endl;

    // T1 tt = T1(100);
    // tt.show();

    // Iadaptee *r = new oldclass();
    // ITarget *it = new Adapter(r);
    // it->process();

    // Business2025 *b = new CMCC2025Proxy;
    // b->charge(1);
    // b->charge(200);

    // hungrysingleton *t = hungrysingleton::getInstance();
    // t->show();
    // singleton *st1 = singleton::getInstance();
    // st1->show();

    // singleton *t1 = singleton::getInstance();
    // t1->show();
    // Business *b = new CMCCProxy;
    // b->charge(1);
    // b->charge(200);

    // CMCC *cm = new CMCCProxy;
    // cm->charge(1);
    // cm->charge(100);

    //     Subject *sub = new Subject;
    //     Observer *obs1 = new Observer;
    //     Observer *obs2 = new Observer;

    //     sub->addObs(obs1);
    //     sub->addObs(obs2);
    //     sub->notify();
    // Receiver *r = new Receiver;
    // command *c = new concroCommand(r);
    // // Invoke *in = new Invoke(c);
    // Invoke *in = new Invoke;
    // in->setCommand(c);
    // ;
    // in->Ivoke();
    // composite root("root");
    // composite node1("node1");
    // leaf leaf1("leaf1");
    // leaf leaf2("leaf2");

    // root.AddNode(&node1);
    // node1.AddNode(&leaf1);
    // node1.AddNode(&leaf2);

    // root.process();

    // CDocument *c = new MyDocument;
    // c->onFileOpen();

    // weapon *ak = new AK47;
    // weapon *kn = new knife;

    // character c;
    // c.setws(ak);
    // c.doit();

    // c.setws(kn);
    // c.doit();

    // Iadaptee *r = new oldclass;
    // Target *t = new adapter(r);
    // t->process();

    // Fruit *f = SimpleFactory::createFruit("Apple");
    // f->show();

    // f = SimpleFactory::createFruit("Banana");
    // f->show();
    // FruitFactory *ff = new AppleFactory();
    // Fruit *f = ff->createFruit();
    // f->show();

    // ff = new BananaFactory();
    // f = ff->createFruit();
    // f->show();

    // ABsBoss *abs = new wtoBoss;
    // ABsHero *h1 = new ChinaHero;
    // ABsHero *h2 = new JpnHero;

    // abs->addHero(h1);
    // abs->addHero(h2);
    // abs->notify();

    // Receiver *r = new Receiver;
    // Command *cmd = new ConcreteCommand(r);
    // Invoke *invoker = new Invoke;
    // invoker->setCommand(cmd);
    // cmd->execute();

    // IAdaptee *IA = new oldclass;
    // ITarget *IT = new Adpater(IA);
    // IT->process();

    // composite root("root");
    // composite node("node");

    // leaf l1("leaf");
    // leaf l2("leaf");

    // root.addComponent(&node);
    // node.addComponent(&l1);
    // node.addComponent(&l2);

    // root.process();

    // Observer *obs1 = new Observer;
    // Observer *obs2 = new Observer;

    // Subject *sub = new Subject;
    // sub->addit(obs1);
    // sub->addit(obs2);

    // sub->notify(2025);

    // Weapon *ak = new AK47;
    // Weapon *kf = new Knife;
    // character cba;
    // cba.setWeapon(ak);
    // cba.useit();

    // cba.setWeapon(kf);
    // cba.useit();

    // CMCC *cmcc = new CMCCProxy();
    // cmcc->onCharge(1);
    // cmcc->onCharge(100);

    // CDocument *cd = new myDocuments();
    // cd->onFileOpen();

    // Animal *abc = new Cat();
    // abc->show();

    // abc = new Dog();
    // abc->show();

    /* code */
    // SimpleFactory *ff = new SimpleFactory();
    // Fruit *f = ff->createFruit("apple");
    // f->show();

    // Fruit *ff = new SimpleFactory("apple");
    //  Fruit *fp = nullptr;
    //  // fp = new SimpleFactory("apple");
    //  fp = SimpleFactory::createFruit("apple");
    //  fp->show();

    // fp = SimpleFactory::createFruit("Banana");
    // fp->show();

    // FruitFactory *ff = new BananaFactory;
    // Fruit *f = ff->createFruit();
    // f->show();

    // delete ff;
    // ff = new AppleFactory;
    // f = ff->createFruit();
    // f->show();

    return 0;
}
