#include <iostream>
#include <thread>
#include <mutex>
#include<string.h>
#include "../include/Apple.h"
using namespace std;



/*
   modify
   1. .vscode/launch.json  
   "program": "${workspaceFolder}/build/template2023",
   2.CmakeLists.txt
   add_executable(Template2023 src/main.cpp) #添加生成可执行文件
   target_link_libraries(template2023 pthread)
        
*/

class CATString
{
friend ostream& operator<<(ostream& os, const CATString&other);
public:
CATString(char * str=0)
{
   if(str)
   {
      m_data = new char[strlen(str) + 1];
      strcpy(m_data, str);
   }
   else
   {
      m_data = new char[1];
      *m_data = '\0';
   }

}

CATString(const CATString& other)
{
    m_data = new char[strlen(other.m_data) + 1];
    strcpy(m_data, other.m_data);

}
CATString& operator=(const CATString& other)
{

   if(this != &other)
   {
      delete[] m_data;
      m_data = new char[strlen(other.m_data)+1];
      strcpy(m_data,other.m_data);
   }
   return *this;

}

~CATString()
{
   if(m_data)
   {
      delete[] m_data;
      m_data =nullptr;
   }
}

char* getData()
{
   return m_data;
}

private:
char *m_data;

};

ostream& operator<<(ostream& os, const CATString&other)
{
   os << other.m_data;
   return os;
}

void test01()
{
   CATString c1;
   CATString c2("hello");
   CATString c3(c2);
   CATString c4;
   c4=c2;

   std::cout<<c1<<std::endl;
   std::cout<<c2<<std::endl;
   std::cout<<c3<<std::endl;
   std::cout<<c4<<std::endl;

   std::cout<<c1.getData()<<std::endl;
   std::cout<<c2.getData()<<std::endl;
   std::cout<<c3.getData()<<std::endl;
   std::cout<<c4.getData()<<std::endl;


}


class Complex
{
public:

Complex(double x=0, double y=0):re(x),im(y)
{

}

Complex(const Complex& other)
{
   this->re = other.re;
   this->im = other.im;
}

Complex& operator=(const Complex& other)
{
      if(this != &other)
      {
            this->re = other.re;
   this->im = other.im;
      }
   
   return *this;
}

private:
double re;
double im;

};

void test02()
{
   Complex c1;
   Complex c2(1,1);
   Complex c3(c2);
   Complex c4;
   c4=c3;

}

int main()
{
   
   test01();
   cout<<"hello,world! tempalte2013"<<endl;

   return 0;


}   