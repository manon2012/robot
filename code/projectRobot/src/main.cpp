#include <DianaAPI.h>

#include <chrono>
#include <cstring>
#include <iostream>
#include <thread>
#include <math.h>
#include<unistd.h>

#define JOINT_NUM 7
#define IP "192.168.10.75"

using namespace std::chrono_literals;
using duration_in_s = ::std::chrono::duration<float>;
using steady_clock = ::std::chrono::steady_clock;

auto t_started = steady_clock::now();
auto tm1_last_command = steady_clock::now();  // time last command was sent
double command[JOINT_NUM];
int count;

void stateCallback(StrRobotStateInfo* pinfo, const char* strIpAddress) {
    // give some time to connection setup
    if(steady_clock::now() - t_started < 1s){
        tm1_last_command = steady_clock::now();
        return;
    }

    // print time elapsed between now and the last command sent
    auto t_now = steady_clock::now();
    auto t_diff      = t_now - tm1_last_command;
    tm1_last_command = t_now;  // save time for next cycle
    if (t_diff > 1ms + 200us) {
    //if (t_diff < 20us) {   //YD changed here
        std::cout << "time elapsed between current and last command " << ::std::chrono::duration_cast<::std::chrono::duration<float, ::std::milli>>(t_diff).count() << std::endl;
    }

    // copy current state as command
    for(int i=0; i<JOINT_NUM; ++i){
        command[i] = pinfo->jointPos[i];
    }

    // move first joint alternating in positive and negative direction
    float second = ::std::chrono::duration_cast<duration_in_s>(steady_clock::now().time_since_epoch()).count();
    if (sin(second) >= 0){
        command[0] +=  0.01;
    }
    else{
        command[0] +=  -0.01;   
    }

    if(pinfo->errorInfo.errorCode != 0){
        printf("ERROR FIELD: error code (%d):%s\n", pinfo->errorInfo.errorCode, pinfo->errorInfo.errorMsg);
    }

    /**
     * Switch reliable flag between true and false and observe the different behavior
     **/
    bool reliable = true;
    servoJ_ex(&command[0], 0.001, 0.1, 300, reliable);
    return;

    int i =0;
    for(i = 0; i <=1000; i++) {
        servoJ_ex(&command[0], 0.001, 0.1, 300, reliable);
        std::this_thread::sleep_for(1ms);
    }
    std::cout<<"i: "<<i<<std::endl;
    count++;
    std::cout<<"count: "<<count<<std::endl;

    //不是100%可以重现，如果<50时停住了可以继续，否则重新f5
    if(count >50)
    {   int res = stop("192.168.10.75");
        std::cout<<"stop res: "<< res <<std::endl;
        std::this_thread::sleep_for(3000ms);
        std::cout<<"sleep 3s to start wireshark " <<std::endl;
        servoJ_ex(&command[0], 0.001, 0.1, 300, reliable);
    }


    //speedl_ex
    double Acc[2]={0.2,0.2};
    double speedls2[6] = { 0, command[0],0,0.0,0.0,0.0 };
	//speedL_ex(speedls2, Acc, 0.1, false,nullptr);
    //speedL_ex(speedls2, Acc, 0.001, false,nullptr);
    //speedL_ex(speedls2, Acc, 10, false,nullptr);
}

void errorCallback(int e, const char* strIpAddress)
{
    const char* strError = formatError(e);
    printf("ERROR CALLBACK: error code (%d):%s\n", e, strError);
}

auto main() -> int
{
    // connect to the robot
    srv_net_st* pinfo = new srv_net_st();
    memset(pinfo->SrvIp, 0x00, sizeof(pinfo->SrvIp));
    memcpy(pinfo->SrvIp, IP, strlen(IP));

    pinfo->LocHeartbeatPort = 0;
    pinfo->LocRobotStatePort = 0;
    pinfo->LocSrvPort = 0;
    pinfo->LocRealtimeSrvPort = 0;
    pinfo->LocPassThroughSrvPort = 0;

    if (initSrv(errorCallback, stateCallback, pinfo) < 0) {
        printf("initSrv failed");
    }
    releaseBrake();
    const char* strIpAddress = IP;

    std::this_thread::sleep_for(80000ms);
    std::cout<<"sleep done"<<std::endl;

    
    // double joints[7]={0, 0, 0, 1.57, 0, -1, 0};
	// int res=moveJToTarget(joints, 0.2, 0.2);
    // usleep(10000000);
    // std::cout<<"movej done:"<<res<<std::endl;

    // disconnect
    if (pinfo) {
        delete pinfo;
        pinfo = nullptr;
    }
    destroySrv(strIpAddress);

    return 0;
}