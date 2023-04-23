#include <iostream>
using namespace std;
#include <thread>
#include <mutex>
#include <string.h>
#include "../include/Apple.h"

class CATString
{

   friend ostream &operator<<(ostream &cout, const CATString &other);

public:
   CATString(const char *string = 0)
   {
      if (string)
      {
         m_data = new char[strlen(string) + 1];
         strcpy(m_data, string);
      }
      else
      {
         m_data = new char[1];

         m_data[0] = '\0';
      }
   }

   ~CATString()
   {

      if (m_data)
      {
         delete[] m_data;
         m_data = NULL;
      }
   }

   CATString(const CATString &other)
   {
      m_data = new char[strlen(other.m_data) + 1];
      strcpy(m_data, other.m_data);
   }

   CATString &operator=(const CATString &other)
   {
      if (this != &other)
      {
         delete[] m_data;
         m_data = new char[strlen(other.m_data) + 1];
         strcpy(m_data, other.m_data);
      }
      return *this;
   }

   char *GetString() const
   {
      return m_data;
   }

private:
   char *m_data;
};

ostream &operator<<(ostream &cout, const CATString &other)
{
   cout << other.m_data << endl;
   return cout;
}

class FruitFactory
{
public:
   virtual Fruit *CreateFruit() = 0;
};

class AppleFactory : public FruitFactory
{
public:
   Fruit *CreateFruit()
   {
      return new Apple;
   }
};

void test01()
{
   CATString s1;
   CATString s2("hello");
   s1 = s2;

   s1 = s1;
   CATString s3(s2);

   cout << s1.GetString() << endl;
   cout << s2.GetString() << endl;
   cout << s3.GetString() << endl;

   cout << s1 << endl;
   cout << s2 << endl;
   cout << s3 << endl;
}

void test02()
{
   // FruitFactory *  ff= new AppleFactory;
}

int n = 0;
std::mutex mtx;
void threadFun()
{
   while (n < 10)
   {

      mtx.lock();
      n++;
      cout << "id:" << std::this_thread::get_id() << ", n= " << n << endl;

      mtx.unlock();

      std::this_thread::sleep_for(std::chrono::seconds(1));
   }
}

void threadFun1(int x)
{
   std::this_thread::sleep_for(std::chrono::seconds(1));
   std::cout << "in threadFun1" << std::endl;
}

void threadFun2(const char *url)
{
   std::this_thread::sleep_for(std::chrono::seconds(1));
   std::cout << "in threadFun2" << std::endl;
}

int main151()
{

   double firstpose[6] = {0.0};
   for (int i = 0; i < 2; i++)
   {
      for (int j = 0; j < 2; j++)
      {
         firstpose[0] = 0.3 * (j + 1);
         firstpose[1] = 0.4 * (i + 1);

         printf("%f,%f\n", firstpose[0], firstpose[1]);
      }
   }

   return 0;

   thread thread1(threadFun1, 2023);
   cout << "this_threadID:" << std::this_thread::get_id() << endl;
   cout << "thread1ID:" << thread1.get_id() << endl;

   thread thread2 = std::thread(threadFun2, "www.ca.com");
   cout << "thread2ID:" << thread2.get_id() << endl;

   thread1.detach();
   if (thread2.joinable())
   {
      thread2.join();
   }
   cout << "main finished" << endl;
   // thread1.join();
   // thread2.join();

   test02();

   return 0;

   // test01();

   return 0;

   std::thread t1(threadFun);
   std::thread t2(threadFun);
   t1.join();
   t2.detach();

   cout << "haha" << endl;
}

#include <thread>
#include <mutex>
#include <iostream>

int g_i = 0;
std::mutex g_i_mutex; // protects g_i

void safe_increment()
{
   std::lock_guard<std::mutex> lock(g_i_mutex);
   for (int i = 0; i < 10; i++)
   {
      ++g_i;
      std::cout << __func__ << ": " << g_i << '\n';
   }

   std::cout << std::this_thread::get_id() << ": " << g_i << '\n';

   // g_i_mutex is automatically released when lock
   // goes out of scope
}

int main231()
{
   std::cout << __func__ << ": " << g_i << '\n';

   std::thread t1(safe_increment);
   std::thread t2(safe_increment);

   t1.join();
   t2.join();

   std::cout << __func__ << ": " << g_i << '\n';
}

#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>

