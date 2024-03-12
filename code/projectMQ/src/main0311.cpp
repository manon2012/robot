#include <string>
#include <vector>
#include <mutex>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <condition_variable>

using namespace std;

void Test(int x, string y)
{
    while (x-- > 0)
    {
        std::cout << y << std::endl;
    }
}

typedef void (*pfun)(int, string);

class call
{
public:
    void setfun(pfun fun)
    {
        m_fun = fun;
    }
    void letrun(int x, string y)
    {
        m_fun(x, y);
    }

private:
    pfun m_fun;
};

int count = 0;
mutex mtx;
void add()
{
    // mutex mtx;

    for (int i = 0; i < 100000; i++)
    {
        // mtx.lock();
        // lock_guard<mutex> lock(mtx);
        unique_lock<mutex> lock(mtx);
        count++;
        // mtx.unlock();
    }
}

int ticketcount = 100;
// mutex mtx;
void sellticket(string x)
{
    while (ticketcount > 0)
    {
        lock_guard<mutex> lock(mtx);
        if (ticketcount > 0)
        {
            std::cout << "ticket id:" << std::this_thread::get_id() << " name: " << x << " sell ticket:" << ticketcount << std::endl;
            ticketcount--;
        }
    }
    // usleep(6);
}

int count1 = 1;
int limit = 100;
condition_variable cv;
void printOdd()
{
    while (count1 < limit)
    {
        // lock_guard<mutex> lock(mtx);
        std::unique_lock<std::mutex> lock(mtx);
        // std::cout << "count1: " << count1 << std::endl;
        if (count1 % 2 == 0)
        {
            cv.wait(lock);
        }
        else
        {
            std::cout << "printodd " << count1 << std::endl;
            count1++;
            cv.notify_one();
        }
    }
}

void printEven()
{
    while (count1 < limit)
    {
        std::unique_lock<std::mutex> lock(mtx);
        // std::cout << "count1: " << count1 << std::endl;
        if (count1 % 2 == 1)
        {
            cv.wait(lock);
        }
        else
        {
            std::cout << "printeven" << count1 << std::endl;
            count1++;
            cv.notify_one();
        }
    }
}

// from pdf
//  std::condition_variable cond;
//  void printOdd()
//  {
//      while (count1 <= limit)
//      {
//          std::unique_lock<std::mutex> lck(mtx);
//          if (count1 % 2 == 0)
//          {
//              cond.wait(lck);
//          }
//          else
//          {
//              std::cout << "Odd thread: " << count1 << std::endl;
//              count1++;
//              cond.notify_one();
//          }
//      }
//  }
//  void printEven()
//  {
//      while (count1 <= limit)
//      {
//          std::unique_lock<std::mutex> lck(mtx);
//          if (count1 % 2 == 1)
//          {
//              cond.wait(lck);
//          }
//          else
//          {
//              std::cout << "Even thread: " << count1 << std::endl;
//              count1++;
//              cond.notify_one();
//          }
//      }
//  }
int main()
{
    int n = 100;
    thread p1(printOdd);
    thread p2(printEven);
    p1.join();
    p2.join();
    return 0;

    thread t1(sellticket, "A");
    thread t2(sellticket, "B");
    t1.join();
    t2.join();

    return 0;

    int boys = 2;
    int girls = 3;
    auto total = [boys, girls]() -> int
    {
        return boys + girls;
    };

    std::cout << typeid(total).name() << std::endl;
    std::cout << total() << std::endl;

    double abc = 1.5;

    decltype(abc) newabc;
    newabc = 1;
    std::cout << typeid(newabc).name() << std::endl;

    return total();
    // thread t1(add);
    // thread t2(add);
    // t1.join();
    // t2.join();
    // std::cout << count << std ::endl;

    // call c1;
    // c1.setfun(Test);
    // c1.letrun(3, "hello world");
    // return 0;
}

// struct Box
// {
//     explicit Box(int num) : num_things{num} {}

//     int num_things;
//     std::mutex m;
// };

// void transfer(Box &from, Box &to, int num)
// {
//     // don't actually take the locks yet
//     std::unique_lock<std::mutex> lock1(from.m, std::defer_lock);
//     std::unique_lock<std::mutex> lock2(to.m, std::defer_lock);

//     // lock both unique_locks without deadlock
//     std::lock(lock1, lock2);

//     from.num_things -= num;
//     to.num_things += num;

//     // 'from.m' and 'to.m' mutexes unlocked in 'unique_lock' dtors
// }

// int main()
// {
//     Box acc1(100);
//     Box acc2(50);

//     std::thread t1(transfer, std::ref(acc1), std::ref(acc2), 10);
//     std::thread t2(transfer, std::ref(acc2), std::ref(acc1), 5);

//     t1.join();
//     t2.join();
// }