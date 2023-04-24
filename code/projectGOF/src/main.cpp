// GOF10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <list>

class Fruit
{
public:
    virtual void showname() = 0;
};

class Apple : public Fruit {
public:
    void showname()
    {
        cout<<"apple" << endl;
    }
};

class Banana : public Fruit {
public:
	void showname()
	{
		cout << "Banana" << endl;
	}
};

class FruitFactory {
public:
    virtual Fruit* CreateFruit() = 0;

};

class AppleFactory : public FruitFactory
{
public:
    Fruit* CreateFruit()
    {
        return new Apple;
    }

};

class BananaFactory : public FruitFactory
{
public:
	Fruit* CreateFruit()
	{
		return new Banana;
	}

};


void test01()
{
    FruitFactory* ff = new AppleFactory;
    Fruit* f = ff->CreateFruit();
    f->showname();

    ff = new BananaFactory;
    f = ff->CreateFruit();
    f->showname();


}


class SimpleFactory
{
public:
    
    static Fruit* CreateFruit(const char* str)
    {
        Fruit* p = nullptr;
        if (str == "apple")
        {
            p = new Apple;
        }
        else if (str == "banana")
        {
            p = new Banana;
        }
        else
            p = nullptr;

        return p;
    }

};

void test02()
{
   
    Fruit* p = nullptr;
    p = SimpleFactory::CreateFruit("apple");
    p->showname();

    p = SimpleFactory::CreateFruit("banana");
    p->showname();
}

class Subject;
class Observer
{
public:
    Observer(string x):name(x){}
    void update(Subject * sub, int x)
    {
        cout<<this->name<<" Observer update..." << endl;
    }
private:
    string name;
};

class Subject
{
    public:
        Subject(int x): m_value(x){}
        void attachObserver(Observer* obs)
        {
            m_list.push_back(obs);
        }
		void deleteObserver(Observer* obs)
		{
			m_list.remove(obs);
		}
        void setValue(int x)
        {
            m_value = x;
            notify();
        }

        void notify()
        {
            for (auto & x:m_list)
            {
                x->update(this, m_value);
            }
        }

private:
    list<Observer*> m_list;
    int m_value;

};


void test03()
{
    Subject* sub1 = new Subject(100);
    Observer* obs1 = new Observer("a");
    Observer* obs2 = new Observer("b");
    Observer* obs3 = new Observer("c");

    sub1->attachObserver(obs1);
    sub1->attachObserver(obs2);
    sub1->attachObserver(obs3);

    sub1->setValue(1000);

}


class AbsHero
{
public:
    virtual void update() = 0;

};

class chinaHero : public AbsHero
{
public:

    void update()
    {
        cout<<"chinahero update" << endl;
    }
};

class TTHero : public AbsHero
{
public:

	void update()
	{
		cout << "TThero update" << endl;
	}
};


class AbsBoss {
public:
    virtual void attachHero(AbsHero* h) = 0;
    virtual void deattachHero(AbsHero* h) = 0;
    virtual void notify() = 0;
protected:
    list<AbsHero*> m_list;
};

class wtoBoss : public AbsBoss
{
public:

    void attachHero(AbsHero* h)
    {
        m_list.push_back(h);
     }
    void deattachHero(AbsHero* h)
    {
        m_list.remove(h);
     }
    void notify()
    {
        for (auto & x: m_list)
        {
            x->update();
        }
     }

};

void test04()
{
    AbsHero* h1 = new chinaHero;
    AbsHero* h2 = new TTHero;
    AbsBoss* b1 = new wtoBoss;

    b1->attachHero(h1);
    b1->attachHero(h2);
    b1->notify();

}


class Business
{
public:
    virtual void recharge(int x) = 0;
};

class CMCC : public Business
{
public:
    void recharge(int x)
    {
        cout<<"rechage done" <<x<< endl;
    }
};

