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

class CATString
{
   friend ostream &operator<<(ostream &os, const CATString &other);

public:
   CATString(const char *str = 0)
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

   ~CATString()
   {
      if (m_data)
      {
         delete[] m_data;
         m_data = nullptr;
      }
   }

private:
   char *m_data;
};

ostream &operator<<(ostream &os, const CATString &other)
{
   os << other.m_data;
   return os;
}

void test01()
{
   CATString a;
   CATString b("string");
   CATString c;
   c = b;
   CATString d("robot");

   std::cout << a << std::endl;
   std::cout << b << std::endl;
   std::cout << c << std::endl;
   std::cout << d << std::endl;
}

class Complex
{
   double re, im;
   friend Complex &__doapl(Complex *ths, const Complex &other);

public:
   Complex(double a = 0, double b = 0) : re(a), im(b)
   {
   }
   Complex(const Complex &other) : re(other.re), im(other.im)
   {
   }
   Complex &operator=(const Complex &other)
   {
      this->re = other.re;
      this->im = other.im;
      return *this;
   }

   Complex &operator+=(const Complex &other)
   {
      return __doapl(this, other);
   }

   double real() const { return re; }
   double imag() const { return im; }
};

double REAL(const Complex &p)
{
   return p.real();
}
double IMAG(const Complex &p)
{
   return p.imag();
}

Complex &__doapl(Complex *ths, const Complex &other)
{
   ths->re += other.real();
   ths->im += other.imag();
   return *ths;
}

ostream &operator<<(ostream &os, const Complex &other)
{
   os << other.real() << "," << other.imag();
   return os;
}
void test02()
{
   Complex abc;
   Complex a1(1, 1);
   Complex a2(a1);
   Complex a3;
   a3 = a2;

   a3 += a2;

   cout << abc << endl;
   cout << a1 << endl;
   cout << a2 << endl;
   cout << a3 << endl;
}

int tcp[2] = {0};
bool flag = true;
int n = 99;
int i = 0;
void test03()
{
   while (1)
   {

      if (n < 100)
      {
         cout << "<100" << endl;
         n++;
      }
      else if (n < 110)
      {
         cout << "<110" << endl;
         n++;
         
         tcp[i]=n;
         std::cout <<"n:"<<n<<endl;
         std::cout <<"tcp["<<i<<"] = " << tcp[i] << endl;
         i++;
      }
      else
      {
         cout << "110" << endl;

         //flag = false;
          cout <<"flag:"<< flag << endl;
         break;
      }
   }
}
int main()
{
   test03();
   cout << "hello,world! tempalte2013" << endl;

   return 0;
}