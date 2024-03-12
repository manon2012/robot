#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>

std::condition_variable cv;
std::mutex cv_m; // This mutex is used for three purposes:
                 // 1) to synchronize accesses to i
                 // 2) to synchronize accesses to std::cerr
                 // 3) for the condition variable cv
int i = 0;

void waits()
{
    std::unique_lock<std::mutex> lk(cv_m);
    std::cerr << "Waiting... \n";
    cv.wait(lk, []
            { return i == 1; });
    std::cerr << "...finished waiting. i == 1\n";
}

void signals()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        std::lock_guard<std::mutex> lk(cv_m);
        std::cerr << "Notifying...\n";
    }
    cv.notify_all();

    std::this_thread::sleep_for(std::chrono::seconds(1));

    {
        std::lock_guard<std::mutex> lk(cv_m);
        i = 1;
        std::cerr << "Notifying again...\n";
    }
    cv.notify_all();
}

using namespace std;
mutex mtx;
// condition_variable cv;

void waits1()
{
    std::unique_lock<std::mutex> lk(mtx); // vc  x
    std::cout << "Waiting..." << std::this_thread::get_id() << std::endl;
    cv.wait(lk, [] // mtx,x
            { return i == 1; });
    std::cout << "finished waiting..." << std::this_thread::get_id() << std::endl;
}

void signals1()
{
    this_thread::sleep_for(std::chrono::seconds(1));
    {
        unique_lock<mutex> lk(mtx);
        std::cout << "notify..." << std::endl;
    }
    cv.notify_all();
    this_thread::sleep_for(std::chrono::seconds(1));
    {
        unique_lock<mutex> lk(mtx);
        i = 1;
        std::cout << "notify again..." << std::endl;
    }
    cv.notify_all();
}

int main()
{
    std::thread t1(waits1), t2(waits1), t3(waits1), t4(signals1);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}