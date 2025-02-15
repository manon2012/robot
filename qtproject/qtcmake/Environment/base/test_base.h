#pragma once

#ifdef _WIN32
#include "windows.h"
#else
#include "time.h"
#endif
#include "string.h"
#include "float.h"
#include "math.h"
#include "iostream"
#include "fstream"
#include "case_api.h"
#include <vector>

// 角度转换：弧度-->度
double to_degree(double x);
// 角度转换：度-->弧度
double to_rad(double x);
// 线程睡眠
void sleepMilliseconds(unsigned int uintMilliseconds);
// 等待用户输入一个字符
char read_input(const char *strPrompt);
// 错误回调函数
void errorControl(int e,const char *strIpAddress);
// 等待运动指令执行完
void wait_move();
// 运动中获取关节数据
void wait_move1();
// 运动中获取位姿数据
void wait_move2();
