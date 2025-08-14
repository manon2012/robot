#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
std::queue<int> q;
std::mutex mtx;
std::condition_variable cond;
void producer()
{
    for (int i = 0; i < 10; ++i)
    {
        {
            std::unique_lock<std::mutex> lck(mtx);
            q.push(i);
            std::cout << "producer: " << i << std::endl;
        }
        cond.notify_one();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
void consumer()
{
    while (true)
    {
        {
            std::unique_lock<std::mutex> lck(mtx);
            cond.wait(lck, []
                      { return !q.empty(); });
            int data = q.front();
            q.pop();
            std::cout << "consumer: " << data << std::endl;
        }

        // if (q.empty())
        // {
        //     break;
        // }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
int main()
{
    std::thread t1(producer);
    std::thread t2(consumer);
    t1.join();
    t2.join();
}