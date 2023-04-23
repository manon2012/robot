#pragma once

#include "DianaAPIDef.h"
#include "environment.h"

#define LIBRARY_MAIN_VERSION 2
#define LIBRARY_SUB_VERSION 5

#pragma pack(1)

// 下列 ifdef 块是创建使从 DLL 导出更简单的宏的标准方法。
// 此 DLL 中的所有文件都是用命令行上定义的 DIANA_API_EXPORTS 符号编译的。
// 在使用此 DLL 的任何其他项目上不应定义此符号。
// 这样，源文件中包含此文件的任何其他项目都会将 DIANA_API_EXPORTS 函数视为是从 DLL 导入的，
// 而此 DLL 则将用此宏定义的符号视为是被导出的。

#if defined _WIN32
#ifdef DIANA_API_EXPORTS
#define DIANA_API extern "C" __declspec(dllexport)
#else
#define DIANA_API extern "C" __declspec(dllimport)
#endif
#else
#if __GNUC__ >= 4
#define DIANA_API extern "C" __attribute__((visibility("default")))
#else
#define DIANA_API extern "C"
#endif
#endif

/*************************************** version 0.1 ***************************************/

extern "C" typedef struct _SrvNetSt {
    char SrvIp[32];
    unsigned short LocHeartbeatPort;
    unsigned short LocRobotStatePort;
    unsigned short LocSrvPort;
    unsigned short LocRealtimeSrvPort;
} srv_net_st;

DIANA_API void initSrvNetInfo(srv_net_st *pinfo);

DIANA_API int initSrv(FNCERRORCALLBACK fnError, FNCSTATECALLBACK fnState, srv_net_st *pinfo);

DIANA_API int destroySrv(const char *strIpAddress = "");

DIANA_API int setPushPeriod(int intPeriod, /*IN*/ const char *strIpAddress = "");  //设置状态推送频率

extern "C" typedef enum _MoveTCPDirection {
    T_MOVE_X_UP,
    T_MOVE_X_DOWN,
    T_MOVE_Y_UP,
    T_MOVE_Y_DOWN,
    T_MOVE_Z_UP,
    T_MOVE_Z_DOWN
} tcp_direction_e;

DIANA_API int moveTCP(/*IN*/ tcp_direction_e d, /*IN*/ double v, /*IN*/ double a,
                      /*IN[6]*/ double *active_tcp = nullptr,
                      /*IN*/ const char *strIpAddress = "");

DIANA_API int rotationTCP(/*IN*/ tcp_direction_e d, /*IN*/ double v, /*IN*/ double a,
                          /*IN[6]*/ double *active_tcp = nullptr, /*IN*/ const char *strIpAddress = "");

extern "C" typedef enum _MoveJointDirection {
    T_MOVE_UP = 0,
    T_MOVE_DOWN,
} joint_direction_e;

DIANA_API int moveJoint(/*IN*/ joint_direction_e d, /*IN*/ int i, /*IN*/ double v, /*IN*/ double a,
                        /*IN*/ const char *strIpAddress = "");

DIANA_API int moveJToTarget(/*IN[7]*/ double *joints, /*IN*/ double v, /*IN*/ double a,
                            /*IN*/ const char *strIpAddress = "");

DIANA_API int moveJToPose(/*IN[6]*/ double *pose, /*IN*/ double v, /*IN*/ double a,
                          /*IN[6]*/ double *active_tcp = nullptr, /*IN*/ const char *strIpAddress = "");

#define moveJ moveJToTarget

#define moveL moveLToPose

DIANA_API int moveLToTarget(/*IN[7]*/ double *joints, /*IN*/ double v, /*IN*/ double a,
                            /*IN*/ const char *strIpAddress = "");

DIANA_API int moveLToPose(/*IN[6]*/ double *pose, /*IN*/ double v, /*IN*/ double a,
                          /*IN[6]*/ double *active_tcp = nullptr, /*IN*/ const char *strIpAddress = "");

DIANA_API int speedJ(/*IN[7]*/ double *speed, /*IN*/ double a, /*option*/ double t,
                     /*IN*/ const char *strIpAddress = "");

DIANA_API int speedL(/*IN[6]*/ double *speed, /*IN[2]*/ double *a, /*option*/ double t,
                     /*IN[6]*/ double *active_tcp = nullptr, /*IN*/ const char *strIpAddress = "");

DIANA_API int freeDriving(bool enable, /*IN*/ const char *strIpAddress = "");

DIANA_API int stop(const char *strIpAddress = "");

DIANA_API int forward(/*IN[7]*/ double *joints, /*OUT[6]*/ double *pose, /*IN[6]*/ double *active_tcp = nullptr,
                      /*IN*/ const char *strIpAddress = "");

DIANA_API int inverse(/*IN[6]*/ double *pose, /*OUT[7]*/ double *joints, /*IN[6]*/ double *active_tcp = nullptr,
                      /*IN*/ const char *strIpAddress = "");

