#include <string>
#include <list>
#include <iostream>
using namespace std;

class Fruit
{
public:
    virtual void show()=0;

};

class Apple : public Fruit
{
public:
   void show()
   {
      cout << "Apple here" << endl;
   }
};


class Banana : public Fruit
{
public:
    void show()
    {
      cout << "Banana here" << endl;
    }

};

class FruitFactory
{
   public:
     virtual Fruit* createFruit()=0;
};


class AppleFactory: public FruitFactory
{
   public:
     Fruit* createFruit()
     {
      return new Apple;
     }
};

class BananaFactory: public FruitFactory
{
   public:
    Fruit* createFruit()
    {
      return new Banana;
    }
};

void t1()
{
    FruitFactory * ff = new AppleFactory;
    Fruit * f = ff->createFruit();
    f->show();

    ff=new BananaFactory;
    f = ff->createFruit();
    f->show();

}

class SimpleFactory
{
public:
    static Fruit* createFruit(char * fruit =nullptr)
    {
       Fruit * f = nullptr;
       if(fruit == "Apple")
       {
         f = new Apple;
       }
       else if (fruit == "Banana")
       {
         f = new Banana;
       }
       else{
         f = new Apple;
       }
       return f;
    }

};

void t2()
{
    Fruit * f = SimpleFactory::createFruit("Apple");
    f->show();
    f=SimpleFactory::createFruit("Banana");
    f->show();
    f=SimpleFactory::createFruit("");
    f->show();

}


class CDocument
{
  public:
    void OnFileOpen()
    {
      f1();
      serilize();
      f3();
    }

private:
    void f1()
    {
      cout<<"openfile"<<endl;
    }

    virtual void serilize()=0;

      void f3()
    {
      cout<<"closefile"<<endl;
    }

};

class MyDoc : public CDocument
{  
   public:
   void serilize()
   {
      cout<<"MyDoc reading..."<<endl;
   }

};

void t3()
{
    MyDoc md;
    md.OnFileOpen();
   

}



class component
{
  public:
  virtual void doprocess()=0;
  virtual void addNode(component*){}
  virtual void removeNode(component*){}
};

class composite: public component
{
  public:
  composite(string name):m_name(name)
  {

  }

  void doprocess()
  {
    cout<<"doprocess in "<<m_name<<endl; 
    for(auto &x : m_list)
    {
       x->doprocess();
    }

  }

  void addNode(component* node)
  {
     m_list.push_back(node);
  }

  void deleteNode(component* node)
  {
     m_list.remove(node);
  }
private:
  list<component*> m_list;
  string m_name;

};

class Leaf: public component
{
  public:
  Leaf(string name):m_name(name)
  {

  }
  void doprocess()
  {
    cout<<"do prodrocess in "<<m_name<<endl;
  }

  private:
  string m_name;
};

void t4()
{
   component * root = new composite("root");
   component * child1 = new composite("child1");
   component * child2 = new composite("child2");
   component * leaf1 = new composite("leaf1");
   component * leaf2 = new composite("leaf2");

   root->addNode(child1);
   root->addNode(child2);
   child1->addNode(leaf1);
   child2->addNode(leaf2);
   root->doprocess();

}

class Business
{
public:
   virtual void recharge(int x) = 0;
};

class CMCC: public Business
{
public:
    void recharge(int x)
    {
      cout<<"recharge "<<x<<endl;
    }
};

class CMCCProxy: public Business
{
public:
    void recharge(int x)
    {
      if(x<100)
      {
        cout<<"x need >100 "<<endl;
      }
      else
      {
          if(m_cmcc==nullptr)
          { 
            m_cmcc = new CMCC;
            m_cmcc->recharge(x);
            delete m_cmcc;
            cout<<"tstring..."<<endl;
          }
      }
    }
private:
CMCC* m_cmcc;
};

void t5()
{
   Business * t =  new CMCCProxy;
   t->recharge(1);
   t->recharge(100);

}


