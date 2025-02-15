//#include "pch.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <future>
  
using namespace std::chrono;
  
std::string fetchDataFromDB(std::string recvData) {
  
    std::cout << "fetchDataFromDB start" << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(seconds(5));
    return "DB_" + recvData;
}
  
  
int main() {
  
    std::cout << "main start" << std::this_thread::get_id() << std::endl;
  
    //获取开始时间
    system_clock::time_point start = system_clock::now();
  
    std::future<std::string> resultFromDB = std::async(std::launch::async, fetchDataFromDB, "Data");
  
    std::future_status status;
    std::string dbData;
    do
    {
        status = resultFromDB.wait_for(std::chrono::seconds(1));
  
        switch (status)
        {
        case std::future_status::ready:
            std::cout << "Ready..." << std::endl;
            //获取结果
            dbData = resultFromDB.get();
            std::cout << dbData << std::endl;
            break;
        case std::future_status::timeout:
            std::cout << "timeout..." << std::endl;
            break;
        case std::future_status::deferred:
            std::cout << "deferred..." << std::endl;
            break;
        default:
            break;
        }
  
    } while (status != std::future_status::ready);
  
     
    //获取结束时间
    auto end = system_clock::now();
  
    auto diff = duration_cast<std::chrono::seconds>(end - start).count();
    std::cout << "Total Time taken= " << diff << "Seconds" << std::endl;
  
    return 0;
}
