#include <iostream>
#include <thread>
#include <mutex>
#include <string.h>
#include "../include/Apple.h"
using namespace std;
#include "functional"

// https://mp.weixin.qq.com/s?src=11&timestamp=1709258656&ver=5111&signature=plN0w0cxEWeUO0bGcYYBKDqQGpgzq7sMyOo5*Jq*LQOPTuQCNnpuP2ZMYvnhlze9mPo54fWBiOp9AK-dRk1jgpJWxjxh2b9JGJE4jQuyjoJsxY9A*bokpWeQWvjxhYLD&new=1

// void print()
// {
//    std::cout << "hello world" << std::endl;
// }

// class Greater
// {
// public:
//    void operator()()
//    {

//       std::cout << "greater operator" << std::endl;
//    }
// };

// void add(int a, int b)
// {
//    std::cout << a + b << std::endl;
// }

// void printmessage(string message, int x)
// {

//    std::cout << message << ": " << x << std::endl;
// }

// int main(int argc, char **argv)
// {
//    std::function<void(void)> f1 = print;
//    f1();

//    std::function<void(void)> f2 = []()
//    {
//       std::cout << "lambda express" << std::endl;
//    }; // here need to add ;
//    f2();

//    std::function<void(void)> f3 = Greater();
//    std::function<void(int, int)> f4 = add;
//    f4(1, 1);
//    f3();

//    std::function<void(int, int)> f4 = add;
//    f4(1, 1);

//    // what is this?
//    auto printhello = std::bind(printmessage, "hello", std::placeholders::_1);
//    std::function<void(int)> f6 = printhello; // here not void<string, int>
//    f6(2024);

//    return 0;
// }

// void print()
// {
//    std::cout << "print..." << std::endl;
// }

// class Greater
// {
// public:
//    void operator()()
//    {
//       std::cout << "Greater..." << std::endl;
//    }
// };

// void add(int x, int y)
// {
//    std::cout << x + y << std::endl;
// }

// void printmessage(string x, int y)
// {
//    std::cout << x << ": " << y << std::endl;
// }

// int main()
// {
//    function<void()> f1 = print;
//    f1();

//    function<void()> f2 = Greater();
//    f2();

//    function<void()> f3 = []()
//    {
//       std::cout << "lambda..." << std::endl;
//    };
//    f3();

//    function<void(int, int)> f4 = add;
//    f4(1, 1);

//    auto xprint = bind(printmessage, "helloprint", std::placeholders::_1);
//    function<void(int)> newx = xprint;
//    newx(2024);
//    return 0;
// }

#include <iostream>
using namespace std;

// template <class... T>
// void f(T... args)
// {
//    cout << sizeof...(args) << endl; // 打印变参的个数
// }
// int main()
// {
//    f();           // 0
//    f(1, 2);       // 2
//    f(1, 2.5, ""); // 3
//    int x = 1;
//    string y = "hello";
//    std::cout << sizeof(x) << std::endl; //
//    std::cout << sizeof(y) << std::endl;
//    return 0;
// }

// template <class T>
// void fun(T x)
// {
//    std::cout << x << std::endl;
// }

// template <class... T>
// void fun(T... args)
// {
//    std::cout << sizeof...(args) << std::endl;
//    std::cout<<arg
// }
// int main()
// {

//    fun(100, 200);
//    fun("hello");
//    return 0;
// }

// 递归终止函数
void print()
{
   cout << "empty" << endl;
}
// 展开函数
template <class T, class... Args>
void print(T head, Args... rest)
{
   cout << "parameter " << head << endl;
   print(rest...);
}

int main(void)
{
   print(1, 2, 3, "darren", "youzi");
   return 0;
}
