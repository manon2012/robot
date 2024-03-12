#include <string>
#include <vector>
#include <iostream>
#include <mutex>
#include <thread>
#include <unistd.h>

using namespace std;

int total = 100;
mutex mtx;
void sellticket(string name)
{
    while (total > 0)
    {
        mtx.lock();
        if (total > 0)
        {
            std::cout << name << "sell ticket: " << total << std::endl;
            total--;
        }
        mtx.unlock();
        usleep(10);
    }
}

int main()
{
    thread t1(sellticket, "A");
    thread t2(sellticket, "B");
    t1.join();
    t2.join();
    return 0;
}