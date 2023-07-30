#include <iostream>
#include <thread>
#include <mutex>
#include<string.h>
#include "../include/Apple.h"
using namespace std;


//#include "LogScope.cpp"

/*
   modify
   1. .vscode/launch.json  
   "program": "${workspaceFolder}/build/template2023",
   2.CmakeLists.txt
   add_executable(Template2023 src/main.cpp) #添加生成可执行文件
   target_link_libraries(template2023 pthread)
        
*/

void test01()
{
//  logscope::LOG_SCOPE; 
//  logscope::f(); 
}


int main0()
{

   test01();
   cout<<"hello,world! tempalte2013"<<endl;

   return 0;


}   