DIANA_API int getJointPos(/*OUT[7]*/ double *joints, /*IN*/ const char *strIpAddress = "");

DIANA_API int getJointAngularVel(/*OUT[7]*/ double *vels, /*IN*/ const char *strIpAddress = "");

DIANA_API int getJointCurrent(/*OUT[7]*/ double *joints, /*IN*/ const char *strIpAddress = "");

DIANA_API int getJointTorque(/*OUT[7]*/ double *torques, /*IN*/ const char *strIpAddress = "");

DIANA_API int getTcpPos(/*OUT[6]*/ double *pose, /*IN*/ const char *strIpAddress = "");

DIANA_API double getTcpExternalForce(const char *strIpAddress = "");

DIANA_API int releaseBrake(const char *strIpAddress = "");  // powerOn

DIANA_API int holdBrake(const char *strIpAddress = "");  // powerOff

typedef enum _Mode {
    T_MODE_INVALID = -1,
    T_MODE_POSITION = 0,
    T_MODE_JOINT_IMPEDANCE,
    T_MODE_CART_IMPEDANCE,
} mode_e;

DIANA_API int changeControlMode(
    mode_e m,
    /*IN*/ const char *strIpAddress = "");  // ChangeMode:Position, JointImpedance, CartImpedance

/*************************************** version 0.2 ***************************************/

DIANA_API unsigned short getLibraryVersion();

DIANA_API const char *formatError(int e, /*IN*/ const char *strIpAddress = "");

DIANA_API int getLastError(const char *strIpAddress = "");

DIANA_API int setLastError(int e, /*IN*/ const char *strIpAddress = "");

// setDefaultActiveTcp:该函数将会改变moveTCP，rotationTCP，moveJToPose，moveLToPose，speedJ，speedL，forward，inverse，getTcpPos，getTcpExternalForce的默认行为。
DIANA_API int setDefaultActiveTcp(/*IN[16]*/ double *default_tcp, /*IN*/ const char *strIpAddress = "");

DIANA_API int getLinkState(const char *strIpAddress = "");

/*************************************** version 0.3 ***************************************/

DIANA_API int getTcpForce(/*OUT[6]*/ double *forces, /*IN*/ const char *strIpAddress = "");

DIANA_API int getJointForce(/*OUT[7]*/ double *forces, /*IN*/ const char *strIpAddress = "");

DIANA_API bool isCollision(const char *strIpAddress = "");

/*************************************** DH参数标定 ***************************************/

DIANA_API int initDHCali(/*IN[3*nrSets]*/ double *tcpMeas, /*IN[7*nrSets]*/ double *jntPosMeas,
                         /*[IN]*/ unsigned int nrSets, /*IN*/ const char *strIpAddress = "");

DIANA_API int getDHCaliResult(/*OUT[28]*/ double *rDH, /*OUT[6]*/ double *wRT, /*OUT[3]*/ double *tRT,
                              /*OUT[2]*/ double *confid, /*IN*/ const char *strIpAddress = "");

DIANA_API int setDH(/*IN[7]*/ double *a, /*IN[7]*/ double *alpha, /*IN[7]*/ double *d, /*IN[7]*/ double *theta,
                    /*IN*/ const char *strIpAddress = "");

DIANA_API int setWrd2BasRT(/*IN[6]*/ double *RTw2b, /*IN*/ const char *strIpAddress = "");

DIANA_API int setFla2TcpRT(/*IN[3]*/ double *RTf2t, /*IN*/ const char *strIpAddress = "");

/*************************************** version 0.4 ***************************************/

DIANA_API char getRobotState(const char *strIpAddress = "");

DIANA_API int resume(const char *strIpAddress = "");

DIANA_API int setJointCollision(/*IN[7]*/ double *collision, /*IN*/ const char *strIpAddress = "");

DIANA_API int setCartCollision(/*IN[6]*/ double *collision, /*IN*/ const char *strIpAddress = "");

/*************************************** version 0.5 ***************************************/

DIANA_API int enterForceMode(/*[IN]*/ int intFrameType,
                             /*IN[16]*/ double *dblFrameMatrix,
                             /*IN[3]*/ double *dblForceDirection,
                             /*[IN]*/ double dblForceValue,
                             /*[IN]*/ double dblMaxApproachVelocity,
                             /*[IN]*/ double dblMaxAllowTcpOffset, /*IN*/ const char *strIpAddress = "");

DIANA_API int leaveForceMode(/*IN*/ int intExitMode, /*IN*/ const char *strIpAddress = "");

DIANA_API int setDefaultActiveTcpPose(/*IN[6]*/ double *arrPose, /*IN*/ const char *strIpAddress = "");

DIANA_API int setResultantCollision(/*IN*/ double force,
                                    /*IN*/ const char *strIpAddress = "");  //合力
