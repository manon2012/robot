#include <iostream>
#include <thread>
#include <mutex>
#include<string.h>
#include "../include/Apple.h"
using namespace std;
#include <unistd.h>
#include <condition_variable>


/*
   modify
   1. .vscode/launch.json  
   "program": "${workspaceFolder}/build/template2023",
   2.CmakeLists.txt
   add_executable(Template2023 src/main.cpp) #添加生成可执行文件
   target_link_libraries(template2023 pthread)
        
*/

mutex mtx;
std::condition_variable cv;
bool flag = true;

int n=10;

void move1()
{
   cout << "move1 done" <<endl;
   sleep(1);
}


void move2()
{
   cout << "move2 done" <<endl;
   sleep(3);
}

void sellticket1(int index)
{  
   while(n>0)
   {
      //std::lock_guard <mutex>lck(mtx);
      // mtx.lock();
      // cout << "id: " <<index<<" ->" <<std::this_thread::get_id() << " sellticket:" << n << endl;
      // n--;
      // mtx.unlock();
      // usleep(10);

      {      
      std::unique_lock<std::mutex> lck(mtx);
      cv.wait(lck,[]{return flag;});//等待flag=true才打印奇数
      cout << "id: " <<index<<" ->" <<std::this_thread::get_id() << " sellticket:" << n << endl;
      n--;
      move1();
      flag = false;
      cv.notify_one();
      }
      std::cout << "after notify one t1"<<std::endl;
      sleep(10);
      std::cout << "after notify one t1 sleep310 done"<<std::endl;
   }

}

void sellticket2(int index)
{  
   while(n>0)
   {
      //std::lock_guard <mutex>lck(mtx);
      // mtx.lock();
      // cout << "id: " <<index<<" ->" <<std::this_thread::get_id() << " sellticket:" << n << endl;
      // n--;
      // mtx.unlock();
      // usleep(10);

      {
      std::unique_lock<std::mutex> lck(mtx);
      cv.wait(lck,[]{return !flag;});//等待flag=false才打印偶数
      cout << "id: " <<index<<" ->" <<std::this_thread::get_id() << " sellticket:" << n << endl;
      n--;
      move2();
      flag = true;
      cv.notify_one();
      }
      std::cout << "after notify one t2"<<std::endl;
      sleep(5);
      std::cout << "after notify one t2 sleep5 done"<<std::endl;
   }

}

mutex mx;
int gcount = 2;
condition_variable vc;
bool flagvc = true;
void sellticket3(int index)
{
   while(gcount>0)
   {
      {
      std::lock_guard <mutex>lc(mx);
      std::cout << "sellticket3 sell :"<<gcount<<std::endl;
      gcount--;
      }
      usleep(20);

   }

}

void sellticket4(int index)
{
   while(gcount>0)
   {
      
      {
         std::lock_guard <mutex>lc(mx);
      std::cout << "sellticket4 sell :"<<gcount<<std::endl;
      gcount--;
      }
      usleep(20);

   }
}

void sellticket5(int index)
{
   while(gcount>0)
   {
     std::cout << "sellticket5 begin: " << gcount << std::endl;
     std::unique_lock<mutex> lock(mtx);
     vc.wait(lock,[]{return flagvc;});

     std::cout << "sellticket5: " << gcount << std::endl;
     gcount--;
     usleep(20);
     flagvc = false;
     vc.notify_one();
   }

}

void sellticket6(int index)
{
   while(gcount>0)
   {
      std::cout << "sellticket6 begin: " << gcount << std::endl;
      std::unique_lock<std::mutex> lock(mtx);
      vc.wait(lock,[]{return !flagvc;});

      std::cout << "sellticket6: " << gcount << std::endl;
      gcount--;
      usleep(20);
      flagvc = true;
      vc.notify_one();
  


   }
   
}

int main()
{
   
   thread t1(sellticket5,1);
   thread t2(sellticket6,2); 

   t1.join();
   t2.join();

   cout<<"hello,world! sellticket"<<endl;

   return 0;


}   

