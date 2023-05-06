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
bool flag = false;
condition_variable cv;
mutex mtx;

void print_id(int index)
{
  unique_lock<mutex> lck(mtx);
  while(!flag) {cv.wait(lck);}
  std::cout <<index << std::endl;

}

void go()
{
   unique_lock<mutex> lck(mtx);  //TODO forget this line
   flag = true;
   cv.notify_one();

}

int main()
{
   thread t[3];
   for (int i = 0; i < 3; i++)
   {
      t[i] = thread(print_id, i);
   }
   std::cout <<"3 threads ready to race" << std::endl;
   go();  //TODO correct

   for (auto &x :t)
   {
      x.join();
   }
   //go();   //not correct

   cout<<"hello,world! tempalte2013"<<endl;

   return 0;


}   

/*
notify_one()与notify_all()常用来唤醒阻塞的线程。

notify_one()：因为只唤醒等待队列中的第一个线程；不存在锁争用，
所以能够立即获得锁。其余的线程不会被唤醒，需要等待再次调用notify_one()或者notify_all()。

notify_all()：会唤醒所有等待队列中阻塞的线程，存在锁争用，
只有一个线程能够获得锁。那其余未获取锁的线程接着会怎么样？会阻塞？还是继续尝试获得锁？

答案是会继续尝试获得锁(类似于轮询)，而不会再次阻塞。
当持有锁的线程释放锁时，这些线程中的一个会获得锁。而其余的会接着尝试获得锁。

all 输出表明所有线程被唤醒，然后依旧获得了锁。
one 输出表明只有有一个线程被唤醒，然后该线程释放锁，这时锁已经处理非锁定状态，但是其余线程依旧处于阻塞状态。

所以，线程阻塞在condition_variable时，它是等待notify_one()或者notify_all()来唤醒，而不是等待锁可以被锁定来唤醒。
线程被唤醒后，会通过轮询方式获得锁，获得锁前也一直处理运行状态，不会被再次阻塞。
https://blog.csdn.net/feikudai8460/article/details/109604690
*/

/*
1. 线程的几种状态

线程在一定条件下，状态会发生变化。线程一共有以下几种状态：

1、新建状态(New)：新创建了一个线程对象。

2、就绪状态(Runnable)：线程对象创建后，其他线程调用了该对象的start()方法。该状态的线程位于“可运行线程池”中，变得可运行，只等待获取CPU的使用权。即在就绪状态的进程除CPU之外，其它的运行所需资源都已全部获得。

3、运行状态(Running)：就绪状态的线程获取了CPU，执行程序代码。

4、阻塞状态(Blocked)：阻塞状态是线程因为某种原因放弃CPU使用权，暂时停止运行。直到线程进入就绪状态，才有机会转到运行状态。

*/