#ifndef USE_JOINT_DAMP_RATIO
DIANA_API int setJointImpedance(/*IN[7]*/ double *arrStiff, /*IN[7]*/ double *arrDamp,
                                /*IN*/ const char *strIpAddress = "");

DIANA_API int getJointImpedance(/*OUT[7]*/ double *arrStiff, /*OUT[7]*/ double *arrDamp,
                                /*IN*/ const char *strIpAddress = "");
#endif
#ifndef USE_CART_DAMP_RATIO
DIANA_API int setCartImpedance(/*IN[6]*/ double *arrStiff, /*IN[6]*/ double *arrDamp,
                               /*IN*/ const char *strIpAddress = "");

DIANA_API int getCartImpedance(/*OUT[6]*/ double *arrStiff, /*OUT[6]*/ double *arrDamp,
                               /*IN*/ const char *strIpAddress = "");
#endif
/*************************************** version 2.2 ( version 0.6 ) ***************************************/

DIANA_API int zeroSpaceFreeDriving(/*IN*/ bool enable, /*IN*/ const char *strIpAddress = "");

DIANA_API int createPath(/*IN*/ int type, /*OUT*/ unsigned int &id_path,
                         /*IN*/ const char *strIpAddress = ""); /*1 for moveJ, 2 for moveL*/

DIANA_API int addMoveL(/*IN*/ unsigned int id_path, /*IN[7]*/ double *joints, /*IN*/ double vel, /*IN*/ double acc,
                       /*IN*/ double blendradius, /*IN*/ const char *strIpAddress = "");

DIANA_API int addMoveJ(/*IN*/ unsigned int id_path, /*IN[7]*/ double *joints, /*IN*/ double vel_percent,
                       /*IN*/ double acc_percent, /*IN*/ double blendradius_percent,
                       /*IN*/ const char *strIpAddress = "");

DIANA_API int runPath(/*IN*/ unsigned int id_path, /*IN*/ const char *strIpAddress = "");

DIANA_API int destroyPath(/*IN*/ unsigned int id_path, /*IN*/ const char *strIpAddress = "");

/*************************************** version 0.7 ***************************************/

DIANA_API int rpy2Axis(/*IN[3]*/ double *arr);

DIANA_API int axis2RPY(/*IN[3]*/ double *arr);

DIANA_API int homogeneous2Pose(/*IN[16]*/ double *matrix, /*OUT[6]*/ double *pose);

DIANA_API int pose2Homogeneous(/*IN[6]*/ double *pose, /*OUT[16]*/ double *matrix);

DIANA_API int enableTorqueReceiver(/*bool*/ bool bEnable, /*IN*/ const char *strIpAddress = "");

#ifdef _API_SUPPORT_V2_
DIANA_API int sendTorque_rt(/*IN[7]*/ double *torque, /*IN*/ double t, /*IN*/ const char *strIpAddress = "");
#endif

/*************************************** version 0.8 ***************************************/

DIANA_API int enableCollisionDetection(bool bEnable, /*IN*/ const char *strIpAddress = "");

DIANA_API int setActiveTcpPayload(/*IN[10]*/ double *payload, /*IN*/ const char *strIpAddress = "");

DIANA_API int servoJ(/*IN[7]*/ double *joints, /*IN*/ double time, /*IN*/ double look_ahead_time, /*IN*/ double gain,
                     /*IN*/ const char *strIpAddress = "");

DIANA_API int servoL(/*IN[6]*/ double *pose, /*IN*/ double time, /*IN*/ double look_ahead_time, /*IN*/ double gain,
                     /*IN*/ double scale, /*IN[6]*/ double *active_tcp = nullptr, /*IN*/ const char *strIpAddress = "");

DIANA_API int servoJ_ex(/*IN[7]*/ double *joints, /*IN*/ double time, /*IN*/ double look_ahead_time, /*IN*/ double gain,
                        /*IN*/ bool realiable, /*IN*/ const char *strIpAddress = "");

DIANA_API int servoL_ex(/*IN[6]*/ double *pose, /*IN*/ double time, /*IN*/ double look_ahead_time, /*IN*/ double gain,
                        /*IN*/ double scale, /*IN*/ bool realiable, /*IN[6]*/ double *active_tcp = nullptr,
                        /*IN*/ const char *strIpAddress = "");

DIANA_API int speedJ_ex(/*IN[7]*/ double *speed, /*IN*/ double a, /*option*/ double t, /*IN*/ bool realiable,
                        /*IN*/ const char *strIpAddress = "");

DIANA_API int speedL_ex(/*IN[6]*/ double *speed, /*IN[2]*/ double *a, /*option*/ double t, /*IN*/ bool realiable,
                        /*IN[6]*/ double *active_tcp = nullptr, /*IN*/ const char *strIpAddress = "");

/*************************************** version 0.9 ***************************************/

DIANA_API int dumpToUDisk(const char *strIpAddress = "");

