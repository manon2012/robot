#include "DianaAPI.h"
#include "test_base.h"
#include <gtest/gtest.h>

static const char *strIpAddress = "192.168.10.75";

class RobotTest : public ::testing::Test
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

TEST_F(RobotTest, move1)
{

    double init_joints[7] = {0, 0, 0, to_rad(90), 0, to_rad(-90), 0};
    double init_vel = 0.4;
    double init_acc = 0.4;
    int HRESULT = moveJToTarget(init_joints, init_vel, init_acc);

    wait_move();
    double pose1[6]={0};
    double pose2[6]={0};
    getTcpPos(pose1);
    getTcpPos(pose2);


    for (int i = 0; i <100;i++)
    {
       pose2[2]= pose1[2] - 0.1;
       moveLToPose(pose2,0.2,0.2);
       wait_move();
       pose2[2] += 0.1;
       moveLToPose(pose2,0.2,0.2);
       wait_move();

    }
}

TEST_F(RobotTest, move2)
{
    double init_joints[7] = {0, 0, 0, to_rad(90), 0, to_rad(-90), 0};
    double init_vel = 0.4;
    double init_acc = 0.4;
    int HRESULT = moveJToTarget(init_joints, init_vel, init_acc);
    wait_move();
}


TEST(RobotTestNormal, move1)
{
    for (int i = 0; i <10;i++)
     {
    double init_joints[7] = {0.0};
    double init_vel = 0.4;
    double init_acc = 0.4;
    int HRESULT = moveJToTarget(init_joints, init_vel, init_acc);

    wait_move();
     }
}