#include <iostream>
#include <thread>
#include <mutex>
#include <string.h>
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

class Complex
{
   friend ostream &operator<<(ostream &cout, const Complex &other);
   friend Complex DoAPL(const Complex&c1 , const Complex &c2);

public:
   Complex(double x = 0, double y = 0) : m_real(x), m_imag(y)
   {
   }

   Complex(const Complex &other)
   {
      this->m_real = other.m_real;
      this->m_imag = other.m_imag;
   }

   Complex operator=(const Complex &other)
   {
      this->m_real = other.m_real;
      this->m_imag = other.m_imag;
   }

   Complex &operator+=(const Complex &other)
   {
      this->m_real += other.m_real;
      this->m_imag += other.m_imag;
      return *this;
   }

   
   ~Complex()
   {
   }

private:
   double m_real;
   double m_imag;
};
ostream &operator<<(ostream &cout, const Complex &other)
{
   cout << "other.real: " << other.m_real << ",other.imag: " << other.m_imag << std::endl;
   return cout;
}

Complex DoAPL(const Complex&c1 , const Complex &c2) 
{
   return Complex(c1.m_real + c2.m_real, c1.m_imag+c2.m_imag);
}

   Complex &operator+(const Complex &C1,const Complex &C2)
   {
         return DoAPL(C1,C2);
   }

void test01()
{
   Complex a;
   Complex b(1.0, 2.0);
   Complex c(b);
   Complex d;
   d = c;
   std::cout << a << std::endl;
   std::cout << b << std::endl;
   std::cout << c << std::endl;
   std::cout << d << std::endl;
   cout << "test01" << endl;
}

int main()
{
   test01();
   cout << "hello,world! tempalte2013" << endl;

   return 0;
}