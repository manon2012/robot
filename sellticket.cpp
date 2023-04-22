// sellticket.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 

#include <iostream>
#include <thread>
#include <list>
#include <mutex>
using namespace std;
mutex mtx;
int gcount = 10;

void sellticket(int index)
{
    //mtx.lock(); //1 if before while, only sellticket0 do it. lock while 
    while (gcount > 0)
    {
        mtx.lock(); //2
        if (gcount > 0)
        {
			cout << "sellticket" << index << ":" << gcount << endl;
			gcount--;
        }
      
        mtx.unlock(); //2
    }


    //mtx.unlock();  //1
    this_thread::sleep_for(chrono::microseconds(10));

}

int main()
{
    list<thread> tlist;
    for (int i=0;i<3; i++)
    {
        tlist.push_back(thread(sellticket, i));
    }

    for (auto& t : tlist)
    {
        t.join();
    }


    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

//1 lock before while
/*
sellticket0:10
sellticket0:9
sellticket0:8
sellticket0:7
sellticket0:6
sellticket0:5
sellticket0:4
sellticket0:3
sellticket0:2
sellticket0:1
Hello World!
*/


//2 no double lock
/*
sellticket0:10
sellticket0 : 9
sellticket0 : 8
sellticket0 : 7
sellticket0 : 6
sellticket0 : 5
sellticket0 : 4
sellticket0 : 3
sellticket0 : 2
sellticket0 : 1
sellticket2 : 0
sellticket1 : -1
Hello World!
*/