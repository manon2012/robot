
#include "DianaRobot.h"
#include <thread>
#include <mutex>
#include <unistd.h>

mutex mtx;

bool getpos(DianaRobot *obj)
{

    double pos[6] = {0};

    bool flag;
    for (int i = 0; i < 20000000; i++)
    {
        // std::cout<<"in for"<<std::endl;
        bool flag = obj->getTcpPose(pos);
        // std::cout << "getTcpPose: " << flag << std::endl;
        if (flag)
        {
            mtx.lock();
            std::cout << "getpos getit->" << flag << std::endl;
            mtx.unlock();
        }
        usleep(300);
    }

    return flag;
}

bool readit(DianaRobot *obj)
{
    bool ret;
    for (int i = 0; i < 20000000; i++)
    {
        ret = obj->readdi();
        // std::cout << "ret = " << bool(ret) << std::endl;
        if (ret)
        {
            mtx.lock();
            std::cout << "readit i:" << i << ", getit->" << ret << std::endl;
            mtx.unlock();
        }
        usleep(300);
    }
    return ret;
}

bool setValue(DianaRobot *obj, const char *key, const double value)
{
    int ret;
    for (int i = 0; i < 20000000; i++)
    {
        ret = obj->setValue(key, value);
        if (ret)
        {
            mtx.lock();
            std::cout << "setValue i:" << i << ", getit->" << ret << std::endl;
            mtx.unlock();
        }
        usleep(300);
    }
    return ret;
}

int main()
{
    int num = 0;
    double pos00[6] = {0};
    srv_net_st net_info;
    initSrvNetInfo(&net_info);
    strcpy(net_info.SrvIp, "192.168.10.75");
    int connect_ret = initSrv(nullptr, nullptr, &net_info);
    if (connect_ret != 0)
    {
        printf("initSrv failed!Return value = %d\n", connect_ret);
    }
    std::cout << "connect done." << std::endl;
    int n = 0;
    while (true)
    {

        int res = getRobotState();
        // std::cout << "state: " << res << std::endl;
        int ret = getTcpPos(pos00);
        if (ret)
        {
            std::cout << "getTcpPos gotit." << ret << std::endl;
            break;
        }
        n++;
        if (n % 1000000 == 0)
        {
            std::cout << "num:" << n << std::endl;
        }
        usleep(300);
    }
    return 0;

    while (true)
    {

        if (num % 1000 == 0)
        {
            std::cout << "num:" << num << std::endl;
            destroySrv();
            srv_net_st net_info2;
            initSrvNetInfo(&net_info2);
            strcpy(net_info2.SrvIp, "192.168.10.75");
            connect_ret = initSrv(nullptr, nullptr, &net_info2);
        }
        int res = getRobotState();
        std::cout << "state: " << res << std::endl;
        int ret = getTcpPos(pos00);
        if (ret)
        {
            std::cout << "while getit,getTcpPos failed: " << num << ": " << ret << std::endl;
            break;
        }
        // usleep(10);
        num++;
        // destroySrv();
    }

    return 0;

    DianaRobot TestRobot;
    TestRobot.ConnectRobot();
    thread t1(getpos, &TestRobot);
    thread t2(getpos, &TestRobot);
    // thread t3(readit,&TestRobot);
    // thread t4(readit,&TestRobot);
    // thread t5(setValue,&TestRobot,"G1",2000);
    // thread t6(setValue,&TestRobot,"G2",2023);

    //   for (int i = 0; i < 20000000; i++)
    //   {

    double pos0[6] = {0};
    int count = 0;
    while (true)
    {
        // std::cout<<"in while"<<std::endl;
        int ret = getTcpPos(pos0);
        if (ret)
        {
            std::cout << "while getit,getTcpPos failed: " << ret << std::endl;
        }
        count++;
    }
    t1.join();
    t2.join();
    // t1.join();
    // t2.join();
    // t3.join();
    // t4.join();
    // t5.join();
    // t6.join();

    // usleep(30);
    //   }

    return 0;

    double pos[6] = {0};
    //     DianaRobot TestRobot;
    //  TestRobot.ConnectRobot();
    bool flag = TestRobot.getTcpPose(pos);
    std::cout << "flag: " << flag << std::endl;
    for (int i = 0; i < 6; i++)
    {
        std::cout << "pose"
                  << "[" << i << "]" << pos[i] << ":"
                  << " ";
    }
    std::cout << std::endl;

    return 0;

    vector<double> L(6);
    vector<double> J(6);

    TestRobot.getRobotWayPoint("apix_5", L, J);

    std::cout << "Getwaypoint tcp: " << L[0] << " " << L[1] << " " << L[2] << " " << L[3] << " " << L[4] << " " << L[5] << std::endl;
    std::cout << "Getwaypoint joints: " << J[0] << " " << J[1] << " " << J[2] << " " << J[3] << " " << J[4] << " " << J[5] << std::endl;

    // ***********SET WAY POINT********
    // vector<double> L_w{0.4, 0.4, 0.4, 0.5, 0.6, 0.8};  //40.435,17.612,54.777
    vector<double> L_w{0.4, 0.4, 0.4, 0.5, 0.5, 0.5}; // 36,18,36 示教器里显示
    // vector<double> L_w{0.412389, 0.412416 ,0.830881 ,1.55038, 0.805656 ,1.14058};
    vector<double> J_w{0, 0, 0, 0, 0, 0};

    double rpy[3] = {0.5, 0.5, 0.5};
    axis2RPY(rpy);
    printf("Diana API axis2Rpy got: %f, %f, %f\n", rpy[0] * 180 / 3.14, rpy[1], rpy[2]);

    std::cout << std::boolalpha;
    bool inverseRet = TestRobot.isinvser(L_w, J_w);
    std::cout << "inverseRet: " << inverseRet << std::endl;

    std::cout << "Setwaypoint tcp: " << L_w[0] << " " << L_w[1] << " " << L_w[2] << " " << L_w[3] << " " << L_w[4] << " " << L_w[5] << std::endl;
    std::cout << "Setwaypoint joints: " << J_w[0] << " " << J_w[1] << " " << J_w[2] << " " << J_w[3] << " " << J_w[4] << " " << J_w[5] << std::endl;

    bool setRobotWayPointRet = TestRobot.setRobotWayPoint("apix_5", L_w, J_w);
    std::cout << "setRobotWayPointRet: " << setRobotWayPointRet << std::endl;

    // std::vector<int> v(2);
    // v.push_back(1);
    // v.push_back(2);
    // std::cout<<"v[100]: " << v[100] << std::endl;
    // std::cout<<"v.at(100):"<<v.at(100)<<std::endl;
    // std::vector<int> myvector(5);
    // int *p = myvector.data();

    // *p = 10;
    // ++p;
    // std::cout <<p[0] <<std::endl;
    //  *p = 20;
    //  p[20] = 100;

    // std::cout << "myvector contains:";
    // for (unsigned i = 0; i < myvector.size(); ++i)
    //     std::cout << ' ' << myvector[i];
    // std::cout << '\n';

    // int test[5]={0,1,2,3,4};
    // int *pp = test;
    // *pp=1;
    // std::cout <<pp[0] <<std::endl;
    // std::cout <<pp[1] <<std::endl;
    // std::cout <<pp[2] <<std::endl;

    // *pp++;
    // std::cout <<pp[0] <<std::endl;
    // std::cout <<pp[1] <<std::endl;
    // std::cout <<pp[2] <<std::endl;

    return 0;
}
