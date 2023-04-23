#include "DianaAPI.h"
#include "test_base.h"
#include <gtest/gtest.h>
#include <stdexcept>

static const char *strIpAddress = "192.168.10.75";



TEST(UTTest,t0)
{
   srv_net_st net_info;
    initSrvNetInfo(&net_info);
    strcpy(net_info.SrvIp, strIpAddress);
    int connect_ret = initSrv(errorControl, nullptr, &net_info);
    EXPECT_EQ(0,connect_ret);
    //ASSERT_EQ(0,connect_ret);
    
    if (connect_ret != 0) {
        printf("initSrv failed!Return value = %d\n", connect_ret);
    }
    int HRESULT = releaseBrake();
    EXPECT_EQ(0,HRESULT);

    //初始位姿 回原
    double init_joints[7] ={0.0};
    double init_vel = 0.4;
    double init_acc = 0.4;
    HRESULT = moveJToTarget(init_joints, init_vel, init_acc);
    
    wait_move();
	EXPECT_EQ(0,HRESULT);
    std::cout <<"已回原"<<std::endl;

}

TEST(UTTest,t1)
{
    double init_joints[7] ={0,0,0,to_rad(90),0,to_rad(-90),0};
	double init_vel = 0.4;
    double init_acc = 0.4;
	int HRESULT = moveJToTarget(init_joints, init_vel, init_acc);
    
    wait_move();
	EXPECT_EQ(0,HRESULT);
}



// class Exception : public runtime_error {
// public:
//     // Defining constructor of class Exception
//     // that passes a string message to the runtime_error class
//     Exception()
//         : runtime_error("Math error: Attempted to divide by Zero\n")
//     {
//     }
// };

TEST(MoveTest, d0)
{
    int abc = 100;
    
    // try{
    //      abc/0;
    // }
    // catch(Exception& e)
    // {
    //    //std::cout << e.what() << std::endl;
    // }
    

}

TEST(MoveTest, onlyprint)
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
    //delete a10;
}