#include <iostream>
#include <thread>
#include <mutex>
#include <string.h>
#include "Apple.h"
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
   friend Complex& _doapl( Complex * ,const Complex &r);

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

   Complex &operator+=(const Complex &r)
   {
      
      return _doapl(this,r);
   }
   double real() const { return m_real;}
   double imag() const { return m_imag; }
   
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

Complex& _doapl(Complex * obj , const Complex &r) 
{
   obj->m_real += r.real();
   obj->m_imag += r.imag();
   return *obj;
}

Complex operator +(const Complex &l,const Complex &r)
{
      return Complex(l.real()+r.real(),l.imag()+r.imag());
}

Complex operator+(const Complex &r, double x)
{
   return Complex(r.real()+x,r.imag());
}

Complex operator+(double x , const Complex&r)
{
   return Complex(x+r.real(),r.imag());
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

   d+=c;
   std::cout << d << std::endl;

   std::cout<<d+2<<std::endl;
   std::cout<<2+d<<std::endl;

   cout << "test01" << endl;
}

int main()
{
   test01();
   cout << "hello,world! tempalte2013" << endl;

   return 0;
}