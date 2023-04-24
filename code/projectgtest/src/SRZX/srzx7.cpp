
#include <sys/time.h>
#include "DianaAPI.h"
#include "test_base.h"
#include <gtest/gtest.h>

// 参数分别为（1, 10, 0.1） （2, 10, 0.1）
// 阶次1滞后1个周期，阶次2滞后1.5个周期
// 频率为10,一个周期为0.1秒，两组的差值时间为（1.5-1）* 0.1 = 0.05秒。
// 程序每次调用2次moveLToPose函数，总差值理论为0.05*2 = 0.1秒。


double vel = 0.5;
double acc = 0.5;


void JToTarget_order(int order, double frequency,double damping)
{
    printf("开始测试输入整形默认功能.\n");
    double joints1[7] = { to_rad(0.207),to_rad(-18.868),to_rad(0.422),to_rad(143.074),to_rad(-3.144),to_rad(-55.220),to_rad(-42.312) };

    int ret = moveJToTarget(joints1, vel, acc, order, frequency, damping);
    if (ret < 0)
    {
    	printf("moveJToTarget failed!Return value = %d\n", ret);
    }
      else
    {
        std::cout <<"moveJToTarget moving..."<<std::endl;
        //sleepMilliseconds(1000);
        wait_move();
        std::cout <<"moveJToTarget done."<<std::endl;
    }

    double init_joints[7] ={0.0};
    moveJToTarget(init_joints, vel, acc, order, frequency, damping);
    wait_move();
    std::cout <<"已回原"<<std::endl;

}


void LToTarget_order(int order, double frequency,double damping)
{

    double joints2[7] = { to_rad(20),to_rad(0),to_rad(0),to_rad(90),to_rad(0),to_rad(-90),to_rad(0) };
    int ret = moveLToTarget(joints2, vel, acc, order, frequency, damping);
    if (ret < 0)
    {
    	printf("moveLToTarget failed!Return value = %d\n", ret);
    }
    else
    {
        std::cout <<"moveLToTarget moving..."<<std::endl;
        //sleepMilliseconds(1000);
        wait_move();
        std::cout <<"moveLToTarget done."<<std::endl;
    }

    double joints3[7] = { to_rad(0),to_rad(0),to_rad(0),to_rad(90),to_rad(0),to_rad(-90),to_rad(0) };
    ret = moveLToTarget(joints3, vel, acc, order, frequency, damping);
    if (ret < 0)
    {
    	printf("moveLToTarget failed!Return value = %d\n", ret);
    }
    else
    {
        std::cout <<"moveLToTarget moving..."<<std::endl;
        //sleepMilliseconds(1000);
        wait_move();
        std::cout <<"moveLToTarget done."<<std::endl;
    }




}


void JToPose_order(int order, double frequency, double damping)
{
    double firstpose[6] = { 0.607404,-0.000014,0.514507, 0, 0.001, 0.001 };
    int ret=moveJToPose(firstpose, vel, acc, nullptr, order, frequency, damping);
    if (ret < 0)
    {
    	printf("moveJToPose failed!Return value = %d\n", ret);
    }
    else
    {
        std::cout <<"moveJToPose moving..."<<std::endl;
        //sleepMilliseconds(1000);
        wait_move();
        std::cout <<"moveJToPose done."<<std::endl;
    }

    double secondpose[6] = { 0.607405, -0.000007, 0.692300, 0, -0.001, -0.001};
    ret=moveJToPose(secondpose, vel, acc, nullptr, order, frequency, damping);
    if (ret < 0)
    {
    	printf("moveJToPose failed!Return value = %d\n", ret);
    }
    else
    {
        std::cout <<"moveJToPose moving..."<<std::endl;
        //sleepMilliseconds(1000);
        wait_move();
        std::cout <<"moveJToPose done."<<std::endl;
    }


}


void LToPose_order(int order, double frequency, double damping)
{
    double firstpose[6] = { 0.607404, -0.000014, 0.514507, 0, 0.001, 0.001 };
    int ret=moveLToPose(firstpose, vel, acc, nullptr, order, frequency, damping);
    if (ret < 0)
    {
    	printf("moveLToPose failed!Return value = %d\n", ret);
    }
    else
    {
        std::cout <<"moveLToPose moving..."<<std::endl;
        //sleepMilliseconds(1000);
        wait_move();
        std::cout <<"moveLToPose done."<<std::endl;
    }

    double secondpose[6] = { 0.607405, -0.000007, 0.692300, 0, -0.001, -0.001};
    ret=moveLToPose(secondpose, vel, acc, nullptr, order, frequency, damping);
    if (ret < 0)
    {
    	printf("moveLToPose failed!Return value = %d\n", ret);
    }
    else
    {
        std::cout <<"moveLToPose moving..."<<std::endl;
        //sleepMilliseconds(1000);
        wait_move();
        std::cout <<"moveLToPose done."<<std::endl;
    }

}



