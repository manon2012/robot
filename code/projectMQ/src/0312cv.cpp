#include <string>
#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <unistd.h>
using namespace std;

mutex mtx;
condition_variable cv;
bool ready;
bool process;
string data = "main data";

void worker_thread()
{
    unique_lock<mutex> lock(mtx);
    cv.wait(lock, []
            { return ready; });
    data += "2024";

    cout << "worker thread done" << endl;
    process = true;
    cv.notify_one();
}

main()
{
    thread t1(worker_thread);

    cout << "main begin ..." << endl;

    {
        lock_guard<mutex> lock(mtx);
        ready = true;
        cv.notify_one();
    }

    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []
                { return process; });
    }
    cout << "back to main data: " << data << endl;

    t1.join();
}