#include "DianaAPI.h"
#include "test_base.h"
#include <gtest/gtest.h>

class Test2023{
public:
    Test2023(int *abc):m_data(abc)
    {
      std::cout<<"init"<<std::endl;
    }

    Test2023(const Test2023&p)
    {
        this->m_data=new int(*p.m_data);

    }
private:
    int *m_data;

};

TEST(onlytest, print)
{
    std::cout <<"agile " << std::endl;
    std::cout <<"robot " << std::endl;

    // int *abc = new int[100];
    // std::cout <<*abc<<std::endl;
    // std::cout <<abc<<std::endl;
    // std::cout <<&(*abc)<<std::endl;
    //sleep(2);

    
    int *a10 = new int[10000];
    int *a11 = new int[10000];
    Test2023 t(new int(10000));
    //delete a10;
}