void AddJToTarget_order(int order, double frequency,double damping)
{
    double acc=0.25;
    double vel=0.25;
    double blendradius=0.0;

    double joints1[7] = { to_rad(0.207),to_rad(-18.868),to_rad(0.422),to_rad(143.074),to_rad(-3.144),to_rad(-55.220),to_rad(-42.312) };
    double joints2[7] = { 0.0 };

    int complex_path_type = 0;
    unsigned int complex_path_id;
    bool ignore_rotation = true;

    std::cout<<"complex_path_type 0 :表示 NORMAL_JOINT,该模式下路径中可以添加";
    std::cout<<"moveJ对应的路径点,路径点用 JOINT_NUM 个关节角度确定。"<<std::endl;
    int ret=createComplexPath(complex_path_type, complex_path_id);
    if (ret < 0)
    {
        printf("createComplexPath failed!Return value = %d\n", ret);
    }
    ret=addMoveJByTarget(complex_path_id, joints1, vel, acc, blendradius, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveJByTarget failed!Return value = %d\n", ret);
    }
    ret=addMoveJByTarget(complex_path_id, joints2, vel, acc, blendradius, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveJByTarget failed!Return value = %d\n", ret);
    }
    else
    {
        printf("addMoveJByTarget add done.");
    }

    ret=runComplexPath(complex_path_id);
    if (ret < 0)
    {
        printf("runComplexPath failed!Return value = %d\n", ret);
    }
    ret=destroyComplexPath(complex_path_id);
    if (ret < 0)
    {
        printf("destroyComplexPath failed!Return value = %d\n", ret);
    }
    wait_move(); 
}


void AddLToTarget_order(int order, double frequency,double damping)
{
    //addMoveJByTarget测试
    double blendradius=0;


    double joints2[7] = { to_rad(20),to_rad(0),to_rad(0),to_rad(90),to_rad(0),to_rad(-90),to_rad(0) };
    double joints3[7] = { to_rad(0),to_rad(0),to_rad(0),to_rad(90),to_rad(0),to_rad(-90),to_rad(0) };

    

    int complex_path_type = 0;
    unsigned int complex_path_id;
    bool ignore_rotation = true;

    std::cout<<"complex_path_type 0 :表示 NORMAL_JOINT,该模式下路径中可以添加";
    std::cout<<"moveJ对应的路径点,路径点用 JOINT_NUM 个关节角度确定。"<<std::endl;
    int ret=createComplexPath(complex_path_type, complex_path_id);
    if (ret < 0)
    {
        printf("createComplexPath failed!Return value = %d\n", ret);
    }
    ret=addMoveLByTarget(complex_path_id, joints2, vel, acc, blendradius, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveJByTarget failed!Return value = %d\n", ret);
    }
    ret=addMoveLByTarget(complex_path_id, joints3, vel, acc, blendradius, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveLByTarget failed!Return value = %d\n", ret);
    }
    else
    {
        printf("addMoveLByTarget add done.");
    }


    ret=runComplexPath(complex_path_id);
    if (ret < 0)
    {
        printf("runComplexPath failed!Return value = %d\n", ret);
    }
    ret=destroyComplexPath(complex_path_id);
    if (ret < 0)
    {
        printf("destroyComplexPath failed!Return value = %d\n", ret);
    }
    wait_move(); 

}


void AddJToPose_order(int order, double frequency,double damping)
{
    double acc=0.25;
    double vel=0.25;
    double blendradius=0;

    double firstpose[6] = { 0.607404,-0.000014,0.514507,0,0.001,0.001 };
    double secondpose[6] = { 0.607405,-0.000007,0.692300,0,-0.001,-0.001};


    int complex_path_type = 2;
    unsigned int complex_path_id;
    bool ignore_rotation = true;

    std::cout<<"complex_path_type 2 :NORMAL_POSE ,该模式下路径中可以添加";
    std::cout<<"moveL对应的路径点,路径点用末端 TCP 位姿数据确定。"<<std::endl;
    int ret=createComplexPath(complex_path_type, complex_path_id);
    if (ret < 0)
    {
        printf("createComplexPath failed!Return value = %d\n", ret);
    }
    ret=addMoveJByPose(complex_path_id, firstpose, vel, acc, blendradius, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveJByPose failed!Return value = %d\n", ret);
    }
    ret=addMoveJByPose(complex_path_id, secondpose, vel, acc, blendradius, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveJByPose failed!Return value = %d\n", ret);
    }
    else
    {
        printf("addMoveJByPose add done.");
    }


    ret=runComplexPath(complex_path_id);
    if (ret < 0)
    {
        printf("runComplexPath failed!Return value = %d\n", ret);
    }
    ret=destroyComplexPath(complex_path_id);
    if (ret < 0)
    {
        printf("destroyComplexPath failed!Return value = %d\n", ret);
    }
    wait_move(); 
}