std::condition_variable_any cv;
std::mutex cv_m; // This mutex is used for three purposes:
                 // 1) to synchronize accesses to i
                 // 2) to synchronize accesses to std::cerr
                 // 3) for the condition variable cv
int i = 0;

void waits()
{
   std::unique_lock<std::mutex> lk(cv_m);
   std::cerr << "Waiting... \n";
   cv.wait(lk, []
           { return i == 1; });
   std::cerr << "...finished waiting. i == 1\n";
}

void signals()
{
   std::this_thread::sleep_for(std::chrono::seconds(1));
   {
      std::lock_guard<std::mutex> lk(cv_m);
      std::cerr << "Notifying...\n";
   }
   cv.notify_all();

   std::this_thread::sleep_for(std::chrono::seconds(1));

   {
      std::lock_guard<std::mutex> lk(cv_m);
      i = 1;
      std::cerr << "Notifying again...\n";
   }
   cv.notify_all();
}

int main285()
{
   std::thread t1(waits), t2(waits), t3(waits), t4(signals);
   t1.join();
   t2.join();
   t3.join();
   t4.join();
}

#include <iostream>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex m;
// std::condition_variable cv;
std::string data;
bool ready = false;
bool processed = false;

void worker_thread()
{
   // Wait until main() sends data
   std::unique_lock<std::mutex> lk(m);
   cv.wait(lk, []
           { return ready; });

   // after the wait, we own the lock.
   std::cout << "Worker thread is processing data\n";
   data += " after processing";

   // Send data back to main()
   processed = true;
   std::cout << "Worker thread signals data processing completed\n";

   // Manual unlocking is done before notifying, to avoid waking up
   // the waiting thread only to block again (see notify_one for details)
   lk.unlock();
   cv.notify_one();
}

int main328()
{
   std::thread worker(worker_thread);

   data = "Example data";
   // send data to the worker thread
   {
      std::lock_guard<mutex> lk(m);
      ready = true;
      std::cout << "main() signals data ready for processing\n";
   }
   cv.notify_one();

   // wait for the worker
   {
      std::unique_lock<mutex> lk(m);
      cv.wait(lk, []
              { return processed; });
   }
   std::cout << "Back in main(), data = " << data << '\n';

   worker.join();
}

#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include <mutex>
// #include<Windows.h>

class demo
{
private:
   condition_variable is_full;
   condition_variable is_empty;
   mutex mtx;
   vector<std::thread> tpool;

private:
   queue<int> item_buff;
   const int buffsize;
   static int item_id;
   int c_no, p_no;

private:
   void producItem()
   {
      while (true)
      {
         std::unique_lock<mutex> lck(mtx);
         while (item_buff.size() == buffsize)
         {
            is_full.wait(lck);
         }
         item_id = item_id++ % buffsize;
         item_buff.push(item_id);
         cout << "product item id: " << item_id << endl;
         lck.unlock();
         is_empty.notify_all();
         //sleep(10);
          std::this_thread::sleep_for(std::chrono::seconds(10));

      }
   }
   void consumeItem()
   {
      while (true)
      {
         std::unique_lock<mutex> lck(mtx);
         while (item_buff.empty())
         {
            cout << "wait product" << endl;
            is_full.notify_one();
            is_empty.wait(lck);
         }
         cout << "customer id : " << this_thread::get_id() << endl;
         cout << "consume Item id: " << item_buff.front() << endl;
         item_buff.pop();
         lck.unlock();
      }
   }

public:
   demo(int size = 10, int pno = 1, int cno = 5) : buffsize(size), p_no(pno), c_no(cno){};
   void run()
   {
      productTask();
      customerTask();
      for (auto &i : tpool)
      {
         i.join();
      }
   }
   void productTask()
   {
      for (int i = 0; i < p_no; i++)
      {
         tpool.emplace_back(thread(&demo::producItem, this));
      }
   }
   void customerTask()
   {
      for (int i = 0; i < c_no; i++)
      {
         tpool.emplace_back(thread(&demo::consumeItem, this));
      }
   }
};

int demo::item_id = 0;

int main416()
{
   demo t;
   t.run();
   return 0;
}



#include <iostream>
#include <deque>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;
 
deque<int> q;
mutex mt;
condition_variable cond;
 
void thread_producer()
{
    int count = 10;
    while (count > 0)
    {
        unique_lock<mutex> unique(mt);
        q.push_front(count);
        unique.unlock();
        cout << "producer a value: " << count << endl;
        cond.notify_one();
        this_thread::sleep_for(chrono::seconds(1));
        count--;
    }
}
 
