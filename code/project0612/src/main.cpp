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
public:
CATString(const char *str=0)
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

CATString(const CATString &other)
{
   m_data = new char[strlen(other.m_data)+1];
   strcpy(m_data,other.m_data);

}

CATString &operator=(const CATString &other)
{
   if(this != &other)
   {
      delete[] this->m_data;
      m_data = new char[strlen(other.m_data)+1];
      strcpy(m_data,other.m_data);
   }
   return *this;

}

~CATString()
{
   if(m_data)
   {
      delete [] m_data;
      m_data=nullptr;
   }
}
friend ostream & operator<<(ostream &os, const CATString &other);

private:
char * m_data;

};

class Complex
{
public:
Complex(const double x=0, const double y=0):m_real(x),m_imag(y) {}
Complex(const Complex &p)
{
    this->m_real = p.m_real;
    this->m_imag = p.m_imag;
}

Complex& operator=(const Complex&p)
{
   this->m_real = p.m_real;
   this->m_imag = p.m_imag;
   return *this;
}



private:
double m_real;
double m_imag;

};

void test01()
{
   CATString a1;
   CATString a2("hello");
   a1 = a2;
   CATString a3(a1);
   std::cout<<a1<<std::endl;
    std::cout<<a2<<std::endl;
     std::cout<<a3<<std::endl;
      //std::cout<<a4<<std::endl;


}

ostream & operator<<(ostream &os, const CATString &other)
{
   std::cout<<other.m_data<<std::endl;
   return os;
}

int main()
{

   cout<<"hello,world! tempalte2013"<<endl;
   test01();
   return 0;


}   