class observer;

class subject
{
public:
subject(int obj):m_A(obj){}
void attach(observer * obs)
{
  m_list.push_back(obs);
}

void detach(observer * obs)
{
  m_list.remove(obs);
}
void setValue(int x)
{
   m_A = x;
   notify();
}

void notify()
{
  for(auto x:m_list)
  {
    //x->update(this,m_A);  //forward error
  }
}
private:
list<observer*> m_list;
int m_A;

};

class observer
{
  public:
  void update(subject* subject, int x)
  {
      cout<<"subject "<<subject<< " update "<<x<<endl;
  }
  private:
  

};


class ITarget
{
   public:
   virtual void doprocess()=0;
};

class IAdaptee
{
  public:
  virtual int foo() = 0;
  virtual void bar(int x)=0;
};

class oldclass : public IAdaptee
{
public:
   int foo()
   {
    cout<<"foo in oldclass"<<endl;
    return 0;
   }

   void bar(int x)
   {
    cout<<"bar in oldclass"<<endl;
   }

};

class Adapter: public ITarget{
public:
 Adapter(IAdaptee* adaptee) : ada(adaptee) {}

  void doprocess()
  {
      int x=ada->foo();
      ada->bar(x);
  }

private:
IAdaptee* ada;

};





void t6()
{
    subject *s1 = new subject(1);
    observer *o1 = new observer;
    observer *o2 = new observer;
    s1->attach(o1);
    s1->attach(o2);
    s1->setValue(100);

    s1->detach(o2);
    s1->setValue(1000);
}

class Animal
{
  public:
  virtual void show()=0;
};

class Cat : public Animal
{
 public:
 virtual void show()
 {
   cout<<"Cat"<<endl;
 }
};

class Dog: public Animal
{

public:
virtual void show()
{
  cout<<"Dog show"<<endl; 
}
};


void doshow(Animal* obj)
{
  obj->show();
}
void t7()
{
    Animal* obj = new Cat;
    obj->show();
    obj = new Dog;
    obj->show();

};

void t8()
{
   IAdaptee* obj = new oldclass;
   ITarget* target = new Adapter(obj);
   target->doprocess();
}

class Receiver
{
public:
  void action()
  {
    cout<<"action"<<endl;
  }

};

class Command
{
public:
virtual void execute()=0;
  
};

class ConcreteCommand: public Command
{
  public:
  ConcreteCommand(Receiver* receiver):rec(receiver) {}

  void execute()
  {
    cout<<"execute in ConcreteCommand"<<endl;
  }

  private:
  Receiver *rec;
};


class Invoke
{
public:
  Invoke(Command* command):cmd(command) {}
  void setCommand(Command* c)
  {
    cmd = c;
  }

  void Ivoke()
  {
    cmd->execute();
  }

private:
  Command* cmd;

};


void t9()
{

  Receiver* r = new Receiver;
  Command* cmd = new ConcreteCommand(r);
  Invoke* invoke = new Invoke(cmd);
  invoke->setCommand(cmd);
  invoke->Ivoke();
}

class WeaponStrategy
{
  public:
  virtual ~WeaponStrategy() {}
  virtual void show()=0;
};

class AK47: public WeaponStrategy
{
  public:
  void show()
  {
    cout<<"AK47"<<endl;
  }
};

class Knife: public WeaponStrategy
{
  public:
  void show()
  {
    cout<<"Knife"<<endl;
  }
};

class Character
{
public:
Character(WeaponStrategy* s):weapon(s) {}

void setWS(WeaponStrategy* s)
{
  weapon = s;
}

void useGun()
{
  weapon->show();
}

private:
WeaponStrategy* weapon;

};

void t10()
{
    WeaponStrategy* ws1 = new AK47;
    WeaponStrategy* ws2 = new Knife;
    Character * c1 = new Character(ws1);
    c1->useGun();

    c1->setWS(ws2);
    c1->useGun();


}

