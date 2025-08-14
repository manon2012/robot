#include <iostream>
#include <thread>
#include <mutex>
#include <string.h>
using namespace std;

string blackboard;

void DannyWrite(string &blackboard)
{
    blackboard += "i ";
    this_thread::sleep_for(std::chrono::milliseconds(rand() % 3));
    blackboard += "am ";
    this_thread::sleep_for(std::chrono::milliseconds(rand() % 3));
    blackboard += "Danny.\n";
    this_thread::sleep_for(std::chrono::milliseconds(rand() % 3));
}

void PeterWrite(string &blackboard)
{
    blackboard += "i ";
    this_thread::sleep_for(std::chrono::milliseconds(rand() % 3));
    blackboard += "am ";
    this_thread::sleep_for(std::chrono::milliseconds(rand() % 3));
    blackboard += "Peter.\n";
    this_thread::sleep_for(std::chrono::milliseconds(rand() % 3));
}

mutex abc;
void DannyWriteWithMutex(string &blackboard)
{
    // abc.lock();
    unique_lock<mutex> lock(abc);
    DannyWrite(blackboard);
    // abc.unlock();
}

void PeterWriteWithMutex(string &blackboard)
{
    abc.lock();
    // unique_lock<mutex> lock(abc);
    PeterWrite(blackboard);
    // abc.unlock();
}

int main()
{
    thread t1(DannyWriteWithMutex, std::ref(blackboard));
    thread t2(PeterWriteWithMutex, std::ref(blackboard));
    t1.join();
    t2.join();
    std::cout << blackboard << std::endl;
    return 0;
}