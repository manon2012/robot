#include "DianaAPI.h"
#include "test_base.h"
#include <gtest/gtest.h>
#include <sys/time.h>

static const char *strIpAddress = "192.168.10.75";

//I
static int order = 2;
static double frequency = 15;
static double damping = 0.1;

//II
// static int order = 1;
// static double frequency = 2023;
// static double damping = 0.1;

//III
// static int order = 1;
// static double frequency = 100;
// static double damping = 0.1;


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



void testmove6()
{
       //初始位姿 回原
    double init_joints[7] ={0.0};
    double init_vel = 0.4;
    double init_acc = 0.4;
    moveJToTarget(init_joints, init_vel, init_acc,order, frequency, damping);
    wait_move();
    std::cout <<"已回原"<<std::endl;

    printf("开始测试输入整形默认功能.\n");
    double joints1[7] = { to_rad(0.207),to_rad(-18.868),to_rad(0.422),to_rad(143.074),to_rad(-3.144),to_rad(-55.220),to_rad(-42.312) };
    double vel = 0.5;
    double acc = 0.5;
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
    

    double joints2[7] = { to_rad(0.216),to_rad(30.758),to_rad(0.278),to_rad(80.966),to_rad(-3.091),to_rad(-67.682),to_rad(-43.086) };
    ret = moveLToTarget(joints2, vel, acc, order, frequency, damping);
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
    

    double firstpose[6] = { 0.600,0.600,0.600,0,0,0 };
    ret = moveJToPose(firstpose, vel, acc, nullptr, order, frequency, damping);
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
    

    firstpose[0]-= 0.3;
    firstpose[1]-= 0.3;
    firstpose[2]-= 0.3;
    vel = 0.28;
    acc = 0.28;
    ret = moveLToPose(firstpose, vel, acc, nullptr, order, frequency, damping);
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

void testAddMove6()
{   
    double acc=0.25;
    double vel=0.25;
    double blendradius=0.05;

    double joints[7] = { to_rad(0.207),to_rad(-18.868),to_rad(0.422),to_rad(143.074),to_rad(-3.144),to_rad(-55.220),to_rad(-42.312) };
    int ret = moveJToTarget(joints, vel, acc);
    if (ret < 0)
    {
    	printf("moveJToTarget failed!Return value = %d\n", ret);
    }
    wait_move();


     //ComplexPath指令
    double joints1[7] = { 0.0 };
    ret = getJointPos(joints1);
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
    firstpose[1] += 0.4;
    double secondjoints[7] = { 0.0 };
    ret = inverse(firstpose, secondjoints, nullptr);
    if (ret < 0)
    {
        printf("inverse failed!Return value = %d\n", ret);
    }
    firstpose[1] -= 0.4;
    double thirdjoints[7] = { 0.0 };
    ret = inverse(firstpose, thirdjoints, nullptr);
    if (ret < 0)
    {
        printf("inverse failed!Return value = %d\n", ret);
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
    std::cout<<"moveL、moveJ、moveC 对应的路径点,路径点用 JOINT_NUM 个关节角度确定。"<<std::endl;
    sleepMilliseconds(100);
    ret=createComplexPath(complex_path_type, complex_path_id);
    if (ret < 0)
    {
        printf("createComplexPath failed!Return value = %d\n", ret);
    }
    ret=addMoveJByTarget(complex_path_id, secondjoints, vel, acc, blendradius, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveJByTarget failed!Return value = %d\n", ret);
    }
    ret=addMoveLByTarget(complex_path_id, thirdjoints, vel, acc, blendradius, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveLByTarget failed!Return value = %d\n", ret);
    }
    ret=addMoveCByTarget(complex_path_id, fourthjoints, fifthjoints, vel, acc, blendradius, ignore_rotation, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveCByTarget failed!Return value = %d\n", ret);
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
    
 
    std::cout<<"complex_path_type 1 :表示 MOVEP_JOINT,该模式下机械臂关节做点对点的匀速运动,路径中可以添加";
    std::cout<<"moveL、moveC 对应的路径点,不可以添加 moveJ 对应的路径点,路径点用 JOINT_NUM个关节角度确定"<<std::endl;
    sleepMilliseconds(100);
    complex_path_type = 1;
    ret=createComplexPath(complex_path_type, complex_path_id);
    if (ret < 0)
    {
        printf("createComplexPath failed!Return value = %d\n", ret);
    }
    firstpose[0] += 0.2;
    firstpose[1] -= 0.2;
    double sixthjoints[7] = { 0.0 };
    ret = inverse(firstpose, sixthjoints, nullptr);
    if (ret < 0)
    {
        printf("inverse failed!Return value = %d\n", ret);
    }
    firstpose[0] -= 0.2;
    firstpose[1] -= 0.2;
    double seventhjoints[7] = { 0.0 };
    ret = inverse(firstpose, seventhjoints, nullptr);
    if (ret < 0)
    {
        printf("inverse failed!Return value = %d\n", ret);
    }
    ret=addMoveCByTarget(complex_path_id, sixthjoints, seventhjoints, vel, acc, blendradius, ignore_rotation, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveCByTarget failed!Return value = %d\n", ret);
    }
    firstpose[1] -= 0.3;
    double eighthjoints[7] = { 0.0 };
    ret = inverse(firstpose, eighthjoints, nullptr);
    if (ret < 0)
    {
        printf("inverse failed!Return value = %d\n", ret);
    }
    ret=addMoveLByTarget(complex_path_id, eighthjoints, vel, acc, blendradius, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveLByTarget failed!Return value = %d\n", ret);
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

    std::cout<<"complex_path_type 2 :NORMAL_POSE ,该模式下路径中可以添加";
    std::cout<<"moveL、moveJ、moveC 对应的路径点,路径点用末端 TCP 位姿数据确定"<<std::endl;
    sleepMilliseconds(100);
    firstpose[0] += 0.3;
    firstpose[1] += 0.3;
    ret = moveLToPose(firstpose, vel, acc, nullptr,0,0,0);
    wait_move();
    firstpose[0] -= 0.3;
    ret = moveLToPose(firstpose, vel, acc, nullptr,0,0,0);
    wait_move();
    double targetpose[6] = { 0.0 };
    firstpose[0] += 0.2;
    firstpose[1] += 0.2;
    targetpose[0] = firstpose[0] - 0.2;
    targetpose[1] = firstpose[1] + 0.2;
    targetpose[2] = firstpose[2];
    targetpose[3] = firstpose[3];
    targetpose[4] = firstpose[4];
    targetpose[5] = firstpose[5];

    complex_path_type = 2;
    ret = createComplexPath(complex_path_type, complex_path_id);
    if (ret < 0)
    {
        printf("创建路径失败!Return value = %d\n", ret);
    }
    ret=addMoveCByPose(complex_path_id, firstpose, targetpose, vel, acc, blendradius, ignore_rotation, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveCByPose failed!Return value = %d\n", ret);
    }
    targetpose[1] -= 0.6;
    ret=addMoveLByPose(complex_path_id, targetpose, vel, acc, blendradius, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveLByPose failed!Return value = %d\n", ret);
    }
    targetpose[1] += 0.6;
    ret=addMoveLByPose(complex_path_id, targetpose, vel, acc, blendradius, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveJByPose failed!Return value = %d\n", ret);
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



    std::cout<<"complex_path_type 3 :表示 MOVEP_POSE,该模式下机械臂末端做点对点的匀速运动";
    std::cout<<"路径中可以添加moveL、moveC 对应的路径点,不可以添加 moveJ 对应的路径点,路径点用末端 TCP 位姿数据确定"<<std::endl;
    sleepMilliseconds(100);
    complex_path_type = 3;
    ret = createComplexPath(complex_path_type, complex_path_id);
    if (ret < 0)
    {
        printf("创建路径失败!Return value = %d\n", ret);
    }
    targetpose[0] += 0.2;
    targetpose[1] -= 0.2;
    double targetpose2[6] = { 0.0 };
    targetpose2[0] = targetpose[0] - 0.2;
    targetpose2[1] = targetpose[1] - 0.2;
    targetpose2[2] = targetpose[2];
    targetpose2[3] = targetpose[3];
    targetpose2[4] = targetpose[4];
    targetpose2[5] = targetpose[5];
    ret=addMoveCByPose(complex_path_id, targetpose, targetpose2, vel, acc, blendradius, ignore_rotation, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveCByPose failed!Return value = %d\n", ret);
    }
    targetpose2[1] -= 0.3;
    ret=addMoveLByPose(complex_path_id, targetpose2, vel, acc, blendradius, order, frequency, damping);
    runComplexPath(complex_path_id);
    destroyComplexPath(complex_path_id);
    wait_move();
    std::cout<<"createComplexPath3 done, all test done."<<std::endl;
}

TEST_F(SRZX, case6)
{
       double init_joints[7] ={0.0};
    double init_vel = 0.5;
    double init_acc = 0.5;
    moveJToTarget(init_joints, init_vel, init_acc,order, frequency, damping);
    wait_move();
    std::cout <<"已回原"<<std::endl;

    float time_use=0;
    struct timeval start;
    struct timeval end;//struct timezone tz; //后面有说明
    gettimeofday(&start,NULL); //gettimeofday(&start,&tz);结果一样
    //printf("start.tv_sec:%dn",start.tv_sec);
    //printf("start.tv_usec:%dn",start.tv_usec);

    // for(int i=0;i<1;i++)
    // {
    //    testmove6();
    // }
    //testmove6();
    testAddMove6();

    gettimeofday(&end,NULL);
    //printf("end.tv_sec:%dn",end.tv_sec);
    //printf("end.tv_usec:%dn",end.tv_usec);
    time_use=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);//微秒
    printf("time_use is %f \n",time_use/1000000);


    EXPECT_EQ(read_input("测试输入整形的运动是否符合预期结果[是-y, 否-n]:"), 'y');
    

}

TEST(SRZX, case7)
{ 
     EXPECT_EQ(1,1);
}

TEST(SRZX, case8)
{ 
     EXPECT_EQ(1,1);
}