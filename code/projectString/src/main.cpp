// GOF10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <list>
#include <string>

class ARstring
{  
    friend ostream &operator<<(ostream &cout, const ARstring &p);
public:
    
    ARstring(const char *abc = 0)
    {
        if (abc)
        {
            int len = sizeof(abc) + 1;
            m_data = new char[len];
            *m_data = *abc;
        }
        else
        {
            m_data = new char[1];
            *m_data = '\0';
        }
    }

    ARstring(const ARstring &p)
    {
        int size = sizeof(p.m_data);
        m_data = new char[size + 1];
        *m_data = *p.m_data;
    }

    ARstring &operator=(const ARstring &p)
    {
        if (this != &p)
        {
            delete m_data;
            int len = sizeof(p.m_data);
            m_data = new char[len + 1];
            *m_data = *p.m_data;
        }
        return *this;
    }

    ~ARstring()
    {
        if (m_data)
        {
            delete m_data;
            m_data = NULL;
        }
    }

private:
    char *m_data;
};

ostream &operator<<(ostream &cout, const ARstring &p)
{
    cout<<p.m_data<<endl;
    return cout;
}

void test01()
{
    ARstring a1;
    ARstring a2("abc");
    a1=a2;

    //a1.m_data is wrong!! ‘char* ARstring::m_data’ is private within this context
    std::cout << a1 << std::endl;   
    std::cout << a2 << std::endl;


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