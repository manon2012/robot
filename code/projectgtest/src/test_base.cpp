#include "test_base.h"
//#include "case_api.h"
#include "DianaAPI.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <thread>
#include <unistd.h>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string.h>
#include <ctime>

using namespace std;

bool bHasCollision = false;
double getjoint[7]={0.0};
double gettcp[6]={0.0};

const char *strIpAddress = "192.168.10.75";

double to_degree(double x) { return ((x)*180.0 / M_PI); }

double to_rad(double x) { return ((x)*M_PI / 180.0); }

void sleepMilliseconds(unsigned int uintMilliseconds) {
#ifdef _WIN32
    Sleep(dwMilliseconds);
#else
    struct timespec ts;
    ts.tv_sec = uintMilliseconds / 1000;
    ts.tv_nsec = (uintMilliseconds % 1000) * 1000000;
    while ((-1 == nanosleep(&ts, &ts)) && (EINTR == errno))
        ;
#endif
}


void errorControl(int e,const char *strIpAddress)
{
	const char * strError = formatError(e, strIpAddress);   
	printf("error code (%d):%s\n", e, strError);
	bool  IsCollision=isCollision();
	if (IsCollision==true)
	{
		bHasCollision = true;
	}
}

void wait_move()
{
	bHasCollision = false;
	bool bEnable1=false;
	sleepMilliseconds(20);
	while (true)
	{
		const char state = getRobotState(strIpAddress);
		if (state != 0)
		{   //std::cout <<"state!=0 "<< (int)state <<std::endl;
			if (state == 6)
			{   //std::cout <<"state==6 "<< (int)state <<std::endl;
				if (bHasCollision == true)
				{
					printf("机器人检测到发生碰撞，马上恢复运行！\n");
                    sleepMilliseconds(2000);
					int cleanResult = cleanErrorInfo(strIpAddress);
                    std::cout<< "cleanResult: "<<cleanResult<<std::endl;
					sleepMilliseconds(2000);
					int ret=resume(strIpAddress);		
					if(ret<0)
					{
						printf("resume failed!return ret=%d\n",ret);
					}
					else
					{
						printf("机器人已执行恢复运行函数！\n");
					}
					bHasCollision=false;
				}
                continue;
			}
			else if (state == 2)
			{
				printf("\t[robot state]:idle\n");
			}
			else if (state == 3)
			{
				printf("\t[robot state]: free-driving \n");
			}
			else if (state == 4)
			{
				printf("\t[robot state]: zero-space-free-driving \n");
			}
			break;
		}
		else
		{
			sleepMilliseconds(1);
		}
	}
	stop(strIpAddress);
}




void wait_move1(const char *strIpAddress)
{
    usleep(20000);
    
    ofstream outFile;
    outFile.open("getdata.csv",ios::app);
    while (true)
    {
        const char state = getRobotState(strIpAddress);
        if (state != 0)
        {
            break;
        }
        else
            usleep(1000);
            getJointPos(getjoint);
            outFile << getjoint[0] << ' '<< getjoint[1]<< ' ' << getjoint[2] << ' '<<getjoint[3] << ' '<<getjoint[4]<< ' ' <<getjoint[5] << ' '<<getjoint[6] <<endl;
            
    }
    outFile.close();
    stop(strIpAddress);
}

void wait_move2(const char *strIpAddress)
{
    usleep(20000);
    
    ofstream outFile;
    outFile.open("getdata.csv",ios::app);
    while (true)
    {
        const char state = getRobotState(strIpAddress);
        if (state != 0)
        {
            break;
        }
        else
            usleep(1000);
            getTcpPos(gettcp);
            outFile << gettcp[0] << ' '<< gettcp[1]<< ' ' << gettcp[2] << ' '<<gettcp[3] << ' '<<gettcp[4]<< ' ' <<gettcp[5] << endl;
            
    }
    outFile.close();
    stop(strIpAddress);
}

char read_input(const char *strPrompt) {
    char input = '\0';
    if (strPrompt != nullptr) {
        cout << strPrompt;
    }
    cin >> input;
    return input;
}