class Receiver1{
   public:
     void action()
     {
      cout<<"Receiver action"<<endl;
     }

};

class Command1
{
  public:
    virtual void execute()=0;
};

class ConcreteCommand1: public Command1
{
  public:
  ConcreteCommand1(Receiver1 * r):rc1(r){

  }
   void execute()
   {
    cout<<"ConcreteCommand1 execution"<<endl;
   }
  private:
  Receiver1 *rc1;
};

class Invoke1
{
public:
Invoke1(Command1* c):com(c){}
void setCmd(Command1 * c)
{
  com = c;
}
void ivoke()
{
   com->execute();

}


private:
Command1 *com;

};

void t11()
{
   Receiver1 * r1 = new Receiver1;
   Command1* c1 = new ConcreteCommand1(r1);
   Invoke1 * I1 = new Invoke1(c1);
   I1->setCmd(c1);
   I1->ivoke();

   Receiver1 * r2 = new Receiver1;
   Command1 * c2 = new ConcreteCommand1(r2);
   I1->setCmd(c2);
   I1->ivoke();
}

#include <string.h>
class Cstring
{
   friend ostream& operator<<(ostream & os, const Cstring & obj);
   public:
     Cstring(char * str= nullptr)
     {
        if(str)
        {
          m_data = new char[strlen(str) + 1];
          strcpy(m_data,str);
        }
        else
        {
          m_data = new char[1];
          *m_data = '\0';
        }
     }
     Cstring(const Cstring & obj)
     {
        m_data = new char[strlen(obj.m_data)+1];
        strcpy(m_data, obj.m_data);

     }
     Cstring& operator=(const Cstring & obj)
     {
        if(this!= &obj)
        {
           m_data = new char[strlen(obj.m_data)+1];
           strcpy(m_data,obj.m_data);
        }
        return *this;
     }

     ~Cstring()
     {
        if(m_data)
        {
          delete[] m_data;
          m_data = nullptr;
        }

     }

   private:
   char * m_data;
};

ostream& operator<<(ostream & os, const Cstring & obj)
{
      os<<obj.m_data;
      return os;
}

void teststr()
{
    Cstring c1;
    Cstring c2("c2");
    Cstring c3;
    c3 = c2;
    Cstring c4(c3);
    cout<<c1<<endl;
      cout<<c2<<endl;

        cout<<c3<<endl;
          cout<<c4<<endl;
}

class complex
{
public:
  complex(double x=0, double y=0): real(x), imag(y)
  {

  }

  complex& operator+=(const complex& obj)
  {
    return __doapl(this,obj);
  }
  
  complex& __doapl(complex* ths, const complex& obj)
  {
    ths->real= ths->real+obj.real;
    ths->imag = ths->imag+obj.imag;
    return *ths;
  }

private:
double real;
double imag;

};


void comtest()
{
  complex c1(1,1);
  complex c2(c1);
  c1+=c2;

}


class chinaApple: public Apple
{
  public:
     void show()
     {
      cout<<"china apple"<<endl;
     }
};


class usApple: public Apple
{
  public:
     void show()
     {
      cout<<"us apple"<<endl;
     }
};


class chinaBanana: public Banana
{
  public:
     void show()
     {
      cout<<"china Banana"<<endl;
     }
};

class usBanana: public Banana
{
  public:
     void show()
     {
      cout<<"us Banana"<<endl;
     }
};

class AbsFactory
{
public:

   virtual Fruit* createApple()=0;
   virtual Fruit* createBanana()=0;

};

class chinaFactory : public AbsFactory
{
public:
   Fruit* createApple()
   {
    cout<<"Creating chinaApple..."<<endl;
    return new chinaApple;
   }
   virtual Fruit* createBanana()
   {
    cout<<"Creating chinaBanana..."<<endl;
    return new chinaBanana;
   }
};

