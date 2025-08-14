
#include <thread>
#include <mutex>
#include <iostream>
#include <string.h>

using namespace std;

// https : // blog.csdn.net/qq_37172182/article/details/121795146

class Counter
{
public:
    Counter(int id, int numIters) : mId(id), mNumIters(numIters)
    {
    }
    // lock_guard
    /*
    void operator()() const{
    for(int i = 0; i < mNumIters; ++i){
    lock_guard lock(mMutex);
    cout << "Counter " << mId << " has value " << i << endl;
    }
    }*/
    // unique_lock
    void operator()() const
    {

        for (int i = 0; i < mNumIters; ++i)
        {
            unique_lock<timed_mutex> lock(mTimeMutex, 200ms);
            if (lock)
            {
                cout << "Counter " << mId << " has value " << i << endl;
            }
            // else lock 200ms
        }
    }

private:
    int mId;
    int mNumIters;
    // static mutex mMutex for lock_guard;
    static timed_mutex mTimeMutex;
};

// mutex Counter::mMutex;
timed_mutex Counter::mTimeMutex;

int main()
{
    thread t1{Counter{1, 30}};
    Counter c(2, 15);
    thread t2(c);
    thread t3(Counter(3, 10));
    t1.join();
    t2.join();
    t3.join();
    return 0;
}