#if 0
#include "stdio.h"
#include "string.h"
#include "unistd.h"
#define M_SLEEP(x) usleep(x * 1000)
#else
#include "stdafx.h"
// #include "OS/OS_Thread.h"
#define M_SLEEP(x) OS::Thread::sleepMilliseconds(x)
#endif
#include "DianaAPI.h"

#define PI 3.14159265358979323846
#define to_rad(x) ((x)*PI / 180.0)
#define RAD_TO_DEGREE(x) ((x)*180.0 / PI)

static LPVOID followThread(void *lpParam);
bool bRunning = true; 
const char *strIpAddress = "192.168.10.75";

double vel = 0.2;
double acc = 0.2;
int ret =0;
double blendradius = 0.0;
double toolpose[6]={0.0};
bool bHasCollision = false;

void errorControl(int e,const char *strIpAddress)
{
	const char * strError = formatError(e, strIpAddress);   
	printf("error code (%d):%s\n", e, strError);
	bool  IsCollision=isCollision();
	if (IsCollision==true)
	{
		bHasCollision = true;
		// stop();
	}
}

void wait_move()
{
	bHasCollision = false;
	bool bEnable1=false;
	M_SLEEP(20);
	while (true)
	{
		const char state = getRobotState(strIpAddress);
		if (state != 0)
		{
			if (state == 1)
			{
				if (bHasCollision == true)
				{
					printf("机器人检测到发生碰撞，马上恢复运行！\n");
					cleanErrorInfo(strIpAddress);
					M_SLEEP(2000);
					ret=resume(strIpAddress);		
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
			M_SLEEP(1);
		}
	}
	stop(strIpAddress);
}


void move()
{
	double firstjoint[7] = { 0.0,0.0,0.0,to_rad(90.0),0.0,to_rad(-90.0),0.0 };
	double secondjoint[7] = { to_rad(44.23),to_rad(-42.13),to_rad(54.22),to_rad(113.78),to_rad(27.89),to_rad(-93.16),to_rad(-3.82) };
	double thirdjoint[7] = { to_rad(15.36),to_rad(11.83),to_rad(49.43),to_rad(103.19),to_rad(-40.19),to_rad(-68.54),to_rad(-8.54) };
	double fourthjoint[7] = { to_rad(-6.78),to_rad(0.51),to_rad(-44.15),to_rad(111.45),to_rad(40.20),to_rad(-67.68),to_rad(-46.94) };
	double fifthjoint[7] = { to_rad(11.91),to_rad(-44.11),to_rad(-83.07),to_rad(118.26),to_rad(-35.20),to_rad(-67.77),to_rad(-46.94) };
	double sixthjoint[7] = { to_rad(-6.53),to_rad(2.40),to_rad(-33.61),to_rad(109.24),to_rad(2.97),to_rad(-67.75),to_rad(-46.89) };
	double seventhjoint[7] = { to_rad(6.187),to_rad(3.258),to_rad(-14.293),to_rad(121.722),to_rad(1.918),to_rad(-53.639),to_rad(-14.869) };
	double eighthjoint[7] = { to_rad(42.937),to_rad(0.742),to_rad(11.538),to_rad(124.631),to_rad(-1.419),to_rad(-53.303),to_rad(49.627) };
	double ninthjoint[7] = { to_rad(3.2),to_rad(-8.29),to_rad(-9.12),to_rad(142),to_rad(-0.9),to_rad(-44.67),to_rad(-10.89) };

	for (acc = 0.3; acc < 0.4; acc += 0.1)
	{
		for (vel = 0.3; vel < 0.5; vel += 0.2)
		{
			printf("当前的速度为：%f,加速度为：%f\n", vel, acc);
			printf("moveJToTarget\n");
			ret = moveJToTarget(firstjoint, vel, acc, strIpAddress);
			wait_move();
			//M_SLEEP(200000);
			ret = moveJToTarget(secondjoint, vel, acc, strIpAddress);
			wait_move();
			ret = moveJToTarget(thirdjoint, vel, acc, strIpAddress);
			wait_move();
			ret = moveJToTarget(fourthjoint, vel, acc, strIpAddress);
			wait_move();
			ret = moveJToTarget(fifthjoint, vel, acc, strIpAddress);
			wait_move();
			ret = moveJToTarget(sixthjoint, vel, acc, strIpAddress);
			wait_move();
			ret = moveLToTarget(seventhjoint, vel, acc, strIpAddress);
			wait_move();
			ret = moveLToTarget(eighthjoint, vel, acc, strIpAddress);
			wait_move();

			double firstpose[6] = { 0.0 };
			ret = forward(eighthjoint, firstpose, nullptr, strIpAddress);

			printf("moveJToPose\n");
			firstpose[2] -= 0.2;
			ret = moveJToPose(firstpose, vel, acc, nullptr, strIpAddress);
			wait_move();

			printf("moveJToPose\n");
			firstpose[1] += 0.5;
			ret = moveJToPose(firstpose, vel, acc, nullptr, strIpAddress);
			wait_move();

			printf("moveJToPose\n");
			firstpose[2] += 0.2;
			ret = moveJToPose(firstpose, vel, acc, nullptr, strIpAddress);
			wait_move();

			printf("moveLToPose\n");
			firstpose[1] -= 0.3;
			ret = moveLToPose(firstpose, vel, acc, nullptr, strIpAddress);
			wait_move();

			printf("moveLToPose\n");
			firstpose[1] += 0.3;
			ret = moveLToPose(firstpose, vel, acc, nullptr, strIpAddress);
			wait_move();

			printf("moveL\n");
			firstpose[1] -= 0.3;
			ret = moveL(firstpose, vel, acc, nullptr, strIpAddress);
			wait_move();

			printf("moveJ\n");
			ret = moveJ(ninthjoint, vel, acc, strIpAddress);
			wait_move();

		}
	}
}

void jogcontrol()
{
	printf("开始测试手动控制moveTCP和rotationTCP功能！\n");
	int count = 0;
	for (acc = 0.1; acc < 0.3; acc += 0.1)
	{
		for (vel = 0.1; vel < 0.3; vel += 0.1)
		{
			count = 0;
			for (int i = 0; i < 6; i++)
			{
				if (count == 0)
				{
					tcp_direction_e dtype = T_MOVE_X_UP;
					ret = moveTCP(dtype, vel, acc, nullptr, strIpAddress);
					if (ret < 0)
					{
						printf("T_MOVE_X_UP direction moveTCP failed!Return value = %d\n", ret);
					}
					M_SLEEP(2000);
					stop(strIpAddress);
					ret = rotationTCP(dtype, vel, acc, nullptr, strIpAddress);
					if (ret < 0)
					{
						printf("T_MOVE_Y_UP direction rotationTCP failed!Return value = %d\n", ret);
					}
					M_SLEEP(2000);
					stop(strIpAddress);
				}
				else if (count == 1)
				{
					tcp_direction_e dtype = T_MOVE_X_DOWN;
					ret = moveTCP(dtype, vel, acc, nullptr, strIpAddress);
					if (ret < 0)
					{
						printf("T_MOVE_X_DOWN direction moveTCP failed!Return value = %d\n", ret);
					}
					M_SLEEP(2000);
					stop(strIpAddress);
					ret = rotationTCP(dtype, vel, acc, nullptr, strIpAddress);
					if (ret < 0)
					{
						printf("T_MOVE_X_DOWN direction rotationTCP failed!Return value = %d\n", ret);
					}
					M_SLEEP(2000);
					stop(strIpAddress);
				}
				else if (count == 2)
				{
					tcp_direction_e dtype = T_MOVE_Y_UP;
					ret = moveTCP(dtype, vel, acc, nullptr, strIpAddress);
					if (ret < 0)
					{
						printf("T_MOVE_Y_UP direction moveTCP failed!Return value = %d\n", ret);
					}
					M_SLEEP(2000);
					stop(strIpAddress);
					ret = rotationTCP(dtype, vel, acc, nullptr, strIpAddress);
					if (ret < 0)
					{
						printf("T_MOVE_Y_UP direction rotationTCP failed!Return value = %d\n", ret);
					}
					M_SLEEP(2000);
					stop(strIpAddress);
				}
				else if (count == 3)
				{
					tcp_direction_e dtype = T_MOVE_Y_DOWN;
					ret = moveTCP(dtype, vel, acc, nullptr, strIpAddress);
					if (ret < 0)
					{
						printf("T_MOVE_Y_DOWN direction moveTCP failed!Return value = %d\n", ret);
					}
					M_SLEEP(2000);
					stop(strIpAddress);
					ret = rotationTCP(dtype, vel, acc, nullptr, strIpAddress);
					if (ret < 0)
					{
						printf("T_MOVE_Y_DOWN direction rotationTCP failed!Return value = %d\n", ret);
					}
					M_SLEEP(2000);
					stop(strIpAddress);
				}
				else if (count == 4)
				{
					tcp_direction_e dtype = T_MOVE_Z_UP;
					ret = moveTCP(dtype, vel, acc, nullptr, strIpAddress);
					if (ret < 0)
					{
						printf("T_MOVE_Z_UP direction moveTCP failed!Return value = %d\n", ret);
					}
					M_SLEEP(2000);
					stop(strIpAddress);
					ret = rotationTCP(dtype, vel, acc, nullptr, strIpAddress);
					if (ret < 0)
					{
						printf("T_MOVE_Z_UP direction rotationTCP failed!Return value = %d\n", ret);
					}
					M_SLEEP(2000);
					stop(strIpAddress);
				}
				else if (count == 5)
				{
					tcp_direction_e dtype = T_MOVE_Z_DOWN;
					ret = moveTCP(dtype, vel, acc, nullptr, strIpAddress);
					if (ret < 0)
					{
						printf("T_MOVE_Z_DOWN direction moveTCP failed!Return value = %d\n", ret);
					}
					M_SLEEP(2000);
					stop(strIpAddress);
					ret = rotationTCP(dtype, vel, acc, nullptr, strIpAddress);
					if (ret < 0)
					{
						printf("T_MOVE_Z_DOWN direction rotationTCP failed!Return value = %d\n", ret);
					}
					M_SLEEP(2000);
					stop(strIpAddress);
				}
				count++;
			}
		}
	}
	printf("结束测试手动控制moveTCP和rotationTCP功能！\n");
	printf("开始测试手动控制moveJoint功能！\n");
	count = 0;
	for (acc = 0.1; acc < 0.3; acc += 0.1)
	{
		for (vel = 0.1; vel < 0.3; vel += 0.1)
		{
			for (int index = 0; index < 7; index++)
			{
				joint_direction_e dtype = T_MOVE_UP;
				ret = moveJoint(dtype, index, vel, acc, strIpAddress);
				if (ret < 0)
				{
					printf("moveJoint failed!Return value = %d\n", ret);
				}
				M_SLEEP(2000);
				stop(strIpAddress);
				dtype = T_MOVE_DOWN;
				ret = moveJoint(dtype, index, vel, acc, strIpAddress);
				if (ret < 0)
				{
					printf("moveJoint failed!Return value = %d\n", ret);
				}
				M_SLEEP(2000);
				stop(strIpAddress);
			}
		}
	}
	printf("结束测试手动控制moveJoint功能！\n");
}

void speed()
{
	printf("开始speedj测试！\n");
	for (acc = 0.2; acc < 0.4; acc += 0.2)
	{
		for (int i = 0; i < 7; i++)
		{
			double speedjs1[7] = { 0.0,0.0,0.0,0.0,0.0,0.0,0.0 };
			double speedjs2[7] = { 0.0,0.0,0.0,0.0,0.0,0.0,0.0 };
			speedjs1[i] = 0.2;
			speedjs2[i] = -0.2;
			
			ret = speedJ(speedjs1, acc, 2, strIpAddress);
			M_SLEEP(2000);
			stop(strIpAddress);

			ret = speedJ(speedjs2, acc, 2, strIpAddress);
			M_SLEEP(2000);
			stop(strIpAddress);
		}
	}

	printf("开始speedl测试！\n");
	for (acc = 0.1; acc < 0.2; acc += 0.1)
	{
		for (int i = 0; i < 6; i++)
		{
			double speedls1[6] = { 0.0,0.0,0.0,0.0,0.0,0.0 };
			double speedls2[6] = { 0.0,0.0,0.0,0.0,0.0,0.0 };
			speedls1[i] = 0.2;
			speedls2[i] = -0.2;
			ret = speedL(speedls1, &acc, 2, nullptr, strIpAddress);
			if(ret<0)
			{
				printf("speedL failed！\n");
			}
			M_SLEEP(2000);
			
			stop(strIpAddress);
			ret = speedL(speedls2, &acc, 2, nullptr, strIpAddress);
			M_SLEEP(2000);
			stop(strIpAddress);
		}
	}
}

void path()
{
	for (acc = 0.2; acc < 0.3; acc += 0.1)
	{
		for (vel = 0.2; vel < 0.3; vel += 0.1)
		{
			for (blendradius = -0.05; blendradius < 0.1; blendradius += 0.05)
			{
				printf("vel:%f,acc:%f,blendradius:%f\n", vel, acc, blendradius);
				//path指令
				double firstjoints[7] = { to_rad(-6.747),to_rad(37.356),to_rad(4.236),to_rad(125.777),to_rad(10.445),to_rad(-15.369),to_rad(-14.146) };
				double secondjoints[7] = { to_rad(-34.316),to_rad(41.824),to_rad(7.005),to_rad(113.005),to_rad(2.090),to_rad(-26.069),to_rad(-31.635) };
				double thirdjoints[7] = { to_rad(-27.893),to_rad(49.382),to_rad(5.242),to_rad(92.856),to_rad(2.660),to_rad(-38.129),to_rad(-27.258) };
				double fourthjoints[7] = { to_rad(-3.412),to_rad(44.393),to_rad(2.527),to_rad(105.514),to_rad(7.381),to_rad(-28.336),to_rad(-8.774) };
				unsigned int path_id = 0;
				printf("开始测试addMoveJ\n");
				ret=createPath(1, path_id);
				if (ret < 0)
				{
					printf("createPath failed!Return value = %d\n", ret);
				}
				ret=addMoveJ(path_id, firstjoints, vel, acc, blendradius);
				if (ret < 0)
				{
					printf("addMoveJ failed!Return value = %d\n", ret);
				}
				addMoveJ(path_id, secondjoints, vel, acc, blendradius);
				addMoveJ(path_id, thirdjoints, vel, acc, blendradius);
				addMoveJ(path_id, fourthjoints, vel, acc, blendradius);
				ret=runPath(path_id);
				if (ret < 0)
				{
					printf("runPath failed!Return value = %d\n", ret);
				}
				ret=destroyPath(path_id);
				if (ret < 0)
				{
					printf("destroyPath failed!Return value = %d\n", ret);
				}
				wait_move();

				double fifthjoints[7] = { to_rad(-5.336),to_rad(11.304),to_rad(-28.405),to_rad(104.527),to_rad(21.237),to_rad(-47.713),to_rad(35.425) };
				double sixthjoints[7] = { to_rad(18.675),to_rad(-1.278),to_rad(-10.679),to_rad(119.476),to_rad(-7.264),to_rad(-40.493),to_rad(92.310) };
				double seventhjoints[7] = { to_rad(53.476),to_rad(21.155),to_rad(-24.072),to_rad(113.772),to_rad(-8.882),to_rad(-29.168),to_rad(119.001) };

				printf("开始测试addMoveL\n");
				path_id = 1;
				createPath(2, path_id);
				ret=addMoveL(path_id, fifthjoints, vel, acc, blendradius);
				if (ret < 0)
				{
					printf("addMoveL failed!Return value = %d\n", ret);
				}
				addMoveL(path_id, sixthjoints, vel, acc, blendradius);
				addMoveL(path_id, seventhjoints, vel, acc, blendradius);
				runPath(path_id);
				destroyPath(path_id);
				wait_move();
			}
		}
	}
}

void complexpath()
{
	for (acc = 0.2; acc < 0.4; acc += 0.2)
	{
		for (vel = 0.2; vel < 0.4; vel += 0.2)
		{
			for (blendradius = 0.05; blendradius < 0.10; blendradius += 0.05)
			{
				printf("当前的vel=%f,acc=%f,blendradius=%f\n", vel, acc, blendradius);
				//ComplexPath指令
				//回起始点
				double joints[7] = { 0.0,0.0,0.0,to_rad(90),0.0,to_rad(-90.0),0.0 };
				ret = moveJToTarget(joints, vel, acc, strIpAddress);
				if (ret < 0)
				{
					printf("moveJToTarget failed!Return value = %d\n", ret);
				}
				wait_move();

				//正解位置
				double poses[6] = { 0.0 };
				ret = forward(joints, poses, nullptr, strIpAddress);
				if (ret < 0)
				{
					printf("forward failed!Return value = %d\n", ret);
				}
				poses[0] -= 0.1;
				poses[1] -= 0.3;
				poses[2] -= 0.3;

				ret = moveLToPose(poses, vel, acc, nullptr, strIpAddress);
				if (ret < 0)
				{
					printf("moveLToPose failed!Return value = %d\n", ret);
				}
				wait_move();


				double joints1[7] = { 0.0 };
				ret = getJointPos(joints1, strIpAddress);
				if (ret < 0)
				{
					printf("getJointPos failed!Return value = %d\n", ret);
				}

				double firstpose[6] = { 0.0 };
				ret = forward(joints1, firstpose, nullptr, strIpAddress);
				if (ret < 0)
				{
					printf("forward failed!Return value = %d\n", ret);
				}
				firstpose[1] += 0.4;
				double secondjoints[7] = { 0.0 };
				ret = inverse(firstpose, secondjoints, nullptr, strIpAddress);
				if (ret < 0)
				{
					printf("inverse failed!Return value = %d\n", ret);
				}
				firstpose[1] -= 0.4;
				double thirdjoints[7] = { 0.0 };
				ret = inverse(firstpose, thirdjoints, nullptr, strIpAddress);
				if (ret < 0)
				{
					printf("inverse failed!Return value = %d\n", ret);
				}
				firstpose[0] += 0.2;
				firstpose[1] += 0.2;
				double fourthjoints[7] = { 0.0 };
				ret = inverse(firstpose, fourthjoints, nullptr, strIpAddress);
				if (ret < 0)
				{
					printf("inverse failed!Return value = %d\n", ret);
				}
				firstpose[0] -= 0.2;
				firstpose[1] += 0.2;
				double fifthjoints[7] = { 0.0 };
				ret = inverse(firstpose, fifthjoints, nullptr, strIpAddress);
				if (ret < 0)
				{
					printf("inverse failed!Return value = %d\n", ret);
				}

				int complex_path_type = 0;
				unsigned int complex_path_id;
				bool ignore_rotation = true;

				ret=createComplexPath(complex_path_type, complex_path_id, strIpAddress);
				if (ret < 0)
				{
					printf("createComplexPath failed!Return value = %d\n", ret);
				}
				ret=addMoveJByTarget(complex_path_id, secondjoints, vel, acc, blendradius, strIpAddress);
				if (ret < 0)
				{
					printf("addMoveJByTarget failed!Return value = %d\n", ret);
				}
				ret=addMoveLByTarget(complex_path_id, thirdjoints, vel, acc, blendradius, strIpAddress);
				if (ret < 0)
				{
					printf("addMoveLByTarget failed!Return value = %d\n", ret);
				}
				ret=addMoveCByTarget(complex_path_id, fourthjoints, fifthjoints, vel, acc, blendradius, ignore_rotation, strIpAddress);
				if (ret < 0)
				{
					printf("addMoveCByTarget failed!Return value = %d\n", ret);
				}
				ret=runComplexPath(complex_path_id, strIpAddress);
				if (ret < 0)
				{
					printf("runComplexPath failed!Return value = %d\n", ret);
				}
				ret=destroyComplexPath(complex_path_id, strIpAddress);
				if (ret < 0)
				{
					printf("destroyComplexPath failed!Return value = %d\n", ret);
				}
				wait_move();

				complex_path_type = 1;
				ret=createComplexPath(complex_path_type, complex_path_id, strIpAddress);
				if (ret < 0)
				{
					printf("createComplexPath failed!Return value = %d\n", ret);
				}
				firstpose[0] += 0.2;
				firstpose[1] -= 0.2;
				double sixthjoints[7] = { 0.0 };
				ret = inverse(firstpose, sixthjoints, nullptr, strIpAddress);
				if (ret < 0)
				{
					printf("inverse failed!Return value = %d\n", ret);
				}
				firstpose[0] -= 0.2;
				firstpose[1] -= 0.2;
				double seventhjoints[7] = { 0.0 };
				ret = inverse(firstpose, seventhjoints, nullptr, strIpAddress);
				if (ret < 0)
				{
					printf("inverse failed!Return value = %d\n", ret);
				}
				ret=addMoveCByTarget(complex_path_id, sixthjoints, seventhjoints, vel, acc, blendradius, ignore_rotation, strIpAddress);
				if (ret < 0)
				{
					printf("addMoveCByTarget failed!Return value = %d\n", ret);
				}
				firstpose[1] -= 0.3;
				double eighthjoints[7] = { 0.0 };
				ret = inverse(firstpose, eighthjoints, nullptr, strIpAddress);
				if (ret < 0)
				{
					printf("inverse failed!Return value = %d\n", ret);
				}
				ret=addMoveLByTarget(complex_path_id, eighthjoints, vel, acc, blendradius, strIpAddress);
				if (ret < 0)
				{
					printf("addMoveLByTarget failed!Return value = %d\n", ret);
				}
				ret=runComplexPath(complex_path_id, strIpAddress);
				if (ret < 0)
				{
					printf("runComplexPath failed!Return value = %d\n", ret);
				}
				ret=destroyComplexPath(complex_path_id, strIpAddress);
				if (ret < 0)
				{
					printf("destroyComplexPath failed!Return value = %d\n", ret);
				}
				wait_move();


				M_SLEEP(2000);
				firstpose[0] += 0.3;
				firstpose[1] += 0.3;
				ret = moveLToPose(firstpose, vel, acc, nullptr);
				wait_move();
				firstpose[0] -= 0.3;
				ret = moveLToPose(firstpose, vel, acc, nullptr);
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
				ret = createComplexPath(complex_path_type, complex_path_id, strIpAddress);
				if (ret < 0)
				{
					printf("创建路径失败!Return value = %d\n", ret);
				}
				ret=addMoveCByPose(complex_path_id, firstpose, targetpose, vel, acc, blendradius, ignore_rotation, strIpAddress);
				if (ret < 0)
				{
					printf("addMoveCByPose failed!Return value = %d\n", ret);
				}
				targetpose[1] -= 0.6;
				ret=addMoveLByPose(complex_path_id, targetpose, vel, acc, blendradius, strIpAddress);
				if (ret < 0)
				{
					printf("addMoveLByPose failed!Return value = %d\n", ret);
				}
				targetpose[1] += 0.6;
				ret=addMoveJByPose(complex_path_id, targetpose, vel, acc, blendradius, strIpAddress);
				if (ret < 0)
				{
					printf("addMoveJByPose failed!Return value = %d\n", ret);
				}
				ret=runComplexPath(complex_path_id, strIpAddress);
				if (ret < 0)
				{
					printf("runComplexPath failed!Return value = %d\n", ret);
				}
				ret=destroyComplexPath(complex_path_id, strIpAddress);
				if (ret < 0)
				{
					printf("destroyComplexPath failed!Return value = %d\n", ret);
				}
				wait_move();

				complex_path_type = 3;
				ret = createComplexPath(complex_path_type, complex_path_id, strIpAddress);
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
				ret=addMoveCByPose(complex_path_id, targetpose, targetpose2, vel, acc, blendradius, ignore_rotation, strIpAddress);
				if (ret < 0)
				{
					printf("addMoveCByPose failed!Return value = %d\n", ret);
				}
				targetpose2[1] -= 0.3;
				ret=addMoveLByPose(complex_path_id, targetpose2, vel, acc, blendradius, strIpAddress);
				runComplexPath(complex_path_id, strIpAddress);
				destroyComplexPath(complex_path_id, strIpAddress);
				wait_move();

			}
		}
	}
}


int main() 
{
	srv_net_st * pinfo = new srv_net_st();
	memset(pinfo->SrvIp, 0x00, sizeof(pinfo->SrvIp));
	memcpy(pinfo->SrvIp, "192.168.10.75", strlen("192.168.10.75"));
	pinfo->LocHeartbeatPort = 0;
	pinfo->LocRobotStatePort = 0;
	pinfo->LocSrvPort = 0;
	ret = initSrv(errorControl, nullptr, pinfo);
	if (ret < 0)
	{
		printf("initSrv failed!Return value = %d\n", ret);
	}
	else
	{
		printf("连接成功：%d\n", ret);
	}
	//ret=enableTorqueReceiver(false);
	
	//开启抱闸
	ret = releaseBrake();
	if (ret < 0)
	{
		printf("打开抱闸失败!Return value = %d\n", ret);
	}
	else
	{
		printf("打开抱闸成功！\n");
	}
	

	ret=freeDriving(false, strIpAddress);
	if (ret < 0)
	{
		printf("exit freeDriving failed!Return value = %d\n", ret);
	}
	else
	{
		printf("exit freeDriving succeeded!Return value = %d\n", ret);
	}
	M_SLEEP(2000);

	ret=zeroSpaceFreeDriving(false, strIpAddress);
	if (ret < 0)
	{
		printf("exit zeroSpaceFreeDriving failed!Return value = %d\n", ret);
	}
	else
	{
		printf("exit zeroSpaceFreeDriving succeeded!Return value = %d\n", ret);
	}
	M_SLEEP(1000);
	
	//回起始点
	double joints[7] = { 0.0,0.0,0.0,to_rad(90.0),to_rad(0),to_rad(-90.0),to_rad(0) };
	vel = 0.2;
	acc = 0.2;
	ret = moveJToTarget(joints, vel, acc, strIpAddress);
	if (ret < 0)
	{
		printf("moveJToTarget failed!Return value = %d\n", ret);
	}
	wait_move();

	// //正解位置
	double poses[6] = { 0.0 };
	ret = forward(joints, poses, nullptr, strIpAddress);
	if (ret < 0)
	{
		printf("forward failed!Return value = %d\n", ret);
	}

	poses[0] += 0.1;
	poses[2] -= 0.2;

	ret = moveLToPose(poses, vel, acc, nullptr, strIpAddress);
	if (ret < 0)
	{
		printf("moveLToPose failed!Return value = %d\n", ret);
	}
	wait_move();
    

	// printf("切换控制模式为位置模式\n");
	// ret = changeControlMode(T_MODE_CART_IMPEDANCE, strIpAddress);

	// M_SLEEP(2000);
	//开启自由驱动
	// printf("开启自由驱动\n");
	// ret = freeDriving(true, strIpAddress);
	// if (ret < 0)
	// {
	// 	printf("开启自由驱动失败!return value = %d\n", ret);
	// }
	// else
	// {
	// 	printf("开启自由驱动成功!return value = %d\n", ret);
	// }
	// M_SLEEP(1000);
	
	// M_SLEEP(3000);
	// // while (true)
	// // {
	// // 	if (isCollision())
	// // 	{
	// // 		printf("Warning: Robot got collision\n");
	// // 		M_SLEEP(1000);
	// // 	}
	// // 	else
	// // 	{
	// // 		printf("Robot is not collision\n");
	// // 		M_SLEEP(1000);
	// // 	}
	// // }
	// ret = freeDriving(false, strIpAddress);
	// if (ret < 0)
	// {
	// 	printf("关闭自由驱动失败!return value = %d\n", ret);
	// }
	// else
	// {
	// 	printf("关闭自由驱动成功!return value = %d\n", ret);
	// }
	// M_SLEEP(2000);
	
	
	// ret = changeControlMode(T_MODE_JOINT_IMPEDANCE, strIpAddress);
	// if (ret < 0)
	// {
	// 	printf("changeControlMode failed!return value = %d\n", ret);
	// }
	// else
	// {
	// 	printf("changeControlMode succeeded!return value = %d\n", ret);
	// }
	//开启零空间自由驱动
	printf("开启零空间自由驱动\n");
	ret = zeroSpaceFreeDriving(true, strIpAddress);
	if (ret < 0)
	{
		printf("zeroSpaceFreeDriving failed!Return value = %d\n", ret);
	}
	M_SLEEP(30000);
	
	M_SLEEP(3000);
	ret = zeroSpaceFreeDriving(false, strIpAddress);
	if (ret < 0)
	{
		printf("关闭零空间自由驱动失败!Return value = %d\n", ret);
	}
	else
	{
		printf("关闭零空间自由驱动成功!Return value = %d\n", ret);
	}
	printf("结束零空间自由驱动\n");


	//零空间左右自由驱动
	//切换控制模式为位置模式
	// printf("切换控制模式为位置模式\n");
	// ret = changeControlMode(T_MODE_CART_IMPEDANCE, strIpAddress);
	// M_SLEEP(1000);
	// printf("开始零空间手动驱动\n");
	// for (vel = 0.1; vel < 0.3; vel = vel + 0.1)
	// {
	// 	int direction = -1;
	// 	double dblJointsVel[7] = { vel,vel,vel, vel, vel, vel, vel };
	// 	double dblJointAcc[7] = { vel,vel,vel, vel, vel, vel, vel };
	// 	ret=zeroSpaceManualMove(direction, dblJointsVel, dblJointAcc, strIpAddress);
	// 	if (ret < 0)
	// 	{
	// 		printf("zeroSpaceManualMove failed!Return value = %d\n", ret);
	// 	}
	// 	M_SLEEP(15000);
		
	// 	ret=stop(strIpAddress);
	// 	if (ret < 0)
	// 	{
	// 		printf("stop failed!Return value = %d\n", ret);
	// 	}

	// 	direction = 1;
	// 	ret=zeroSpaceManualMove(direction, dblJointsVel,dblJointAcc, strIpAddress);
	// 	if (ret < 0)
	// 	{
	// 		printf("zeroSpaceManualMove failed!Return value = %d\n", ret);
	// 	}
	// 	M_SLEEP(20000);
	// 	stop(strIpAddress);
	// }
	// printf("结束零空间手动驱动\n");


	// ret = setEndKeyEnableState(false, strIpAddress);
	// if (ret < 0)
	// {
	// 	printf("开启末端自由驱动按键失败!Return value = %d\n", ret);
	// }

	// //关闭末端自由驱动按键，尝试按下按键进行自由驱动
	// M_SLEEP(20000);

	// ret = setEndKeyEnableState(true, strIpAddress);
	// if (ret < 0)
	// {
	// 	printf("关闭末端自由驱动按键失败!Return value = %d\n", ret);
	// }

	// int value1;
	// while(1)
	// {
	// 	value1=-1;
	// 	ret=readDI("tcp", "button", value1,strIpAddress);
	// 	if (ret < 0)
	// 	{
	// 		printf("readDI failed!Return value = %d\n", ret);
	// 	}
	// 	printf("value1:%d\n",value1);
	// 	M_SLEEP(100);

	// }

	//开启末端自由驱动按键，尝试按下按键进行自由驱动
	M_SLEEP(20000);
	
	//读取DI的值
	int value22;
	ret = readDI("board", "di0", value22, strIpAddress);
	if (ret < 0)
	{
		printf("readDI failed!Return value = %d\n", ret);
	}
	printf("readDI di0的值：%d\n", value22);

	ret = readDI("board", "di1", value22, strIpAddress);
	if (ret < 0)
	{
		printf("readDI failed!Return value = %d\n", ret);
	}
	printf("readDI di1的值：%d\n", value22);

	ret = readDI("board", "di2", value22, strIpAddress);
	if (ret < 0)
	{
		printf("readDI failed!Return value = %d\n", ret);
	}
	printf("readDI di2的值：%d\n", value22);

	ret = readDI("board", "di3", value22, strIpAddress);
	if (ret < 0)
	{
		printf("readDI failed!Return value = %d\n", ret);
	}
	printf("readDI di3的值：%d\n", value22);
	M_SLEEP(1000);
	//关闭抱闸
    M_SLEEP(10000);
    ret = holdBrake();
    M_SLEEP(2000);
    printf("holdBrake= %d\n", ret);
    destroySrv();

    return 0;
}
