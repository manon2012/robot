#include <string>
#include <vector>
#include <iostream>

//GOF on 20230922
using namespace std;


// class ITarget
// {
//   public:
//     virtual void process()=0;
// };

// class IAdaptee
// {
//   public:
//   virtual int foo()=0;
//   virtual void bar(int x)=0;
// };

// class oldclass : public IAdaptee
// {
//   public:
//   int foo(){cout<<"foo in oldclass"<<endl; return 2023;}
//   void bar(int x){cout<<"bar in oldclass "<<x<<endl;}
// };

// class Adapter: public ITarget
// {
//   public:
//   Adapter(IAdaptee * x) : ada(x) {}
//   void process()
//   {
//      cout<<"process in Adapter"<<endl;
//      int x=ada->foo();
//      ada->bar(x);
//   }
//   private:
//   IAdaptee * ada;
// };

// void test01()
// {
//     IAdaptee * ia = new oldclass;
//     ITarget*  it = new Adapter(ia);
//     it->process();

// }


// class clientAPP
// {
//    public:
//    clientAPP()
//    {
//     is = new RealSubjectProxy;
//    }
//    void doit()
//    {
//       is->process();
//    }
//    private:
//    ISubject *is;
// };

// class ISubject
// {
//   public:
//      virtual void process()=0;
// };

// class RealSubject : public ISubject
// {
//   public :
//   void process(){cout<<"realsubject";}
// };

// class RealSubjectProxy: public ISubject
// {
//   public:
//    RealSubjectProxy(RealSubject* r=nullptr):real(r) {}
//    void process(){cout<<"proxy begin"<<endl; real->process();}
//   private:
//    RealSubject *real;
// };


class ITarget
{
  public:
  virtual void process ()=0;
};

class IAdaptee
{
  public:
  virtual int foo()=0;
  virtual void bar(int x)=0;
};

class oldclass : public IAdaptee
{
public:
  virtual int foo(){cout<<"foo in oldclass"<<endl; return 2023;}
  virtual void bar(int x){cout<<"bar in oldclass"<<endl;}
};

class Adapter: public ITarget
{
  public:
   Adapter(IAdaptee *ada)
   {
    this->ada=ada;
   }

   virtual void process()
  {

     int x = ada->foo();
     ada->bar(x);
  }

  private:
  IAdaptee *ada;
};

void test01()
{
    IAdaptee * ada = new oldclass;
    ITarget * it = new Adapter(ada);
    it->process();

}

class Isubject
{
  public:
   virtual void process()=0;
};

class realsubject: public Isubject
{
  public:
  void process()
  {
    cout<<"process in real"<<std::endl;
  }
};

class realsubjectproxy: public Isubject
{
  public:
  realsubjectproxy( )
  {
    real = new realsubject;
  }
  void process()
  {
    cout<<"process in realproxy"<<std::endl;
    real->process();
  }

  private:
  realsubject *real;
};

class clientApp
{
  public:
  clientApp()
  {
    is = new realsubjectproxy;
  }

  void doit()
  {
    is->process();
  }

  private:
  Isubject * is; 
};

void test02()
{
    clientApp * ca = new clientApp;
    ca->doit();
}

class Business
{
  public:
  virtual void charge(int x)=0;
};

class CMCC: public Business
{
  public:
  void charge(int x)
  {
    cout<<"charge "<<x<<endl;
  }

};

class CMCCProxy : public Business{
public:
virtual void charge(int x)
{
  if (x <100)
  {
    cout<<"need more than 100"<<endl;
  }
  else{

    if(m_cmcc==nullptr)
    {
      m_cmcc = new CMCC;
      m_cmcc->charge(x);
      delete m_cmcc;
    }
  }
};

private:
CMCC * m_cmcc;

};

void test03()
{
     Business * it = new CMCCProxy;
     it->charge(1);
     it->charge(100);

}

class Receiver
{
   public:
   void action()
   {
    cout<<"rec action"<<endl;
   }
};

class Command
{
  public:
  virtual void execute()=0;
};

class ConcreCommand : public Command
{
  public:
  ConcreCommand(Receiver * r):m_r(r) {}
  void execute()
  {
    m_r->action();
  }   
  private:
  Receiver * m_r;

};

class IVoke
{
   public:
   IVoke(Command * c=nullptr):m_c(c) {}
   void Invoke()
   {
      m_c->execute();
   }

   void setCmd(Command *abc)
   {
     m_c = abc;
   }

   private:
   Command *m_c;

};

void test04()
{
    Receiver * r = new Receiver;
    Command * c = new ConcreCommand(r);
    IVoke * ic = new IVoke;
    ic->setCmd(c);
    ic->Invoke();

}

int main()
{
  cout<<"Welcome"<<endl;
  test04();
}