void thread_consumer()
{
    int data = 0;
    while (data != 1)
    {
        unique_lock<mutex> unique(mt);
        while (q.empty())
            cond.wait(unique);
        data = q.back();
        q.pop_back();
        cout << "consumer a value: " << data << endl;
        unique.unlock();
    }
}
 
int main()
{
    thread t1(thread_consumer);
    thread t2(thread_producer);
    t1.join();
    t2.join();
    return 0;
}




#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <vector>
static const int repository_size = 10;//循环队列的大小
static const int item_total = 20;//要生产的产品数目
 
//std::mutex mtx;//互斥量，保护产品缓冲区
std::mutex mtx_counter;//互斥量，保护产品计数器
 
std::condition_variable repo_not_full;//条件变量指示产品缓冲区不满
std::condition_variable repo_not_empty;//条件变量指示产品缓冲区不为空，就是缓冲区有产品
 
int item_buffer[repository_size];//产品缓冲区，这里使用了一个循环队列
 
static std::size_t read_position = 0;//消费者读取产品的位置
static std::size_t write_position = 0;//生产者写入产品的位置
 
static std::size_t item_counter = 0;//消费者消费产品计数器
 
std::chrono::seconds t(1);//a  new feature of c++ 11 standard
 
void produce_item(int i)
{
	std::unique_lock<std::mutex> lck(mtx);
	//item buffer is full, just wait here.
	while (((write_position + 1) % repository_size) == read_position)
	{
		std::cout << "Producer is waiting for an empty slot..." << std::endl;
		repo_not_full.wait(lck);// 生产者等待"产品库缓冲区不为满"这一条件发生.
	}                            //当缓冲区满了之后我们就不能添加产品了
 
	item_buffer[write_position] = i;//写入产品
	write_position++;
 
	if (write_position == repository_size)//写入的位置如果在队列最后则重新设置
	{
		write_position = 0;
	}
 
	repo_not_empty.notify_all();//通知消费者产品库不为空
 
	lck.unlock();//解锁
}
 
int consume_item()
{
	int data;
	std::unique_lock<std::mutex> lck(mtx);
	// item buffer is empty, just wait here.
	while (write_position == read_position)
	{
		std::cout << "Consumer is waiting for items..." << std::endl;
		repo_not_empty.wait(lck);// 消费者等待"产品库缓冲区不为空"这一条件发生.
	}
 
	data = item_buffer[read_position];//读取产品
	read_position++;
 
	if (read_position >= repository_size)
	{
		read_position = 0;
	}
 
	repo_not_full.notify_all();//通知产品库不满
	lck.unlock();
 
	return data;
}
 
void Producer_thread()
{
	for (int i = 1; i <= item_total; ++i)
	{
		//std::this_thread::sleep_for(t);
		std::cout << "生产者生产第" << i << "个产品" << std::endl;
		produce_item(i);
	}
}
 
void Consumer_thread()
{
	bool read_to_exit = false;
	while (1)
	{
		std::this_thread::sleep_for(t);
		std::unique_lock<std::mutex> lck(mtx_counter);
		if (item_counter < item_total)
		{
			int item = consume_item();
			++item_counter;
			std::cout << "消费者线程" << std::this_thread::get_id()
				<< "消费第" << item << "个产品" << std::endl;
		}
		else
		{
			read_to_exit = true;
		}
		if (read_to_exit == true)
			break;
	}
 
	std::cout << "Consumer thread " << std::this_thread::get_id()
		<< " is exiting..." << std::endl;
 
}
 
int main586()
{
	std::thread producer(Producer_thread); // 创建生产者线程.
	std::vector<std::thread> thread_vector;
	for (int i = 0; i != 2; ++i)
	{
		thread_vector.push_back(std::thread(Consumer_thread));// 创建消费者线程.
	}
	
	producer.join();
	for (auto &thr : thread_vector)
	{
		thr.join();
	}
 
}


#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
mutex mu;//互斥锁 
void test1()
{
    for(int i=0;i<5;i++)
    {
      mu.lock();//锁住 
        cout<<"test1 i = "<<i<<endl;
        mu.unlock();//释放 
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}
void test2()
{
    for(int j=0;j<5;j++)
    {
        mu.lock();
        cout<<"test2 j = "<<j<<endl;
        mu.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}
int main629()
{
    thread a(test1);
    thread b(test2);
    a.join();
    b.join();
    cout<<"main thread finish."<<endl;
} 