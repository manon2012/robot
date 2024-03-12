#include <string>
#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <unistd.h>
using namespace std;

void Test(int x, string y)
{
    while (x-- > 0)
    {
        cout << y << endl;
    }
}

typedef void (*pfunc)(int x, string y);

class Call
{
public:
    void setfun(pfunc func)
    {
        m_func = func;
    }
    void letrun(int x, string y)
    {
        m_func(x, y);
    }

private:
    pfunc m_func;
};

int count1 = 0;
mutex mtx;
void add10000()
{
    for (int i = 0; i < 100000; i++)
    {
        unique_lock<mutex> lock(mtx);
        count1++;
    }
}

int ticketcount = 10;
void sellticket(string name)
{
    while (ticketcount > 0)
    {
        unique_lock<mutex> lock(mtx);
        if (ticketcount > 0)
        {
            cout << name << "sell ticket: " << ticketcount << endl;
            ticketcount--;
            // usleep(1);
        }
    }
}

condition_variable cv;
bool Aready = true;
bool Bready = false;
bool Cready = false;

void sellticketA()
{
    while (ticketcount > 0)
    {
        unique_lock<mutex> lock(mtx);

        cv.wait(lock, []
                { return Aready; });
        if (ticketcount > 0)
        {
            cout << "A sell ticket: " << ticketcount << endl;
            ticketcount--;
            Aready = false;
            Bready = true;
            cv.notify_all();
        }
        else
        {
            Cready = true;
            Bready = true;
            Aready = true;
            cv.notify_all();
        }
    }
}
void sellticketB()
{
    while (ticketcount > 0)
    {
        unique_lock<mutex> lock(mtx);

        cv.wait(lock, []
                { return Bready; });
        if (ticketcount > 0)
        {
            cout << "B sell ticket: " << ticketcount << endl;
            ticketcount--;
            Bready = false;
            Cready = true;
            cv.notify_all();
        }
        else
        {
            Cready = true;
            Bready = true;
            Aready = true;
            cv.notify_all();
        }
    }
}

void sellticketC()
{
    while (ticketcount > 0)
    {
        unique_lock<mutex> lock(mtx);

        cv.wait(lock, []
                { return Cready; });

        if (ticketcount > 0)
        {
            cout << "C sell ticket: " << ticketcount << endl;
            ticketcount--;
            Cready = false;
            Aready = true;
            cv.notify_all();
        }
        else
        {
            Cready = true;
            Bready = true;
            Aready = true;
            cv.notify_all();
        }
    }
}

int main()
{
    thread t3(sellticketA);
    thread t4(sellticketB);
    thread t5(sellticketC);
    // thread t3(sellticket, "A");
    // thread t4(sellticket, "B");
    t3.join();
    t4.join();
    t5.join();

    return 0;

    thread t1(add10000);
    thread t2(add10000);
    t1.join();
    t2.join();
    cout << count1 << endl;
    return 0;

    Call c1;
    c1.setfun(Test);
    c1.letrun(3, "hello world");

    return 0;
}