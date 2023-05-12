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

class Animal
{
   public:
       virtual void talk() const
       {
         std::cout << "animal talk" << std::endl;
       }
   int name;
};

class Dog: public Animal
{
   public:
       void talk() const
       {
         std::cout << "dog talk" << std::endl;
       }

};

class Cat: public Animal
{
   public:
       void talk() const
       {
         std::cout << "cat talk" << std::endl;
       }

};

void test01(Animal * animal)
{
    animal->talk();
}

int main()
{

   Animal  animal1;
   test01(&animal1);

   Dog dog1;
   test01(&dog1);

   
   Animal * obj = new Dog();
   obj->talk();

   Animal * obj2 = new Cat();
   obj2->talk();

   test01(obj);
   test01(obj2);

   

   cout<<"hello,world! tempalte2013"<<endl;

   return 0;


}   
