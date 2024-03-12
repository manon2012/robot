#include <iostream>
#include <thread>
#include <mutex>
#include <string.h>
#include "../include/Apple.h"
using namespace std;

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
std::mutex mtx;
std::condition_variable cond;
int count = 1;
int limit = 10;
void printOdd()
{
   while (count <= limit)
   {
      std::unique_lock<std::mutex> lck(mtx);
      if (count % 2 == 0)
      {
         cond.wait(lck);
      }
      else
      {
         std::cout << "Odd thread: " << count << std::endl;
         count++;
         cond.notify_one();
      }
   }
}
void printEven()
{
   while (count <= limit)
   {
      std::unique_lock<std::mutex> lck(mtx);
      if (count % 2 == 1)
      {
         cond.wait(lck);
      }
      else
      {
         std::cout << "Even thread: " << count << std::endl;
         count++;
         cond.notify_one();
      }
   }
}
int main()
{
   std::thread t1(printOdd);
   std::thread t2(printEven);
   t1.join();
   t2.join();
   return 0;
}