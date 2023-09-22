#include <list>

#include <iostream>
using namespace std;
#include <string.h>
class Fruit
{
public:
   virtual void showname()=0;

};

class Apple:public Fruit
{
   public:
   void showname()
   {
      cout<<"Apple"<<endl;
   }
};

class Banana:public Fruit
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

void t1()
{
   FruitFactory * ff = new AppleFactory;
   Fruit* f = ff->createFruit();
   f->showname();

   ff = new BananaFactory;
   f = ff->createFruit();
   f->showname();

}

class simplefactory
{
   public:
   static Fruit* createfruit(string obj = "")
   {
      Fruit * f = nullptr;

      if(obj == "Apple")
      {
         f = new Apple;
      }
      else if(obj == "Banana")
      {
         f = new Banana;
      }
      else{
         f = new Banana;
      }
   }

};

void t2()
{
    Fruit * f = simplefactory::createfruit("Apple");
    f->showname();
    f = simplefactory::createfruit("Bababa");
    f->showname();

    f = simplefactory::createfruit("");
    f->showname();

}


class CDocument
{
public:
    void onFileOpen()
    {
       f1();
       f2();
       f3();
    }
   
    void f1()
    {
      cout<<"open file done."<<endl;
    }

    virtual void f2()=0;

    void f3()
    {
      cout<<"close file done"<<endl;
    }

};

class App: public CDocument
{
  public:
  void f2()
  {
    cout<<"read file in subclass"<<endl;
  }

};

class WeaponStrategy
{
   public:
   virtual void showname() =0;

};

class AK47 : public WeaponStrategy
{
   public:
   void showname()
   {
      cout<<"AK47 on."<<endl;
   }

};

class Knife: public WeaponStrategy
{
   public:
   void showname()
   {
      cout<<"Knife on"<<endl;
   }
};

class Character
{
  public:
   Character(WeaponStrategy *weapon= nullptr):ws(weapon)
   {

   } 

   void setWS(WeaponStrategy *weapon)
   {
       ws = weapon;
   }

   void showweapon()
   {
      ws->showname();
   }
private:
  WeaponStrategy *ws;
};


void t4()
{
   WeaponStrategy * ak47 = new AK47;
   WeaponStrategy* knife = new Knife;
   Character * cc = new Character;
   cc->setWS(ak47);
   cc->showweapon();

   cc->setWS(knife);
   cc->showweapon();
}



void t3()
{
   App app1;
   app1.onFileOpen();

}


class Business
{
   public:
   virtual void recharge(int x)=0;
};

class CMCC: public Business{

   public:
   void recharge(int x)
   {
      cout<<"CMCC recharge done."<<x<<endl;
   }
};

class CMCCProxy: public Business{
public:
   void recharge(int x)
   {
      if(x<100)
      {
         cout<<"need more than 100"<<endl;
      }
      else
      {
        if(m_cmcc==nullptr)
        {
           m_cmcc = new CMCC;
           m_cmcc->recharge(x);
           delete m_cmcc;
        }

      }
   }
public:
   CMCC * m_cmcc;
};

void t5()
{

   Business * b = new CMCCProxy;
   b->recharge(1);
   b->recharge(100);
   delete b;
}

class Subject;
class Observer
{
public:
    Observer(string x): m_str(x)
    {

    }
    void update(Subject * subjet, int x)
    {
      cout<<"update"<<x<<endl;
    }
private:
    string m_str;
 
};

class Subject
{
   public:
   Subject(int x):m_A(x) {}

   void attache(Observer *obs)
   {
      m_list.push_back(obs);
   }
   void detach(Observer *obs)
   {
      m_list.remove(obs);

   }
   int setValue(int x)
   {
      m_A = x;
      notify();
      return 0;
   }
 
   void notify()
   {
     for(auto x: m_list)
     {
         x->update(this,m_A);
     }


   }
   private:
   list<Observer*> m_list;
   int m_A;
};

class AbsBoss;
class AbsHero
{
    public:
      virtual void update()=0;

    private:

};

class ChinaHero: public AbsHero
{
public:
    void update()
    {
      cout<<"chinahero update."<<endl;
    }

};

class JpnHero: public AbsHero
{
public:
    void update()
    {
      cout<<"jpnhero update."<<endl;
    }

};

class AbsBoss{
public:
    virtual void attach(AbsHero* obj)=0;
    virtual void detach(AbsHero*obj)=0;
    virtual void notify()=0;

   protected:
   list<AbsHero*> m_list;
};

class EarthBoss: public AbsBoss
{
   public:
   void attach(AbsHero * o) 
   {
       m_list.push_back(o);
   }
   void detach(AbsHero *o) 
   {
      m_list.remove(o);
   }

   void notify()
   {
      for(auto x:m_list)
      {
         x->update();
      }
   }


};

void t7()
{
    AbsHero* c1 = new ChinaHero;
    AbsHero* j1 = new JpnHero;
    AbsBoss* e1 = new EarthBoss;
    
    e1->attach(c1);
    e1->attach(j1);
    e1->notify();

    e1->detach(j1);
    e1->notify();

}


