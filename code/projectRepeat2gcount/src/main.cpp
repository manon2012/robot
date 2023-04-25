#include <iostream>
#include <thread>
#include <mutex>
#include<string.h>
#include "Apple.h"
using namespace std;
#include "test01.h"



/*
   modify
   1. .vscode/launch.json  
   "program": "${workspaceFolder}/build/template2023",
   2.CmakeLists.txt
   add_executable(Template2023 src/main.cpp) #添加生成可执行文件
   target_link_libraries(template2023 pthread)
        
*/




void test02()
{
   test01();
   test01();

}

int main()
{
   test02();
   cout<<"hello,world! tempalte2013"<<endl;

   return 0;


}   