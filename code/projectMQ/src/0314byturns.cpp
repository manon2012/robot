

#include <thread>
#include <iostream>
#include <cstdio>
#include <mutex>
#include <condition_variable>

using namespace std;
int flag = 10;
mutex mu;
condition_variable cv;
void fun(int x, char c)
{
    for (int i = 0; i < 50; i++)
    {
        unique_lock<mutex> lock(mu);
        while (flag != x)
            cv.wait(lock); // 在该线程阻塞以前会执行lock.unlock，这样别的线程才不会被锁住
        for (int j = 0; j < x; j++)
            cout << c << ":" << j << endl;
        flag = (x == 10) ? 100 : 10;
        cv.notify_one();
    }
}
int main()
{
    thread t1(fun, 10, 'A');
    fun(100, 'B');
    t1.join();
}
