#include <iostream>
using namespace std;
#include <thread>
#include <mutex>
#include<string.h>
#include "../include/Apple.h"

#include <gtest/gtest.h>

int add(int a, int b)
{
   return a + b;
}

TEST(addTest, positivenum)
{
   EXPECT_EQ(2,add(1,1));
}

TEST(addTest, negativenum)
{
   EXPECT_EQ(-2,add(-1,-1));
}

TEST(addTest, zeronum)
{
   EXPECT_EQ(-2,add(0,0));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


class CATString{

   friend ostream& operator<<(ostream&cout, const CATString& other);
public:
    CATString(const char* string=0)
    {
      if (string)
      {
         m_data = new char[strlen(string)+1];
         strcpy(m_data,string);
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
         delete [] m_data;
         m_data = NULL;
      }

    }

    CATString(const CATString& other)
    {
      m_data = new char[strlen(other.m_data) + 1];
      strcpy(m_data, other.m_data);
    }
    
    CATString& operator=(const CATString& other){
       if (this != &other)
       {
         delete[] m_data;
         m_data = new char[strlen(other.m_data) + 1];
         strcpy(m_data, other.m_data);
       }
       return *this;
    }

    char* GetString() const {
      return m_data;
    }

private:
    char* m_data;

};

ostream& operator<<(ostream&cout, const CATString& other) {
    cout << other.m_data << endl;
    return cout;

}


class FruitFactory
{
public:

   virtual Fruit* CreateFruit()=0;

};

class AppleFactory: public FruitFactory 
{
public:
   Fruit* CreateFruit()
   {
      return new Apple;
   }

};


void test01()
{
    CATString s1;
    CATString s2("hello");
    s1=s2;

    s1 = s1;
    CATString s3(s2);

    cout<<s1.GetString()<<endl;
    cout<<s2.GetString()<<endl;
    cout<<s3.GetString()<<endl;

    cout<<s1<<endl; 
    cout<<s2<<endl;
    cout<<s3<<endl;

}

void test02()
{
   //FruitFactory *  ff= new AppleFactory;
   


}

int n=0;
std::mutex  mtx;
void threadFun()
{
  while(n<10)
  {

   mtx.lock();
   n++;
   cout<<"id:"<<std::this_thread::get_id()<<", n= "<<n<<endl;

   mtx.unlock();

   std::this_thread::sleep_for(std::chrono::seconds(1));

  }

}

void threadFun1(int x)
{
   std::this_thread::sleep_for(std::chrono::seconds(1));
   std::cout<<"in threadFun1"<<std::endl;
}


void threadFun2(const char* url)
{
   std::this_thread::sleep_for(std::chrono::seconds(1));
   std::cout<<"in threadFun2"<<std::endl;
}


int main0()
{

    
   //  double firstpose[6] = {0.0};
	// for(int i =0; i<2; i++) 
	// {
   //     for(int j = 0; j<2; j++) 
	//    {
   //      firstpose[0] = 0.3*(j+1);
   //      firstpose[1] = 0.4*(i+1);

	// 	  printf("%f,%f\n",firstpose[0] ,firstpose[1]); 

	//    }

	// }

   //return 0;

    thread thread1(threadFun1,2023);
    cout<<"this_threadID:"<<std::this_thread::get_id()<<endl;
    cout<<"thread1ID:"<<thread1.get_id()<<endl;

    thread thread2 = std::thread(threadFun2,"www.ca.com");
    cout<<"thread2ID:"<<thread2.get_id()<<endl;

    thread1.detach();
    if(thread2.joinable())
    {
       thread2.join();
    }
    cout<<"main finished"<<endl;
    //thread1.join();
    //thread2.join();



    test02();

    return 0;

    
    //test01();

   return 0;

   std::thread t1(threadFun);
   std::thread t2(threadFun);
   t1.join();
   t2.detach();

   cout<<"haha"<<endl;


}   