void AddLToPose_order(int order, double frequency,double damping)
{
    double blendradius=0;
    double firstpose[6] = { 0.607404,-0.000014,0.514507,0,0.001,0.001 };
    double secondpose[6] = { 0.607405,-0.000007,0.692300,0,-0.001,-0.001};

    int complex_path_type = 2;
    unsigned int complex_path_id;
    bool ignore_rotation = true;

    std::cout<<"complex_path_type 2 :NORMAL_POSE ,该模式下路径中可以添加";
    std::cout<<"moveL对应的路径点,路径点用末端 TCP 位姿数据确定"<<std::endl;
    int ret=createComplexPath(complex_path_type, complex_path_id);
    if (ret < 0)
    {
        printf("createComplexPath failed!Return value = %d\n", ret);
    }
    ret=addMoveLByPose(complex_path_id, firstpose, vel, acc, blendradius, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveLByPose failed!Return value = %d\n", ret);
    }
    ret=addMoveLByPose(complex_path_id, secondpose, vel, acc, blendradius, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveLByPose failed!Return value = %d\n", ret);
    }
    else
    {
        printf("addMoveLByPose add done.");
    }


    ret=runComplexPath(complex_path_id);
    if (ret < 0)
    {
        printf("runComplexPath failed!Return value = %d\n", ret);
    }
    ret=destroyComplexPath(complex_path_id);
    if (ret < 0)
    {
        printf("destroyComplexPath failed!Return value = %d\n", ret);
    }
    wait_move(); 

}


void AddCToTarget_order(int order, double frequency,double damping)
{
    double acc=0.25;
    double vel=0.25;
    double blendradius=0.00;

    double joints[7] = { to_rad(0.207),to_rad(-18.868),to_rad(0.422),to_rad(143.074),to_rad(-3.144),to_rad(-55.220),to_rad(-42.312) };

     //ComplexPath指令
    double joints1[7] = { 0.0 };
    int ret = getJointPos(joints1);
    if (ret < 0)
    {
        printf("getJointPos failed!Return value = %d\n", ret);
    }

    double firstpose[6] = { 0.0 };
    ret = forward(joints1, firstpose, nullptr);
    if (ret < 0)
    {
        printf("forward failed!Return value = %d\n", ret);
    }
 
    firstpose[0] += 0.2;
    firstpose[1] += 0.2;
    double fourthjoints[7] = { 0.0 };
    ret = inverse(firstpose, fourthjoints, nullptr);
    if (ret < 0)
    {
        printf("inverse failed!Return value = %d\n", ret);
    }
    firstpose[0] -= 0.2;
    firstpose[1] += 0.2;
    double fifthjoints[7] = { 0.0 };
    ret = inverse(firstpose, fifthjoints, nullptr);
    if (ret < 0)
    {
        printf("inverse failed!Return value = %d\n", ret);
    }

    int complex_path_type = 0;
    unsigned int complex_path_id;
    bool ignore_rotation = true;

    std::cout<<"complex_path_type 0 :表示 NORMAL_JOINT,该模式下路径中可以添加";
    std::cout<<"moveC 对应的路径点,路径点用 JOINT_NUM 个关节角度确定。"<<std::endl;
    sleepMilliseconds(100);
    ret=createComplexPath(complex_path_type, complex_path_id);
    if (ret < 0)
    {
        printf("createComplexPath failed!Return value = %d\n", ret);
    }

    ret=addMoveCByTarget(complex_path_id, fourthjoints, fifthjoints, vel, acc, blendradius, ignore_rotation, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveCByTarget failed!Return value = %d\n", ret);
    }

    ret=addMoveCByTarget(complex_path_id, fourthjoints, joints1, vel, acc, blendradius, ignore_rotation, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveCByTarget failed!Return value = %d\n", ret);
    }
    else
    {
        printf("addMoveCByTarget add done.");
    }



    ret=runComplexPath(complex_path_id);
    if (ret < 0)
    {
        printf("runComplexPath failed!Return value = %d\n", ret);
    }
    ret=destroyComplexPath(complex_path_id);
    if (ret < 0)
    {
        printf("destroyComplexPath failed!Return value = %d\n", ret);
    }
    wait_move(); 

}


