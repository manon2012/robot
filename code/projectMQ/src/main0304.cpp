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

void Test(int x, string y)
{
   while (x-- > 0)
   {
      std::cout << y << std::endl;
   }
}

typedef void (*pFunc)(int, string);

class call
{
public:
   void setfunc(pFunc func)
   {
      m_func = func;
   }

   void letrun(int x, string y)
   {
      m_func(x, y);
   }

private:
   pFunc m_func;
};

int main(int argc, const char **argv)
{
   call c1;
   c1.setfunc(Test);
   c1.letrun(3, "test");
   return 0;
}