DIANA_API int inverse_ext(/*IN[7]*/ double *ref_joints, /*IN[6]*/ double *pose, /*OUT[7]*/ double *joints,
                          /*IN[6]*/ double *active_tcp = nullptr, /*IN*/ const char *strIpAddress = "");

DIANA_API int getJointLinkPos(/*OUT[7]*/ double *joints, /*IN*/ const char *strIpAddress = "");

enum COMPLEX_PATH_TYPE {
    NORMAL_JOINT_PATH = 0,
    MOVEP_JOINT_PATH = 1,
    NORMAL_POSE_PATH = 2,
    MOVEP_POSE_PATH = 3,
};

DIANA_API int createComplexPath(/*IN*/ int complex_path_type, /*OUT*/ unsigned int &complex_path_id,
                                /*IN*/ const char *strIpAddress = "");

DIANA_API int addMoveLByTarget(/*IN*/ unsigned int complex_path_id, /*IN[7]*/ double *target_joints, /*IN*/ double vel,
                               /*IN*/ double acc, /*IN*/ double blendradius, /*IN*/ const char *strIpAddress = "");

DIANA_API int addMoveLByPose(/*IN*/ unsigned int complex_path_id, /*IN[6]*/ double *target_pose, /*IN*/ double vel,
                             /*IN*/ double acc, /*IN*/ double blendradius, /*IN*/ const char *strIpAddress = "");

DIANA_API int addMoveJByTarget(/*IN*/ unsigned int complex_path_id, /*IN[7]*/ double *target_joints,
                               /*IN*/ double vel_percent, /*IN*/ double acc_percent, /*IN*/ double blendradius_percent,
                               /*IN*/ const char *strIpAddress = "");

DIANA_API int addMoveJByPose(/*IN*/ unsigned int complex_path_id, /*IN[6]*/ double *target_pose,
                             /*IN*/ double vel_percent, /*IN*/ double acc_percent, /*IN*/ double blendradius_percent,
                             /*IN*/ const char *strIpAddress = "");

DIANA_API int addMoveCByTarget(/*IN*/ unsigned int complex_path_id, /*IN[7]*/ double *pass_joints,
                               /*IN[7]*/ double *target_joints, /*IN*/ double vel, /*IN*/ double acc,
                               /*IN*/ double blendradius, /*IN*/ bool ignore_rotation,
                               /*IN*/ const char *strIpAddress = "");

DIANA_API int addMoveCByPose(/*IN*/ unsigned int complex_path_id, /*IN[6]*/ double *pass_pose,
                             /*IN[6]*/ double *target_pose, /*IN*/ double vel, /*IN*/ double acc,
                             /*IN*/ double blendradius, /*IN*/ bool ignore_rotation,
                             /*IN*/ const char *strIpAddress = "");

DIANA_API int runComplexPath(/*IN*/ unsigned int complex_path_id, /*IN*/ const char *strIpAddress = "");

DIANA_API int destroyComplexPath(/*IN*/ unsigned int complex_path_id, /*IN*/ const char *strIpAddress = "");

DIANA_API int saveEnvironment(const char *strIpAddress = "");

DIANA_API int moveTcpBaseLinearRelative(double *pose, double v, double a, /*IN*/ const char *strIpAddress = "");

/*************************************** version 0.10 ***************************************/

DIANA_API int dumpToUDiskEx(/*IN*/ double timeout_second, /*IN*/ const char *strIpAddress = "");

DIANA_API int enterForceMode_ex(/*IN[3]*/ double *dblForceDirection, /*[IN]*/ double dblForceValue,
                                /*[IN]*/ double dblMaxApproachVelocity, /*[IN]*/ double dblMaxAllowTcpOffset,
                                /*IN[6]*/ double *dblActiveTcp = nullptr, /*IN*/ const char *strIpAddress = "");

DIANA_API int readDI(/*IN*/ const char *groupName, /*IN*/ const char *IOName, /*OUT*/ int &value,
                     /*IN*/ const char *strIpAddress = "");
DIANA_API int readAI(/*IN*/ const char *groupName, /*IN*/ const char *IOName, /*OUT*/ int &mode, /*OUT*/ double &value,
                     /*IN*/ const char *strIpAddress = "");
DIANA_API int setAIMode(/*IN*/ const char *groupName, /*IN*/ const char *IOName, /*IN*/ int mode,
                        /*IN*/ const char *strIpAddress = "");
DIANA_API int writeDO(/*IN*/ const char *groupName, /*IN*/ const char *IOName, /*IN*/ int value,
                      /*IN*/ const char *strIpAddress = "");
DIANA_API int writeAO(/*IN*/ const char *groupName, /*IN*/ const char *IOName, /*IN*/ int mode, /*IN*/ double value,
                      /*IN*/ const char *strIpAddress = "");
DIANA_API int readBusCurrent(/*OUT*/ double &current, /*IN*/ const char *strIpAddress = "");
DIANA_API int readBusVoltage(/*OUT*/ double &voltage, /*IN*/ const char *strIpAddress = "");
/*************************************** version 1.1***************************************/

