#include "test01.h"
using namespace std;
#include <string>
#include <iostream>

int gcount = 0;
bool flag = false;

void test01()
{
   //int gcount = 0; here ok
//    if(gcount)
//    {
//       gcount = 0;
//    }
   if(flag)
   {
    gcount = 0;
   }

   for(int i = 0; i <10;i++)
       {
         gcount+=i;
       }
   std::cout << gcount << std::endl;
   flag = true;
   std::cout <<"called one, reset " <<std::endl;
}