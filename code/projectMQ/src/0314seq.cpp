#include <iostream>
#include <thread>
#include <string>
#include <chrono>

void th1()
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << "th1--" << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1)); //@1
    }
}
void th2()
{
    for (int i = 0; i < 5; i++)
    {
        std::cout << "th2--" << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1)); //@2
    }
}
int main()
{
    std::cout << "--begin--" << std::endl;
    std::thread t1(th1);
    std::this_thread::sleep_for(std::chrono::seconds(5)); //@3
    std::thread t2(th2);
    //    t1.join();//$1
    //    t2.join();//$2

    for (int i = 0; i < 10; i++)
    {
        std::cout << "main th --" << i << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::seconds(5)); //@4
    t1.detach();                                          //$3
    t2.detach();                                          //$4
    std::cout << "--end--" << std::endl;
    return 0;
}