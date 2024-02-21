#include <iostream>
#include <thread>
#include <mutex>
#include <string.h>
// #include "../include/Apple.h"
using namespace std;

/*
   modify
   1. .vscode/launch.json
   "program": "${workspaceFolder}/build/template2023",
   2.CmakeLists.txt
   add_executable(Template2023 src/main.cpp) #添加生成可执行文件
   target_link_libraries(template2023 pthread)

*/

#include <iostream>
#include <stdio.h>
#include <string.h>

//  int main()
//  {
//         int test = 0;
//       //分配512M, 未使用
//       char * p = new char [1024*1024*512];
//      std::cout<<"new done"<<std::endl;
//      scanf("%d", &test); //等待输入

//      //使用10M
//      memset(p, 0, 1024 * 1024 * 10);
//      scanf("%d", &test); //等待输入

//      //使用50M
//      memset(p, 0, 1024 * 1024 * 50);
//      scanf("%d", &test); //等待输入
//      delete [] p;
//      return 0;

//  }

class Animal
{
public:
  void show()
  {
    cout << "Animal show" << endl;
  }
};

class Cat : public Animal
{
public:
  void show()
  {
    cout << "cat show" << endl;
  }
};

void doShow(Animal *obj)
{
  obj->show();
}

int main0()
{
  Animal *obj = new Animal;
  Cat *cat = new Cat;

  doShow(cat);
}

class Fruit
{
public:
  virtual void show()
  {
    cout << " i'am Fruit" << endl;
  }
};

class Apple : public Fruit
{
public:
  void show()
  {
    cout << "i'am Apple" << endl;
  }
};

class Banana : public Fruit
{
public:
  void show()
  {
    cout << "i'am Banana" << endl;
  }
};

class FruitFactory
{
public:
  virtual Fruit *CreateFruit()
  {
    return new Fruit;
  }
};

class AppleFactory : public FruitFactory
{
public:
  Fruit *CreateFruit()
  {
    return new Apple;
  }
};

class BananaFactory : public FruitFactory
{
public:
  Fruit *CreateFruit()
  {
    return new Banana;
  }
};

void test01()
{
  FruitFactory *ff = new AppleFactory;
  Fruit *f = ff->CreateFruit();
  f->show();

  delete ff;
  ff = new BananaFactory;
  f = ff->CreateFruit();
  f->show();
}

class SimpleFruitFactory
{
public:
  static Fruit *f;
  static Fruit *CreateFruit(string name = "")
  {
    if (name == "Apple")
    {
      f = new Apple;
    }
    else if (name == "Banana")
    {
      f = new Banana;
    }
    else
    {
      f = new Fruit;
    }
    return f;
  }
};

Fruit *SimpleFruitFactory::f = nullptr;

void test02()
{
  Fruit *f = SimpleFruitFactory::CreateFruit("Apple");
  f->show();

  f = SimpleFruitFactory::CreateFruit("Banana");
  f->show();

  f = SimpleFruitFactory::CreateFruit();
  f->show();
}

class CDocument
{
public:
  void OnFileOpen()
  {
    open();
    serilize();
    close();
  }

  void open()
  {
    cout << "Open document..." << endl;
  }

  virtual void serilize() = 0;
  void close()
  {
    cout << "Closing document..." << endl;
  }
};

class MyDocument : public CDocument
{
public:
  void serilize()
  {
    cout << "MyDocument serialize" << endl;
  }
};

void test03()
{
  MyDocument doc;
  doc.OnFileOpen();
}

class Business
{
public:
  virtual void docharge(int x) = 0;
};

class CMCC : public Business
{
public:
  void docharge(int x)
  {
    cout << "CMCC Docharge done ->" << x << endl;
  }
};

class CMCCProxy : public Business
{
public:
  void docharge(int x)
  {
    if (x < 100)
    {
      cout << "x needs to be greater than 100" << endl;
      return;
    }
    else
    {
      if (m_cmcc == nullptr)
      {
        m_cmcc = new CMCC;
        m_cmcc->docharge(x);
        delete m_cmcc;
        m_cmcc = nullptr;
      }
    }
  }

private:
  CMCC *m_cmcc;
};

