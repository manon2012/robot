#include "thread"
#include "iostream"
#include "queue"
#include "condition_variable"
#include <mutex>
using namespace std;

condition_variable QueueNotEmpty;
condition_variable QueueNotFull;
int totaltime = 10;
int buffersize = 3;
queue<int> q;
mutex mtx;

void producer()
{
    for (int i = 0; i < totaltime; i++)
    {
        {
            unique_lock<mutex> lock(mtx);
            QueueNotFull.wait(lock, []
                              { return q.size() != buffersize; });
            q.push(i);

            std::cout << "producer:" << i << " , buffersizesize():" << q.size() << std::endl;
        }
        QueueNotEmpty.notify_one();

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

void consumer()
{
    // for (int i = 0; i < totaltime; i++)   not for
    while (true)
    {
        {
            unique_lock<mutex> lock(mtx);
            QueueNotEmpty.wait(lock, []
                               { return q.size() > 0; });
            int data = q.front();
            q.pop();
            std::cout << "consumer: " << data << " , buffersize:" << q.size() << std::endl;
        }
        QueueNotFull.notify_one();

        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        if (q.empty())
            break;
    }
}

int main(int argc, const char **argv)
{
    thread t1(producer);
    thread t2(consumer);
    t1.join();
    t2.join();

    system("pause");
    return 0;
}
