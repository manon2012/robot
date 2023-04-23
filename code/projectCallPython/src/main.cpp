#include <iostream>
using namespace std;
#include <thread>
#include <mutex>
#include<string.h>
#include "../include/Apple.h"


//https://www.codeproject.com/Articles/820116/Embedding-Python-program-in-a-C-Cplusplus-code

#include <stdio.h>
//#include <conio.h>
#include <Python.h>

int main100()
{
	PyObject* pInt;

	Py_Initialize();

	PyRun_SimpleString("print('Hello World from Embedded Python!!!')");
	
	Py_Finalize();

	//printf("\nPress any key to exit...\n");
	//if(!_getch()) _getch();
	return 0;
}


int main()
{
	char filename[] = "pyemb7.py";
	FILE* fp;

	Py_Initialize();

	fp = _Py_fopen(filename, "r");
	PyRun_SimpleFile(fp, filename);

	Py_Finalize();
	return 0;
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


void *print_message_function( void *ptr )
{
     char *message;
     message = (char *) ptr;
     printf("%s \n", message);
}


int main0()
{
     pthread_t thread1, thread2;
     char *message1 = "Thread 1";
     char *message2 = "Thread 2";
     int  iret1, iret2;

    /* Create independent threads each of which will execute function */

     iret1 = pthread_create( &thread1, NULL, print_message_function, (void*) message1);
     iret2 = pthread_create( &thread2, NULL, print_message_function, (void*) message2);

     /* Wait till threads are complete before main continues. Unless we  */
     /* wait we run the risk of executing an exit which will terminate   */
     /* the process and all threads before the threads have completed.   */

     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL); 

     printf("Thread 1 returns: %d\n",iret1);
     printf("Thread 2 returns: %d\n",iret2);
     exit(0);
}

int main1()
{


    //two ways ctor
    thread th1(threadFun1,2023);
    cout<<"this_threadID:"<<std::this_thread::get_id()<<endl;
    cout<<"thread1ID:"<<th1.get_id()<<endl;

    thread th2 = std::thread(threadFun2,"www.ca.com");
    cout<<"thread2ID:"<<th2.get_id()<<endl;

    th1.detach();
    if(th2.joinable())
    {
       th2.join();
    }
    cout<<"main finished"<<endl;
    //thread1.join();
    //thread2.join();
}

int count=0;

//int i=0;  this will not work
mutex m;

void threadFunc1()
{
   for(int i=0;i<1000000;i++){
      m.lock();
      count++;
      m.unlock();

   }
}

void threadFunc2()
{
   for(int i=0;i<1000000;i++){
      m.lock();
      count--;
      m.unlock();

   }
}


// int sum=0;
// mutex m_mutex;
// int func(size_t num){
//   for(size_t i=0;i<num;i++){
//      //m_mutex.lock();
//      sum++;
//      //m_mutex.unlock();
//   }




int main123()
{

   //  thread t1(func,1000000);
   //  thread t2(func,1000000);
   //  t1.join();
   //  t2.join();
   //  cout<<"sum:"<<sum<<endl;
   //  return 0;


    //test02();

    //return 0;

    
    //test01();

   

   std::thread t1(threadFunc1);
   std::thread t2(threadFunc2);
   t1.join();
   t2.join();

   cout<<"haha"<<endl;
   cout<<count<<endl;
return 0;

}   




