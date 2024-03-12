#include <iostream>
#include <thread>
#include <mutex>
#include <string.h>
#include "../include/Apple.h"
using namespace std;

mutex mtx;

void add(int x, int y)
{
   std::lock_guard<std::mutex> lock(mtx);
std:
   cout << x + y << std::endl;
}

typedef void (*padd)(int x, int y);

padd p1 = &add;

void Test(int x, string y)
{
   while (x-- > 0)
   {
      std::cout << y << std::endl;
   }
}

typedef void (*pfun)(int, string);
class call
{
public:
   void setfun(pfun fun)
   {
      m_fun = fun;
   }
   void letrun(int x, string y)
   {
      m_fun(x, y);
   }

private:
   pfun m_fun;
};

int main(int argc, const char **argv)
{
   call c1;
   c1.setfun(Test);
   c1.letrun(3, "test");

   // p1(100, 100);
   return 0;
}

// int add(int x, int y)
// {
//    std::cout<<x+y<<std::endl;
//    return x+y;
// }

// int (*pAdd)(int x, int y) = &add;

// typedef int (*tAdd)(int, int);
// tAdd f = &add;

// int main()
// {

//    cout<<"hello,world! testmq"<<endl;

//    pAdd(1,1);
//    pAdd = add;
//    pAdd(1000,1000);
//    f(11,11);

//    return 0;

// }