void t6()
{
   Observer * ob1 = new Observer("obs1");
   Observer*  ob2 = new Observer("obs2");

   Subject * sub1 =  new Subject(1);
   sub1->attache(ob1);
   sub1->attache(ob2);
   sub1->setValue(100);

   sub1->detach(ob2);
   sub1->setValue(1000);

}


class ITarget
{
   public:
   virtual void doprocess() = 0;

};

class IAdaptee
{
   public:
   virtual int  foo() =0;
   virtual void bar(int x)=0;
};

class oldclass: public IAdaptee{
public:
   int foo()
   {
      cout<<"oldclass foo"<<endl;
      return 0;
   }
   void bar(int x)
   {
      cout<<"oldclass bar"<<endl;

   }
};

class Adapter : public ITarget{
public:
   Adapter(IAdaptee *adaptee):ada(adaptee) {}
   void doprocess()
   {
        int x = ada->foo();
        ada->bar(x);

   }

private:
IAdaptee * ada;

};

void t8()
{
    IAdaptee* ada = new oldclass;
    ITarget * it = new Adapter(ada);
    it->doprocess();
}

class TRIString
{
   friend ostream& operator<< (ostream& os, const TRIString &str);
   public:
   TRIString(const char* str = nullptr)
   {
      if(str)
      {
         m_data = new char[strlen(str) + 1];
         strcpy(m_data,str);
      }
      else{
         m_data = new char[1];
         *m_data = '\0';
      }
   }

   TRIString (const TRIString & other)
   {
          m_data = new char[strlen(other.m_data) + 1];
      strcpy(m_data, other.m_data); 
   }

   TRIString& operator=(const TRIString &other)
   {
      if(this != &other)
      {
           m_data = new char[strlen(other.m_data) + 1];
      strcpy(m_data, other.m_data);
         
      }
      return *this;
    
   }

   virtual ~TRIString()
   {
      if(m_data)
      {
         delete [] m_data;
         m_data = nullptr;
      }
   }

   private:
   char * m_data;
};

ostream& operator<< (ostream& os, const TRIString &str)
{
   os<<str.m_data;
   return os;
}

void t9()
{

  TRIString abc;
  TRIString abc2("123");
  TRIString abc3;
  abc3 = abc2;
  TRIString abc4 = abc2;

  cout<<abc<<endl;
   cout<<abc2<<endl;
    cout<<abc3<<endl;
     cout<<abc4<<endl;

}

class Complex
{
   friend Complex& __doapl(Complex* ths, const Complex& other);
   friend ostream& operator<<(ostream& os, const Complex&other);
  public:
  Complex(double x=0,double y=0):real(x),img(y)
  {
   cout<<"ctor done"<<endl;
  }

  double Real() const
  {
   return this->real;
  }
  double Imag() const
  {
   return this->img;
  }

  Complex operator+=(const Complex& other)
  {
      return __doapl(this, other);
  }

  private:
  double real;
  double img;


};
Complex& __doapl(Complex* ths, const Complex& other)
{
      //a pointer to a bound function may only be used
      //return Complex(ths->Real+other.real, ths->Imag+other.img);
      ths->real += other.real;
      ths->img += other.img;
      return *ths;
}

Complex operator+(const Complex& obj, const Complex& other)
{
   return Complex(obj.Real()+other.Real(), obj.Imag()+other.Imag());
}

ostream& operator<<(ostream& os, const Complex&other)
{
    os<<"real:"<<other.real<<" img:"<<other.img<<endl;
    return os;
}

Complex operator+(const Complex& obj, int index)
{
   return Complex(obj.Real()+index, obj.Imag());
}
void t10()
{
   Complex c1(1,1);
   Complex c2(2,2);
   Complex c3;
   c3 = c1 +c2 ;
   cout<<c3<<endl;


}

class component
{
   public:
   virtual void doprocess()=0;
   virtual void addnode(component *c){};
   virtual void deletenode(component *c){};
};


class composite: public component
{
   public:
   composite(string x):name(x){ cout<<"ctor "<<x<<endl;}
   void doprocess()
   {
      cout<<"doprocess in Node"<<name<<endl;
      for(auto x: m_list)
      {
         x->doprocess();
      }
   }

   void addnode(component* c)
   {
      m_list.push_back(c);
   }

   void deletenode(component* c)
   {
      m_list.remove(c);
   }
   private:
   list<component *> m_list;
   string name;

};

class leaf: public component
{
  public: 
  leaf(string x):name(x){ cout<<"ctor "<<x<<endl;}
   void doprocess()
   {
      cout<<"doprocess in leaf"<<name<<endl;

   }
   private:
   string name;
};

void t11()
{
   composite root("root");
   component * node1 = new composite("node1");
   component * node2 = new composite("node2");
   component * leaf1 = new  leaf("leaf1");
   component * leaf2 = new leaf("leaf2");
   root.addnode(node1);
   root.addnode(node2);
   node1->addnode(leaf1);
   node1->addnode(leaf2);
   root.doprocess();

}


int main()
{

   t11();

   cout<<"hello world!"<<endl;
   return 0;
}