void test04()
{
  Business *b1 = new CMCCProxy;
  b1->docharge(0);
  b1->docharge(100);
  delete b1;
  b1 = nullptr;
}

#include <list>
class Subject;
class Observer
{
public:
  void update()
  {
    cout << "Subject update" << endl;
  }
};

class Subject
{
public:
  Subject(int abc) : m_A(abc)
  {
  }
  void addOserver(Observer *obj)
  {
    m_list.push_back(obj);
  }
  void removeOserver(Observer *obj)
  {
    m_list.remove(obj);
  }

  void changeValue(int x)
  {
    m_A = x;
    notify();
  }
  void notify()
  {
    for (auto &observer : m_list)
    {
      observer->update();
    }
  }

private:
  list<Observer *> m_list;
  int m_A;
};

void test05()
{

  Observer *obs1 = new Observer;
  Observer *obs2 = new Observer;
  Observer *obs3 = new Observer;
  Subject *subject1 = new Subject(1);
  subject1->addOserver(obs1);
  subject1->addOserver(obs2);
  subject1->addOserver(obs3);
  subject1->changeValue(100);
}

class Weapon
{
public:
  virtual void show()
  {
    cout << "Weapon ..." << endl;
  }
};

class AK47 : public Weapon
{
public:
  void show()
  {
    cout << "AK47 ..." << endl;
  }
};

class Knife : public Weapon
{
public:
  void show()
  {
    cout << "Knife ..." << endl;
  }
};

class character
{
public:
  character(Weapon *w = nullptr) : ws(w) {}
  void setWeapon(Weapon *w)
  {
    ws = w;
  }

  void showWeapon()
  {
    if (ws != nullptr)
    {
      ws->show();
    }
  }

private:
  Weapon *ws;
};

void test06()
{
  Weapon *w1 = new AK47;
  Weapon *w2 = new Knife;
  character *c1 = new character;
  c1->showWeapon();
  c1->setWeapon(w1);
  c1->showWeapon();
  c1->setWeapon(w2);
  c1->showWeapon();
}

class hungrySingleton
{
public:
  static hungrySingleton *GetInstance()
  {
    return ins;
  }
  void show()
  {
    cout << "hungry Loading..." << endl;
  }

private:
  hungrySingleton(){};
  hungrySingleton(const hungrySingleton &p){};
  static hungrySingleton *ins;
};
hungrySingleton *hungrySingleton::ins = new hungrySingleton;

class lazySingleton
{
public:
  static lazySingleton *GetInstance()
  {
    if (ins = nullptr)
    {
      ins = new lazySingleton;
    }
    return ins;
  }
  void show()
  {
    cout << "lazy Loading..." << endl;
  }

private:
  lazySingleton(){};
  lazySingleton(const lazySingleton &p){};
  static lazySingleton *ins;
};
lazySingleton *lazySingleton::ins = nullptr;

void test07()
{
  hungrySingleton *ins = hungrySingleton::GetInstance();
  ins->show();

  hungrySingleton *ins2 = hungrySingleton::GetInstance();
  ins2->show();

  if (ins == ins2)
  {
    cout << "one " << endl;
  }
}

void test08()
{
  lazySingleton *ins = lazySingleton::GetInstance();
  ins->show();
}

class ABSHero;
class ABSBoss
{
public:
  virtual void attachHero(ABSHero *h) = 0;
  virtual void detachHero(ABSHero *h) = 0;
  virtual void notify() = 0;

protected:
  list<ABSHero *> h;
};

class ABSHero
{
public:
  virtual void update() = 0;
};

class chinaBoss : public ABSBoss
{
public:
  void attachHero(ABSHero *hero)
  {
    h.push_back(hero);
  }

  void detachHero(ABSHero *hero)
  {
    h.remove(hero);
  }

  void notify()
  {
    for (auto &x : h)
    {
      x->update();
    }
  }
};

class jpnBoss : public ABSBoss
{
public:
};

class chinaHero : public ABSHero
{
public:
  void update()
  {
    cout << "chinaBoss update" << endl;
  }
};

class jpnHero : public ABSHero
{
public:
  void update()
  {
    cout << "jpnBoss update" << endl;
  }
};

