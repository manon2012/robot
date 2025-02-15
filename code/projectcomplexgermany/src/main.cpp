#include <DianaAPI.h>

#include <cstring>
#include <csignal>
#include <cstdlib>
#include <cstdio>
#include <math.h>

#include <chrono>
#include <iostream>
#include <thread>
#include <atomic>

#define JOINT_NUM 6

#define IP "10.3.7.1"      // iriss setup
#define IP "192.168.10.75" // local setup
const char *strIpAddress = IP;
// double home[JOINT_NUM] = {0.0, 0.0, M_PI_2, 0.0, -M_PI_2, 0.0}; // diana7CS home
double home[JOINT_NUM] = {0.0, 0.0, M_PI_2, 0.0, M_PI_2, 0.0}; // thor3 home
double pose1[JOINT_NUM] = {M_PI_2, 0.0, M_PI_2, 0.0, M_PI_2, 0.0};

unsigned int path_id = 0;

using namespace std::chrono_literals;
using duration_in_s = ::std::chrono::duration<float>;
using steady_clock = ::std::chrono::steady_clock;

::std::atomic_bool start_servoing{false};
auto t_started = steady_clock::now();
auto tm1_last_command = steady_clock::now(); // time last command was sent
double defaultTcp[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
double command[6];
double acc[2];
bool reliable = false;
int mode = 0;
double J[6 * JOINT_NUM];

// mode switch
auto t_since_mode_switch = steady_clock::now();

void wait_move(const char *strIpAddress)
{
    std::this_thread::sleep_for(20ms);

    while (true)
    {
        const char state = getRobotState(strIpAddress);
        if (state != 0)
        {
            break;
        }
        else
        {
            std::this_thread::sleep_for(1ms);
        }
    }
    stop(strIpAddress);
    std::this_thread::sleep_for(20ms);
}

void stateCallback(StrRobotStateInfo *pinfo, const char *strIpAddress)
{
    static int prev_segIndex = 0;

    // print time elapsed between now and the last command sent
    auto t_now = steady_clock::now();
    auto t_since_epoch = ::std::chrono::duration_cast<::std::chrono::duration<float>>(t_now.time_since_epoch()).count();
    auto t_diff = t_now - tm1_last_command;
    tm1_last_command = t_now; // save time for next cycle
    // if (t_diff > 1ms + 200us) {
    //     printf("[%.9f]: state callback, time elapsed between current and last command %.5fms\n",
    //         t_since_epoch,
    //         ::std::chrono::duration_cast<::std::chrono::duration<float, ::std::milli> >(t_diff).count());
    // }

    if (pinfo->errorInfo.errorCode != 0)
    {
        printf("[%.9f]: state callback: error code (%d): %s\n",
               t_since_epoch,
               pinfo->errorInfo.errorCode,
               pinfo->errorInfo.errorMsg);
    }

    if(pinfo->trajState.segIndex == prev_segIndex || 
        pinfo->trajState.segIndex == (prev_segIndex + 1) || 
        pinfo->trajState.segIndex < prev_segIndex) {
            // all good, do nothing
    }
    else {
        printf("[%.9f]: state callback: ups, segIndex changed from %d to %d\n",
               t_since_epoch,
               prev_segIndex,
               pinfo->trajState.segIndex);
    }

    prev_segIndex = pinfo->trajState.segIndex;
}

void errorCallback(int e, const char *strIpAddress)
{
    const char *strError = formatError(e);
    printf("error callback: error code (%d): %s\n",
           e,
           strError);
}

void disconnect()
{
    printf("disconnecting");
    destroySrv(strIpAddress);
}

void stop_handler(int sig)
{
    printf("got signal %d\n", sig);
    disconnect();
    exit(0);
}

auto main(int argc, char **argv) -> int
{
    
    // ===== SetUp =================
    if (argc != 1)
    {
        printf("Usage: <program>\n");
        exit(-1);
    }
    std::cout<<123<<std::endl;
    signal(SIGINT, stop_handler);
    signal(SIGABRT, stop_handler);
    signal(SIGTERM, stop_handler);

    // connect to the robot
    srv_net_st *pinfo = new srv_net_st();
    memset(pinfo->SrvIp, 0x00, sizeof(pinfo->SrvIp));
    memcpy(pinfo->SrvIp, IP, strlen(IP));

    pinfo->LocHeartbeatPort = 0;
    pinfo->LocRobotStatePort = 0;
    pinfo->LocSrvPort = 0;
    pinfo->LocRealtimeSrvPort = 0;
    pinfo->LocPassThroughSrvPort = 0;

    if (initSrv(errorCallback, stateCallback, pinfo) < 0)
    //if (initSrv(errorCallback, nullptr, pinfo) < 0)
    {
        printf("initSrv failed");
        exit(-1);
    }

    if (moveJToTarget(home, /*vel=*/4.0, /*acc=*/16.0, 0, 0, 0, strIpAddress) != 0)
    {
        printf("move home failed");
        exit(-1);
    }
    printf("moving home\n");
    wait_move(strIpAddress);
    printf("done home\n");
    // ==============================    

    // 0. Test data: lin moves (last is incorrect)
    double pose_1[JOINT_NUM] = {-0.499151, 0.170889, 1.38839, 0.008305, 1.5868, -0.498874};
    double pose_2[JOINT_NUM] = {-0.00055931, 0.233642, 2.03472, -0.00111372, 0.875902, 0.00152316};
    double pose_3[JOINT_NUM] = {0.681293, -1.13095, -0.866192, 0.0159646, -1.13757, 0.674657};
    
    // 1. Create batch 
    createComplexPath(0 /* ::NORMAL_JOINT_PATH */, path_id);
    if (addMoveLByTarget(path_id, pose_1, /*vel=*/0.2, /*acc=*/0.4, 0.01, 0, 0,0, strIpAddress) != 0)
    {
        printf("add pose_1 to batch failed");
        exit(-1);
    }
    if (addMoveLByTarget(path_id, pose_2, /*vel=*/0.2, /*acc=*/0.4, 0.01, 0, 0,0, strIpAddress) != 0)
    {
        printf("add pose_2 to batch failed");
        exit(-1);
    }

    if (addMoveLByTarget(path_id, pose_3, /*vel=*/0.2, /*acc=*/0.4, 0.01, 0, 0,0, strIpAddress) != 0)
    {
        printf("add pose_3 (errored) to batch failed");
        exit(-1);
    }    

    // run the batch
    printf("moving batch\n");    
    if(runComplexPath(path_id) != 0)
    {
        printf("run batch failed");
        exit(-1);
    }

    wait_move(strIpAddress);
    printf("done batch\n");
    return 0;


   // 2. Create a sequence of moves
   if (moveLToTarget(pose_1, /*vel=*/0.2, /*acc=*/0.4, 0, 0, 0, strIpAddress) != 0)
    {
        printf("add pose_1 failed");
        exit(-1);
    }
    printf("moving pose_1\n");
    wait_move(strIpAddress);
    printf("done pose_1\n");

    if (moveLToTarget(pose_2, /*vel=*/0.2, /*acc=*/0.4, 0, 0, 0, strIpAddress) != 0)
    {
        printf("add pose_2 failed");
        exit(-1);
    }
    printf("moving pose_2\n");
    wait_move(strIpAddress);
    printf("done pose_2\n");

    if (moveLToTarget(pose_3, /*vel=*/0.2, /*acc=*/0.4, 0, 0, 0, strIpAddress) != 0)
    {
        printf("add pose_3 (expected PathError) failed");
        exit(-1);
    }
    printf("moving pose_3\n");
    wait_move(strIpAddress);
    printf("done pose_3\n");


    // ===== TearDown =================
    // if (moveJToTarget(home, /*vel=*/4.0, /*acc=*/16.0, 0, 0, 0, strIpAddress) != 0)
    // {
    //     printf("move home failed");
    //     exit(-1);
    // }
    // printf("moving home\n");
    // wait_move(strIpAddress);
    // printf("done\n");

    // disconnect
    disconnect();

    return 0;
}
