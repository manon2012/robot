#include <string>
#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <unistd.h>
using namespace std;

mutex mtx;
condition_variable cv;
bool Bready = true;
bool Aready = false;
int flag = 0;
int Mflag = 0;
void write3()
{
    while (flag < 10)

    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []
                { return Aready; });
        for (int i = 0; i < 3; i++)
        {
            cout << "B" << endl;
            if (i == 2)
            {
                Bready = true;
                cv.notify_all();
            }
        }
        flag++;
    }
}

int main()
{

    thread t1(write3);

    {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, []
                { return Bready; });
    }

    while (Mflag < 10)

    {
        {
            unique_lock<mutex> lock(mtx);

            for (int i = 0; i < 3; i++)
            {
                cout << "A" << endl;
                if (i == 2)
                {
                    Aready = true;
                    cv.notify_all();
                }
            }
        }
        Mflag++;
    }
    t1.join();

    return 0;
}