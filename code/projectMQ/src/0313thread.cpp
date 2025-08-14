#include <string>
#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <unistd.h>
#include <queue>
using namespace std;

bool ready = false;
mutex mtx;
condition_variable cv;
queue<int> q;
int account = 10;
void producer()
{
    for (int i = 1; i <= account; i++)
    {

        unique_lock<mutex> lock(mtx);
        cout << "produce: " << i << endl;
        q.push(i);
        lock.unlock();
        cv.notify_one();

        // std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void consumer()
{
    int i = 0;
    while (true)
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []
                { return !q.empty(); });
        cout << "consume: " << q.front() << endl;
        q.pop();
        i++;
        lock.unlock();
        // std::this_thread::sleep_for(std::chrono::milliseconds(10));
        if (i == account)
            break;
    }
}

string data;

bool process = false;
void worker_thread()
{
    cout << "worker_thread start" << endl;
    unique_lock<mutex> lk(mtx);
    cv.wait(lk, []
            { return ready; });
    data = +"2024";
    cout << "worker done" << endl;
    process = true;
    cv.notify_one();
}
//
int main()
{
    // thread tw(worker_thread);
    // cout << "main thread start" << endl; // hang here!!! sometimes
    //                                      //{

    // lock_guard<mutex> lk(mtx);
    // ready = true;
    // cv.notify_one();
    // //}

    // {
    //     unique_lock<mutex> lk(mtx);
    //     cv.wait(lk, []
    //             { return process; });
    // }

    // cout << "back to main: " << data << endl;
    // tw.join();

    thread t1(producer);
    thread t2(consumer);
    t1.join();
    t2.join();

    return 0;
}