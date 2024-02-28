#include <iostream>
#include <thread>
#include <mutex>
#include <string.h>
#include "../include/Apple.h"

#include <unistd.h>

using namespace std;

/*
回调过程：
调用回调接口【SetFun】  并设置一回调接受函数【Test】  ----->
保存 被调用端传来的 参数 【myFun】-----> 等待.....----->
LetRun ----->myFun------>回调到Test
*/

void Test2(int x, string y)
{
   while (x-- > 0)
   {
      std::cout << y << std::endl;
   }
}

typedef void (*pAdd2)(int, string);

class Call2
{
public:
   void setfun(pAdd2 fun)
   {
      m_fun = fun;
   }
   void letrun(int x, string y)
   {
      m_fun(x, y);
   }

private:
   pAdd2 m_fun;
};

void p1()
{
   std::cout << "p1 run1" << std::endl;
   usleep(1000000);
   std::cout << "p1 run2" << std::endl;
}
void p2()
{
   std::cout << "p2 run1" << std::endl;
   usleep(1000000);
   std::cout << "p2 run2" << std::endl;
}

void testthead()
{
   thread t1(&p1);
   thread t2(&p2);
   t1.join();
   t2.join();
}

void Test1(int x, string y)
{
   while (x-- > 0)
   {
      std::cout << y << std::endl;
   }
}

typedef void (*pfun1)(int, string);
class Call1
{
public:
   void setfun(pfun1 fun)
   {
      m_fun = fun;
   }
   void letrun(int x, string y)
   {
      m_fun(x, y);
   }

private:
   pfun1 m_fun;
};

void Test(int x, string y)
{
   while (x-- > 0)
   {
      std::cout << y << std::endl;
   }
}

typedef void (*pfun)(int x, string y);
class Call
{
public:
   void setfun(pfun fun)
   {
      myfun = fun;
   }

   void letrun(int x, string y)
   {
      myfun(x, y);
   }

private:
   pfun myfun;
};

int main()
{
   Call2 c2;
   c2.setfun(Test2);
   c2.letrun(3, "test");

   int count = 10;
   // testthead();
   thread t1(&p1);
   thread t2(&p2);
   t1.join();
   t2.join();
   // t1.join();
   // t2.join();
   while (count-- > 0)
   {
      std::cout << "count: " << count << std::endl;
      usleep(100000);
   }

   // Call1 c11;
   // c11.setfun(Test1);
   // c11.letrun(3, "test1");

   // Call c1;
   // c1.setfun(Test);
   // c1.letrun(3, "test");
   return 0;
}

// void Test(int x, string y)
// {
//    while (x-- > 0)
//    {
//       std::cout << y << std::endl;
//    }
// }

// typedef void (*pFun)(int, string);

// class Call
// {
// public:
//    void setfun(pFun x)
//    {
//       myfun = x;
//    }
//    void letrun(int x, string y)
//    {
//       myfun(x, y);
//    }

// private:
//    pFun myfun;
// };

// int main()
// {
//    Call c1;
//    c1.setfun(Test);
//    c1.letrun(3, "test");
//    return 0;
// }

// void Test(int x, string y);
// typedef void (*padd)(int, int);

// void add(int x, int y)
// {
//    std::cout << x + y << std::endl;
// }

// padd t1 = &add;

// typedef void (*pFun)(int, string);

// class Call
// {
// public:
//    void setFun(pFun x)
//    {
//       p = x;
//    }
//    void letRun(int x, string y)
//    {
//       std::cout << "p: " << p << std::endl;
//       p(x, y);
//    }

// private:
//    pFun p;
// };

// void Test(int x, string y)
// {
//    while (x-- > 0)
//    {
//       std::cout << y << std::endl;
//    }
// }

// int main()
// {
//    Call c1;
//    c1.setFun(Test);
//    c1.letRun(3, "hello world");

//    t1(1, 1);
//    return 0;
// }