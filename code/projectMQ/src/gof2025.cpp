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

main(int argc, char const *argv[])
{
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
