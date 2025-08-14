// https : // zhuanlan.zhihu.com/p/450583728
// 1 : 环境类（Context）角色：也称为上下文，它定义了客户端需要的接口，内部维护一个当前状态，并负责具体状态的切换。
// 2 : 抽象状态（State）角色：定义一个接口，用以封装环境对象中的特定状态所对应的行为，可以有一个或多个行为。
// 3 : 具体状态（Concrete State）角色：实现抽象状态所对应的行为，并且在需要的情况下进行状态切换。

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
class Context; // 声明
// 数据驱动模型：状态基类
class IState
{
public:
    /*行为方法*/
    virtual void Handle(Context *context) = 0;
    // 获得当前的状态
    virtual void GetState() = 0;
};
// 状态管理类
class Context
{
public:
    // 初始化状态
    Context(IState *state)
    {
        m_pState = state;
    }
    // 获得当前的状态
    IState *GetState()
    {
        return m_pState;
    }
    // 改变当前的状态
    void SetState(IState *state)
    {
        m_pState = state;
    }
    // 执行状态类实现的方法
    void Request()
    {
        m_pState->Handle(this);
    }
    IState *m_pState;
};
// 具体的状态子类
class ConcreteStateA : public IState
{
public:
    void Handle(Context *context);
    void GetState();
};
// 具体的状态子类
class ConcreteStateB : public IState
{
public:
    void Handle(Context *context);
    void GetState();
};
// 具体的状态子类
class ConcreteStateC : public IState
{
public:
    void Handle(Context *context);
    void GetState();
};
void ConcreteStateA::Handle(Context *context)
{
    // A->B
    // Next:ConcreteStateB
    context->m_pState = new ConcreteStateB;
    cout << "当前状态是A，下一状态是B" << endl;
}
void ConcreteStateB::Handle(Context *context)
{
    // B->C
    // Next:ConcreteStateC
    context->m_pState = new ConcreteStateC;
    cout << "当前状态是B，下一状态是C" << endl;
}
void ConcreteStateC::Handle(Context *context)
{
    // C->A
    // Next:ConcreteStateA
    context->m_pState = new ConcreteStateA;
    cout << "当前状态是C，下一状态是A" << endl;
}
void ConcreteStateA::GetState()
{
    cout << "当前状态是A" << endl;
}
void ConcreteStateB::GetState()
{
    cout << "当前状态是B" << endl;
}
void ConcreteStateC::GetState()
{
    cout << "当前状态是B" << endl;
}

int test11()
{
    {
        // 初始化A状态
        Context *context = new Context(new ConcreteStateA);
        context->Request(); // 由A驱动，Next=B
        context->Request(); // 由B驱动，Next=C
        context->Request(); // 由C驱动，Next=A
        getchar();
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    test11();

    return 0;
}
