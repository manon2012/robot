#include <iostream>
#include <thread>
#include <mutex>
#include <string.h>
#include "../include/Apple.h"
using namespace std;
#include <unistd.h>

/*
   modify
   1. .vscode/launch.json
   "program": "${workspaceFolder}/build/template2023",
   2.CmakeLists.txt
   add_executable(Template2023 src/main.cpp) #添加生成可执行文件
   target_link_libraries(template2023 pthread)

*/

int num = 0;
mutex mtx;
void add()
{
   for (int j = 0; j < 100000; j++)
   {
      // mtx.lock();
      // lock_guard<mutex> lck(mtx);
      unique_lock<mutex> lck(mtx);
      num++;
      // mtx.unlock();
   }
}

void sub()
{
   for (int j = 0; j < 100000; j++)
   { // mtx.lock();
      // lock_guard<mutex> lck(mtx);
      unique_lock<mutex> lck(mtx);
      num--;
      // mtx.unlock();
   }
}

int ticketnumber = 100;
void sellT(int index)
{
   while (ticketnumber > 0)
   {
      {
         lock_guard<mutex> lck(mtx);
         if (ticketnumber > 0)
         {
            std::cout << "index:" << index << " sell ticket-->" << ticketnumber << std::endl;
            ticketnumber--;
         }
      }

      usleep(10);
   }
}

#include <condition_variable>

condition_variable cv;
bool flag = true;
void printA()
{
   while (1)
   {
      unique_lock<mutex> lck(mtx);
      cv.wait(lck, []
              { return flag; });

      std::cout << "printA()" << std::endl;
      flag = false;
      usleep(1000000);
      cv.notify_one();
   }
}
void printB()
{
   while (true)
   {
      unique_lock<mutex> lck(mtx);
      cv.wait(lck, []
              { return !flag; });
      std::cout << "printB()" << std::endl;
      flag = true;
      usleep(1000000);
      cv.notify_one();
   }
}

char Message[] = {'A', 'B', 'C'};
char init = 'A';

void printABC(int index)
{
   for (int i = 0; i < 10; i++)
   {
      unique_lock<mutex> lck(mtx);
      cv.wait(lck, [=]
              { return init == Message[index]; });
      std::cout << Message[index] << std::endl;

      init = Message[(index + 1) % 3];
      //lck.unlock();   //TODO need this?
      cv.notify_one();  //one only print ABC once; all print all
   }
}
int main()
{
   thread t[3];
   for (int i = 0; i < 3; i++)
   {
      t[i] = thread(printABC, i);
   }
   for (int i = 0; i < 3; i++)
   {
      t[i].join();
   }

   //  thread t1(printA);
   //  thread t2(printB);
   //  t1.join();
   //  t2.join();

   // thread t1(sellT, 1);
   // thread t2(sellT, 2);
   // thread t3(sellT, 3);

   // t1.join();
   // t2.join();
   // t3.join();

   // thread t1(add);
   // thread t2(sub);
   // t1.join();
   // t2.join();
   // cout<<"num: "<<num<< endl;

   cout << "hello,world! tempalte2013" << endl;

   return 0;
}