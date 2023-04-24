// GOF10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <list>
#include <string.h>

#include "NewString.h"

// class ARstring
// {  
//     friend ostream &operator<<(ostream &cout, const ARstring &p);
// public:
    
//     ARstring( char *abc = 0)
//     {
//         if (abc)
//         {
//             int len = sizeof(abc) + 1;
//             m_data = new char[len];
//             //invalid conversion from ‘const char*’ to ‘char*’
//             strcpy(m_data,abc);
//         }
//         else
//         {
//             m_data = new char[1];
//             *m_data = '\0';
//         }
//     }

//     ARstring(const ARstring &p)
//     {
//         int size = sizeof(p.m_data);
//         m_data = new char[size + 1];
//         strcpy(m_data,p.m_data);
//     }

//     ARstring &operator=(const ARstring &p)
//     {
//         if (this != &p)
//         {
//             delete[] m_data;
//             int len = sizeof(p.m_data);
//             m_data = new char[len + 1];
//             //*m_data = *p.m_data;
//             //m_data = p.m_data;
//             strcpy(m_data,p.m_data);
//         }
//         return *this;
//     }

//     ~ARstring()
//     {
//         if (m_data)
//         {
//             //free(): invalid pointer  exception has occur
//             delete[] m_data;
//             m_data = NULL;
//         }
//     }

// private:
//     char *m_data;
// };

// ostream &operator<<(ostream &cout, const ARstring &p)
// {
//     cout<<p.m_data<<endl;
//     return cout;
// }

// class NewString
// {
// friend ostream& operator<<(ostream& cout, const NewString & other);
// public:
// NewString(const char *str=0)
// {
//     if(str)
//     {
//        m_data = new char[strlen(str) + 1];
//        strcpy(m_data, str);
//     }
//     else{
//         m_data = new char[1];
//         *m_data = '\0';
//     }
// }
// NewString(const NewString &other)
// {
//     int len = strlen(other.m_data);
//     m_data = new char[len +1];
//     strcpy(m_data,other.m_data);
// }

// NewString& operator=(const NewString &other)
// {
//     if(this!=&other)
//     {
//         delete [] m_data;
//         m_data = new char[strlen(other.m_data)+1];
//         strcpy(m_data,other.m_data);
//     }
//     return *this;
// }

// ~NewString()
// {
//     if(m_data)
//     {
//         delete [] m_data;
//         m_data = nullptr;
//     }
// }
// private:
// char *m_data;

// };

// ostream& operator<<(ostream& cout, const NewString & other)
// {
//     cout << other.m_data ;
//     return cout;
// }

// void test01()
// {
//     ARstring a1;
//     ARstring a2("New String");
//     a1=a2;

//     //a1.m_data is wrong!! ‘char* ARstring::m_data’ is private within this context
//     std::cout << a1 << std::endl;      //thi version only cout a
//     std::cout << a2 << std::endl;


// }

void test02()
{
    NewString a1;
    NewString a2("abc");
    NewString a3(a2);
    NewString a4;
    a4= a3;
    cout<<a1<<endl;
    cout<<a2<<endl;
    cout<<a3<<endl;
    cout<<a4<<endl;

    
    

}

int main()
{
    test02();
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