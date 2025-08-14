#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>
#include <condition_variable>

using namespace std;

int ticketcount = 10;
mutex mtx;

void sellticket1()
{
   //std::cout<<"sellticket1..."<<std::endl;
   while(ticketcount>0)
   {
       {lock_guard<mutex> lck(mtx);

       //mtx.lock();
       std::cout<<"sellticket1:"<<ticketcount<<std::endl;
       ticketcount--;
       //mtx.unlock();
       }
       sleep(1);
   }


}


void sellticket2()
{
   //std::cout<<"sellticket2..."<<std::endl;
   while(ticketcount>0)
   {

        {lock_guard<mutex> lck(mtx);

       //mtx.lock();
       std::cout<<"sellticket2:"<<ticketcount<<std::endl;
       ticketcount--;
       }
       //mtx.unlock();
       sleep(1);
   }


}

bool flag = true;
condition_variable cv;
int n = 10;

void sellticketA1()
{
    while (n>0) {
        std::unique_lock<std::mutex> lck(mtx);
        cv.wait(lck,[]{return flag;});
        std::cout<<this_thread::get_id()<<"->sell: "<<n<<std::endl;
        n--;

        flag = false;
        cv.notify_one();

    }

}

void sellticketB1()
{
    while (n>0) {
        std::unique_lock<std::mutex> lck(mtx);
        cv.wait(lck,[]{return !flag;});
        std::cout<<this_thread::get_id()<<"->sell: "<<n<<std::endl;
        n--;

        flag = true;
        cv.notify_one();

    }

}


int pn = 6;
int avsignal =1;
void printA()
{
    while(pn>0)
      {
          unique_lock<mutex> lck(mtx);
          cv.wait(lck,[]{return avsignal==1;});
          if(pn>0)
          {
              std::cout<<this_thread::get_id()<<"pthreaA:"<<"A"<<pn<<std::endl;
              pn--;
          }

          avsignal = 2;
          cv.notify_all();
      }


}

void printB()
{
    while(pn>0)
    {
          unique_lock<mutex> lck(mtx);
          cv.wait(lck,[]{return avsignal==2;});
          if(pn>0)
          {
              std::cout<<this_thread::get_id()<<"pthreadB:"<<"B"<<pn<<std::endl;
              pn--;
          }

          avsignal = 3;
          cv.notify_all();
}
}

void printC()
    {
        while(pn>0)
        {
              unique_lock<mutex> lck(mtx);
              cv.wait(lck,[]{return avsignal==3;});
              if(pn>0)
              {
                  std::cout<<this_thread::get_id()<<"pthreadB:"<<"C"<<pn<<std::endl;
                  pn--;
              }

              avsignal = 1;
              cv.notify_all();

    }
}

void printall()
{


}

int main()
{

    thread t1(printA);
    thread t2(printB);
    thread t3(printC);

    t1.join();
    t2.join();
    t3.join();

    cout << "Hello World!" << endl;
    return 0;
}
