#ifndef DIANAROBOT_H
#define DIANAROBOT_H
#include <iostream>
#include <DianaAPI.h>
#include <DianaAPIDef.h>
#include <vector>
#include "string.h"
using namespace std;

#define M_SLEEP(x) usleep(x * 1000) // usleep(um) M_SLEEP(ms)

class DianaRobot
{

public:
    DianaRobot() = default;
    ~DianaRobot(){};

    bool ConnectRobot()
    {
        // strcpy(net_info.SrvIp, name_rob);
        strcpy(net_info.SrvIp, "192.168.10.75");
        net_info.LocSrvPort = 0;
        net_info.LocRobotStatePort = 0;
        net_info.LocHeartbeatPort = 0;
        int res = initSrv(nullptr, nullptr, &net_info);

        if (res == 0)
        {
            stop();
            // holdBrake();
            // releaseBrake();
            return 1;
        }
        else
        {
            return 0;
        }
    };

    bool getRobotWayPoint(const std::string strVariableName, std::vector<double> &L, std::vector<double> &J)
    {
        int bRe = 0;
        bRe = getWayPoint(strVariableName.c_str(), L.data(), J.data());
        if (bRe == -1)
        {
            cout << "Thor12 getRobotWayPoint() error" << endl;
            return false;
        }
        return true;
    }

    bool setRobotWayPoint(const std::string strVariableName, std::vector<double> &L, std::vector<double> &J)
    {
        int bRe = 0;
        bRe = setWayPoint(strVariableName.c_str(), L.data(), J.data());
        if (bRe == -1)
        {
            cout << "Thor12 setRobotWayPoint() error" << endl;
            return false;
        }
        return true;
    }

    bool isinvser(std::vector<double> &L, std::vector<double> &J) 
    {

        auto ret = inverse(L.data(), J.data());
        if (ret == -1)
        {
            std::cout << "Inverse Failed." << std::endl;
            return false;
        }
        else
        {
            return true;
        }
    }
    
    bool getTcpPose(double * pos)
    {
       return getTcpPos(pos);
    }
    
    bool readdi()
    {
        int value1[16]={0};
		int ret1 = readDI("board", "di0", value1[0]);
		int ret2 = readDI("board", "di1", value1[1]);
		int ret3 = readDI("board", "di2", value1[2]);
		int ret4 = readDI("board", "di3", value1[3]);
        if(ret1 + ret2 + ret3 + ret4 ==0)
        {
            return 0;
        }
    }


    bool setValue(const char * abc,const double x)
    {
      int ret = setVariableValue (abc,x);
      return ret;
    }

private:
    srv_net_st net_info;
    /* add your private declarations */
};

#endif /* DIANAROBOT_H */