void AddCToPose_order(int order, double frequency,double damping)
{

    double acc=0.25;
    double vel=0.25;
    double blendradius=0.0;

    double joints[7] = { to_rad(0.207),to_rad(-18.868),to_rad(0.422),to_rad(143.074),to_rad(-3.144),to_rad(-55.220),to_rad(-42.312) };
    double beginpose[6] = { 0.0 };
    forward(joints, beginpose, nullptr);
    
     //ComplexPath指令
    double joints1[7] = { 0.0 };
    int ret = getJointPos(joints1);
    if (ret < 0)
    {
        printf("getJointPos failed!Return value = %d\n", ret);
    }

    double firstpose[6] = { 0.0 };
    ret = forward(joints1, firstpose, nullptr);
    if (ret < 0)
    {
        printf("forward failed!Return value = %d\n", ret);
    }
 
    firstpose[0] += 0.2;
    firstpose[1] += 0.2;
    double fourthjoints[7] = { 0.0 };
    ret = inverse(firstpose, fourthjoints, nullptr);
    if (ret < 0)
    {
        printf("inverse failed!Return value = %d\n", ret);
    }
    firstpose[0] -= 0.2;
    firstpose[1] += 0.2;
    double fifthjoints[7] = { 0.0 };
    ret = inverse(firstpose, fifthjoints, nullptr);
    if (ret < 0)
    {
        printf("inverse failed!Return value = %d\n", ret);
    }


    double fourthpose[6] = { 0.0 };
    double fifthpose[6] = { 0.0 };
    forward(fourthjoints, fourthpose, nullptr);
    forward(fifthjoints, fifthpose, nullptr);

    int complex_path_type = 2;
    unsigned int complex_path_id;
    bool ignore_rotation = true;

    std::cout<<"complex_path_type 2 :NORMAL_POSE ,该模式下路径中可以添加";
    std::cout<<"moveC 对应的路径点,路径点用末端 TCP 位姿数据确定"<<std::endl;
    sleepMilliseconds(100);
    ret=createComplexPath(complex_path_type, complex_path_id);
    if (ret < 0)
    {
        printf("createComplexPath failed!Return value = %d\n", ret);
    }

    ret=addMoveCByPose(complex_path_id, fourthpose, fifthpose, vel, acc, blendradius, ignore_rotation, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveCByPose failed!Return value = %d\n", ret);
    }

    ret=addMoveCByPose(complex_path_id, fourthpose, beginpose, vel, acc, blendradius, ignore_rotation, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveCByPose failed!Return value = %d\n", ret);
    }
    else
    {
        printf("addMoveCByPose add done.");
    }



    ret=runComplexPath(complex_path_id);
    if (ret < 0)
    {
        printf("runComplexPath failed!Return value = %d\n", ret);
    }
    ret=destroyComplexPath(complex_path_id);
    if (ret < 0)
    {
        printf("destroyComplexPath failed!Return value = %d\n", ret);
    }
    wait_move(); 

}



typedef void (*p) (int x, double y,double z);
bool funcTimer(p func)
{
    float time_use1=0;
    float time_use2=0;
    float t=0;
    struct timeval start;
    struct timeval end; 

    double joints[7] = { to_rad(0.207),to_rad(-18.868),to_rad(0.422),to_rad(143.074),to_rad(-3.144),to_rad(-55.220),to_rad(-42.312) };
    gettimeofday(&start,NULL); 
    for(int i=0;i<3;i++)
    {
        func(1,10,0.1);
    }
    gettimeofday(&end,NULL);
    time_use1=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);//微秒
    printf("time_use1 is %f \n",time_use1/3000000); 
    //moveJToTarget(joints, vel, acc);
    gettimeofday(&start,NULL); 
    for(int i=0;i<3;i++)
    {
        func(2,10,0.1);
    }
    gettimeofday(&end,NULL);
    time_use2=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);//微秒
    printf("time_use2 is %f \n",time_use2/3000000);
    //频率都为10, 一个周期0.1s，阶次2滞后3/2个周期，阶次1滞后1个周期，2者差0.5个周期，即0.05s
    //每个运动包含2个moveJToTarget，总共应该差0.05*2=0.1秒。
    std::cout<<"time_use2:"<<time_use2<<std::endl;
    std::cout<<"time_use1:"<<time_use1<<std::endl;
    std::cout<<"time_use2-time_use1:"<<(time_use2-time_use1)/3000000<<std::endl;
    t= (time_use2-time_use1)/3000000;
    std::cout <<t<<std::endl;
    if(t>0.05&&t<0.11)
    {
        return true;
    }
    else
    {
        return false;
    }
}







