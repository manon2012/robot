// sellticket.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <list>
#include <mutex>
using namespace std;
mutex mtx;
int gcount = 10;

void sellticket1(int index)
{
    mtx.lock();
    while (gcount > 0)
    { 
		cout << "sellticket" << index << ":" << gcount << endl;
		gcount--;
       
    }
    mtx.unlock();
    this_thread::sleep_for(chrono::microseconds(10));
}

void sellticket2(int index)
{
	while (gcount > 0)
	{
        mtx.lock();
		cout << "sellticket" << index << ":" << gcount << endl;
		gcount--;
        mtx.unlock();
		
	}
    this_thread::sleep_for(chrono::microseconds(10));

}

void sellticket3(int index)
{
	while (gcount > 0)
	{
        mtx.lock();
        if (gcount>0)
        {
			cout << "sellticket" << index << ":" << gcount << endl;
			gcount--;
        }
        mtx.unlock();
	}
	
    //it's none of your business
    //this_thread::sleep_for(chrono::microseconds(10));

}

void sellticket4(int index)
{
	while (gcount > 0)
	{
		mtx.lock();
		if (gcount > 0)
		{
			cout << "sellticket" << index << ":" << gcount << endl;
			gcount--;
		}
		mtx.unlock();
        this_thread::sleep_for(chrono::microseconds(10));
	}
}

void sellticket5(int index)
{
	while (gcount > 0)
	{
		lock_guard<mutex> lock(mtx); 
		if (gcount > 0)
		{
			cout << "sellticket" << index << ":" << gcount << endl;
			gcount--;
		}
		this_thread::sleep_for(chrono::microseconds(10));
	}
}

void sellticket6(int index)
{
	while (gcount > 0)
	{
		{    //�������ں����������ݺͷ��ع�����  ֻ�����ڼ򵥵��ٽ������뻥��
			lock_guard<mutex> lock(mtx);  //lock_guradû�п������� ��������
			if (gcount > 0)
			{
				cout << "sellticket" << index << ":" << gcount << endl;
				gcount--;
			}
		}
		this_thread::sleep_for(chrono::microseconds(10));
	}
	
}


void sellticket7(int index)
{
	while (gcount > 0)
	{
		{   
			unique_lock<mutex> lck(mtx);//��ֵ�ÿ��� 
			if (gcount > 0)
			{
				cout << "sellticket" << index << ":" << gcount << endl;
				gcount--;
			}
		}
		this_thread::sleep_for(chrono::microseconds(10));
	}

	/*
	  unique_lock<mutex> lck(mtx);   //�����ں������ù����� �߳�ͨ��
	  cv.wait(lck) 1ʹ�߳̽���ȴ�״̬ 2 lck.unlock���԰�mtx�ͷŵ�
	*/


	/*
	vc.notify_all()
	֪ͨ��cv�ϵȴ����̣߳����������ˣ������ɻ���~
	������cv�ϵȴ����̣߳��յ�֪ͨ���ӵȴ�״̬->����״̬->��ȡ��������->�̼߳�������ִ��
	*/
}

int main()
{
    list<thread> tlist;
    for (int i=0;i<3; i++)
    {
        tlist.push_back(thread(sellticket6, i));
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
sellticket1:10
sellticket1:9
sellticket1:8
sellticket1:7
sellticket1:6
sellticket1:5
sellticket1:4
sellticket1:3
sellticket1:2
sellticket1:1
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


//t3
/*
ellticket0:10
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

//t4
/*
sellticket0:10
sellticket1:9
sellticket2:8
sellticket0:7
sellticket2:6
sellticket1:5
sellticket1:4
sellticket0:3
sellticket2:2
sellticket1:1
Hello World!

*/


//t5
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
*/


//t6
/*
sellticket0:10
sellticket1:9
sellticket2:8
sellticket2:7
sellticket0:6
sellticket1:5
sellticket2:4
sellticket1:3
sellticket0:2
sellticket2:1
Hello World!
*/