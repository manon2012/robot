#include <string>
#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <unistd.h>
#include <queue>
using namespace std;

bool data_ready = false;
mutex mtx;
condition_variable cv;
queue<int> q;
void producer()
{
    // while (true)
    // {
    //     this_thread::sleep_for(std::chrono::milliseconds(10));
    //     unique_lock<mutex> lock(mtx);
    //     data_ready = true;
    //     cout << "producer->data ready" << endl;
    //     cv.notify_one();
    // }
    for (int i = 0; i < 10; i++)
    {
        //{
        unique_lock<mutex> lock(mtx);
        q.push(i);
        std::cout << "produce: " << i << endl;
        cv.notify_one();
        //}
        this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void consumer()
{
    // while (true)
    // {
    //     unique_lock<mutex> lock(mtx);
    //     cv.wait(lock, []
    //             { return data_ready; });
    //     cout << "consumer-> done" << endl;
    //     data_ready = false;
    // }
    while (true)
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []
                { return !q.empty(); }); // 这出来后要加锁，如果26/31不加作用域，这里加不上锁

        cout << "consume: " << q.front() << endl;
        q.pop();
    }
}

int main(int argc, const char **argv)
{
    thread t1(producer);
    thread t2(consumer);
    t1.join();
    t2.join();

    return 0;
}