DIANA_API int getDH(/*OUT[7]*/ double *aDH, /*OUT[7]*/ double *alphaDH, /*OUT[7]*/ double *dDH,
                    /*OUT[7]*/ double *thetaDH, /*IN*/ const char *strIpAddress = "");

DIANA_API int getOriginalJointTorque(/*OUT[7]*/ double *torques, /*IN*/ const char *strIpAddress = "");

DIANA_API int getJacobiMatrix(/*OUT[42]*/ double *matrix_jacobi, /*IN*/ const char *strIpAddress = "");

/*************************************** version 1.2***************************************/

DIANA_API int resetDH(const char *strIpAddress = "");

/*************************************** version 1.3***************************************/

DIANA_API int runProgram(const char *programName, /*IN*/ const char *strIpAddress = "");
DIANA_API int stopProgram(const char *programName, /*IN*/ const char *strIpAddress = "");
DIANA_API int getVariableValue(const char *variableName, double &value, /*IN*/ const char *strIpAddress = "");
DIANA_API int setVariableValue(const char *variableName, const double &value, /*IN*/ const char *strIpAddress = "");
DIANA_API int isTaskRunning(const char *variableName, /*IN*/ const char *strIpAddress = "");
DIANA_API int pauseProgram(const char *strIpAddress = "");
DIANA_API int resumeProgram(const char *strIpAddress = "");
DIANA_API int stopAllProgram(const char *strIpAddress = "");
DIANA_API int isAnyTaskRunning(const char *strIpAddress = "");

/*************************************** version 1.4***************************************/

DIANA_API int cleanErrorInfo(const char *strIpAddress = "");
DIANA_API int setCollisionLevel(int level, /*IN*/ const char *strIpAddress = "");
//以下mapping相关函数暂不支持python版本
DIANA_API int mappingInt8Variant(const char *variantName, int index, /*IN*/ const char *strIpAddress = "");
DIANA_API int mappingDoubleVariant(const char *variantName, int index, /*IN*/ const char *strIpAddress = "");
DIANA_API int mappingInt8IO(const char *groupName, const char *name, int index, /*IN*/ const char *strIpAddress = "");
DIANA_API int mappingDoubleIO(const char *groupName, const char *name, int index, /*IN*/ const char *strIpAddress = "");
DIANA_API int setMappingAddress(double *dblAddress, int doubleItemCount, int8_t *int8Address, int int8ItemCount,
                                /*IN*/ const char *strIpAddress = "");
DIANA_API int lockMappingAddress(const char *strIpAddress = "");
DIANA_API int unlockMappingAddress(const char *strIpAddress = "");

/*************************************** version 1.5***************************************/

DIANA_API int getJointCount(const char *strIpAddress = "");

DIANA_API int getWayPoint(const char *waypointName, double *dblTcppos, double *dblJoints,
                          /*IN*/ const char *strIpAddress = "");
DIANA_API int setWayPoint(const char *waypointName, double *dblTcppos, double *dblJoints,
                          /*IN*/ const char *strIpAddress = "");
DIANA_API int addWayPoint(const char *waypointName, double *dblTcppos, double *dblJoints,
                          /*IN*/ const char *strIpAddress = "");
DIANA_API int deleteWayPoint(const char *waypointName, /*IN*/ const char *strIpAddress = "");

DIANA_API int setExternalAppendTorCutoffFreq(/*IN*/ double dblFreq, /*IN*/ const char *strIpAddress = "");

/*************************************** version 1.6***************************************/
DIANA_API int zeroSpaceManualMove(/*IN*/ int direction, /*IN[7 or 6]*/ double *dblJointsVel,
                                  /*IN[7 or 6]*/ double *dblJointAcc, /*IN*/ const char *strIpAddress = "");

/*****************************************
 * function name: getHomingState
 * -1: get state failed
 *  0: home position
 *  1: running
 *  2: homing stop with error
 *  3: not at home position = need homing
 * **************************************/
DIANA_API int getHomingState(const char *strIpAddress = "");
DIANA_API int startHoming(const char *strIpAddress = "");
DIANA_API int setEndKeyEnableState(bool bEnable, const char *strIpAddress = "");
DIANA_API int updateForce(/*[IN]*/ double dblForceValue, const char *strIpAddress = "");

/*************************************** version 1.7***************************************/

DIANA_API int getCartImpedanceCoordinateType(const char *strIpAddress = "");
DIANA_API int setCartImpedanceCoordinateType(const int intCoordinateType, const char *strIpAddress = "");
DIANA_API int getInertiaMatrix(/*IN[7]*/ double *dblMotorPosition, /*OUT[7*7]*/ double *dblInerMatrix,
                               const char *strIpAddress = "");
DIANA_API int getSixAxiaForce(/*OUT[6]*/ double *dblForce, const char *strIpAddress = "");

