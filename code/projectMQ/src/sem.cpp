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
#include <functional>
#include <semaphore.h>

/*
线程之间一等一的情况，建议使用sem信号量，而不是notify和wait。

sem主要有以下几个方法（返回值为0是表示成功）：
int sem_init(sem_t *sem,int pshared,unsigned int value);
int sem_destroy(sem_t *sem);
int sem_wait(sem_t *sem);
int sem_trywait(sem_t *sem);
int sem_post(sem_t *sem);
int sem_getvalue(sem_t *sem);
*/

// way1
//  void first() { printf("first"); }
//  void second() { printf("second"); }
//  void third() { printf("third"); }

// class Foo
// {
// protected:
//    sem_t sem1;
//    sem_t sem2;

// public:
// public:
//    Foo()
//    {
//       sem_init(&sem1, 0, 0); // 初始化两个信号量
//       sem_init(&sem2, 0, 0);
//    }

//    void first(function<void()> printFirst)
//    {
//       printFirst();
//       sem_post(&sem1);
//    }

//    void second(function<void()> printSecond)
//    {
//       sem_wait(&sem1); // 等待sem1结束
//       printSecond();
//       sem_post(&sem2); // 通知sem2可以开始了
//    }

//    void third(function<void()> printThird)
//    {
//       sem_wait(&sem2);
//       printThird();
//    }
// };

// int main(int argc, const char **argv)
// {

//    Foo obj;
//    thread t1(std::bind(&Foo::first, &obj, first));
//    thread t3(std::bind(&Foo::second, &obj, second));
//    thread t2(std::bind(&Foo::third, &obj, third));
//    t1.join();
//    t2.join();
//    t3.join();

//    return 0;
// }

// 我们提供了一个类：
// public
// class Foo {
//     public void one() { print("one"); }
//     public void two() { print("two"); }
//     public void three() { print("three"); }
// } 三个不同的线程将会共用一个 Foo 实例。
// 线程 A 将会调用
// one() 方法 线程 B 将会调用 two() 方法 线程 C 将会调用
// three() 方法 请设计修改程序，以确保 two() 方法在 one()
//     方法之后被执行，three() 方法在 two() 方法之后被执行。
// 示例 1 :
// 输入 : [ 1, 2, 3 ] 输出 : "onetwothree" 解释
// : 有三个线程会被异步启动。 输入[1, 2, 3] 表示线程 A 将会调用
//   one() 方法，线程 B 将会调用 two() 方法，线程 C 将会调用
//   three() 方法。 正确的输出是 "onetwothree"。 示例 2 :
// 输入 : [ 1, 3, 2 ] 输出 : "onetwothree" 解释
// : 输入[1, 3, 2] 表示线程 A 将会调用 one() 方法，线程 B 将会调用
//   three() 方法，线程 C 将会调用 two() 方法。 正确的输出是 "onetwothree"。
//   注意 :
// 尽管输入中的数字似乎暗示了顺序，但是我们并不保证线程在操作系统中的调度顺序。
// 你看到的输入格式主要是为了确保测试的全面性。 在真实的面试中遇到过这道题？
// 来源：力扣（LeetCode） 链接：https
// :  // leetcode-cn.com/problems/print-in-order
//    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

// way2
#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <thread>

void p1() { std::cout << "one" << std::endl; }

void p2() { std::cout << "two" << std::endl; }

void p3() { std::cout << "three" << std::endl; }

class Foo
{
public:
   Foo() {}

   void first(std::function<void()> printFirst)
   {
      std::unique_lock<std::mutex> guard(mutex_);
      // printFirst() outputs "first". Do not change or remove this line.
      printFirst();
      first_ = true;
      cond_.notify_all();
   }

   void second(std::function<void()> printSecond)
   {
      std::unique_lock<std::mutex> guard(mutex_);
      while (!first_)
      {
         cond_.wait(guard);
      }
      // printSecond() outputs "second". Do not change or remove this line.
      printSecond();
      second_ = true;
      cond_.notify_all();
   }

   void third(std::function<void()> printThird)
   {
      std::unique_lock<std::mutex> guard(mutex_);
      while (!second_)
      {
         cond_.wait(guard);
      }
      // printThird() outputs "third". Do not change or remove this line.
      printThird();
   }

private:
   volatile bool first_ = false;
   volatile bool second_ = false;
   std::mutex mutex_;
   std::condition_variable cond_;
};

int main()
{
   Foo fo;
   std::thread th1(std::bind(&Foo::second, &fo, p2));
   std::thread th2(std::bind(&Foo::first, &fo, p1));
   std::thread th3(std::bind(&Foo::third, &fo, p3));
   th1.join();
   th2.join();
   th3.join();
   return 0;
}