#include <iostream>
#include <thread>
#include <mutex>
#include<string.h>
#include "../include/Apple.h"
using namespace std;
#include <condition_variable>


/*
   modify
   1. .vscode/launch.json  
   "program": "${workspaceFolder}/build/template2023",
   2.CmakeLists.txt
   add_executable(Template2023 src/main.cpp) #添加生成可执行文件
   target_link_libraries(template2023 pthread)
        
*/

char arr[]={'a','b','c'};
char message = 'a';
mutex mtx;
condition_variable cv;

void printabc(int index)
{
    for(int i=0; i<10;i++)
    {
       unique_lock<mutex> lck(mtx);
       cv.wait(lck, [=]{return message == arr[index]; });
       std::cout << arr[index] << std::endl;
       message = arr[(index+1)%3];
       lck.unlock();
       cv.notify_all();
    }

}



int pn = 6;
int avsignal =1;
void printA()
{
    while(pn>0)
      {
          unique_lock<mutex> lck(mtx);
          cv.wait(lck,[]{return avsignal==1;});
          if(pn>0)
          {
              std::cout<<this_thread::get_id()<<"pthreaA:"<<"A"<<pn<<std::endl;
              pn--;
          }

          avsignal = 2;
          cv.notify_all();
      }


}

void printB()
{
    while(pn>0)
    {
          unique_lock<mutex> lck(mtx);
          cv.wait(lck,[]{return avsignal==2;});
          if(pn>0)
          {
              std::cout<<this_thread::get_id()<<"pthreadB:"<<"B"<<pn<<std::endl;
              pn--;
          }

          avsignal = 3;
          cv.notify_all();
}
}

void printC()
    {
        while(pn>0)
        {
              unique_lock<mutex> lck(mtx);
              cv.wait(lck,[]{return avsignal==3;});
              if(pn>0)
              {
                  std::cout<<this_thread::get_id()<<"pthreadB:"<<"C"<<pn<<std::endl;
                  pn--;
              }

              avsignal = 1;
              cv.notify_all();

    }
}




int main()
{
   std::thread t[3];
   for (int i = 0; i <3;i++)
   {
       t[i] = thread(printabc, i);
   }

   for (int i = 0; i <3;i++)
   {
      t[i].join();
   }
  

    //step by step version
    thread t1(printA);
    thread t2(printB);
    thread t3(printC);

    t1.join();
    t2.join();
    t3.join();

   cout<<"hello,world! tempalte2013"<<endl;

   return 0;


}   