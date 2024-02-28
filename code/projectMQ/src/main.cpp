#include <iostream>
#include <thread>
#include <mutex>
#include <string.h>
#include "../include/Apple.h"
using namespace std;

/*
回调过程：
调用回调接口【SetFun】  并设置一回调接受函数【Test】  ----->
保存 被调用端传来的 参数 【myFun】-----> 等待.....----->
LetRun ----->myFun------>回调到Test
*/

typedef void (*MyFun)(int n, string str);

class Call
{
private:
   MyFun myFun;

public:
   void SetFun(MyFun _myFun)
   {
      myFun = _myFun;
   }

   void LetRun(int n, string str)
   {
      myFun(n, str);
   }
};

void Test(int n, string str) // 如果不定义全局变量，而定义在类中 则必须是 静态成员函数
{
   while (n-- > 0)
   {
      cout << n << " " << str << endl;
   }
}
int main(int argc, char *argv[])
{
   Call call;
   call.SetFun((MyFun)Test); // 调回调函数的接口，并传入一个函数作为参数
   call.LetRun(3, "hello");

   return 0;
}
