#include "DianaAPI.h"
#include "test_base.h"
#include <gtest/gtest.h>


static const char *strIpAddress = "192.168.10.75";

static int order = 0;
static double frequency = 0;
static double damping = 0.1;
static double vel = 0.4;
static double acc = 0.4;
static double Targetjoints[7] = {0};

static std::map<int, std::array<double, 7> > wobjmap;
int wobjarr[3][3];
int gnumber;
int gcount1;


void init_array() {
    srand((int)time(0));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            wobjarr[i][j] = rand() % 2;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (wobjarr[i][j] == 1) {
                gcount1++;
            }
        }
    }
}

int get_number(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (wobjarr[i][j] == 0) {
                return 3 * i + j;
            }
        }
    }
}

int set_number(int arr[3][3], int targetnum) {
    int a = targetnum / 3;
    int b = targetnum % 3;
    arr[a][b] = 1;
}

void printarr(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << wobjarr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


TEST(MoveTest,move3plus3)
{
    srv_net_st net_info;
    initSrvNetInfo(&net_info);
    strcpy(net_info.SrvIp, strIpAddress);
    int connect_ret = initSrv(errorControl, nullptr, &net_info);
    if (connect_ret != 0) {
        printf("initSrv failed!Return value = %d\n", connect_ret);
    }
    releaseBrake();

    double zero[7] = {0};
    getJointPos(zero);

    // init pos
    double jointsinit[7] = {to_rad(0), to_rad(0), to_rad(0), to_rad(90), to_rad(0), to_rad(-90), to_rad(0)};
    moveJToTarget(jointsinit, 0.5, 0.5, 0, 0, 0, strIpAddress);

    wait_move();

    init_array();
    std::cout << "初始化完成" << std::endl;

    while (1) {
        std::cout << "已有" << gcount1 << "个，还差" << 9 - gcount1 << std::endl;
        printarr(wobjarr);

        int targetnum = get_number(wobjarr);
        std::cout << "目标位置: " << targetnum << std::endl;

        // wobjdata    tcp    源坐标系下位姿
        double srcPose[6] = {0, 0, 0, to_rad(0.7), to_rad(-0.7), to_rad(-146)};

        // 工具坐标系
        double tool[6];
        char tcpName[256];
        getDefaultTcpCoordinate(tcpName);
        //std::cout << "toolname: " << tcpName << std::endl;
        getTcpPoseByTcpName(tcpName, tool);   
         for(int i=0;i<6;i++)
    {
        //std::cout<<"tool"<<i<<": "<<tool[i]<<std::endl;
    }


        double poses[6] = {0.0};
        const char* strIpAddress = "192.168.10.75";
        int res = getTcpPos(poses, strIpAddress);

        // 工件坐标系
        double piece[6];
        char pieceName[256];
        getDefaultWorkPieceCoordinate(pieceName);
        //std::cout << "wobjname: " << pieceName << std::endl;
        getTcpPoseByWorkPieceName(pieceName, piece);
        for (int i = 0; i < 6; i++) {
           // std::cout<<"piece"<<i<<": "<<piece[i]<<std::endl;
        } //return;

        double dstMatrixPose[6] = {0.0, 0.0, 0, 0.0, 0.0, 0.0};
        double dstPose[6] = {0};

        double objNumber[25];
        int index = 0;
        // save target info to map
        for (int y = 0; y < 3; y++) {
            srcPose[1] = 0.05 * y;

            for (int x = 0; x < 3; x++) {
                srcPose[0] = 0.03 * x;

                // change wobj to basic
                poseTransform(srcPose, piece, dstMatrixPose, dstPose);

                inverse_ext(zero, dstPose, Targetjoints);

                // double to array
                std::array<double, 7> temp;
                for (int i = 0; i < 7; i++) {
                    temp[i] = Targetjoints[i];
                }
                wobjmap[index] = temp;
                index++;
            }
        }

        double targetjoint[7] = {0};
        for (int i = 0; i < 7; i++) {
            targetjoint[i] = wobjmap[targetnum][i];
        }
        moveJToTarget(targetjoint, vel, acc, order, frequency, damping);
        wait_move();
        sleepMilliseconds(2000);
        std::cout << "ok" << std::endl;

        set_number(wobjarr, targetnum);
        gcount1++;
        std::cout << "最新的状态:" << std::endl;
        printarr(wobjarr);

        // get obj to home
        double joints[7] = {to_rad(0), to_rad(0), to_rad(0), to_rad(90), to_rad(0), to_rad(-90), to_rad(0)};
        moveJToTarget(joints, 0.5, 0.5, 0, 0, 0, strIpAddress);
        wait_move();

        // check if full
        if (gcount1 == 9) {
            std::cout << "obj is full." << std::endl;
            break;
        }
        sleepMilliseconds(2000);
    }
    sleepMilliseconds(1000);
    destroySrv();
    EXPECT_EQ(9,gcount1);
}

TEST(MoveTest, add100)
{
    int sum=0;
    for(int i=0; i<=100;i++)
    {
        sum += i;
    }
    EXPECT_EQ(5050,sum);
}
