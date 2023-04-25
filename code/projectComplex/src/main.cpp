#include <iostream>
#include <thread>
#include <mutex>
#include <string.h>
#include "Apple.h"
using namespace std;

class Complex
{
   friend Complex& _doapl(Complex *obj, const Complex &p);
   friend ostream & operator<<(ostream &, const Complex &p);
   public:
   Complex(double x = 0, double y = 0) : re(x), im(y) {}
   Complex(const Complex &p)
   {
      this->re = p.re;
      this->im = p.im;
   }

   Complex &operator=(const Complex &p)
   {
      if (this != &p)
      {
         this->re = p.re;
         this->im = p.im;
      }
      return *this;
   }

   Complex& operator+=(const Complex &p)
   {
      return _doapl(this,p);
   }

   double Real() const { return re; }
   double Img() const { return im; }

private:
   double re;
   double im;

};

Complex& _doapl(Complex *obj, const Complex &p)
{
   obj->re += p.re;
   obj->im += p.im;
   return *obj;
}

Complex operator+(const Complex &p, const Complex &q)
{

   return Complex(p.Real()+ q.Real(), p.Img()+q.Img());
}

Complex operator+(const Complex &p, double x)
{
   return Complex(p.Real()+x, p.Img());
}

ostream & operator<<(ostream &os, const Complex &p)
{
   cout<<p.re<<", "<<p.im<<endl;
   return os;
}

int test01()
{
  Complex a;
  Complex b(1.0,2.0);
  Complex c;
  c=b;
  Complex d(c);
  
  std::cout<<a<<std::endl;
   std::cout<<b<<std::endl;
    std::cout<<c<<std::endl;
     std::cout<<d<<std::endl;

  d+=c;
  std::cout<<d<<std::endl;
  
  std::cout<<d+c<<std::endl;
  std::cout<<d+2023<<std::endl;

}
main()
{
   test01();
   cout << "hello,world! tempalte2013" << endl;

   return 0;
}