class CMCCProxy : public Business
{
public:
    void recharge(int x)
    {
        if (x<50)
        {
            cout<<"need >50" << endl;
            
        } 
        else
        {
            if (m_cmcc==nullptr)
            {
                m_cmcc = new CMCC;
                m_cmcc->recharge(x);
            }
        }
    }

private:
    CMCC* m_cmcc;
};

void test05()
{
    Business* b = new CMCCProxy;
    b->recharge(10);
    b->recharge(100);
    delete b;

}

class WeaponStrategy {
public:
    virtual void showweapon() = 0;
};

class AK47 :public WeaponStrategy
{
public:

    void showweapon()
    {
        cout<<"AK47" << endl;
    }
};


class Knife : public WeaponStrategy
{
public:
    void showweapon()
    {
        cout<<"knife " << endl;
    }

};



class character
{
public:
    character(WeaponStrategy* ws = nullptr){}

    void setWS(WeaponStrategy* ws)
    {
        this->ws = ws;
    }

    void showit()
    {
        ws->showweapon();
    }
private:
    WeaponStrategy* ws;
};


void test06()
{
    WeaponStrategy* ws1 = new AK47;
    WeaponStrategy* ws2 = new Knife;

    character abc;
    abc.setWS(ws1);
    abc.showit();

    abc.setWS(ws2);
    abc.showit();



}

class ITarget
{
public:
    virtual void process() = 0;

};

class IAdaptee
{
public:
    virtual void foo(int x) = 0;
    virtual int bar() = 0;
};

class oldclass : public IAdaptee
{
public:
    virtual void foo(int x)
    {
        cout<<"foo in oldclass" << endl;
    }
    virtual int bar()
    {
        cout<<"bar in oldclass" << endl;
        return 0;
    }
};

class Adapter : public ITarget
{
public:
    Adapter(IAdaptee* pAd)
    {
        this->pAd = pAd;
    }
    void process()
    {
        cout<<"process in adapter" << endl;
        int x = pAd->bar();
        pAd->foo(x);
    }

private:
    IAdaptee* pAd;
};


void test07()
{
    IAdaptee* pad = new oldclass;
    Adapter* pdter = new Adapter(pad);
    pdter->process();

}

class Component
{
public:
    virtual void process() = 0;
    virtual void attachNode() {}
    virtual void deleteNode(){}

};


class Composite : public Component
{
public:
    Composite(string abc):m_name(abc){}

    void process()
    {
        cout<<"do process in Composite " <<m_name<< endl;
        for (auto &x :m_list)
        {
            x->process();
        }
    }

    void attachNode(Component* c)
    {
        m_list.push_back(c);
    }

    void deleteNode(Component* c)
    {
        m_list.remove(c);
    }
private:
    list<Component*> m_list;
    string m_name;
};


class Leaf : public Component {
public:
    Leaf(string abc):m_name(abc){}
    void process()
    {
        cout<<"do process in Leaf" <<this->m_name<< endl;
    }

private:   
    string m_name;
};

void test08()
{
    
    Composite root("root");
    Composite node1("node1");
    Leaf leaf1("leaf1");
    Leaf leaf2("leaf2");

    root.attachNode(&node1);
    node1.attachNode(&leaf1);
    node1.attachNode(&leaf2);
    root.process(); 

}


class Receiver
{
public:
    void action()
    {
        cout<<"Rec action" << endl;
    }
};

class Command {

public:
    virtual void execute() = 0;

};

class ConcreteCommand : public Command {
public:
    ConcreteCommand(Receiver* r):rec(r){}

    void execute()
    {
        rec->action();
    }

private:
    Receiver* rec;
};

class Invoke {
public:
    Invoke(Command * c= nullptr):cmd(c){}

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


void test09()
{
    Receiver* r = new Receiver;
    Command* c = new ConcreteCommand(r);
    Invoke* ik = new Invoke;
    ik->setCommand(c);
    c->execute();
}


int main()
{
    test01();
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file