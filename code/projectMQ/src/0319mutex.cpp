#include <string>
#include <map>
#include <mutex>
#include <iostream>
#include <thread>
using namespace std;

map<string, string> buffer;
string content;

void savepage(string x)
{
    this_thread::sleep_for(std::chrono::microseconds(1));
    string fakecontent = "content2024";
    buffer[x] = fakecontent;
}

int main(int argc, const char **argv)
{
    thread t1(savepage, "www.example.com");
    thread t2(savepage, "www.cpp.com");
    t1.join();
    t2.join();
    for (auto x : buffer)
    {
        cout << x.first << "->" << x.second << endl;
    }
    return 0;
}