#include <iostream>

using namespace std;

#include <iostream>
using namespace std;
#include <thread>
#include <mutex>
#include<string.h>


int count=0;


//int i=0;   this will not work
mutex mtx;
 std::lock_guard<std::mutex> lck (mtx);
int i = 0;
mutex m;


void threadFunc1()
{
   for(i=0;i<1000;i++){
      m.lock();
      count++;
      m.unlock();

   }
}

void threadFunc2()
{
   for(i=0;i<1000;i++){
      m.lock();
      count--;
      m.unlock();

   }
}


int main()
{
   std::thread t1(threadFunc1);
   std::thread t2(threadFunc2);
   t1.join();
   t2.join();

   cout<<"haha"<<endl;
   cout<<"count: "<<count<<endl;
   return 0;

}

