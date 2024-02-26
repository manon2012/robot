#include <iostream>
#include <thread>
#include <mutex>
#include<string.h>
#include "../include/Apple.h"
using namespace std;


int add(int x, int y)
{
   std::cout<<x+y<<std::endl;
   return x+y;
}

int (*pAdd)(int x, int y) = &add;

typedef int (*tAdd)(int, int);
tAdd f = &add;

int main()
{

   cout<<"hello,world! testmq"<<endl;

   pAdd(1,1);
   pAdd = add;
   pAdd(1000,1000);
   f(11,11);


   return 0;


}   