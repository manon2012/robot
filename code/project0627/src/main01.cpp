#include <iostream>
#include <thread>
#include <mutex>
#include <string.h>
//#include "../include/Apple.h"
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
   CATString(const char *str = "")
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
         delete[] this->m_data;
         this->m_data = new char[strlen(other.m_data) + 1];
         strcpy(m_data, other.m_data);
      }
      return *this;
   }

   ~CATString()
   {
      if (m_data)
      {
         delete[] m_data;
         m_data = NULL;
      }
   }

   char *getchar() const
   {
      return this->m_data;
   }

private:
   char *m_data;
};

ostream &operator<<(ostream &os, const CATString &other)
{
   os << other.m_data;
   return os;
}

class Complex
{
public:
   Complex(double x = 0, double y = 0) : real(x), imag(y)
   {
      std::cout << "init done" << std::endl;
   }
   Complex(const Complex &other)
   {
      this->real = other.real;
      this->imag = other.imag;
   }

   Complex &operator=(const Complex &other)
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

// contents are not sure
//  Complex& operator+=(const Complex&other, double value)
//  {
//     return Complex(other.Real() + value, other.Imag());
//  }

Complex &operator+=(double value, const Complex &other)
{
}

void test01()
{

   CATString c1;
   CATString c2("world");
   CATString c3(c2);
   CATString c4;
   c4 = c2;

   std::cout << c1 << std::endl;
   std::cout << c2 << std::endl;
   std::cout << c3 << std::endl;
   std::cout << c4 << std::endl;

   std::cout << c4.getchar() << std::endl;
}

// int main()
// {
//    test01();
//    cout<<"hello,world! p0627"<<endl;

//    return 0;

// }

#include <fstream>

int main0()
{
   ifstream infile;
   infile.open("data.txt");
   if (infile.is_open())
   {
      string line;
      while (getline(infile, line))
      {
         cout << line << endl;
      }
      infile.close();
   }
   else
   {
      cout << "Error opening file" << endl;
   }
   return 0;
}

class Animal
{
public:
   virtual void talk()
   {
      std::cout << "Animal talk" << std::endl;
   }
};

class CAT : public Animal
{
public:
   void talk()
   {
      std::cout << "Cat talk" << std::endl;
   }
};

void dotalk(Animal *obj)
{
   obj->talk();
}

class CString
{
public:
   CString(const char *str = 0)
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
   CString(const CString &other)
   {
      m_data = new char[strlen(other.m_data) + 1];
      strcpy(m_data, other.m_data);
   }
   CString &operator=(const CString &other)
   {
      if (this != &other)
      {
         delete[] m_data;
         m_data = new char[strlen(other.m_data) + 1];
         strcpy(m_data, other.m_data);
      }
      return *this;
   }

   ~CString()
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

int addit(int A, int B)
{
   return A + B;
}

typedef int (*Fun)(int a, int b);

Fun abc = addit;

void test02()
{
   using namespace std;
   const char *test01 = "helloworld";
   string test02 = "helloworld";
   cout << strlen(test01) << endl;
   cout << sizeof(test02) << endl;
}

void test03()
{
   int a;

   cout << "&a:" << &a << endl;
   cout << "a:" << a << endl;
}

class TRIstring
{

public:
   TRIstring(const char *str = nullptr)
   {
   }
   TRIstring(const TRIstring &other)
   {
   }

   TRIstring operator=(const TRIstring &other)
   {
   }

   ~TRIstring()
   {
   }

private:
   char *m_data;
};


void testfunc()
{
   char s1[10]="hello";
   char s2[10]="world";
   cout<<strlen(s1)<<endl;
   cout<<sizeof(s2)<<endl;

}


class Fruit{
   public:
 virtual void showname()=0;

};
class Apple: public Fruit
{
   public:
   void showname()
   {
      cout<<"Apple"<<endl;
   }
};

class Banana: public Fruit
{
   public:
   void showname()
   {
      cout<<"Banana"<<endl;
   }
};

class FruitFactory
{
public:
    virtual Fruit* createFruit()=0;


};
class AppleFactory:public FruitFactory
{
public:
   Fruit* createFruit()
   {
      return new Apple;
   }

};
class BananaFactory:public FruitFactory
{
public:
   Fruit* createFruit()
   {
      return new Banana;
   }

};

void test001()
{
   FruitFactory* ff = new AppleFactory;
   Fruit * f = ff->createFruit();
   f->showname();

   ff = new BananaFactory();
   f = ff->createFruit();
   f->showname();

}

class SimpleFactory
{
 public:

    static Fruit* createFruit(const char* name=nullptr)
    {
        Fruit* p = nullptr;
        if(name == "Apple")
        {
         p = new Apple;
        }
        else if(name == "Banana")
        {
         p = new Banana;
        }
        else{
         p = nullptr;
        }
    }

};

void test002()
{
   // SimpleFactory* factory = new SimpleFactory;
   // Fruit* p = factory->createFruit("Apple");
   // p->showname();

   // p = factory->createFruit("Banana");
   // p->showname();
   Fruit *p = SimpleFactory::createFruit("Banana");
   p->showname();

   p = SimpleFactory::createFruit("Apple");
   p->showname();

}

#include <list>
class Subject;
class Observer
{
public:
   Observer(string a):m_str(a)
   {

   }
   void update(Subject *obj, int value)
   {
      cout<<"Subject:"<<obj<<"update value: "<<value<<endl;
   }
private:
   string m_str;
};

class Subject
{
public:
   Subject(int A): m_A(A) {}