class USFactory : public AbsFactory
{
public:
   Fruit* createApple()
   {
    cout<<"Creating USApple..."<<endl;
    return new usApple;
   }
   virtual Fruit* createBanana()
   {
    cout<<"Creating USBanana..."<<endl;
    return new usBanana;
   }
};


void testAbsFactory()
{
   AbsFactory* factory = new chinaFactory;
   Fruit* f = factory->createApple();
   f->show();

   delete f;
   delete factory;

   factory = new USFactory;
   f = factory->createBanana();
   f->show();

   delete f;
   delete factory;

}

class singleton
{
    public:
    
    static singleton* getInstance()
    {
      return new singleton;
    }

    void show() const
    {
      cout<<"Singleton show"<<endl;
    }

    private:
    singleton(){}
};

void testit()
{
   singleton* s1 = singleton::getInstance();
   s1->show();

}


class singleton2
{
public:
   static singleton2* getInstance()
   {
      if (p == nullptr)
        {
          p = new singleton2;
        }
      return p;
   }
private:
   singleton2(){}
   static singleton2* p;
};

 singleton2*  singleton2::p = nullptr;


 class singleton_hungry
{
public:
   static singleton_hungry* getInstance()
   {

      return p;
   }
private:
   singleton_hungry(){}
   static singleton_hungry* p;
};

 singleton_hungry*  singleton_hungry::p = new singleton_hungry;

 void t111()
 {
    singleton2* p1 = singleton2::getInstance();
    singleton2* p2 = singleton2::getInstance();
    cout<<p1<<endl;
    cout<<p2<<endl;
 }

 void t112()
 {
    singleton_hungry * p1 = singleton_hungry::getInstance();
    singleton_hungry * p2 = singleton_hungry::getInstance();
        cout<<p1<<endl;
    cout<<p2<<endl;
 }

class test
{
public:
    int  a;
};

void testt()
{

    test * t1 = new test;
    cout<<t1->a<<endl;

    test* t2 = new test();
    cout<<t2->a<<endl;

}


class singleton_lazy
{
   private:
      singleton_lazy(){}

      static singleton_lazy * p;

  public:
  static singleton_lazy * getInstance()
  {
    if(p==NULL)
    {
      p = new singleton_lazy;

    }
    return p;
  }

};
singleton_lazy * singleton_lazy::p = nullptr;

void test_lazy()
{
    singleton_lazy * p1 = singleton_lazy::getInstance();
    singleton_lazy * p2 = singleton_lazy::getInstance();
    cout<<p1<<endl;
    cout<<p2<<endl;

}





class singleton_h
{
   private:
      singleton_h(){}

      static singleton_h * p;

  public:
  static singleton_h * getInstance()
  {
    if(p==NULL)
    {
      p = new singleton_h;

    }
    return p;
  }

};
singleton_h * singleton_h::p = new singleton_h;

void testh()
{

   singleton_h* p1 = singleton_h::getInstance();
   singleton_h* p2 = singleton_h::getInstance();
   cout<<p1<<endl;
   cout<<p2<<endl;

}

class Business1
{

 public:
   virtual void charge(int x)=0;

};
class CMCC1: public Business1
{
public:
  void charge(int x)
  {
       cout << "charging..."<<x<<endl;
  }

};

class CMCCProxy1: public Business1{
public:
   void charge(int x)
   {
     if(x<100)
     {
      cout<<"Charge needed >=100"<<endl;
    
     }
     else
     {
       if(m_cmcc==nullptr)
       {
          m_cmcc = new CMCC1;
          m_cmcc->charge(x);
          delete m_cmcc;
       }

     }
      
   }
private:
   CMCC1 * m_cmcc;
};


void testproxy()
{
   Business1* b1 = new CMCCProxy1;
   b1->charge(1);
   b1->charge(200);
   delete b1;
}

class subject1;
class observer1{
public:
    virtual void update(subject1*s, int x)
    {
      cout<<"subject1 update"<<s<<" value:"<<x<<endl;
    }
};

