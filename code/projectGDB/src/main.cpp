#include <iostream>
#include <thread>
#include <mutex>
#include<string.h>
#include "Apple.h"
using namespace std;
#include <vector>


/*
   modify
   1. .vscode/launch.json  
   "program": "${workspaceFolder}/build/template2023",
   2.CmakeLists.txt
   add_executable(Template2023 src/main.cpp) #添加生成可执行文件
   target_link_libraries(template2023 pthread)
        
*/

int main()
{

   cout<<"hello,world! tempalte2013"<<endl;

   // for(int i=0; i<10; i++)
   // {
   //    cout<<"i: "<<i<< endl;
   // }

   vector<int> v;
   v.push_back(10);
   v.push_back(20);
   v.push_back(30);
   for(auto x:v)
   {
      cout<<x<<endl;
   }

   return 0;


}   