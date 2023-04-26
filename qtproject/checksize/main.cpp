#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

class dummy
{
public:
    dummy(int x=0, int y=0,int x2=0, int y2=0, int x3=0, int y3=0,int x4=0, int y4=0):m_A1(x),m_B1(y)
    {
        cout<<"init done"<<endl;
    }
    void show()
    {
        cout<<"dummy show"<<endl;
    }

private:
    int m_A1;
    int m_B1;
    int m_A2;
    int m_B2;
    int m_A3;
    int m_B3;
    int m_A4;
    int m_B4;
};

void test01()
{
    //dummy *instance1 = new dummy(1,1);

    //for (int i=0; i<100; i++)
    //{
        //string name = "dummy"+to_string(i);
       // dummy "dummy".append(to_string(i))= new dummy(10,10);
   // }

//    dummy myInstance[10];

//    for(int i = 0; i < 10; i++)
//    {
//        myInstance[i].show();
//    }

    dummy *myInstance[40000];

    // Allocate
    for (unsigned int i = 0; i < 40000; i++)
    {
    myInstance[i] = new dummy(1,1);
    }

}

int main()
{

     test01();

     dummy *t = new dummy(1,1);
     std::cout<<"sizet: "<<sizeof(t)<<std::endl;

     int * p = new int(10);
     std::cout<<"sizep: "<<sizeof(p)<<std::endl;
    cout << "Hello World!" << endl;
    usleep(1000);
    std::cout<<"sizeofdummy:"<<sizeof(dummy)<<std::endl;
    return 0;
}