class observer11: public observer1{
      virtual void update(subject1*s, int x)
    {
      cout<<"sub-subject1 update"<<s<<" value:"<<x<<endl;
    }
};



class subject1
{
  public:
  subject1(int x):m_A(x){}
  void attach(observer1* s)
  {
     m_list.push_back(s);
  }
  void detach(observer1*s)
  {
    m_list.remove(s);
  }

  void changeX(int x)
  {
    m_A = x;
    notify();
  }
  void notify()
  {
    for (auto &x : m_list)
    {
      x->update(this, m_A);
    }
  }

  private:
  list<observer1*> m_list;
  int m_A;
};

void testbs()
{

   observer1 * o1= new observer1;
   observer1* o2 = new observer11;

   subject1 * sub = new subject1(1);
   sub->attach(o1);
   sub->attach(o2);

   sub->changeX(100);


}


class component1
{
   public:
   virtual void addNode(component1* c){}
   virtual void deleteNode(component1* c){}
   virtual void doprocess()=0;

   protected:
   list< component1* > m_list;

};
class composite1: public component1
{
  public:
  composite1(string abc):m_name(abc){}
  void addNode(component1*c)
  {
    m_list.push_back(c);
  }
  void deleteNode(component1*c)
  {
    m_list.remove(c);
  }
  void doprocess()
  {
    cout<<"doprocess in composite1 "<<m_name<<endl;
    for(auto c : m_list)
    {
        c->doprocess();
    }
  }
  private:
  string m_name;
};

class Leaf1: public component1
{
  public:
    Leaf1(string abc):m_name(abc){}
    void doprocess()
    {
      cout<<"doprocess in leaf1 "<<m_name<<endl;
    }
   private:
   string m_name;
};

void testc1()
{
    component1 * root = new composite1("root");
    component1 * node1 = new composite1("node1");
    component1 * node2 = new composite1("node2");
    component1 * leaf1 = new Leaf1("leaf1");
    component1 * leaf2 = new Leaf1("leaf2");
    
    root->addNode(node1);
    root->addNode(node2);
    node1->addNode(leaf1);
    node2->addNode(leaf2);
    root->doprocess();

}

//c++ - 带有继承的 Pimpl 成语 

// class A
// {
//     public:
//       A(bool DoNew = true){
//         if(DoNew)
//           pAImpl = new AImpl;
//       };
//       void foo(){pAImpl->foo();};
//     protected:
//       void SetpAImpl(AImpl* pImpl) {pAImpl = pImpl;};
//     private:
//       AImpl* pAImpl;  
// };
// class AImpl
// {
//     public:
//       void foo(){/*do something*/};
// };

// class B : public A
// {
//     public:
//       B() : A(false){
//           pBImpl = new BImpl;
//           SetpAImpl(pBImpl);
//       };
//       void bar(){pBImpl->bar();};    
//     private:
//       BImpl* pBImpl;  
// };        

// class BImpl : public AImpl
// {
//     public:
//       void bar(){/*do something else*/};
// };


class weapon1
{
  public:
  virtual void show()=0;
};

class ak471: public weapon1
{
  public:
  virtual void show()
  {
    cout<<"ak471 show"<<endl;
  }
};

class knife1: public weapon1
{
  public:
  virtual void show()
  {
    cout<<"knife1 show"<<endl;
  }
};

class character1
{
  public:
  character1(weapon1 *ws) : p(ws) {}
  void setweapon(weapon1 *s)
  {
    p = s;
  }

  void showweapon()
  {
    p->show();
  }

  private:
  weapon1* p;

};

void testweapon()
{
  weapon1 *w1 = new ak471;
  weapon1 *w2 = new knife1;
  character1 *c1 = new character1(w1);

  c1->showweapon();
  c1->setweapon(w2);
  c1->showweapon();
}

int main()
{
   testweapon();
   //testc1();
   //testbs();
   //test_lazy();
   //testh();
   //testproxy();
   //testAbsFactory();
   return 0;
}