DIANA_API int inverseClosedFull(/*IN[6]*/ const double *pose, /*IN*/ const int lock_joint_index,
                                /*IN*/ const double lock_joint_position, /*IN[7]*/ double *ref_joints,
                                /*IN[6]*/ double *active_tcp = nullptr, /*IN*/ const char *strIpAddress = "");
DIANA_API int getInverseClosedResultSize(/*IN*/ const int id, /*IN*/ const char *strIpAddress = "");
DIANA_API int getInverseClosedJoints(/*IN*/ const int id, /*IN*/ const int index, /*OUT*/ double *joints,
                                     /*IN*/ const char *strIpAddress = "");
DIANA_API int destoryInverseClosedItems(/*IN*/ const int id, /*IN*/ const char *strIpAddress = "");

#define nullSpaceFreeDriving zeroSpaceFreeDriving
#define nullSpaceManualMove zeroSpaceManualMove

DIANA_API int calculateJacobi(/*OUT[6*JOINT_COUNT]*/ double *dblJacobiMatrix, /*IN[7]*/ const double *dblJointPosition,
                              /*IN*/ int intJointCount, /*IN*/ const char *strIpAddress = "");
DIANA_API int calculateJacobiTF(/*OUT[6*JOINT_COUNT]*/ double *dblJacobiMatrix,
                                /*IN[7]*/ const double *dblJointPosition,
                                /*IN*/ int intJointCount, /*IN[6]*/ double *active_tcp = nullptr,
                                /*IN*/ const char *strIpAddress = "");
DIANA_API int getTcpForceInToolCoordinate(/*OUT[6]*/ double *forces, /*IN*/ const char *strIpAddress = "");
DIANA_API int speedLOnTcp(/*IN[6]*/ double *speed, /*IN[2]*/ double *a, /*option*/ double t,
                          /*IN[6]*/ double *active_tcp = nullptr, /*IN*/ const char *strIpAddress = "");
DIANA_API int inverseClosedIdeal(/*IN[6]*/ const double *pose, /*IN*/ const double lock_robot_arm_angle,
                                 /*IN[7]*/ double *ref_joints, /*IN[6]*/ double *active_tcp = nullptr,
                                 /*IN*/ const char *strIpAddress = "");
DIANA_API int getInverseClosedIdealResultSize(/*IN*/ const int id, /*IN*/ const char *strIpAddress = "");
DIANA_API int getInverseClosedIdealJoints(/*IN*/ const int id, /*IN*/ const int index, /*OUT*/ double *joints,
                                          /*IN*/ const char *strIpAddress = "");
DIANA_API int destoryInverseClosedIdealItems(/*IN*/ const int id, /*IN*/ const char *strIpAddress = "");
DIANA_API int getSixAxisZeroOffset(/*OUT[10]*/ double *dblZeroOffset, /*IN*/ const char *strIpAddress = "");
DIANA_API int setSixAxisZeroOffset(/*IN[10]*/ double *dblZeroOffset, /*IN*/ const char *strIpAddress = "");
DIANA_API int setDefaultActiveWorkpiece(/*IN[16]*/ double *dblWop, /*IN*/ const char *strIpAddress = "");
DIANA_API int setDefaultActiveWorkpiecePose(/*IN[6]*/ double *dblWopPose, /*IN*/ const char *strIpAddress = "");
DIANA_API int getDefaultActiveWorkpiece(/*OUT[16]*/ double *dblWop, /*IN*/ const char *strIpAddress = "");
DIANA_API int getDefaultActiveWorkpiecePose(/*OUT[6]*/ double *dblWopPose, /*IN*/ const char *strIpAddress = "");
DIANA_API int freeDriving_ex(/*IN*/ bool enable, /*[IN]*/ int intFrameType, /*IN[6]*/ double *dblForceDirection,
                             /*IN*/ const char *strIpAddress = "");

/*************************************** version 1.8***************************************/

extern "C" typedef enum _CONTROLLER_FEATURE_CODE {
    NONE_FEATURE = 0,
    AUTO_SWITCH_TO_IMPEDANCE_MODE_WHEN_COLLISION_DETECTED = 1,
} controller_feature;

DIANA_API int setControllerFeatureCode(/*IN*/ controller_feature intFeatureCode, /*IN*/ bool bEnable,
                                       /*IN*/ const char *strIpAddress = "");
DIANA_API int testControllerFeature(/*IN*/ controller_feature intFeatureCode, /*OUT*/ bool &bEnable,
                                    /*IN*/ const char *strIpAddress = "");

extern "C" typedef enum _SIX_AXIS_TYPE {
    SIX_AXIS_IN_FREE_DRIVING = 0,
    SIX_AXIS_IN_FORCE_MODE,
    SIX_AXIS_IN_JOINT_IMPEDANCE,
    SIX_AXIS_IN_CART_IMPEDANCE,
} six_axis_type_e;

