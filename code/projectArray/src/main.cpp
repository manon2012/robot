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
void test01()
{
    int a[2];
    a[0]=1;
    a[1]=2;
    a[2]=3;

    for(int i=0; i<3;i++)
    {
      std::cout <<a[i] << std::endl;
    }
       for(int i=0; i<3;i++)
    {
      std::cout <<&a[i] << std::endl;
    }

}   //crash here stack smashing detected ***: <unknown> terminated

int main()
{
   test01();
   cout<<"hello,world! tempalte2013"<<endl;

   return 0;


}   




/*
https://blog.csdn.net/ive_lanco/article/details/81094484
1
2
3
0x7fffffffcb10
0x7fffffffcb14
0x7fffffffcb18
*** stack smashing detected ***: <unknown> terminated
*/