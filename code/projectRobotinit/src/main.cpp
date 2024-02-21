#include <DianaAPI.h>
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <vector>
#define JOINT_NUM 7
using namespace std;

void logRobotState(StrRobotStateInfo *pinfo, const char *strIpAddress)
{
    strIpAddress = "192.168.10.75";
    static int staCnt = 1;
    if ((staCnt++ % 1000 == 0) && pinfo)
    {
        for (int i = 0; i < JOINT_NUM; ++i)
        {
            // printf("jointPos[%d] = %f \n", i, pinfo->jointPos[i]);
            // printf("jointCurrent [%d] = %f \n", i, pinfo->jointCurrent[i]);
            // printf("jointTorque [%d] = %f \n", i, pinfo->jointTorque[i]);
            if (i < 6)
            {
                // printf("tcpPos [%d] = %f \n", i, pinfo->tcpPos[i]);
            }
        }
    }
}

void errorControl(int e, const char *strIpAddress)
{
    strIpAddress = "192.168.10.75";
    const char *strError = formatError(e); // 该函数后面会介绍
    printf("error code (%d):%s\n", e, strError);
}

int main()
{

    srv_net_st *pinfo = new srv_net_st();
    memset(pinfo->SrvIp, 0x00, sizeof(pinfo->SrvIp));
    memcpy(pinfo->SrvIp, "192.168.10.75", strlen("192.168.10.75"));
    pinfo->LocHeartbeatPort = 0;
    pinfo->LocRobotStatePort = 0;
    pinfo->LocSrvPort = 0;
    int ret = initSrv(errorControl, logRobotState, pinfo);
    std::cout << "initSrv ret:" << ret << std::endl;
    if (ret < 0)
    {
        printf("192.168.10.75 initSrv failed! Return value = %d\n", ret);
    }
    releaseBrake();

    double joints_0[7] = {0, 0, 0, 1.57, 0, -1.57, 0};
    moveJToTarget(joints_0, 0.5, 0.5);
    usleep(1000000);

    // char tool[64];
    // char wobj[64];

    double dblTcppos5[6];
    double dblJoint5[7];
    ret = getWayPoint("apix_5", dblTcppos5, dblJoint5);

    double firstpose[6] = {0.4, 0.4, 0.5, 0.5, 0.6, 0.8};
    double firstjoints[7] = {0.0};
    ret = inverse(firstpose, firstjoints, nullptr);
    std::cout << "inverse ret------------:" << ret << std::endl;
    for (int i = 0; i < 100; i++)
    {
        ret = setWayPoint("apix_5", firstpose, firstjoints);
        std::cout << "setwaypoint ret------------:" << ret << std::endl;
    }
    if (pinfo)
    {
        delete pinfo;
        pinfo = nullptr;
    }
    destroySrv("192.168.10.75");
}
