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
  friend ostream & operator<<(ostream &os, const CATString &other);
  public:
  CATString(const char *str="")
  {
   if (str)
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
     strcpy(m_data, other.m_data);
  }

  CATString& operator=(const CATString & other)
  {
     if(this!=&other)
     {
        delete [] this->m_data;
        this->m_data = new char[strlen(other.m_data)+1];
        strcpy(m_data, other.m_data);
     }
     return * this;
  }

  ~CATString()
  {
    if (m_data)
    {
        delete[] m_data;
        m_data = NULL;
    }

  }

  char* getchar() const
  {
     return this->m_data;
  }

  private:
  char * m_data;

};

ostream & operator<<(ostream &os, const CATString &other)
{
   os << other.m_data;
   return os;
}

class Complex
{
public:
  Complex(double x=0, double y=0):real(x), imag(y)
  {
     std::cout<<"init done"<<std::endl;
  }
  Complex(const Complex & other)
  {
      this->real = other.real;
      this->imag = other.imag;
  }

  Complex& operator=(const Complex & other)
  {
      this->real = other.real;
      this->imag = other.imag;
  }

  double Real()
  {
   return this->real;
  }

  double Imag()
  {
   return this->imag;
  }
private:
  double real;
  double imag;

};

Complex& operator+=(const Complex, double value)
{
   return Complex(this->real + value, this->imag);
}

Complex& operator+=(double value, const Complex& other)
{

}

void test01()
{

   CATString c1;
   CATString c2("world");
   CATString c3(c2);
   CATString c4;
   c4 =  c2;
 

   std::cout<<c1<<std::endl;
   std::cout<<c2<<std::endl;
   std::cout<<c3<<std::endl;
   std::cout<<c4<<std::endl;
  
   std::cout<<c4.getchar()<<std::endl;



}

int main()
{
   test01();
   cout<<"hello,world! p0627"<<endl;

   return 0;


}   