void test09()
{
  ABSBoss *c = new chinaBoss;
  ABSHero *h1 = new chinaHero;
  ABSHero *h2 = new chinaHero;
  c->attachHero(h1);
  c->attachHero(h2);
  c->notify();
}

class component
{
public:
  virtual void doprocess() = 0;
  virtual void addNode(component *c) {}
  virtual void removeNode(component *c) {}

protected:
  list<component *> m_list;
};

class composite : public component
{
public:
  composite(string abc) : name(abc) {}
  void doprocess()
  {
    cout << "do processing in " << name << endl;
    for (auto &x : m_list)
    {
      // cout<<"do processing in "<<name<<endl;
      x->doprocess();
    }
  }

  void addNode(component *c)
  {
    m_list.push_back(c);
  }

  void removeNode(component *c)
  {
    m_list.remove(c);
  }

private:
  string name;
};

class leaf : public component
{
public:
  leaf(string abc) : name(abc) {}
  void doprocess()
  {
    cout << "do processing in " << name << endl;
  }

private:
  string name;
};

class ITarget
{
public:
  virtual void process() = 0;
};

class IAdapter
{

public:
  virtual int foo() = 0;
  virtual void bar(int x) = 0;
};

class oldclass : public IAdapter
{
public:
  virtual int foo()
  {
    cout << "foo in oldclass" << endl;
    return 0;
  }
  virtual void bar(int x) { cout << "bar in oldclass" << endl; }
};

class IAdaptee : public ITarget
{
public:
  IAdaptee(IAdapter *abc) : ada(abc) {}
  void process()
  {
    cout << "Processing in IAdaptee..." << endl;
    int x = ada->foo();
    ada->bar(x);
  }

private:
  IAdapter *ada;
};

void test10()
{

  composite *root = new composite("root");
  composite *node1 = new composite("node1");
  composite *node2 = new composite("node2");
  leaf *leaf1 = new leaf("leaf1");
  leaf *leaf2 = new leaf("leaf2");

  root->addNode(node1);
  root->addNode(node2);
  node1->addNode(leaf1);
  node2->addNode(leaf2);
  root->doprocess();
}

void test11()
{

  IAdapter *ada = new oldclass;
  ITarget *it = new IAdaptee(ada);
  it->process();
}

class Receiver
{
public:
  virtual void action()
  {
    cout << "Receiver action" << endl;
  }
};

class Command
{
public:
  virtual void execute() = 0;

  //  protected:
  //  Receiver *r;
};

class ConcreCommand : public Command
{
public:
  ConcreCommand(Receiver *re) : r(re) {}
  void execute()
  {
    r->action();
  }

private:
  Receiver *r;
};

class IVoke
{
public:
  IVoke(Command *command = nullptr) : c(command) {}
  void setCMD(Command *command)
  {
    c = command;
  }
  void Invoke()
  {
    if (c)
    {
      c->execute();
    }
  }

private:
  Command *c;
};

void test12()
{
  Receiver *r = new Receiver;
  Command *c = new ConcreCommand(r);
  IVoke *token = new IVoke();
  token->Invoke();

  token->setCMD(c);
  token->Invoke();
}

class CATString
{
  friend ostream &operator<<(ostream &os, const CATString &abc);

public:
  CATString(char *str = 0)
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

  ~CATString()
  {
    if (m_data)
    {
      delete[] m_data;
    }
  }
  CATString(const CATString &s)
  {
    m_data = new char[strlen(s.m_data) + 1];
    strcpy(m_data, s.m_data);
  }

  CATString &operator=(const CATString &s)
  {
    if (this != &s)
    {
      delete[] m_data;
      m_data = new char[strlen(s.m_data) + 1]; // forget here,free(): double free detected in tcache 2
      strcpy(m_data, s.m_data);
    }
    return *this;
  }

private:
  char *m_data;
};

void test13()
{
  CATString s;
  CATString s2("test01");
  CATString s3;
  s3 = s2;
  CATString s4 = s3;

  cout << "Testing" << endl;
  cout << "s1:" << s << endl;
  cout << "s2:" << s2 << endl;
  cout << "s3:" << s3 << endl;
  cout << "s4:" << s4 << endl;
}

ostream &operator<<(ostream &os, const CATString &abc)
{
  os << abc.m_data << endl;
  return os;
}

