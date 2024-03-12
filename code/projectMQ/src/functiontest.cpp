#include <iostream>
#include <thread>
#include <mutex>
#include <string.h>
#include "../include/Apple.h"
using namespace std;
#include "functional"

// https://mp.weixin.qq.com/s?src=11&timestamp=1709258656&ver=5111&signature=plN0w0cxEWeUO0bGcYYBKDqQGpgzq7sMyOo5*Jq*LQOPTuQCNnpuP2ZMYvnhlze9mPo54fWBiOp9AK-dRk1jgpJWxjxh2b9JGJE4jQuyjoJsxY9A*bokpWeQWvjxhYLD&new=1

void print()
{
   std::cout << "hello world" << std::endl;
}

class Greater
{
public:
   void operator()()
   {

      std::cout << "greater operator" << std::endl;
   }
};

void add(int a, int b)
{
   std::cout << a + b << std::endl;
}

void printmessage(string message, int x)
{

   std::cout << message << ": " << x << std::endl;
}

int main(int argc, char **argv)
{
   std::function<void(void)> f1 = print;
   f1();

   std::function<void(void)> f2 = []()
   {
      std::cout << "lambda express" << std::endl;
   }; // here need to add ;
   f2();

   std::function<void(void)> f3 = Greater();
   std::function<void(int, int)> f4 = add;
   f4(1, 1);
   f3();

   std::function<void(int, int)> f4 = add;
   f4(1, 1);

   // what is this?
   auto printhello = std::bind(printmessage, "hello", std::placeholders::_1);
   std::function<void(int)> f6 = printhello; // here not void<string, int>
   f6(2024);

   return 0;
}