DIANA_API int enableSixAxis(/*IN*/ six_axis_type_e type, /*IN & OUT*/ bool &bEnable,
                            /*IN*/ const char *strIpAddress = "");

DIANA_API bool isSixAxisEnabled(/*IN*/ six_axis_type_e type, /*IN*/ const char *strIpAddress = "");

/*************************************** version 1.9***************************************/

DIANA_API int getMechanicalJointsPositionRange(/*OUT[7]*/ double *dblMinPos, /*OUT[7]*/ double *dblMaxPos,
                                               /*IN*/ const char *strIpAddress = "");
DIANA_API int getMechanicalMaxJointsVel(/*OUT[7]*/ double *dblVel, /*IN*/ const char *strIpAddress = "");
DIANA_API int getMechanicalMaxJointsAcc(/*OUT[7]*/ double *dblAcc, /*IN*/ const char *strIpAddress = "");
DIANA_API int getMechanicalMaxCartVelAcc(/*OUT*/ double &dblMaxCartTranslationVel,
                                         /*OUT*/ double &dblMaxCartRotationVel,
                                         /*OUT*/ double &dblMaxCartTranslationAcc,
                                         /*OUT*/ double &dblMaxCartRotationAcc,
                                         /*IN*/ const char *strIpAddress = "");
DIANA_API int getJointsPositionRange(/*OUT[7]*/ double *dblMinPos, /*OUT[7]*/ double *dblMaxPos,
                                     /*IN*/ const char *strIpAddress = "");
DIANA_API int getMaxJointsVel(/*OUT[7]*/ double *dblVel, /*IN*/ const char *strIpAddress = "");
DIANA_API int getMaxJointsAcc(/*OUT[7]*/ double *dblAcc, /*IN*/ const char *strIpAddress = "");
DIANA_API int getMaxCartTranslationVel(/*OUT*/ double &dblMaxCartTranslationVel, /*IN*/ const char *strIpAddress = "");
DIANA_API int getMaxCartRotationVel(/*OUT*/ double &dblMaxCartRotationVel, /*IN*/ const char *strIpAddress = "");
DIANA_API int getMaxCartTranslationAcc(/*OUT*/ double &dblMaxCartTranslationAcc, /*IN*/ const char *strIpAddress = "");
DIANA_API int getMaxCartRotationAcc(/*OUT*/ double &dblMaxCartRotationAcc, /*IN*/ const char *strIpAddress = "");
DIANA_API int setJointsPositionRange(/*IN[7]*/ double *dblMinPos, /*IN[7]*/ double *dblMaxPos,
                                     /*IN*/ const char *strIpAddress = "");
DIANA_API int setMaxJointsVel(/*IN[7]*/ double *dblVel, /*IN*/ const char *strIpAddress = "");
DIANA_API int setMaxJointsAcc(/*IN[7]*/ double *dblAcc, /*IN*/ const char *strIpAddress = "");
DIANA_API int setMaxCartTranslationVel(/*IN*/ double dblMaxCartTranslationVel, /*IN*/ const char *strIpAddress = "");
DIANA_API int setMaxCartRotationVel(/*IN*/ double dblMaxCartRotationVel, /*IN*/ const char *strIpAddress = "");
DIANA_API int setMaxCartTranslationAcc(/*IN*/ double dblMaxCartTranslationAcc, /*IN*/ const char *strIpAddress = "");
DIANA_API int setMaxCartRotationAcc(/*OUT*/ double dblMaxCartRotationAcc, /*IN*/ const char *strIpAddress = "");
DIANA_API bool calcRobotArmAngle(/*IN[7]*/ double *dblJoints, /*OUT*/ double &dblAngle,
                                 /*IN*/ const char *strIpAddress = "");

/*************************************** version 1.10***************************************/

DIANA_API int freeDrivingWithLockedJoint(bool enable, /*IN*/ int intLockedJntIndex = -1,
                                         /*IN*/ const char *strIpAddress = "");

DIANA_API int freeDrivingWithLockedJoint_ex(/*IN*/ bool enable, /*[IN]*/ int intFrameType,
                                            /*IN[6]*/ double *dblForceDirection,
                                            /*IN*/ int intLockedJntIndex = -1, /*IN*/ const char *strIpAddress = "");

DIANA_API int freeDrivingForCurrentLoop(bool enable, /*IN*/ const char *strIpAddress = "");
DIANA_API int getCurrentLoopFreeDrivingState(/*IN*/ const char *strIpAddress = "");

/*************************************** version 1.11***************************************/

DIANA_API int getJointsSoftLimitRange(/*OUT[7]*/ double *dblMinPos, /*OUT[7]*/ double *dblMaxPos,
                                      /*IN*/ const char *strIpAddress = "");
DIANA_API int setJointsSoftLimitRange(/*IN[7]*/ double *dblMinPos, /*IN[7]*/ double *dblMaxPos,
                                      /*IN*/ const char *strIpAddress = "");