static const char *strIpAddress = "192.168.10.75";

class SRZX : public ::testing::Test
{
protected:
    virtual void SetUp()
    {
        srv_net_st net_info;
        initSrvNetInfo(&net_info);
        strcpy(net_info.SrvIp, strIpAddress);
        int connect_ret = initSrv(errorControl, nullptr, &net_info);
        EXPECT_EQ(0, connect_ret);
        // ASSERT_EQ(0,connect_ret);

        if (connect_ret != 0)
        {
            printf("initSrv failed!Return value = %d\n", connect_ret);
        }
        int HRESULT = releaseBrake();

        cleanErrorInfo();
    }

    void TearDown()
    {
        // 恢复关节极限位置
        double setdbJMinPos_2[7] = {to_rad(-179), to_rad(-90), to_rad(-179), to_rad(0), to_rad(-179), to_rad(-179), to_rad(-179)};
        double setdbJMaxPos_2[7] = {to_rad(179), to_rad(90), to_rad(179), to_rad(175), to_rad(179), to_rad(179), to_rad(179)};
        setJointsPositionRange(setdbJMinPos_2, setdbJMaxPos_2);

        // 恢复关节软限位置
        double dblMinPos1[7] = {to_rad(-174), to_rad(-85), to_rad(-174), to_rad(5), to_rad(-174), to_rad(-174), to_rad(-174)};
        double dblMaxPos1[7] = {to_rad(174), to_rad(85), to_rad(174), to_rad(170), to_rad(174), to_rad(174), to_rad(174)};
        setJointsSoftLimitRange(dblMinPos1, dblMaxPos1);

        holdBrake();
        destroySrv();
    }
};

TEST_F(SRZX, srzx_case7)
{
   int count=0;

    //初始位姿 回原
    double init_joints[7] ={0.0};
    double init_vel = 0.5;
    double init_acc = 0.5;
    moveJToTarget(init_joints, init_vel, init_acc);
    wait_move();
    std::cout <<"已回原"<<std::endl;


    p func=JToTarget_order;
    if(funcTimer(func))
    {
        count++;
    }

    double joints2[7] = { to_rad(0),to_rad(0),to_rad(0),to_rad(90),to_rad(0),to_rad(-90),to_rad(0) };
    moveJToTarget(joints2, vel, acc);
    wait_move();
    func = LToTarget_order;
    if(funcTimer(func))
    {
        count++;
    }


    moveJToTarget(joints2, vel, acc);
    wait_move();
    func = JToPose_order;
    if(funcTimer(func))
    {
        count++;
    } 
    

    moveJToTarget(joints2, vel, acc);
    wait_move();
    func = LToPose_order;
    if(funcTimer(func))
    {
        count++;
    }

    //return;

    double initjoints[7] = {0};
    int ret = moveJToTarget(initjoints, vel, acc);
    wait_move();
    func = AddJToTarget_order;
    if(funcTimer(func))
    {
        count++;
    }

    moveJToTarget(joints2, vel, acc);
    wait_move();
    func = AddLToTarget_order;
    if(funcTimer(func))
    {
        count++;
    }

    moveJToTarget(joints2, vel, acc);
    wait_move();
    func = AddJToPose_order;
    if(funcTimer(func))
    {
        count++;
    }

    moveJToTarget(joints2, vel, acc);
    wait_move();
    func = AddLToPose_order;
    if(funcTimer(func))
    {
        count++; 
    }

    double joints[7] = { to_rad(0.207),to_rad(-18.868),to_rad(0.422),to_rad(143.074),to_rad(-3.144),to_rad(-55.220),to_rad(-42.312) };
    moveJToTarget(joints, vel, acc);
    wait_move();
    func = AddCToTarget_order;
    if(funcTimer(func))
    {
        count++;
    }

    moveJToTarget(joints, vel, acc, -1);
    wait_move();
    func = AddCToPose_order;
    if(funcTimer(func))
    {
        count++;
    }
     
    EXPECT_EQ(count,10);

    std::cout<<"count = "<<count<<std::endl;

}