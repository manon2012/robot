#include <iostream>
#include <thread>
#include <mutex>
#include<string.h>
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

int main()
{
   string country[3]= {"us","jpn","cn"};
   string power[6] = {"A","B","C","D","E","F"};
   for(auto &x:country)
   {
      cout << x<<" ";
      string temp = x;

      cout<< temp<<endl;
      for(auto &y:power)
      {
         
         cout << y;
      }
      cout<<endl;
      
   }


   cout<<"hello,world! tempalte2013"<<endl;

   return 0;


}   