class complex
{
  friend complex operator+(const complex& a, const complex& b);
  friend complex operator+(const complex& a, double b);
  friend complex& _doapl(complex * ths, const complex & obj);
public:
  complex(double x=0, double y=0) : real(x), imag(y)
  {
    cout<<"complex ctor"<<endl;
  }
  complex(const complex& obj)
  {
     this->real = obj.real;
     this->imag = obj.imag;
     cout<<"complex copy ctor"<<endl;
  }

  complex& operator=(const complex& obj)
  {
    cout<<"complex copy ="<<endl;
         this->real = obj.real;
     this->imag = obj.imag;
     return *this;
  }
  
  double Real() const
  {
     return this->real;
  }

  double Imag() const
  {
    return this->imag;
  }

  complex& operator+=(const complex& obj)
{
  return _doapl(this, obj);
}

private:
  double real;
  double imag;
};
complex operator+(const complex& a, const complex& b)
{
  //  complex temp;
  //  temp.real = a.Real() + b.Real();
  //  temp.imag = a.Imag() + b.Imag();
  //  return temp;
 // cout<<a.Real()<<endl;
    
     return complex(a.Real() + b.Real(),a.Imag() + b.Imag());
  
}

complex operator+(const complex& a, double b)
{
   complex temp;
   temp.real = a.Real()+b;
   temp.imag = a.Imag();
   return temp;
}

ostream& operator<<(ostream& os, const complex& obj)
{
  os<<"real: "<<obj.Real()<<" imag: "<<obj.Imag();

  return os;
}

complex& _doapl(complex * ths, const complex & obj)
{
   ths->real += obj.Real();
   ths->imag += obj.Imag();
   return *ths;

}



void test14()
{
   complex c1(1.0, 1.0);
   complex c2;
   complex c3 = c1;
   complex c4(c1);

   c2 = c1 + c4;

   c3 = c1 +11.21;
   cout<<c2<<endl;
   cout<<c3<<endl;

   complex c5;
   c5+=c3;
   cout<<c5<<endl;


}

class ITarget2023
{
public:
  virtual void process()=0;

};

class IAdaptee2023
{
  public:
    virtual void foo()=0;
    virtual void bar()=0;

};

class oldclass2023: public IAdaptee2023{
public:
   void foo()
   {

   }

   void bar()
   {

   }

};


class Adapter2023: public ITarget2023

{
public: 
    Adapter2023(IAdaptee2023 * adee)
    {
      this->adee = adee;
    }
    void process()
    {
       adee->foo();
       adee->bar();
    }

private:
IAdaptee2023 * adee;

};

void test15()
{
   IAdaptee2023 * adee = new oldclass2023;
   ITarget2023 * ada = new Adapter2023(adee);
   ada->process();
   
}


class ISubject
{
public:
    virtual void process()=0;

};

class realsubject: public ISubject
{
public:
   void process()
   {
      cout<<"realsubject process"<<endl;  
   }

};

class realsubjectProxy: public ISubject
{
   public:
   void process()
   {   
       real = new realsubject;
       cout<<"realsubjectproxy process"<<endl;
       real->process();
   }
   private:
   realsubject * real;

};

class clientApp
{
 public:
    clientApp()
    {
      sub = new realsubjectProxy();
    }
    
    void dotask()
    {
      sub->process();
    }

 private:
    ISubject* sub;
};

void test16()
{
  //  ISubject *s = new realsubjectProxy;
  //  s->process();

   clientApp ca;
   ca.dotask();

}

class ITarget123
{
 public:
    virtual void doprocess()=0;
};

class IAdaptee123
{
  public:
  virtual void foo()=0;
  virtual void bar()=0;
};

class oldclass123 : public IAdaptee123
{
  public:
  void foo(){}
  void bar(){}
};


class Adapter123: public ITarget123
{
 public:
    Adapter123( IAdaptee123 * x= nullptr ):adee(x){}
    void doprocess()
    {
         adee->bar();
         adee->bar();
    }
  private:
  IAdaptee123 * adee;
};

void test17()
{
    IAdaptee123 * abc = new oldclass123;
    ITarget123* it = new Adapter123( abc );
    it->doprocess(); //20230922

}

int main0()
{

  test17();
}