/*************************************** version 1.12 **************************************/
DIANA_API int setJointLockedInCartImpedanceMode(/*IN*/ const bool bLock, /*IN*/ const int intLockedJointIndex = 2,
                                                /*IN*/ const char *strIpAddress = "");
DIANA_API int getJointLockedInCartImpedanceMode(/*OUT*/ bool &isLocked, /*IN*/ const char *strIpAddress = "");

DIANA_API int enterSafetyIdle(/*IN*/ const char *strIpAddress = "");

DIANA_API int leaveSafetyIdle(/*IN*/ const char *strIpAddress = "");

struct LoadIdentificationWaypoint {
    double joints[7];
    double vel;
};
struct LoadIdentificationParam {
    LoadIdentificationParam(bool valid = false, double mass = 0.0, LoadIdentificationWaypoint *arr = nullptr,
                            int len = 0)
        : bIsMassValid(valid), dblMass(mass), arrWaypoints(arr), arrWaypointsSize(len) {}
    bool bIsMassValid;                         // default:false
    double dblMass;                            // default:0.0,
    LoadIdentificationWaypoint *arrWaypoints;  // default:nullptr,
    int arrWaypointsSize;                      // default:0
};
extern "C" typedef bool (*FNCSTOP)(const char *strIpAddress);
/***********************************
 *  identifyTcpPayload 函数返回值含义
 *  0：成功
 * -1：其他错误
 * -2：无法读取关节扭矩
 * -3：初始化失败
 * -4：采样失败
 * -5：传送辨识数据失败
 * -6：结果不可信
 * -7：负载辨识失败
 * -8：回调函数中断负载辨识
 * -9:robot正在执行负载辨识任务
 * -10:开启辨识失败
 * -11:结束负载辨识失败
 * -12:robot正在执行示教程序
 * *********************************/
DIANA_API int identifyTcpPayload(/*OUT[10]*/ double *dblResult, /*IN*/ FNCSTOP fnNeedStop = nullptr,
                                 /*IN*/ LoadIdentificationParam *ptrParam = nullptr,
                                 /*IN*/ const char *strIpAddress = "");

typedef struct color_rgb {
public:
    color_rgb(uint8_t r = 255, uint8_t g = 255, uint8_t b = 255) : red(r), green(g), blue(b) {}

public:
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} led_color;

DIANA_API int getRgbLedState(/*OUT[7]*/ led_color *rgbLedColor, /*IN*/ const char *strIpAddress = "");
DIANA_API int setRgbLedState(/*IN[7]*/ led_color *rgbLedColor, /*IN*/ const char *strIpAddress = "");
#ifdef USE_CART_DAMP_RATIO
DIANA_API int setCartImpeda(/*IN[6]*/ double *arrStiff, /*IN*/ double dblDampRatio, const char *strIpAddress = "");

DIANA_API int getCartImpeda(/*OUT[6]*/ double *arrStiff, /*OUT*/ double *dblDampRatio, const char *strIpAddress = "");

#endif
#ifdef USE_JOINT_DAMP_RATIO
DIANA_API int setJointImpeda(/*IN[7]*/ double *arrStiff, /*IN*/ double dblDampRatio,
                             /*IN*/ const char *strIpAddress = "");
DIANA_API int getJointImpeda(/*OUT[7]*/ double *arrStiff, /*OUT*/ double *dblDampRatio,
                             /*IN*/ const char *strIpAddress = "");

#endif

DIANA_API int getDefaultActiveTcp(/*OUT[16]*/ double *default_tcp, /*IN*/ const char *strIpAddress = "");

DIANA_API int getRobotNetworkInfo(char *strNetworkInfo, /*option*/ const char *strIpAddress = "");
DIANA_API int setRobotNetworkInfo(const char *strCurrentNetworkInfo, const char *strTargetNetworkInfo,
                                  /*option*/ const char *strIpAddress = "");

DIANA_API int getFunctionOptI4(/*IN*/ int intFunctionIndex, /*IN*/ int intOptName, /*OUT*/ int *intOptVal,
                               /*IN*/ const char *strIpAddress = "");
DIANA_API int setFunctionOptI4(/*IN*/ int intFunctionIndex, /*IN*/ int intOptName, /*IN*/ int intOptVal,
                               /*IN*/ const char *strIpAddress = "");
DIANA_API int getFunctionOptR8(/*IN*/ int intFunctionIndex, /*IN*/ int intOptName, /*OUT*/ double *dblOptVal,
                               /*IN*/ const char *strIpAddress = "");
DIANA_API int setFunctionOptR8(/*IN*/ int intFunctionIndex, /*IN*/ int intOptName, /*IN*/ double dblOptVal,
                               /*IN*/ const char *strIpAddress = "");
/*************************************** 以下是测试用函数 ***************************************/
#ifdef PRESS_TEST

DIANA_API void getTestData(int &fail, int &timeout, int &success, /*IN*/ const char *strIpAddress = "");
#endif

#pragma pack()
