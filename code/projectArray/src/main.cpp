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


#define PASSWORD "123456"
int Test(char *str)
{
//   int flag;
  char buffer[7];
  int flag;
  flag=strcmp(str,PASSWORD);
  strcpy(buffer,str);
  return flag;
}
int main(void)
{
  int flag=0;
  char str[1024];
  while(1)
  {
    printf("请输入密码： ");
    scanf("%s",str);
    flag = Test(str);
    if(flag)
    {
      printf("密码错误！\n");
    }
      else
      {
        printf("密码正确！\n");
      }
  }
  return 0;
}


// int main()
// {
//    test01();
//    cout<<"hello,world! tempalte2013"<<endl;

//    return 0;


// }   




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


/*
https://www.jb51.net/article/189149.htm
上面的示例代码模拟了一个密码验证的例子，它将用户输入的密码与宏定义中的密码“123456”进行比较。
很显然，本示例中最大的设计漏洞就在于 Test() 函数中的 strcpy(buffer,str) 调用。

由于程序将用户输入的字符串原封不动地复制到 Test() 函数的数组 char buffer[7] 中。
因此，当用户的输入大于 7 个字符的缓冲区尺寸时，就会发生数组越界错误，
这也就是大家所谓的缓冲区溢出(Buffer overflow)漏洞。
但是要注意，如果这个时候我们根据缓冲区溢出发生的具体情况填充缓冲区，
不但可以避免程序崩溃，还会影响到程序的执行流程，甚至会让程序去执行缓冲区里的代码。
示例运行结果为：

    请输入密码:12345
    密码错误！
    请输入密码:123456
    密码正确！
    请输入密码:1234567
    密码正确！
    请输入密码:aaaaaaa
    密码正确！
    请输入密码:0123456
    密码错误！
    请输入密码:

在示例代码中，flag 变量实际上是一个标志变量，其值将决定着程序是进入“密码错误”的流程（非 0）
还是“密码正确”的流程（0）。当我们输入错误的字符串“1234567”或者“aaaaaaa”，
程序也都会输出“密码正确”。但在输入“0123456”的时候，程序却输出“密码错误”，这究竟是为什么呢？

其实，原因很简单。当调用 Test() 函数时，系统将会给它分配一片连续的内存空间，
而变量 char buffer[7] 与 int flag 将会紧挨着进行存储，
用户输入的字符串将会被复制进 buffer[7] 中。如果这个时候，
我们输入的字符串数量超过 6 个（注意，有字符串截断符也算一个），
那么超出的部分将破坏掉与它紧邻着的 flag 变量的内容。

当输入的密码不是宏定义的“123456”时，字符串比较将返回 1 或 -1。
我们都知道，内存中的数据按照 4 字节（DWORD）逆序存储，
所以当 flag 为 1 时，在内存中存储的是 0x01000000。
如果我们输入包含 7 个字符的错误密码，如“aaaaaaa”，
那么字符串截断符 0x00 将写入 flag 变量，
这样溢出数组的一个字节 0x00 将恰好把逆序存放的 flag 变量改为 0x00000000。
在函数返回后，一旦 main 函数的 flag 为 0，就会输出“密码正确”。
这样，我们就用错误的密码得到了正确密码的运行效果。

而对于“0123456”，因为在进行字符串的大小比较时，它小于“123456”，flag的值是 -1，
在内存中将按照补码存放负数，所以实际存储的不是 0x01000000 而是 0xffffffff。
那么字符串截断后符 0x00 淹没后，变成 0x00ffffff，还是非 0，所以没有进入正确分支。

其实，本示例只是用一个字节淹没了邻接变量，导致程序进入密码正确的处理流程，使设计的验证功能失效。
*/