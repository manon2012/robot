#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

std::mutex mtx;
std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;

void worker_thread()
{
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, []()
            { return ready == true; });

    std::cout << "worker begin" << std::endl;

    data += "2024";
    processed = true;

    std::cout << "worker finished" << data << std::endl;
    lock.unlock();
    cv.notify_one();
}

int main()
{
    std::thread t(worker_thread);
    data = "Example data";
    {
        unique_lock<mutex> lock(mtx);
        std::cout << "main() signals data ready for processing" << std::endl;
        ready = true;
    }
    cv.notify_one();
    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []
                { return processed; });
    }

    std::cout << "back to main again" << std::endl;

    t.join();

    return 0;
}