   void attach(Observer* obs)
   {
      m_list.push_back(obs);
   }
   void detach(Observer* obs)
   {
      m_list.remove(obs);
   }
   void setValue(int value)
   {
      m_A = value;
      notify();
   }
   void notify()
   {
      for (auto x: m_list)
      {
           x->update(this,m_A);
      }
   }

private:
   list<Observer*> m_list;
   int m_A;

};

void test003()
{

   Observer* obs1 = new Observer("t1");
   Observer* obs2 = new Observer("t2");
   Subject* subject1 = new Subject(100);

   subject1->attach(obs1);
   subject1->attach(obs2);
   subject1->setValue(1001);
 
   subject1->detach(obs2);

   subject1->setValue(100);

}


class AbsHero
{
public:
    virtual void update()=0;
};

class ChinaHero: public AbsHero
{
public:
   void update()
   {
      cout<<"chinahero update"<<endl;  
   }

};

class JHero: public AbsHero
{
public:
   void update()
   {
      cout<<"jhero update"<<endl;
   }
};

class AbsBoss
{
public:
virtual void attach(AbsHero* hero)=0;
virtual void detach(AbsHero* hero)=0;
virtual void notify()=0;

protected:
 list<AbsHero*> m_list;

};

class EarthBoss: public AbsBoss
{
  void attach(AbsHero* hero)
  {
     m_list.push_back(hero);
  }

  void detach(AbsHero* hero)
  {
     m_list.remove(hero);
  }

  void notify()
  {
   for(auto& item : m_list)
   {
       item->update();
   }
  }

};

void test004()
{
    AbsHero* h1 = new ChinaHero;
    AbsHero* h2 = new JHero;

    AbsBoss* ab = new EarthBoss;

    ab->attach(h1);
    ab->attach(h2);

    ab->notify();
   

}


class Business
{
public:
  virtual void charge(int value)=0;

};

class CMCC: public Business
{
public:
   void charge(int value)
   {
      cout<<"Charge: "<<value<<endl;
   }
};

class CMCCProxy : public Business
{
public:
  void charge(int value)
  {
   if (value<100)
   {
      cout<<"Charge min 100 "<<endl;
   }

   else{
      if(m_cmcc==nullptr)
      {
         m_cmcc=new CMCC;
         m_cmcc->charge(value);
         delete m_cmcc;
      }

   }
  }

private:
  CMCC *m_cmcc;

};

void test005()
{
  
   Business *business = new CMCCProxy;
   business->charge(10);
   business->charge(100);
   delete business;

}

class WeaponStrategy
{
public:
    virtual void showit()=0;

};

class AK47: public WeaponStrategy
{
public: 
   void showit()
   {
      cout<<"Weapon AJ47"<<endl;
   }

};
class Knife: public WeaponStrategy
{
  public:
  void showit()
  {
     cout<<"Weapon Knife"<<endl;
  }

};

class character
{
public:
character(WeaponStrategy *weaponstrategy = nullptr){}
void setWS(WeaponStrategy* ws)
{
   m_ws = ws;
}
void show()
{
   m_ws->showit();
}

private:
 WeaponStrategy* m_ws;
};

void test006()
{
   character c1;
   WeaponStrategy* w1 = new AK47;
   WeaponStrategy* w2 = new Knife;
   c1.setWS(w1);
   w1->showit();

   c1.setWS(w2);
   w2->showit();

}


class ITarget
{
   public:
   virtual void process()=0;
};

class IAdaptee
{
public:
  virtual int foo()=0;
  virtual void bar(int value)=0;

};

class oldclass : public IAdaptee
{
   public:
   int foo()
   {
      cout<<"foo in old class"<<endl;
      return 0;
   }
   void bar(int arg)
   {
      cout<<"bar in old class"<<endl;
   }

};

class Adapter : public ITarget
{
  public:
  Adapter(IAdaptee* adapter=nullptr) : Ada(adapter){}
  void process()
  {
      int status = Ada->foo();
      Ada->bar(status);
  }

private:
  IAdaptee * Ada;

};

void test007()
{
    IAdaptee * Ada = new oldclass;
    ITarget * t1 = new Adapter(Ada);
    t1->process();

}

class simplefactory
{
public:
  static Fruit* createfruit(char* name)
  {
    Fruit * fp = nullptr;

    if(name == "Apple")
    {
        return new Apple; 
    }
    else if (name == "Banana")
    {
      return new Banana;
    }
    else
    {
      return new Apple;
    }
     
  }

};

void test011()
{
   Fruit* fp = simplefactory::createfruit("Apple");
   fp->showname();

   fp = simplefactory::createfruit("Banana");
   fp->showname();

   fp = simplefactory::createfruit("");
   fp->showname();
    
}



int main01()
{
   
   test011();

   Animal *obj = new CAT();
   dotalk(obj);

   std::cout << abc(100, 100);

   return 0;
}