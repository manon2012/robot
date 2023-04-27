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
class MyClass
{
public:
   MyClass(int x=0):m_A(x)
   {

   }
 
   void show()
   {
      cout << "MyClass show" << endl;
   }

private:
   int m_A;
};

void test01()
{
   MyClass myInstance[10];

   for (int i = 0; i < 10; i++)
   {
      myInstance[i].show();
   }
}

void test02()
{
   MyClass *MyInstance[10];

   // Allocate
   for (unsigned int i = 0; i < 10; i++)
   {
      MyInstance[i] = new MyClass(i);
   }

   // At the end free
   for (unsigned int i = 0; i < 10; i++)
   {
      delete MyInstance[i];
   }
}

int main()
{

   test01();
   test02();
   return 0;
}