#!usr/bin/python3


from ctypes import *
import platform
import os
import time
import sys
from enum import Enum
import math

errorCodeMessage = {
    0: 'NO_ERROR_CODE',
    -1000: 'ERROR_CODE_SOCKET_OTHER_ERROR',
    -1001: 'ERROR_CODE_WSASTART_FAIL',
    -1002: 'ERROR_CODE_CREATE_SOCKET_FAIL',
    -1003: 'ERROR_CODE_BIND_PORT_FAIL',
    -1004: 'ERROR_CODE_SOCKET_READ_FAIL',
    -1005: 'ERROR_CODE_SOCKET_TIMEOUT',
    -1006: 'ERROR_CODE_RECVFROM_FAIL',
    -1007: 'ERROR_CODE_SENDTO_FAIL',
    -1008: 'ERROR_CODE_LOST_HEARTBEAT',
    -1009: 'ERROR_CODE_LOST_ROBOTSTATE',
    -1010: 'ERROR_CODE_GET_DH_FAILED',
    -1011: 'ERROR_CODE_RELEASE_BRAKE_FAILED',
    -1012: 'ERROR_CODE_HOLD_BRAKE_FAILED',
    -1013: 'ERROR_CODE_IP_ADDRESS_NOT_REGISTER',
    -1014: 'ERROR_CODE_ROBOTARM_OVERNUMBER',
    -1015: 'ERROR_CODE_SOCKET_OTHER_ERROR',
    -1016: 'ERROR_CODE_SOCKET_CONNECTED_ALREADY',
    -1017: 'ERROR_CODE_UNKNOWN_ROBOTSTATE',
    -2001: 'ERROR_CODE_JOINT_REGIST_ERROR',
    -2002: 'ERROR_CODE_CURRENT_OFFSET_ERROR',
    -2003: 'ERROR_CODE_EQEP_ENCODER',
    -2004: 'ERROR_CODE_SPIENCODER',
    -2005: 'ERROR_CODE_HALL_SENSOR',
    -2006: 'ERROR_CODE_CURRENT_BUS_OVERTIME',
    -2007: 'ERROR_CODE_CURRENT_IQ_OVERTIME',
    -2008: 'ERROR_CODE_POSITION_CMD_STEP',
    -2009: 'ERROR_CODE_TORQUE_SENSOR',
    -2010: 'ERROR_CODE_EEPROM_READ',
    -2011: 'ERROR_CODE_EEPROM_WRITE',
    -2012: 'ERROR_CODE_LS_ENCODER_OVERSPEED',
    -2013: 'ERROR_CODE_LS_ENCODER_FB_ERROR',
    -2014: 'ERROR_CODE_MS_SINGAL_Z_ERROR',
    -2015: 'ERROR_CODE_THREE_PHASE_CURRENT',
    -2016: 'ERROR_CODE_TORQUE_SENSOR_READ_ERROR',
    -2101: 'ERROR_CODE_COMMUNICATE_ERROR',
    -2102: 'ERROR_CODE_LOST_HEART_WITH_DIANAROBOT_ERROR',
    -2201: 'ERROR_CODE_CALLING_CONFLICT_ERR',
    -2202: 'ERROR_CODE_COLLISION_ERROR',
    -2203: 'ERROR_CODE_NOT_FOLLOW_POSITION_CMD',
    -2204: 'ERROR_CODE_NOT_FOLLOW_TCP_CMD',
    -2205: 'ERROR_CODE_NOT_ALL_AT_OP_STATE',
    -2206: 'ERROR_CODE_OUT_RANGE_FEEDBACK',
    -2207: 'ERROR_CODE_EMERGENCY_STOP',
    -2208: 'ERROR_CODE_NO_INIT_PARAMETER',
    -2209: 'ERROR_CODE_NOT_MATCH_LOAD',
    -2210: 'ERROR_CODE_CANNOT_MOVE_WHILE_FREE_DRIVING', 
    -2211: 'ERROR_CODE_CANNOT_MOVE_WHILE_ZERO_SPACE_FREE_DRIVING',
    -2212: 'ERROR_CODE_PASSTHROUGH_FIFO_OVERFLOW_UP_ERROR',
    -2213: 'ERROR_CODE_PASSTHROUGH_FIFO_OVERFLOW_DOWN_ERROR',
    -2214: 'ERROR_CODE_ROBOT_IN_VIRTUAL_WALL',
    -2215: 'ERROR_CODE_CONFLICT_TASK_RUNNING',
    -2216: 'ERROR_CODE_OUT_OF_PHYSICAL_RANGE_FEEDBACK',
    -2217: 'ERROR_CODE_PARAMETER_POINTER_EQUALS_NULLPTR',
    -2218: 'ERROR_CODE_PARAMETER_EQUALS_NAN_OR_INF',
    -2219: 'ERROR_CODE_UNKNOWN_FIRMWARE_VERSION',
    -2220: 'ERROR_CODE_INPUT_OUT_OF_EXTREME_POSITION_RANGE',
    -2221: 'ERROR_CODE_INPUT_OUT_OF_PHYSICAL_POSITION_RANGE',
    -2222: 'ERROR_CODE_NOT_IN_SAFETY_HANDLE_MODE',
    -2223: 'ERROR_CODE_INCOMPATIBLE_FIRMWARE_VERSION',
    -2224: 'ERROR_CODE_JOINT_IMPEDANCE_DECLINED_IN_SAFETY_HANDLE',
    -2225: 'ERROR_CODE_CART_IMPEDANCE_DECLINED_IN_SAFETY_HANDLE',
    -2226: 'ERROR_CODE_CART_IMPEDANCE_PARAMETER_OUT_OF_RANGE',
    -2227: 'ERROR_CODE_JOINT_IMPEDANCE_PARAMETER_OUT_OF_RANGE',
    -2301: 'ERROR_CODE_PLAN_ERROR',
    -2302: 'ERROR_CODE_INTERPOLATE_ERROR',
    -2303: 'ERROR_CODE_INTERPOLATE_TORQUE_ERROR',
    -2304: 'ERROR_CODE_SINGULAR_VALUE_ERROR',
    -2305: 'ERROR_CODE_PLANNER_ERROR_ERROR',
    -2306: 'ERROR_CODE_HOME_POSITION_ERROR',
    -2307: 'ERROR_CODE_FATAL',
    -2308: 'ERROR_CODE_POS_LIMIT',
    -2309: 'ERROR_CODE_FORCE_LIMIT',
    -2310: 'ERROR_CODE_SPEED_LIMIT',
    -2311: 'ERROR_CODE_ACC_LIMIT',
    -2312: 'ERROR_CODE_JERK_LIMIT',
    -2313: 'ERROR_CODE_MOTION_LIMIT',
    -2314: 'ERROR_CODE_IK_TRACK',
    -2315: 'ERROR_CODE_IK_GENERAL',
    -2316: 'ERROR_CODE_PLAN_INPUT',
    -2317: 'ERROR_CODE_PLAN_MOVJ',
    -2318: 'ERROR_CODE_PLAN_MOVL',
    -2319: 'ERROR_CODE_PLAN_MOVC',
    -2320: 'ERROR_CODE_PLAN_BLEND',
    -2321: 'ERROR_CODE_PLAN_SPDJ',
    -2322: 'ERROR_CODE_PLAN_SPDL',
    -2323: 'ERROR_CODE_PLAN_SRVJ',
    -2324: 'ERROR_CODE_PLAN_SRVL',
    -2325: 'ERROR_CODE_MOVE_UNKNOWN',
    -2326: 'ERROR_CODE_MOVE_UNPLAN',
    -2327: 'ERROR_CODE_MOVE_INPUT',
    -2328: 'ERROR_CODE_MOVE_INTERP',
    -2329: 'ERROR_CODE_PLAN_TRANSLATION',
    -2330: 'ERROR_CODE_PLAN_ROTATION',
    -2331: 'ERROR_CODE_PLAN_JOINTS',
    -2332: 'ERROR_CODE_UNMATCHED_JOINTS_NUMBER',
    -2333: 'ERROR_CODE_TCPCALI_FUTILE_WPS',
    -2334: 'ERROR_CODE_TCPCALI_FIT_FAIL',
    -2335: 'ERROR_CODE_DHCALI_FIT_WF_FAIL',
    -2336: 'ERROR_CODE_DHCALI_FIT_TF_FAIL',
    -2337: 'ERROR_CODE_DHCALI_FIT_DH_FAIL',
    -2338: 'ERROR_CODE_DHCALI_INIT_FAIL',
    -2339: 'ERROR_CODE_SLFMOV_SINGULAR',
    -2340: 'ERROR_CODE_SLFMOV_FUTILE',
    -2341: 'ERROR_CODE_SLFMOV_JNTLIM',
    -2342: 'ERROR_CODE_SLFMOV_SPDLIM',
    -2343: 'ERROR_CODE_SLFMOV_FAIL',
    -2344: 'ERROR_CODE_SLFMOV_FFC_FAIL',
    -2345: 'ERROR_CODE_LOADIDENT_INIT_FAIL',
    -2346: 'ERROR_CODE_LOADIDENT_UFB_FAIL',
    -2347: 'ERROR_CODE_LOADIDENT_FIT_FAIL',
    -2348: 'ERROR_CODE_LOADIDENT_NONLOADED',
    -3001: 'ERROR_CODE_RESOURCE_UNAVAILABLE',
    -3002: 'ERROR_CODE_DUMP_LOG_TIMEOUT',
    -3003: 'ERROR_CODE_DUMP_LOG_FAILED',
    -3004: 'ERROR_CODE_RESET_DH_FAILED',
    -3005: 'ERROR_CODE_SIX_AXIS_DEVICE_OFFLINE',
}
loadIdentificationErrorCodeMessage = {
    0: 'NO_ERROR_CODE',
    -1: 'LOAD_IDENTIFICATION_OTHER_ERROR',
    -2: 'LOAD_IDENTIFICATION_READ_JOINTS_TORQUE_FAIL',
    -3: 'LOAD_IDENTIFICATION_INIT_FAIL',
    -4: 'LOAD_IDENTIFICATION_SAMPLING_FAIL',
    -5: 'LOAD_IDENTIFICATION_TRANS_FAIL',
    -6: 'LOAD_IDENTIFICATION_UNRELIABLE_RESULT',
    -7: 'LOAD_IDENTIFICATION_FAIL',
    -8: 'LOAD_IDENTIFICATION_CALLBACK_STOP',
    -9: 'LOAD_IDENTIFICATION_CONFLICT_ALREADY_RUNNING',
    -10: 'LOAD_IDENTIFICATION_START_FAIL',
    -11: 'LOAD_IDENTIFICATION_STOP_FAIL',
    -12: 'LOAD_IDENTIFICATION_CONFLICT_PROGRAM_RUNNING',
    -13: 'LOAD_IDENTIFICATION_PARAMETERS_ILLEGAL'
}

scriptLibraryNames = {
	'Linux': 'libDianaApi.so',
	'Windows': 'DianaApi.dll'
}

scriptLibraryDir = os.path.split(os.path.realpath(__file__))[0]
scriptLibraryPath = os.path.join(
    scriptLibraryDir, scriptLibraryNames[platform.system()])
api_mod = None
if sys.version_info < (3, 8):
    api_mod = CDLL(scriptLibraryPath)
else:
    api_mod = CDLL(scriptLibraryPath, winmode=0)

#Enumration starts
#add Enumration here


class tcp_direction_e(Enum):
    T_MOVE_X_UP = 0
    T_MOVE_X_DOWN = 1
    T_MOVE_Y_UP = 2
    T_MOVE_Y_DOWN = 3
    T_MOVE_Z_UP = 4
    T_MOVE_Z_DOWN = 5


class mode_e(Enum):
    T_MODE_INVALID = -1
    T_MODE_POSITION = 0
    T_MODE_JOINT_IMPEDANCE = 1
    T_MODE_CART_IMPEDANCE = 2


class joint_direction_e(Enum):
    T_MOVE_UP = 0
    T_MOVE_DOWN = 1


class complex_path_type(Enum):
    NORMAL_JOINT_PATH = 0
    MOVEP_JOINT_PATH = 1
    NORMAL_POSE_PATH = 2
    MOVEP_POSE_PATH = 3

class zero_space_move_direction(Enum):
    E_FORWARD = 1
    E_BACKWARD = -1

class controller_feature_e(Enum):
    NONE_FEATURE = 0
    AUTO_SWITCH_TO_IMPEDANCE_MODE_WHEN_COLLISION_DETECTED = 1

class six_axis_type_e(Enum):
    SIX_AXIS_IN_FREE_DRIVING = 0
    SIX_AXIS_IN_FORCE_MODE = 1
    SIX_AXIS_IN_JOINT_IMPEDANCE = 2
    SIX_AXIS_IN_CART_IMPEDANCE = 3

class function_index_e(Enum):
    E_FREEDRIVING = 0
    E_CART_IMPEDANCE = 1

class function_opt_name_e(Enum):
    E_DEFAULT_OPT = 0
    E_ENABLE_ARM_ANGLE = 0x10001
    E_FLOOR_ARM_ANGLE = 0x10002
    E_CEIL_ARM_ANGLE = 0x10003
    E_IS_SINGLE_AXIS_LOCKED = 0x10101
    E_LOCKED_SINGLE_AXIS = 0x10102
    E_CONSTRAIN_TYPE = 0x10103

#Enumeration ends

#Structure starts
#add Structure here


class DIANA_JOINTS_POSITION(Structure):
    pass


DIANA_JOINTS_POSITION._fields_ = [
    ('values', c_double*7)
]


class DIANA_JOINTS_FORCE(Structure):
    pass


DIANA_JOINTS_FORCE._fields_ = [
    ('values', c_double*7)
]


class DIANA_TCP_POSE(Structure):
    pass


DIANA_TCP_POSE._fields_ = [
    ('values', c_double * 6)
]


class DIANA_WOP_POSE(Structure):
    pass


DIANA_WOP_POSE._fields_ = [
    ('values', c_double * 6)
]


class DIANA_JOINTS_SPEED(Structure):
    pass


DIANA_JOINTS_SPEED._fields_ = [
    ('values', c_double*7)
]


class DIANA_JOINTS_SPEED_L(Structure):
    pass


DIANA_JOINTS_SPEED_L._fields_ = [
    ('values', c_double*6)
]


class DIANA_JOINTS_ACC(Structure):
    pass


DIANA_JOINTS_ACC._fields_ = [
    ('values', c_double*2)
]

class DIANA_JOINT_ACC(Structure):
    pass


DIANA_JOINT_ACC._fields_ = [
    ('values', c_double*7)
]


class DIANA_FRAME_MATRIX(Structure):
    pass


DIANA_FRAME_MATRIX._fields_ = [
    ('values', c_double * 16)
]


class DIANA_FORCE_DIRECTION(Structure):
    pass


DIANA_FORCE_DIRECTION._fields_ = [
    ('values', c_double * 3)
]

class DIANA_FORCE_FULL_DIRECTION(Structure):
    pass


DIANA_FORCE_FULL_DIRECTION._fields_ = [
    ('values', c_double * 6)
]


class SRV_NET_ST(Structure):
    pass


SRV_NET_ST._fields_ = [
    ('ipAddress', c_char * 32),
    ('SLocHeartbeatPortrvIp', c_ushort),
    ('LocRobotStatePort', c_ushort),
    ('LocSrvPort', c_ushort),
    ('LocRealtimeSrvPort', c_ushort)
]


class DIANA_JOINT_ANGULAR_VEL(Structure):
    pass


DIANA_JOINT_ANGULAR_VEL._fields_ = [
    ('values', c_double * 7)
]


class DIANA_JOINT_CURRENT(Structure):
    pass


DIANA_JOINT_CURRENT._fields_ = [
    ('values', c_double * 7)
]


class DIANA_JOINT_TORQUE(Structure):
    pass


DIANA_JOINT_TORQUE._fields_ = [
    ('values', c_double * 7)
]


class DIANA_TCP_FORCE(Structure):
    pass


DIANA_TCP_FORCE._fields_ = [
    ('values', c_double * 6)
]


class DIANA_DEFAULT_TCP(Structure):
    pass


DIANA_DEFAULT_TCP._fields_ = [
    ('values', c_double * 16)
]


class DIANA_DEFAULT_WOP(Structure):
    pass


DIANA_DEFAULT_WOP._fields_ = [
    ('values', c_double * 16)
]


class DIANA_TCP_VECTOR(Structure):
    pass


DIANA_TCP_VECTOR._fields_ = [
    ('values', c_double * 6)
]


class DIANA_WOP_VECTOR(Structure):
    pass


DIANA_WOP_VECTOR._fields_ = [
    ('values', c_double * 6)
]


class DIANA_RPY_VECTOR(Structure):
    pass


DIANA_RPY_VECTOR._fields_ = [
    ('values', c_double * 3)
]


class DIANA_AXIS_VECTOR(Structure):
    pass


DIANA_AXIS_VECTOR._fields_ = [
    ('values', c_double * 3)
]


class DIANA_JOINT_COLLISION(Structure):
    pass


DIANA_JOINT_COLLISION._fields_ = [
    ('values', c_double * 7)
]


class DIANA_CART_COLLISION(Structure):
    pass


DIANA_CART_COLLISION._fields_ = [
    ('values', c_double * 6)
]


class DIANA_JOINT_STIFF(Structure):
    pass


DIANA_JOINT_STIFF._fields_ = [
    ('values', c_double * 7)
]


class DIANA_JOINT_DAMP(Structure):
    pass


DIANA_JOINT_DAMP._fields_ = [
    ('values', c_double * 7)
]


class DIANA_CART_STIFF(Structure):
    pass


DIANA_CART_STIFF._fields_ = [
    ('values', c_double * 6)
]


class DIANA_CART_DAMP(Structure):
    pass


DIANA_CART_DAMP._fields_ = [
    ('values', c_double * 6)
]


class DIANA_TCP_PAYLOAD(Structure):
    pass


DIANA_TCP_PAYLOAD._fields_ = [
    ('values', c_double * 10)
]

class DIANA_CART_VEL_ACC(Structure):
    pass

DIANA_CART_VEL_ACC._fields_ = [
    ('dblMaxCartTranslationVel', c_double),
    ('dblMaxCartRotationVel', c_double),
    ('dblMaxCartTranslationAcc', c_double),
    ('dblMaxCartRotationAcc', c_double),
]

class StrTrajectoryState(Structure):
    _pack_ = 1
    _fields_ = [
        ('taskId', c_int),
        ('segCount', c_int),
        ('segIndex', c_int),
        ('errorCode', c_int),
        ('isPaused', c_int),
        ('isFreeDriving', c_int),
        ('isZeroSpaceFreeDriving', c_int)
    ]


class StrErrorInfo(Structure):
    _pack_ = 1
    _fields_ = [
        ('errorId', c_int),
        ('errorType', c_int),
        ('errorCode', c_int),
        ('errorMsg', c_char * 64)
    ]


class StrRobotStateInfo(Structure):
    _pack_ = 1
    _fields_ = [
        ('jointPos', c_double * 7),
        ('jointAngularVel', c_double * 7),
        ('jointCurrent', c_double * 7),
        ('jointTorque', c_double * 7),
        ('tcpPos', c_double * 6),
        ('tcpExternalForce', c_double),
        ('bCollision', c_bool),
        ('bTcpForceValid', c_bool),
        ('tcpForce', c_double * 6),
        ('jointForce', c_double * 7),
        ('trajState', StrTrajectoryState),
        ('StrErrorInfo', StrErrorInfo)
    ]

class DIANA_DH_A(Structure):
        pass


DIANA_DH_A._fields_ = [
    ('values', c_double * 7)
]

class DIANA_DH_Alpha(Structure):
        pass


DIANA_DH_Alpha._fields_ = [
    ('values', c_double * 7)
]

class DIANA_DH_D(Structure):
        pass


DIANA_DH_D._fields_ = [
    ('values', c_double * 7)
]

class DIANA_DH_Theta(Structure):
        pass


DIANA_DH_Theta._fields_ = [
    ('values', c_double * 7)
]


class DIANA_JACOBI_MATRIX(Structure):
    pass


DIANA_JACOBI_MATRIX._fields_ = [
    ('values', c_double * 42)
]

class DIANA_DIGTAL_VALUE_ALL(Structure):
    pass

DIANA_DIGTAL_VALUE_ALL._fields_ = [
    ('values', c_int * 8)
]

class DIANA_ANALOG_VALUE_ALL(Structure):
    pass

DIANA_ANALOG_VALUE_ALL._fields_ = [
    ('values', c_double * 2)
]

class DIANA_ANALOG_MODE(Structure):
    pass

DIANA_ANALOG_MODE._fields_ = [
    ('values', c_int * 2)
]

class DIANA_DH_R(Structure):
    pass

DIANA_DH_R._fields_ = [
    ('values', c_double * 28)
]

class DIANA_DH_WRT(Structure):
    pass

DIANA_DH_WRT._fields_ = [
    ('values', c_double * 6)
]

class DIANA_DH_TRT(Structure):
    pass

DIANA_DH_TRT._fields_ = [
    ('values', c_double * 3)
]

class DIANA_DH_CONFID(Structure):
    pass

DIANA_DH_CONFID._fields_ = [
    ('values', c_double * 2)
]

class DIANA_DH_RTw2b(Structure):
    pass

DIANA_DH_RTw2b._fields_ = [
    ('values', c_double * 6)
]

class DIANA_DH_RTf2t(Structure):
    pass

DIANA_DH_RTf2t._fields_ = [
    ('values', c_double * 3)
]

class DIANA_KP(Structure):
    pass

DIANA_KP._fields_ = [
    ('values', c_double * 7)
]

class DIANA_KD(Structure):
    pass

DIANA_KD._fields_ = [
    ('values', c_double * 7)
]

class DIANA_ACTIVE_TCP(Structure):
    pass

DIANA_ACTIVE_TCP._fields_ = [
    ('values', c_double * 6)
]

class DIANA_SIX_AXIS_ZERO_OFFSET(Structure):
    pass


DIANA_SIX_AXIS_ZERO_OFFSET._fields_ = [
    ('values', c_double * 10)
]

class DIANA_FEATURE_CODE_STATE(Structure):
        pass

DIANA_FEATURE_CODE_STATE._fields_ = [
    ('value', c_bool)
]

class DIANA_SIX_AXIS_STATE(Structure):
        pass

DIANA_SIX_AXIS_STATE._fields_ = [
    ('value', c_bool)
]


class DIANA_LOAD_IDENTIFICATION_RESULT(Structure):
        pass

DIANA_LOAD_IDENTIFICATION_RESULT._fields_ = [
    ('values', c_double * 10)
]

class DIANA_LOAD_IDENTIFICATION_WAYPOINT(Structure):
    _pack_ = 1
    _fields_ = [
        ('joints', c_double * 7),
        ('vel', c_double)
    ]

class DIANA_LOAD_IDENTIFICATION_PARAM(Structure):
    _pack_ = 1
    _fields_ = [
        ('bIsMassValid', c_bool),
        ('dblMass', c_double),
        ('arrWaypoints', POINTER(DIANA_LOAD_IDENTIFICATION_WAYPOINT)),
        ('arrWaypointsSize', c_int),
    ]

class DIANA_RGB_LED_STATE(Structure):
    pass
DIANA_RGB_LED_STATE._fields_ = [
    ('red', c_uint8),
    ('green', c_uint8),
    ('blue', c_uint8),
]

class DIANA_RGB_LED_ALL_JOINTS(Structure):
    pass

DIANA_RGB_LED_ALL_JOINTS._fields_ = [
    ('color',DIANA_RGB_LED_STATE * 7),
]

# Structure ends


#Callback function starts
#add callback function here
FNCERRORCALLBACK = CFUNCTYPE(None, c_int)

FNCSTATECALLBACK = CFUNCTYPE(None, POINTER(StrRobotStateInfo))

FNCSTOP = CFUNCTYPE(c_bool, c_char_p)
#Callback function ends


def message(ret):
    if(ret >= 0):
        return True
    else:
        errorcode = getLastError()
        errorMessage = errorCodeMessage.get(errorcode)
        callerName = 'function ' + sys._getframe().f_back.f_code.co_name + ' fails,'
        if errorMessage == None:
            print(callerName + 'Error Code ' + str(errorcode))
        else:
            print(callerName + errorMessage)
        return False

def load_identification_message(ret):
    if(ret >= 0):
        return True
    else:
        errorMessage = loadIdentificationErrorCodeMessage.get(ret)
        callerName = 'function ' + sys._getframe().f_back.f_code.co_name + ' fails,'
        if errorMessage == None:
            print(callerName + 'Error Code ' + str(ret))
        else:
            print(callerName + errorMessage)
        return False

def wait_move():
    time.sleep(0.02)
    while True:
        state = getRobotState()
        if state != 0:
            break
        else:
            time.sleep(0.001)
    stop()

def initSrv(srv_net_st, fnError=None, fnState=None):
    pinfo = SRV_NET_ST()
    ipAddress = srv_net_st[0]
    pinfo.ipAddress = bytes(ipAddress.encode('utf-8'))
    pinfo.SLocHeartbeatPortrvIp = srv_net_st[1]
    pinfo.LocRobotStatePort = srv_net_st[2]
    pinfo.LocSrvPort = srv_net_st[3]
    pinfo.LocRealtimeSrvPort = srv_net_st[4]
    api_mod.initSrv.argtypes = [FNCERRORCALLBACK, FNCSTATECALLBACK, POINTER(SRV_NET_ST)]
    api_mod.initSrv.restype = c_int
    if fnError == None:
        fnError = FNCERRORCALLBACK()
    if fnState == None:
        fnState = FNCSTATECALLBACK()
    ret = api_mod.initSrv(fnError, fnState, byref(pinfo))
    return message(ret)

def destroySrv(ipAddress=''):
    api_mod.destroySrv.argtypes = [c_char_p]
    api_mod.destroySrv.restype = c_int
    ret = api_mod.destroySrv(bytes(ipAddress.encode('utf-8')))
    return message(ret)

def setPushPeriod(period, ipAddress=''):
    api_mod.setPushPeriod.argtypes = [c_int, c_char_p]
    api_mod.setPushPeriod.restype = c_int
    ret = api_mod.setPushPeriod(period, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def moveTCP(d, v, a, ipAddress = ''):
    active_tcp = c_void_p(0)
    api_mod.moveTCP.argtypes = [c_int, c_double, c_double, c_void_p, c_char_p]
    api_mod.moveTCP.restype = c_int
    ret = api_mod.moveTCP(d.value, v, a, active_tcp, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def rotationTCP(d, v, a, ipAddress = ''):
    active_tcp = c_void_p(0)
    api_mod.rotationTCP.argtypes = [c_int, c_double, c_double, c_void_p, c_char_p]
    api_mod.rotationTCP.restype = c_int
    ret = api_mod.rotationTCP(d.value, v, a, active_tcp, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def moveJoint(d, i, v, a, ipAddress = ''):
    api_mod.moveJoint.argtypes = [c_int, c_int, c_double, c_double, c_char_p]
    api_mod.moveJoint.restype = c_int
    ret = api_mod.moveJoint(d.value, i, v, a, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def moveJToTarget(joints, v, a, ipAddress = ''):
    dianaJointPos = DIANA_JOINTS_POSITION()
    dianaJointPos.values = (c_double * 7)()
    for index in range(0, len(joints)):
        dianaJointPos.values[index] = joints[index]
    api_mod.moveJToTarget.argtypes = [
        POINTER(DIANA_JOINTS_POSITION), c_double, c_double, c_char_p]
    api_mod.moveJToTarget.restype = c_int
    ret = api_mod.moveJToTarget(byref(dianaJointPos), v, a, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def moveJToPose(pose, v, a, ipAddress = ''):
    dianaTcpPose = DIANA_TCP_POSE()
    dianaTcpPose.values = (c_double * 6)()
    active_tcp = c_void_p(0)
    for index in range(0, len(dianaTcpPose.values)):
        dianaTcpPose.values[index] = pose[index]
    api_mod.moveJToPose.argtypes = [
        POINTER(DIANA_TCP_POSE), c_double, c_double, c_void_p, c_char_p]
    api_mod.moveJToPose.restype = c_int
    ret = api_mod.moveJToPose(dianaTcpPose, v, a, active_tcp, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def moveLToTarget(joints, v, a, ipAddress = ''):
    dianaJointPos = DIANA_JOINTS_POSITION()
    dianaJointPos.values = (c_double * 7)()
    for index in range(0, len(joints)):
        dianaJointPos.values[index] = joints[index]
    api_mod.moveLToTarget.argtypes = [
        POINTER(DIANA_JOINTS_POSITION), c_double, c_double, c_char_p]
    api_mod.moveLToTarget.restype = c_int
    ret = api_mod.moveLToTarget(dianaJointPos, v, a, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def moveLToPose(pose, v, a, ipAddress = ''):
    dianaTcpPose = DIANA_TCP_POSE()
    dianaTcpPose.values = (c_double * 6)()
    active_tcp = c_void_p(0)
    for index in range(0, len(dianaTcpPose.values)):
        dianaTcpPose.values[index] = pose[index]
    api_mod.moveLToPose.argtypes = [
        POINTER(DIANA_TCP_POSE), c_double, c_double, c_void_p, c_char_p]
    api_mod.moveLToPose.restype = c_int
    ret = api_mod.moveLToPose(dianaTcpPose, v, a, active_tcp, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def speedJ(speed, acc, t=0.0, ipAddress = ''):
    dianaJointsSpeed = DIANA_JOINTS_SPEED()
    dianaJointsSpeed.values = (c_double * 7)()
    for index in range(0, len(speed)):
        dianaJointsSpeed.values[index] = speed[index]
    api_mod.speedJ.argtypes = [POINTER(DIANA_JOINTS_SPEED), c_double, c_double, c_char_p]
    api_mod.speedJ.restype = c_int
    ret = api_mod.speedJ(dianaJointsSpeed, acc, t, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def speedL(speed, acc, t=0.0, ipAddress = ''):
    dianaJointsSpeed = DIANA_JOINTS_SPEED_L()
    dianaJointsSpeed.values = (c_double * 6)()
    for index in range(0, len(dianaJointsSpeed.values)):
        dianaJointsSpeed.values[index] = speed[index]
    dianaJointsAcc = DIANA_JOINTS_ACC()
    dianaJointsAcc.values = (c_double * 2)()
    for index in range(0, len(dianaJointsAcc.values)):
        dianaJointsAcc.values[index] = acc[index]
    active_tcp = c_void_p(0)
    api_mod.speedL.argtypes = [POINTER(DIANA_JOINTS_SPEED_L), POINTER(
        DIANA_JOINTS_ACC), c_double, c_void_p, c_char_p]
    api_mod.speedL.restype = c_int
    ret = api_mod.speedL(dianaJointsSpeed, dianaJointsAcc, t, active_tcp, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def setEndKeyEnableState(enable, ipAddress = ''):
    api_mod.setEndKeyEnableState.argtypes = [c_bool, c_char_p]
    api_mod.setEndKeyEnableState.restype = c_int
    ret = api_mod.setEndKeyEnableState(enable, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def freeDriving(enable, ipAddress = ''):
    api_mod.freeDriving.argtypes = [c_bool, c_char_p]
    api_mod.freeDriving.restype = c_int
    ret = api_mod.freeDriving(enable, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def stop(ipAddress = ''):
    api_mod.freeDriving.argtypes = [c_char_p]
    api_mod.stop.restype = c_int
    ret = api_mod.stop(bytes(ipAddress.encode('utf-8')))
    return message(ret)

def forward(joints, pose, ipAddress = ''):
    dianaJointsPosition = DIANA_JOINTS_POSITION()
    dianaJointsPosition.values = (c_double * 7)()
    for index in range(0, len(joints)):
        dianaJointsPosition.values[index] = joints[index]
    dianaTcpPose = DIANA_TCP_POSE()
    dianaTcpPose.values = (c_double * 6)()
    active_tcp = c_void_p(0)
    api_mod.forward.argtypes = [
        POINTER(DIANA_JOINTS_POSITION), POINTER(DIANA_TCP_POSE), c_void_p, c_char_p]
    api_mod.forward.restype = c_int
    ret = api_mod.forward(byref(dianaJointsPosition), byref(dianaTcpPose), active_tcp, bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(dianaTcpPose.values)):
        pose[index] = dianaTcpPose.values[index]
    return message(ret)

def inverse(pose, joints, ipAddress = ''):
    dianaTcpPose = DIANA_TCP_POSE()
    dianaTcpPose.values = (c_double * 6)()
    for index in range(0, len(dianaTcpPose.values)):
        dianaTcpPose.values[index] = pose[index]
    dianaJointsPosition = DIANA_JOINTS_POSITION()
    dianaJointsPosition.values = (c_double * 7)()
    active_tcp = c_void_p(0)
    api_mod.inverse.argtypes = [POINTER(DIANA_TCP_POSE), POINTER(
        DIANA_JOINTS_POSITION),  c_void_p, c_char_p]
    api_mod.inverse.restype = c_int
    ret = api_mod.inverse(dianaTcpPose, byref(dianaJointsPosition), active_tcp, bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(joints)):
        joints[index] = dianaJointsPosition.values[index]
    return message(ret)

def getJointPos(jointsPosition, ipAddress = ''):
    dianaJointsPosition = DIANA_JOINTS_POSITION()
    dianaJointsPosition.values = (c_double * 7)()
    api_mod.getJointPos.argtypes = [POINTER(DIANA_JOINTS_POSITION), c_char_p]
    api_mod.getJointPos.restype = c_int
    ret = api_mod.getJointPos(byref(dianaJointsPosition), bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(jointsPosition)):
      jointsPosition[index] = dianaJointsPosition.values[index]
    return message(ret)

def getJointAngularVel(jointAngularVel, ipAddress = ''):
    dianaJointAngularVel = DIANA_JOINT_ANGULAR_VEL()
    dianaJointAngularVel.values = (c_double * 7)()
    api_mod.getJointAngularVel.argtypes = [POINTER(DIANA_JOINT_ANGULAR_VEL), c_char_p]
    api_mod.getJointAngularVel.restype = c_int
    ret = api_mod.getJointAngularVel(byref(dianaJointAngularVel), bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(jointAngularVel)):
      jointAngularVel[index] = dianaJointAngularVel.values[index]
    return message(ret)

def getJointCurrent(jointCurrent, ipAddress = ''):
    dianaJointCurrent = DIANA_JOINT_CURRENT()
    dianaJointCurrent.values = (c_double*7)()
    for index in range(0, len(jointCurrent)):
        dianaJointCurrent.values[index] = jointCurrent[index]
    api_mod.getJointCurrent.argtypes = [POINTER(DIANA_JOINT_CURRENT), c_char_p]
    api_mod.getJointCurrent.restype = c_int
    ret = api_mod.getJointCurrent(byref(dianaJointCurrent), bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(jointCurrent)):
        jointCurrent[index] = dianaJointCurrent.values[index]
    return message(ret)

def getJointTorque(jointTorque, ipAddress = ''):
    dianaJointTorque = DIANA_JOINT_TORQUE()
    dianaJointTorque.values = (c_double*7)()
    for index in range(0, len(jointTorque)):
        dianaJointTorque.values[index] = jointTorque[index]
    api_mod.getJointTorque.argtypes = [POINTER(DIANA_JOINT_TORQUE), c_char_p]
    api_mod.getJointTorque.restype = c_int
    ret = api_mod.getJointTorque(byref(dianaJointTorque), bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(jointTorque)):
        jointTorque[index] = dianaJointTorque.values[index]
    return message(ret)

def getTcpPos(tcpPose, ipAddress = ''):
    dianaTcpPose = DIANA_TCP_POSE()
    dianaTcpPose.values = (c_double * 6)()
    api_mod.getTcpPos.argtypes = [POINTER(DIANA_TCP_POSE), c_char_p]
    api_mod.getTcpPos.restype = c_int
    ret = api_mod.getTcpPos(byref(dianaTcpPose), bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(dianaTcpPose.values)):
      tcpPose[index] = dianaTcpPose.values[index]
    return message(ret)

def getTcpExternalForce(ipAddress = ''):
    api_mod.getTcpExternalForce.argtypes = [c_char_p]
    api_mod.getTcpExternalForce.restype = c_double
    ret = api_mod.getTcpExternalForce(bytes(ipAddress.encode('utf-8')))
    return ret

def releaseBrake(ipAddress = ''):
    api_mod.releaseBrake.argtypes = [c_char_p]
    api_mod.releaseBrake.restype = c_int
    ret = api_mod.releaseBrake(bytes(ipAddress.encode('utf-8')))
    return message(ret)

def holdBrake(ipAddress = ''):
    api_mod.holdBrake.argtypes = [c_char_p]
    api_mod.holdBrake.restype = c_int
    ret = api_mod.holdBrake(bytes(ipAddress.encode('utf-8')))
    return message(ret)

def changeControlMode(m, ipAddress = ''):
    if not isinstance(m, mode_e):
	        raise TypeError(
			            'mode must be an instance of mode_e Enum')
    api_mod.changeControlMode.argtypes = [c_int, c_char_p]
    api_mod.changeControlMode.restype = c_int
    ret = api_mod.changeControlMode(m.value, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def getLibraryVersion():
    # api_mod.getLibraryVersion.argtypes = [c_char_p]
    api_mod.getLibraryVersion.restype = c_uint
    ret = api_mod.getLibraryVersion()
    return ret

def formatError(e, ipAddress = ''):
    api_mod.formatError.argtypes = [c_int, c_char_p]
    api_mod.formatError.restype = c_char_p
    ret = api_mod.formatError(e, bytes(ipAddress.encode('utf-8')))
    return ret

def getLastError(ipAddress = ''):
    api_mod.getLastError.argtypes = [c_char_p]
    api_mod.getLastError.restype = c_int
    ret = api_mod.getLastError(bytes(ipAddress.encode('utf-8')))
    return ret

def setLastError(e, ipAddress = ''):
    api_mod.setLastError.argtypes = [c_int, c_char_p]
    api_mod.setLastError.restype = c_int
    ret = api_mod.setLastError(e, bytes(ipAddress.encode('utf-8')))
    return ret

def setDefaultActiveTcp(default_tcp, ipAddress = ''):
    defaultTcp = DIANA_DEFAULT_TCP()
    defaultTcp.values = (c_double*16)()
    for index in range(0, len(defaultTcp.values)):
        defaultTcp.values[index] = default_tcp[index]
    api_mod.setDefaultActiveTcp.argtypes = [POINTER(DIANA_DEFAULT_TCP), c_char_p]
    api_mod.setDefaultActiveTcp.restype = c_int
    ret = api_mod.setDefaultActiveTcp(defaultTcp, bytes(ipAddress.encode('utf-8')))
    if(ret == 0):
        print("setDefaultActiveTcp succeeds")
        return True
    else:
        print("setDefaultActiveTcp fails")
        return False

def getLinkState(ipAddress = ''):
    api_mod.getLinkState.argtypes = [c_char_p]
    api_mod.getLinkState.restype = c_int
    ret = api_mod.getLinkState(bytes(ipAddress.encode('utf-8')))
    return message(ret)

def getTcpForce(tcpForce, ipAddress = ''):
    dianaTcpForce = DIANA_TCP_FORCE()
    dianaTcpForce.values = (c_double * 6)()
    api_mod.getTcpForce.argtypes = [POINTER(DIANA_TCP_FORCE), c_char_p]
    api_mod.getTcpForce.restype = c_int
    ret = api_mod.getTcpForce(byref(dianaTcpForce), bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(dianaTcpForce.values)):
      tcpForce[index] = dianaTcpForce.values[index]
    return message(ret)

def getJointForce(jointForce, ipAddress = ''):
    dianaJointForce = DIANA_JOINTS_FORCE()
    dianaJointForce.values = (c_double * 7)()
    api_mod.getJointForce.argtypes = [POINTER(DIANA_JOINTS_FORCE), c_char_p]
    api_mod.getJointForce.restype = c_int
    ret = api_mod.getJointForce(byref(dianaJointForce), bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(jointForce)):
      jointForce[index] = dianaJointForce.values[index]
    return message(ret)

def isCollision(ipAddress = ''):
    api_mod.isCollision.argtypes = [c_char_p]
    api_mod.isCollision.restype = c_bool
    ret = api_mod.isCollision(bytes(ipAddress.encode('utf-8')))
    return ret

def initDHCali(tcpMeas,jntPosMeas,nrSets, ipAddress = ''):
    tcpMeasArray = c_double * (nrSets * 3)
    tcpMeasData = tcpMeasArray()
    jntPosMeasArray = c_double * (nrSets * 7)
    jntPosMeasData = jntPosMeasArray()
    for index in range(0, nrSets * 3):
        tcpMeasData[index] = tcpMeas[index]
    for index in range(0, nrSets * 7):
        jntPosMeasData[index] = jntPosMeas[index]
    api_mod.initDHCali.restype = c_int
    api_mod.initDHCali.argtypes = [ POINTER(c_double),POINTER(c_double),c_uint, c_char_p]
    ret = api_mod.initDHCali(tcpMeasData, jntPosMeasData, nrSets, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def getDHCaliResult(rDH,wRT,tRT,confid, ipAddress = ''):
    dhR = DIANA_DH_R()
    dhR.values = (c_double*28)()
    rtW = DIANA_DH_WRT()
    rtW.values = (c_double*6)()
    rtT = DIANA_DH_TRT()
    rtT.values = (c_double*3)()
    dhConfid = DIANA_DH_CONFID()
    dhConfid.values = (c_double*2)()
    api_mod.getDHCaliResult.restype = c_int
    api_mod.getDHCaliResult.argtypes = [ POINTER(DIANA_DH_R),POINTER(DIANA_DH_WRT),POINTER(DIANA_DH_TRT),POINTER(DIANA_DH_CONFID), c_char_p]
    ret = api_mod.getDHCaliResult(byref(dhR), byref(rtW), byref(rtT), byref(dhConfid), bytes(ipAddress.encode('utf-8')))
    for index in range(0,len(rDH)):
        rDH[index] = dhR.values[index]
    for index in range(0,len(wRT)):
        wRT[index] = rtW.values[index]
    for index in range(0,len(tRT)):
        tRT[index] = rtT.values[index]
    for index in range(0,len(confid)):
        confid[index] = dhConfid.values[index]
    return message(ret)

def setDH(a,alpha,d,theta, ipAddress = ''):
    arr_aDH = DIANA_DH_A()
    arr_aDH.values = (c_double*7)()
    for index in range(0, len(a)):
        arr_aDH.values[index] = a[index]
    arr_alphaDH = DIANA_DH_Alpha()
    arr_alphaDH.values = (c_double*7)()
    for index in range(0, len(alpha)):
        arr_alphaDH.values[index] = alpha[index]
    arr_dDH = DIANA_DH_D()
    arr_dDH.values = (c_double*7)()
    for index in range(0, len(d)):
        arr_dDH.values[index] = d[index]
    arr_thetaDH = DIANA_DH_Theta()
    arr_thetaDH.values = (c_double*7)()
    for index in range(0, len(theta)):
        arr_thetaDH.values[index] = theta[index]
    api_mod.setDH.restype = c_int
    api_mod.setDH.argtypes = [ POINTER(DIANA_DH_A), 
        POINTER(DIANA_DH_Alpha),POINTER(DIANA_DH_D), POINTER(DIANA_DH_Theta), c_char_p]
    ret = api_mod.setDH(byref(arr_aDH),byref(arr_alphaDH),byref(arr_dDH),byref(arr_thetaDH), bytes(ipAddress.encode('utf-8')))
    return message(ret)

def setWrd2BasRT(RTw2b, ipAddress = ''):
    arr_RTw2b = DIANA_DH_RTw2b()
    arr_RTw2b.values = (c_double*6)()
    for index in range(0, len(RTw2b)):
        arr_RTw2b.values[index] = RTw2b[index]
    api_mod.setWrd2BasRT.restype = c_int
    api_mod.setWrd2BasRT.argtypes = [ POINTER(DIANA_DH_RTw2b), c_char_p]
    ret = api_mod.setWrd2BasRT(byref(arr_RTw2b), bytes(ipAddress.encode('utf-8')))
    return message(ret)

def setFla2TcpRT(RTf2t, ipAddress = ''):
    arr_RTf2t = DIANA_DH_RTf2t()
    arr_RTf2t.values = (c_double*3)()
    for index in range(0, len(RTf2t)):
        arr_RTf2t.values[index] = RTf2t[index]
    api_mod.setFla2TcpRT.restype = c_int
    api_mod.setFla2TcpRT.argtypes = [ POINTER(DIANA_DH_RTf2t), c_char_p]
    ret = api_mod.setFla2TcpRT(byref(arr_RTf2t), bytes(ipAddress.encode('utf-8')))
    return message(ret)

def getRobotState(ipAddress = ''):
    api_mod.getRobotState.argtypes = [c_char_p]
    api_mod.getRobotState.restype = c_int8
    ret = api_mod.getRobotState(bytes(ipAddress.encode('utf-8')))
    return ret

def resume(ipAddress = ''):
    api_mod.resume.argtypes = [c_char_p]
    api_mod.resume.restype = c_int
    ret = api_mod.resume(bytes(ipAddress.encode('utf-8')))
    return message(ret)

def setJointCollision(collision, ipAddress = ''):
    jointCollision = DIANA_JOINT_COLLISION()
    jointCollision.values = (c_double*7)()
    for index in range(0, len(collision)):
        jointCollision.values[index] = collision[index]
    api_mod.setJointCollision.argtypes = [POINTER(DIANA_JOINT_COLLISION), c_char_p]
    api_mod.setJointCollision.restype = c_int
    ret = api_mod.setJointCollision(jointCollision, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def setCartCollision(collision, ipAddress = ''):
    cartCollision = DIANA_CART_COLLISION()
    cartCollision.values = (c_double*6)()
    for index in range(0, len(cartCollision.values)):
        cartCollision.values[index] = collision[index]
    api_mod.setCartCollision.argtypes = [POINTER(DIANA_CART_COLLISION), c_char_p]
    api_mod.setCartCollision.restype = c_int
    ret = api_mod.setCartCollision(cartCollision, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def enterForceMode(frame_type, frame_matrix, force_direction, force_value, max_approach_velocity, max_allow_tcp_offset, ipAddress = ''):
    dianaFrameMatrix = DIANA_FRAME_MATRIX()
    dianaFrameMatrix.values = (c_double * 16)()
    for index in range(0, len(dianaFrameMatrix.values)):
        dianaFrameMatrix.values[index] = frame_matrix[index]
    dianaForceDirection = DIANA_FORCE_DIRECTION()
    dianaForceDirection.values = (c_double * 3)()
    for index in range(0, len(dianaForceDirection.values)):
        dianaForceDirection.values[index] = force_direction[index]
    api_mod.enterForceMode.argtypes = [c_int, POINTER(DIANA_FRAME_MATRIX), POINTER(
        DIANA_FORCE_DIRECTION), c_double, c_double, c_double, c_char_p]
    api_mod.enterForceMode.restype = c_int
    ret = api_mod.enterForceMode(frame_type, byref(dianaFrameMatrix), byref(
        dianaForceDirection), force_value, max_approach_velocity, max_allow_tcp_offset, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def leaveForceMode(mode, ipAddress = ''):
    if not isinstance(mode, mode_e):
	        raise TypeError(
			            'mode must be an instance of mode_e Enum')
    api_mod.leaveForceMode.argtypes = [c_int, c_char_p]
    api_mod.leaveForceMode.restype = c_int
    ret = api_mod.leaveForceMode(mode.value, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def setDefaultActiveTcpPose(arrPose, ipAddress = ''):
    tcpPose = DIANA_TCP_VECTOR()
    tcpPose.values = (c_double*6)()
    for index in range(0, len(tcpPose.values)):
        tcpPose.values[index] = arrPose[index]
    api_mod.setDefaultActiveTcpPose.argtypes = [POINTER(DIANA_TCP_VECTOR), c_char_p]
    api_mod.setDefaultActiveTcpPose.restype = c_int
    ret = api_mod.setDefaultActiveTcpPose(tcpPose, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def setResultantCollision(force, ipAddress = ''):
    api_mod.setResultantCollision.argtypes = [c_double, c_char_p]
    api_mod.setResultantCollision.restype = c_int
    ret = api_mod.setResultantCollision(force, bytes(ipAddress.encode('utf-8')))
    return message(ret)
'''
# discards in medical-v2.8
def setJointImpedance(arrStiff, arrDamp, ipAddress = ''):
    jointStiff = DIANA_JOINT_STIFF()
    jointStiff.values = (c_double*7)()
    for index in range(0, len(arrStiff)):
        jointStiff.values[index] = arrStiff[index]
    jointDamp = DIANA_JOINT_DAMP()
    jointDamp.values = (c_double*7)()
    for index in range(0, len(arrDamp)):
        jointDamp.values[index] = arrDamp[index]
    api_mod.setJointImpedance.argtypes = [
        POINTER(DIANA_JOINT_STIFF), POINTER(DIANA_JOINT_DAMP), c_char_p]
    api_mod.setJointImpedance.restype = c_int
    ret = api_mod.setJointImpedance(jointStiff, jointDamp, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def getJointImpedance(arrStiff, arrDamp, ipAddress = ''):
    jointStiff = DIANA_JOINT_STIFF()
    jointStiff.values = (c_double*7)()
    jointDamp = DIANA_JOINT_DAMP()
    jointDamp.values = (c_double*7)()
    api_mod.getJointImpedance.argtypes = [
        POINTER(DIANA_JOINT_STIFF), POINTER(DIANA_JOINT_DAMP), c_char_p]
    api_mod.getJointImpedance.restype = c_int
    ret = api_mod.getJointImpedance(byref(jointStiff), byref(jointDamp), bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(arrStiff)):
        arrStiff[index] = jointStiff.values[index]
    for index in range(0, len(arrDamp)):
        arrDamp[index] = jointDamp.values[index]
    return message(ret)

def setCartImpedance(arrStiff, arrDamp, ipAddress = ''):
    cartStiff = DIANA_CART_STIFF()
    cartStiff.values = (c_double*6)()
    for index in range(0, len(cartStiff.values)):
        cartStiff.values[index] = arrStiff[index]
    cartDamp = DIANA_CART_DAMP()
    cartDamp.values = (c_double*6)()
    for index in range(0, len(cartDamp.values)):
        cartDamp.values[index] = arrDamp[index]
    api_mod.setCartImpedance.argtypes = [
        POINTER(DIANA_CART_STIFF), POINTER(DIANA_CART_DAMP), c_char_p]
    api_mod.setCartImpedance.restype = c_int
    ret = api_mod.setCartImpedance(cartStiff, cartDamp, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def getCartImpedance(arrStiff, arrDamp, ipAddress = ''):
    cartStiff = DIANA_CART_STIFF()
    cartStiff.values = (c_double*6)()
    cartDamp = DIANA_CART_DAMP()
    cartDamp.values = (c_double*6)()
    api_mod.getCartImpedance.argtypes = [
        POINTER(DIANA_CART_STIFF), POINTER(DIANA_CART_DAMP), c_char_p]
    api_mod.getCartImpedance.restype = c_int
    ret = api_mod.getCartImpedance(byref(cartStiff), byref(cartDamp), bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(cartStiff.values)):
       arrStiff[index] = cartStiff.values[index]
    for index in range(0, len(cartDamp.values)):
        arrDamp[index] = cartDamp.values[index]
    return message(ret)
'''

def zeroSpaceFreeDriving(enable, ipAddress = ''):
    api_mod.zeroSpaceFreeDriving.argtypes = [c_bool, c_char_p]
    api_mod.zeroSpaceFreeDriving.restype = c_int
    ret = api_mod.zeroSpaceFreeDriving(enable, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def createPath(id_type, ipAddress = ''):
    id_path = c_uint()
    api_mod.createPath.argtypes = [c_int, POINTER(c_uint), c_char_p]
    api_mod.createPath.restype = c_int
    ret = api_mod.createPath(id_type, byref(id_path), bytes(ipAddress.encode('utf-8')))
    return ret, id_path

def addMoveL(id_path, joints, vel, acc, blendradius, ipAddress = ''):
    dianaJointPos = DIANA_JOINTS_POSITION()
    dianaJointPos.values = (c_double * 7)()
    for index in range(0, len(joints)):
        dianaJointPos.values[index] = joints[index]
    api_mod.addMoveL.argtypes = [c_uint, POINTER(
        DIANA_JOINTS_POSITION), c_double, c_double, c_double, c_char_p]
    api_mod.addMoveL.restype = c_int
    ret = api_mod.addMoveL(id_path, dianaJointPos, vel, acc, blendradius, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def addMoveJ(id_path, joints, vel, acc, blendradius, ipAddress = ''):
    dianaJointPos = DIANA_JOINTS_POSITION()
    dianaJointPos.values = (c_double * 7)()
    for index in range(0, len(joints)):
        dianaJointPos.values[index] = joints[index]
    api_mod.addMoveJ.argtypes = [c_uint, POINTER(
        DIANA_JOINTS_POSITION), c_double, c_double, c_double, c_char_p]
    api_mod.addMoveJ.restype = c_int
    ret = api_mod.addMoveJ(id_path, dianaJointPos, vel, acc, blendradius, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def runPath(id_path, ipAddress = ''):
    api_mod.runPath.argtypes = [c_uint, c_char_p]
    api_mod.runPath.restype = c_int
    ret = api_mod.runPath(id_path, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def destroyPath(id_path, ipAddress = ''):
    api_mod.destroyPath.argtypes = [c_uint, c_char_p]
    api_mod.destroyPath.restype = c_int
    ret = api_mod.destroyPath(id_path, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def rpy2Axis(arr):
    _rpy = DIANA_RPY_VECTOR()
    _rpy.values = (c_double*3)()
    for index in range(0, len(_rpy.values)):
        _rpy.values[index] = arr[index]
    api_mod.rpy2Axis.argtypes = [POINTER(DIANA_RPY_VECTOR)]
    api_mod.rpy2Axis.restype = c_int
    ret = api_mod.rpy2Axis(byref(_rpy))
    for index in range(0, len(_rpy.values)):
        arr[index] = _rpy.values[index]
    return message(ret)

def axis2RPY(arr):
    _axis = DIANA_AXIS_VECTOR()
    _axis.values = (c_double*3)()
    for index in range(0, len(_axis.values)):
        _axis.values[index] = arr[index]
    api_mod.axis2RPY.argtypes = [POINTER(DIANA_AXIS_VECTOR)]
    api_mod.axis2RPY.restype = c_int
    ret = api_mod.axis2RPY(byref(_axis))
    for index in range(0, len(_axis.values)):
        arr[index] = _axis.values[index]
    return message(ret)

def homogeneous2Pose(matrix, pose):
    _matrix = DIANA_FRAME_MATRIX()
    _matrix.values = (c_double*16)()
    for index in range(0, len(_matrix.values)):
        _matrix.values[index] = matrix[index]
    _pose = DIANA_TCP_POSE()
    _pose.values = (c_double*6)()
    api_mod.homogeneous2Pose.argtypes = [
        POINTER(DIANA_FRAME_MATRIX), POINTER(DIANA_TCP_POSE)]
    api_mod.homogeneous2Pose.restype = c_int
    ret = api_mod.homogeneous2Pose(_matrix, byref(_pose))
    for index in range(0, len(_pose.values)):
        pose[index] = _pose.values[index]
    return message(ret)

def pose2Homogeneous(pose, matrix):
    _pose = DIANA_TCP_POSE()
    _pose.values = (c_double*6)()
    for index in range(0, len(_pose.values)):
        _pose.values[index] = pose[index]
    _matrix = DIANA_FRAME_MATRIX()
    _matrix.values = (c_double*16)()
    api_mod.pose2Homogeneous.argtypes = [
        POINTER(DIANA_TCP_POSE), POINTER(DIANA_FRAME_MATRIX)]
    api_mod.pose2Homogeneous.restype = c_int
    ret = api_mod.pose2Homogeneous(_pose, byref(_matrix))
    for index in range(0, len(_matrix.values)):
        matrix[index] = _matrix.values[index]
    return message(ret)

def enableTorqueReceiver(bEnable, ipAddress = ''):
    api_mod.enableTorqueReceiver.restype = c_int
    api_mod.enableTorqueReceiver.argtypes = [ c_bool, c_char_p]
    ret = api_mod.enableTorqueReceiver(bEnable, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def sendTorque_rt(torque,t, ipAddress = ''):
    jnt_torque = DIANA_JOINT_TORQUE()
    jnt_torque.values = (c_double*7)()
    for index in range(0, len(torque)):
        jnt_torque.values[index] = torque[index]
    api_mod.sendTorque_rt.restype = c_int
    api_mod.sendTorque_rt.argtypes = [ POINTER(DIANA_JOINT_TORQUE),c_double, c_char_p]
    ret = api_mod.sendTorque_rt(byref(jnt_torque),t, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def enableCollisionDetection(enable, ipAddress = ''):
    api_mod.enableCollisionDetection.argtypes = [c_bool, c_char_p]
    api_mod.enableCollisionDetection.restype = c_int
    ret = api_mod.enableCollisionDetection(enable, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def setActiveTcpPayload(payload, ipAddress = ''):
    tcpPayload = DIANA_TCP_PAYLOAD()
    tcpPayload.values = (c_double*10)()
    for index in range(0, len(tcpPayload.values)):
        tcpPayload.values[index] = payload[index]
    api_mod.setActiveTcpPayload.argtypes = [POINTER(DIANA_TCP_PAYLOAD), c_char_p]
    api_mod.setActiveTcpPayload.restype = c_int
    ret = api_mod.setActiveTcpPayload(tcpPayload, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def servoJ(joints_pos, t=0.01, ah_t=0.01, gain=300, ipAddress = ''):
    dianaJointsPosition = DIANA_JOINTS_POSITION()
    dianaJointsPosition.values = (c_double * 7)()
    for index in range(0, len(joints_pos)):
        dianaJointsPosition.values[index] = joints_pos[index]
    api_mod.servoJ.argtypes = [
        POINTER(DIANA_JOINTS_POSITION), c_double, c_double, c_double, c_char_p]
    api_mod.servoJ.restype = c_int
    ret = api_mod.servoJ(dianaJointsPosition, t, ah_t, gain, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def servoL(tcp_pose, t=0.01, ah_t=0.01, gain=300, scale=1000, ipAddress = ''):
    dianaTcpPose = DIANA_TCP_POSE()
    dianaTcpPose.values = (c_double * 6)()
    for index in range(0, len(dianaTcpPose.values)):
        dianaTcpPose.values[index] = tcp_pose[index]
    active_tcp = c_void_p(0)
    api_mod.servoL.argtypes = [
        POINTER(DIANA_TCP_POSE), c_double, c_double, c_double, c_double, c_void_p, c_char_p]
    api_mod.servoL.restype = c_int
    ret = api_mod.servoL(dianaTcpPose, t, ah_t, gain, scale, active_tcp, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def servoJ_ex(joints_pos, t=0.01, ah_t=0.01, gain=300, realiable=False, ipAddress = ''):
    dianaJointsPosition = DIANA_JOINTS_POSITION()
    dianaJointsPosition.values = (c_double * 7)()
    for index in range(0, len(joints_pos)):
        dianaJointsPosition.values[index] = joints_pos[index]
    api_mod.servoJ_ex.argtypes = [
        POINTER(DIANA_JOINTS_POSITION), c_double, c_double, c_double, c_bool, c_char_p]
    api_mod.servoJ_ex.restype = c_int
    ret = api_mod.servoJ_ex(dianaJointsPosition, t, ah_t, gain, realiable, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def servoL_ex(tcp_pose, t=0.01, ah_t=0.01, gain=300, scale=1000, realiable=False, ipAddress = ''):
    dianaTcpPose = DIANA_TCP_POSE()
    dianaTcpPose.values = (c_double * 6)()
    for index in range(0, len(dianaTcpPose.values)):
        dianaTcpPose.values[index] = tcp_pose[index]
    active_tcp = c_void_p(0)
    api_mod.servoL_ex.argtypes = [POINTER(
        DIANA_TCP_POSE), c_double, c_double, c_double, c_double, c_void_p, c_bool, c_char_p]
    api_mod.servoL_ex.restype = c_int
    ret = api_mod.servoL_ex(dianaTcpPose, t, ah_t, gain,
                         scale, active_tcp, realiable, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def speedJ_ex(speed, acc, t=0.0, realiable=False, ipAddress = ''):
    dianaJointsSpeed = DIANA_JOINTS_SPEED()
    dianaJointsSpeed.values = (c_double * 7)()
    for index in range(0, len(speed)):
        dianaJointsSpeed.values[index] = speed[index]
    api_mod.speedJ_ex.argtypes = [
        POINTER(DIANA_JOINTS_SPEED), c_double, c_double, c_bool, c_char_p]
    api_mod.speedJ_ex.restype = c_int
    ret = api_mod.speedJ_ex(dianaJointsSpeed, acc, t, realiable, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def speedL_ex(speed, acc, t=0.0, realiable=False, ipAddress = ''):
    dianaJointsSpeed = DIANA_JOINTS_SPEED_L()
    dianaJointsSpeed.values = (c_double * 6)()
    for index in range(0, len(dianaJointsSpeed.values)):
        dianaJointsSpeed.values[index] = speed[index]
    dianaJointsAcc = DIANA_JOINTS_ACC()
    dianaJointsAcc.values = (c_double * 2)()
    for index in range(0, len(dianaJointsAcc.values)):
        dianaJointsAcc.values[index] = acc[index]
    active_tcp = c_void_p(0)
    api_mod.speedL_ex.argtypes = [POINTER(DIANA_JOINTS_SPEED_L), POINTER(
        DIANA_JOINTS_ACC), c_double, c_void_p, c_bool, c_char_p]
    api_mod.speedL_ex.restype = c_int
    ret = api_mod.speedL_ex(dianaJointsSpeed, dianaJointsAcc,
                         t, active_tcp, realiable, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def dumpToUDisk(ipAddress = ''):
    api_mod.dumpToUDisk.argtypes = [c_char_p]
    api_mod.dumpToUDisk.restype = c_int
    ret = api_mod.dumpToUDisk(bytes(ipAddress.encode('utf-8')))
    return message(ret)

def inverse_ext(ref_joints, pose, joints, ipAddress = ''):
    refJointsPosition = DIANA_JOINTS_POSITION()
    refJointsPosition.values = (c_double * 7)()
    for index in range(0, len(ref_joints)):
        refJointsPosition.values[index] = ref_joints[index]
    dianaTcpPose = DIANA_TCP_POSE()
    dianaTcpPose.values = (c_double * 6)()
    for index in range(0, len(dianaTcpPose.values)):
        dianaTcpPose.values[index] = pose[index]
    dianaJointsPosition = DIANA_JOINTS_POSITION()
    dianaJointsPosition.values = (c_double * 7)()
    active_tcp = c_void_p(0)
    api_mod.inverse_ext.argtypes = [POINTER(DIANA_JOINTS_POSITION), POINTER(DIANA_TCP_POSE), POINTER(
        DIANA_JOINTS_POSITION),  c_void_p, c_char_p]
    api_mod.inverse_ext.restype = c_int
    ret = api_mod.inverse_ext(refJointsPosition, dianaTcpPose,
                           byref(dianaJointsPosition), active_tcp, bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(joints)):
        joints[index] = dianaJointsPosition.values[index]
    return message(ret)

## ToDo: check all python Api
def getJointLinkPos(joints, ipAddress = ''):
    dianaJointPos = DIANA_JOINTS_POSITION()
    dianaJointPos.values = (c_double*7)()
    for index in range(0, len(joints)):
        dianaJointPos.values[index] = joints[index]
    api_mod.getJointLinkPos.argtypes = [POINTER(DIANA_JOINTS_POSITION), c_char_p]
    api_mod.getJointLinkPos.restype = c_int
    ret = api_mod.getJointLinkPos(byref(dianaJointPos), bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(joints)):
        joints[index] = dianaJointPos.values[index]
    return message(ret)

def createComplexPath(path_type, ipAddress = ''):
    complex_path_id = c_uint()
    api_mod.createComplexPath.argtypes = [c_int, POINTER(c_uint), c_char_p]
    api_mod.createComplexPath.restype = c_int
    ret = api_mod.createComplexPath(path_type.value, byref(complex_path_id), bytes(ipAddress.encode('utf-8')))
    return ret, complex_path_id

def addMoveLSegmentByTarget(complex_path_id, joints, vel, acc, blendradius, ipAddress = ''):
    dianaJointPos = DIANA_JOINTS_POSITION()
    dianaJointPos.values = (c_double * 7)()
    for index in range(0, len(joints)):
        dianaJointPos.values[index] = joints[index]
    api_mod.addMoveLByTarget.argtypes = [c_uint, POINTER(
        DIANA_JOINTS_POSITION), c_double, c_double, c_double, c_char_p]
    api_mod.addMoveLByTarget.restype = c_int
    ret = api_mod.addMoveLByTarget(
        complex_path_id, dianaJointPos, vel, acc, blendradius, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def addMoveLSegmentByPose(complex_path_id, pose, vel, acc, blendradius, ipAddress = ''):
    dianaTcpPose = DIANA_TCP_POSE()
    dianaTcpPose.values = (c_double * 6)()
    for index in range(0, len(dianaTcpPose.values)):
        dianaTcpPose.values[index] = pose[index]
    api_mod.addMoveLByPose.argtypes = [c_uint, POINTER(
        DIANA_TCP_POSE), c_double, c_double, c_double, c_char_p]
    api_mod.addMoveLByPose.restype = c_int
    ret = api_mod.addMoveLByPose(
        complex_path_id, dianaTcpPose, vel, acc, blendradius, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def addMoveJSegmentByTarget(complex_path_id, joints, vel_percent, acc_percent, blendradius_percent, ipAddress = ''):
    dianaJointPos = DIANA_JOINTS_POSITION()
    dianaJointPos.values = (c_double * 7)()
    for index in range(0, len(joints)):
        dianaJointPos.values[index] = joints[index]
    api_mod.addMoveJByTarget.argtypes = [c_uint, POINTER(
        DIANA_JOINTS_POSITION), c_double, c_double, c_double, c_char_p]
    api_mod.addMoveJByTarget.restype = c_int
    ret = api_mod.addMoveJByTarget(
        complex_path_id, dianaJointPos, vel_percent, acc_percent, blendradius_percent, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def addMoveJSegmentByPose(complex_path_id, pose, vel_percent, acc_percent, blendradius_percent, ipAddress = ''):
    dianaTcpPose = DIANA_TCP_POSE()
    dianaTcpPose.values = (c_double * 6)()
    for index in range(0, len(dianaTcpPose.values)):
        dianaTcpPose.values[index] = pose[index]
    api_mod.addMoveJByPose.argtypes = [c_uint, POINTER(
        DIANA_TCP_POSE), c_double, c_double, c_double, c_char_p]
    api_mod.addMoveJByPose.restype = c_int
    ret = api_mod.addMoveJByPose(
        complex_path_id, dianaTcpPose, vel_percent, acc_percent, blendradius_percent, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def addMoveCSegmentByTarget(complex_path_id, pass_joints, target_joints, vel, acc, blendradius, ignore_rotation, ipAddress = ''):
    dianaPassJointPos = DIANA_JOINTS_POSITION()
    dianaPassJointPos.values = (c_double * 7)()
    dianaTargetJointPos = DIANA_JOINTS_POSITION()
    dianaTargetJointPos.values = (c_double * 7)()
    for index in range(0, len(pass_joints)):
        dianaPassJointPos.values[index] = pass_joints[index]
    for index in range(0, len(target_joints)):
        dianaTargetJointPos.values[index] = target_joints[index]
    api_mod.addMoveCByTarget.argtypes = [c_uint, POINTER(DIANA_JOINTS_POSITION), POINTER(
        DIANA_JOINTS_POSITION), c_double, c_double, c_double, c_bool, c_char_p]
    api_mod.addMoveCByTarget.restype = c_int
    ret = api_mod.addMoveCByTarget(complex_path_id, dianaPassJointPos,
                                dianaTargetJointPos, vel, acc, blendradius, ignore_rotation, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def addMoveCSegmentByPose(complex_path_id, pass_pose, target_pose, vel, acc, blendradius, ignore_rotation, ipAddress = ''):
    dianaPassTcpPose = DIANA_TCP_POSE()
    dianaPassTcpPose.values = (c_double * 6)()
    dianaTargetTcpPose = DIANA_TCP_POSE()
    dianaTargetTcpPose.values = (c_double * 6)()
    for index in range(0, len(dianaPassTcpPose.values)):
        dianaPassTcpPose.values[index] = pass_pose[index]
    for index in range(0, len(dianaTargetTcpPose.values)):
        dianaTargetTcpPose.values[index] = target_pose[index]
    api_mod.addMoveCByPose.argtypes = [c_uint, POINTER(DIANA_TCP_POSE), POINTER(
        DIANA_TCP_POSE), c_double, c_double, c_double, c_bool, c_char_p]
    api_mod.addMoveCByPose.restype = c_int
    ret = api_mod.addMoveCByPose(complex_path_id, dianaPassTcpPose,
                              dianaTargetTcpPose, vel, acc, blendradius, ignore_rotation, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def runComplexPath(complex_path_id, ipAddress = ''):
    api_mod.runComplexPath.argtypes = [c_uint, c_char_p]
    api_mod.runComplexPath.restype = c_int
    ret = api_mod.runComplexPath(complex_path_id, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def destroyComplexPath(complex_path_id, ipAddress = ''):
    api_mod.destroyComplexPath.argtypes = [c_uint, c_char_p]
    api_mod.destroyComplexPath.restype = c_int
    ret = api_mod.destroyComplexPath(complex_path_id, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def saveEnvironment(ipAddress = ''):
    api_mod.saveEnvironment.argtypes = [c_char_p]
    api_mod.saveEnvironment.restype = c_int
    ret = api_mod.saveEnvironment(bytes(ipAddress.encode('utf-8')))
    return message(ret)

def moveTcpBaseLinearRelative(pose, v, a, ipAddress = ''):
    dianaTcpPose = DIANA_TCP_POSE()
    dianaTcpPose.values = (c_double * 6)()
    for index in range(0, len(dianaTcpPose.values)):
        dianaTcpPose.values[index] = pose[index]
    api_mod.moveTcpBaseLinearRelative.argtypes = [POINTER(
        DIANA_TCP_POSE), c_double, c_double, c_char_p]
    api_mod.moveTcpBaseLinearRelative.restype = c_int
    ret = api_mod.moveTcpBaseLinearRelative(dianaTcpPose, v, a, bytes(ipAddress.encode('utf-8')))

def dumpToUDiskEx(timeout_second, ipAddress = ''):
    api_mod.dumpToUDiskEx.restype = c_int
    api_mod.dumpToUDiskEx.argtypes = [c_double, c_char_p]
    ret = api_mod.dumpToUDiskEx(timeout_second, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def enterForceMode_ex(forceDirection,forceValue,maxApproachVelocity,maxAllowTcpOffset,active_tcp, ipAddress = ''):
    arr_ForceDirection = DIANA_FORCE_DIRECTION()
    arr_ForceDirection.values = (c_double*3)()
    for index in range(0, len(arr_ForceDirection.values)):
        arr_ForceDirection.values[index] = forceDirection[index]
    ret = 0
    if active_tcp==None:
        use_active_tcp = c_void_p(0)
        api_mod.enterForceMode_ex.restype = c_int
        api_mod.enterForceMode_ex.argtypes = [POINTER(
            DIANA_FORCE_DIRECTION), c_double, c_double, c_double, c_void_p, c_char_p]
        ret = api_mod.enterForceMode_ex(byref(
            arr_ForceDirection), forceValue, maxApproachVelocity, maxAllowTcpOffset, use_active_tcp, bytes(ipAddress.encode('utf-8')))
    else:
        arr_Active_Tcp = DIANA_ACTIVE_TCP()
        arr_Active_Tcp.values = (c_double*6)()
        for index in range(0, len(arr_Active_Tcp.values)):
            arr_Active_Tcp.values[index] = active_tcp[index]
        api_mod.enterForceMode_ex.restype = c_int
        api_mod.enterForceMode_ex.argtypes = [POINTER(
            DIANA_FORCE_DIRECTION), c_double, c_double, c_double, POINTER(DIANA_ACTIVE_TCP), c_char_p]
        ret = api_mod.enterForceMode_ex(byref(
            arr_ForceDirection), forceValue, maxApproachVelocity, maxAllowTcpOffset, byref(arr_Active_Tcp), bytes(ipAddress.encode('utf-8')))
    return message(ret)

def readDI(group_name, di_name, ipAddress = ''):
    DIValue = c_int()
    api_mod.readDI.argtypes = [c_char_p, c_char_p, POINTER(c_int), c_char_p]
    api_mod.readDI.restype = c_int
    ret = api_mod.readDI(bytes(group_name, encoding = 'utf-8'), bytes(di_name, encoding = 'utf-8'), byref(DIValue), bytes(ipAddress.encode('utf-8')))
    return ret, DIValue

def readAI(group_name, di_name, ipAddress = ''):
    AIValue = c_double()
    AIMode = c_int()
    api_mod.readAI.argtypes = [c_char_p, c_char_p, POINTER(c_int),POINTER(c_double), c_char_p]
    api_mod.readAI.restype = c_int
    ret = api_mod.readAI(bytes(group_name, encoding = 'utf-8'), bytes(di_name, encoding = 'utf-8'), byref(AIMode),byref(AIValue), bytes(ipAddress.encode('utf-8')))
    return ret, AIMode, AIValue

def setAIMode(group_name, di_name,mode, ipAddress = ''):
    api_mod.setAIMode.argtypes = [c_char_p, c_char_p, c_int, c_char_p]
    api_mod.setAIMode.restype = c_int
    ret = api_mod.setAIMode(bytes(group_name, encoding = 'utf-8'), bytes(di_name, encoding = 'utf-8'),mode, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def writeDO(group_name, di_name,value, ipAddress = ''):
    api_mod.writeDO.argtypes = [c_char_p, c_char_p, c_int, c_char_p]
    api_mod.writeDO.restype = c_int
    ret = api_mod.writeDO(bytes(group_name, encoding = 'utf-8'), bytes(di_name, encoding = 'utf-8'),value, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def writeAO(group_name, di_name,mode,value, ipAddress = ''):
    api_mod.writeAO.argtypes = [c_char_p, c_char_p, c_int, c_double, c_char_p]
    api_mod.writeAO.restype = c_int
    ret = api_mod.writeAO(bytes(group_name, encoding = 'utf-8'), bytes(di_name, encoding = 'utf-8'),mode,value, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def readBusCurrent(ipAddress = ''):
    Current = c_double()
    api_mod.readBusCurrent.argtypes = [POINTER(c_double), c_char_p]
    api_mod.readBusCurrent.restype = c_int
    ret = api_mod.readBusCurrent(byref(Current), bytes(ipAddress.encode('utf-8')))
    return ret, Current

def readBusVoltage(ipAddress = ''):
    Voltage = c_double()
    api_mod.readBusVoltage.argtypes = [POINTER(c_double), c_char_p]
    api_mod.readBusVoltage.restype = c_int
    ret = api_mod.readBusVoltage(byref(Voltage), bytes(ipAddress.encode('utf-8')))
    return ret, Voltage

def getDH(aDH,alphaDH,dDH,thetaDH, ipAddress = ''):
    arr_aDH = DIANA_DH_A()
    arr_aDH.values = (c_double*7)()
    arr_alphaDH = DIANA_DH_Alpha()
    arr_alphaDH.values = (c_double*7)()
    arr_dDH = DIANA_DH_D()
    arr_dDH.values = (c_double*7)()
    arr_thetaDH = DIANA_DH_Theta()
    arr_thetaDH.values = (c_double*7)()
    api_mod.getDH.restype = c_int
    api_mod.getDH.argtypes = [ POINTER(DIANA_DH_A), 
        POINTER(DIANA_DH_Alpha),POINTER(DIANA_DH_D), POINTER(DIANA_DH_Theta), c_char_p]
    ret = api_mod.getDH(byref(arr_aDH),byref(arr_alphaDH),byref(arr_dDH),byref(arr_thetaDH), bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(aDH)):
       aDH[index] = arr_aDH.values[index]
    for index in range(0, len(alphaDH)):
       alphaDH[index] = arr_alphaDH.values[index]
    for index in range(0, len(dDH)):
       dDH[index] = arr_dDH.values[index]
    for index in range(0, len(thetaDH)):
       thetaDH[index] = arr_thetaDH.values[index]
    return message(ret)

def getOriginalJointTorque(torques, ipAddress = ''):
    jointTorque = DIANA_JOINT_TORQUE()
    jointTorque.values = (c_double*7)()
    api_mod.getOriginalJointTorque.restype = c_int
    api_mod.getOriginalJointTorque.argtypes = [ POINTER(DIANA_JOINT_TORQUE), c_char_p]
    ret = api_mod.getOriginalJointTorque(byref(jointTorque), bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(torques)):
       torques[index] = jointTorque.values[index]
    return message(ret)

def getJacobiMatrix(matrix_jacobi, ipAddress = ''):
    jacobi_matrix = DIANA_JACOBI_MATRIX()
    jacobi_matrix.values = (c_double*42)()
    api_mod.getJacobiMatrix.restype = c_int
    api_mod.getJacobiMatrix.argtypes = [ POINTER(DIANA_JACOBI_MATRIX), c_char_p]
    ret = api_mod.getJacobiMatrix(byref(jacobi_matrix), bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(matrix_jacobi)):
       matrix_jacobi[index] = jacobi_matrix.values[index]
    return message(ret)

def resetDH(ipAddress = ''):
    api_mod.resetDH.argtypes = [c_char_p]
    api_mod.resetDH.restype = c_int
    ret = api_mod.resetDH(bytes(ipAddress.encode('utf-8')))
    return message(ret)

def runProgram(name, ipAddress = ''):
    api_mod.runProgram.argtypes = [c_char_p, c_char_p]
    api_mod.runProgram.restype = c_int
    ret = api_mod.runProgram(bytes(name, encoding = 'utf-8'), bytes(ipAddress.encode('utf-8')))
    return message(ret)

def stopProgram(name, ipAddress = ''):
    api_mod.stopProgram.argtypes = [c_char_p, c_char_p]
    api_mod.stopProgram.restype = c_int
    ret = api_mod.stopProgram(bytes(name, encoding = 'utf-8'), bytes(ipAddress.encode('utf-8')))
    return message(ret)

def getVariableValue(name,ipAddress = ''):
    api_mod.getVariableValue.argtypes = [c_char_p, POINTER(c_double), c_char_p]
    api_mod.getVariableValue.restype = c_int
    value = c_double()
    ret = api_mod.getVariableValue(
        bytes(name, encoding="utf-8"), byref(value), bytes(ipAddress.encode('utf-8')))
    return message(ret), value.value
	

def setVariableValue(name,value, ipAddress = ''):
    api_mod.setVariableValue.argtypes = [c_char_p, POINTER(c_double), c_char_p]
    api_mod.setVariableValue.restype = c_int
    value_d = c_double(0)
    value_d.value = value
    ret = api_mod.setVariableValue(bytes(name, encoding = 'utf-8'),byref(value_d), bytes(ipAddress.encode('utf-8')))
    return message(ret)

def isTaskRunning(name, ipAddress = ''):
    api_mod.isTaskRunning.argtypes = [c_char_p, c_char_p]
    api_mod.isTaskRunning.restype = c_int
    ret = api_mod.isTaskRunning(bytes(name, encoding = 'utf-8'), bytes(ipAddress.encode('utf-8')))
    if(ret == -1):
        return False
    else:
        return message(ret)

def pauseProgram(ipAddress = ''):
    api_mod.pauseProgram.argtypes = [c_char_p]
    api_mod.pauseProgram.restype = c_int
    ret = api_mod.pauseProgram(bytes(ipAddress.encode('utf-8')))
    return message(ret)

def resumeProgram(ipAddress = ''):
    api_mod.resumeProgram.argtypes = [c_char_p]
    api_mod.resumeProgram.restype = c_int
    ret = api_mod.resumeProgram(bytes(ipAddress.encode('utf-8')))
    return message(ret)

def stopAllProgram(ipAddress = ''):
    api_mod.stopAllProgram.argtypes = [c_char_p]
    api_mod.stopAllProgram.restype = c_int
    ret = api_mod.stopAllProgram(bytes(ipAddress.encode('utf-8')))
    if(ret == -1):
        return False
    else:
        return message(ret)

def isAnyTaskRunning(ipAddress = ''):
    api_mod.isAnyTaskRunning.argtypes = [c_char_p]
    api_mod.isAnyTaskRunning.restype = c_int
    ret = api_mod.isAnyTaskRunning(bytes(ipAddress.encode('utf-8')))
    return message(ret)

def cleanErrorInfo(ipAddress = ''):
    api_mod.cleanErrorInfo.argtypes = [c_char_p]
    api_mod.cleanErrorInfo.restype = c_int
    ret = api_mod.cleanErrorInfo(bytes(ipAddress.encode('utf-8')))
    return message(ret)

def setCollisionLevel(level, ipAddress = ''):
    api_mod.setCollisionLevel.argtypes = [c_int, c_char_p]
    api_mod.setCollisionLevel.restype = c_int
    ret = api_mod.setCollisionLevel(level, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def zeroSpaceManualMove(direction, dblJointsVel, dblJointAcc, ipAddress=''):
    if not isinstance(direction, zero_space_move_direction):
        raise TypeError(
            'direction must be an instance of zero_space_move_direction Enum')
    joint_vel = DIANA_JOINT_ANGULAR_VEL()
    joint_vel.values = (c_double*7)()
    for index in range(0, len(dblJointsVel)):
        joint_vel.values[index] = dblJointsVel[index]
    joint_acc = DIANA_JOINT_ACC()
    joint_acc.values = (c_double*7)()
    for index in range(0, len(joint_acc.values)):
        joint_acc.values[index] = dblJointAcc[index]
    api_mod.zeroSpaceManualMove.argtypes = [c_int, POINTER(
        DIANA_JOINT_ANGULAR_VEL), POINTER(DIANA_JOINT_ACC), c_char_p]
    api_mod.zeroSpaceManualMove.restype = c_int
    ret = api_mod.zeroSpaceManualMove(
        direction.value, byref(joint_vel),byref(joint_acc), bytes(ipAddress.encode('utf-8')))
    return message(ret)

def getHomingState(ipAddress = ''):
    api_mod.getHomingState.argtypes = [c_char_p]
    api_mod.getHomingState.restype = c_int
    ret = api_mod.getHomingState(bytes(ipAddress.encode('utf-8')))
    return ret

def startHoming(ipAddress = ''):
    api_mod.startHoming.argtypes = [c_char_p]
    api_mod.startHoming.restype = c_int
    ret = api_mod.startHoming(bytes(ipAddress.encode('utf-8')))
    return message(ret)

def updateForce(forceValue, ipAddress = ''):
    api_mod.updateForce.restype = c_int
    api_mod.updateForce.argtypes = [c_double, c_char_p]
    ret = api_mod.updateForce(forceValue, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def getCartImpedanceCoordinateType(ipAddress = ''):
    api_mod.getCartImpedanceCoordinateType.argtypes = [c_char_p]
    api_mod.getCartImpedanceCoordinateType.restype = c_int
    ret = api_mod.getCartImpedanceCoordinateType(bytes(ipAddress.encode('utf-8')))
    return ret

def setCartImpedanceCoordinateType(intCoordinateType, ipAddress = ''):
    api_mod.setCartImpedanceCoordinateType.argtypes = [c_int, c_char_p]
    api_mod.setCartImpedanceCoordinateType.restype = c_int
    ret = api_mod.setCartImpedanceCoordinateType(intCoordinateType, bytes(ipAddress.encode('utf-8')))
    return ret

def inverseClosedFull(pose, lock_joint_index, lock_joint_position, ref_joints, active_tcp, ipAddress=''):
    refJointsPosition = DIANA_JOINTS_POSITION()
    refJointsPosition.values = (c_double * 7)()
    for index in range(0, len(ref_joints)):
        refJointsPosition.values[index] = ref_joints[index]
    dianaPose = DIANA_TCP_POSE()
    dianaPose.values = (c_double * 6)()
    for index in range(0, len(pose)):
        dianaPose.values[index] = pose[index]
    arrActiveTcp = DIANA_ACTIVE_TCP()
    arrActiveTcp.values = (c_double*6)()
    for index in range(0, len(arrActiveTcp.values)):
        arrActiveTcp.values[index] = active_tcp[index]
    api_mod.inverseClosedFull.argtypes = [POINTER(DIANA_TCP_POSE),c_int,c_double,POINTER(DIANA_JOINTS_POSITION),POINTER(DIANA_ACTIVE_TCP), c_char_p]
    api_mod.inverseClosedFull.restype = c_int
    id = api_mod.inverseClosedFull(byref(dianaPose),lock_joint_index,lock_joint_position,refJointsPosition, byref(arrActiveTcp), bytes(ipAddress.encode('utf-8')))
    return id

def getInverseClosedResultSize(id, ipAddress=''):
    api_mod.getInverseClosedResultSize.argtypes = [c_int, c_char_p]
    api_mod.getInverseClosedResultSize.restype = c_int
    size = api_mod.getInverseClosedResultSize(id, bytes(ipAddress.encode('utf-8')))
    return size

def getInverseClosedJoints(id, index, joints, ipAddress=''):
    dianaJoints = DIANA_JOINTS_POSITION()
    dianaJoints.values = (c_double * 7)()
    api_mod.getInverseClosedJoints.argtypes = [c_int, c_int, POINTER(DIANA_JOINTS_POSITION), c_char_p]
    api_mod.getInverseClosedJoints.restype = c_int
    size = api_mod.getInverseClosedJoints(id, index, dianaJoints, bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(joints)):
        joints[index] = dianaJoints.values[index]
    return size

def destoryInverseClosedItems(id, ipAddress=''):
    api_mod.destoryInverseClosedItems.argtypes = [c_int, c_char_p]
    api_mod.destoryInverseClosedItems.restype = c_int
    ret = api_mod.destoryInverseClosedItems(id, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def calculateJacobi(matrixJacobi, joints, ipAddress=''):
    dianaJoints = DIANA_JOINTS_POSITION()
    dianaJoints.values = (c_double * 7)()
    for index in range(0, len(joints)):
        dianaJoints.values[index] = joints[index]
    dianaJacobiMatrix = DIANA_JACOBI_MATRIX()
    dianaJacobiMatrix.values = (c_double * 42)()
    api_mod.calculateJacobi.argtypes = [POINTER(DIANA_JACOBI_MATRIX), POINTER(DIANA_JOINTS_POSITION), c_int, c_char_p]
    api_mod.calculateJacobi.restype = c_int
    ret = api_mod.calculateJacobi(byref(dianaJacobiMatrix), dianaJoints, 7, bytes(ipAddress.encode('utf-8')))
    if ret < 0:
        return message(ret)
    for index in range(0, len(matrixJacobi)):
        matrixJacobi[index] = dianaJacobiMatrix.values[index]
    return message(ret)
                             
def calculateJacobiTF(matrixJacobi, joints, toolMatrix, ipAddress=''):
    dianaJoints = DIANA_JOINTS_POSITION()
    dianaJoints.values = (c_double * 7)()
    for index in range(0, len(joints)):
        dianaJoints.values[index] = joints[index]
    dianaToolMatrix = DIANA_ACTIVE_TCP()
    dianaToolMatrix.values = (c_double * 6)()
    for index in range(0, len(toolMatrix)):
        dianaToolMatrix.values[index] = toolMatrix[index]
    dianaJacobiMatrix = DIANA_JACOBI_MATRIX()
    dianaJacobiMatrix.values = (c_double * 42)()
    api_mod.calculateJacobiTF.argtypes = [POINTER(DIANA_JACOBI_MATRIX),POINTER(DIANA_JOINTS_POSITION), c_int, POINTER(DIANA_ACTIVE_TCP), c_char_p]
    api_mod.calculateJacobiTF.restype = c_int
    ret = api_mod.calculateJacobiTF(byref(dianaJacobiMatrix), dianaJoints, 7, dianaToolMatrix, bytes(ipAddress.encode('utf-8')))
    if ret < 0 :
        return message(ret)
    for index in range(0, len(matrixJacobi)):
        matrixJacobi[index] = dianaJacobiMatrix.values[index]
    return message(ret)

def getTcpForceInToolCoordinate(forces, ipAddress=''):
    dianaTcpForce = DIANA_TCP_FORCE()
    dianaTcpForce.values = (c_double * 6)()
    api_mod.getTcpForceInToolCoordinate.argtypes = [POINTER(DIANA_TCP_FORCE), c_char_p]
    api_mod.getTcpForceInToolCoordinate.restype = c_int
    ret = api_mod.getTcpForceInToolCoordinate(byref(dianaTcpForce),
                              bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(dianaTcpForce.values)):
        forces[index] = dianaTcpForce.values[index]
    return message(ret)

def speedLOnTcp(speed, acc, t=0.0, ipAddress=''):
    dianaJointsSpeed = DIANA_JOINTS_SPEED_L()
    dianaJointsSpeed.values = (c_double * 6)()
    for index in range(0, len(dianaJointsSpeed.values)):
        dianaJointsSpeed.values[index] = speed[index]
    dianaJointsAcc = DIANA_JOINTS_ACC()
    dianaJointsAcc.values = (c_double * 2)()
    for index in range(0, len(dianaJointsAcc.values)):
        dianaJointsAcc.values[index] = acc[index]
    active_tcp = c_void_p(0)
    api_mod.speedLOnTcp.argtypes = [POINTER(DIANA_JOINTS_SPEED_L), POINTER(
        DIANA_JOINTS_ACC), c_double, c_void_p, c_char_p]
    api_mod.speedLOnTcp.restype = c_int
    ret = api_mod.speedLOnTcp(dianaJointsSpeed, dianaJointsAcc,
                            t, active_tcp, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def inverseClosedIdeal(pose, lock_robot_arm_angle, ref_joints, active_tcp, ipAddress=''):
    refJointsPosition = DIANA_JOINTS_POSITION()
    refJointsPosition.values = (c_double * 7)()
    for index in range(0, len(ref_joints)):
        refJointsPosition.values[index] = ref_joints[index]
    dianaPose = DIANA_TCP_POSE()
    dianaPose.values = (c_double * 6)()
    for index in range(0, len(pose)):
        dianaPose.values[index] = pose[index]
    arrActiveTcp = DIANA_ACTIVE_TCP()
    arrActiveTcp.values = (c_double*6)()
    for index in range(0, len(arrActiveTcp.values)):
        arrActiveTcp.values[index] = active_tcp[index]
    api_mod.inverseClosedIdeal.argtypes = [POINTER(DIANA_TCP_POSE),c_double,POINTER(DIANA_JOINTS_POSITION),POINTER(DIANA_ACTIVE_TCP), c_char_p]
    api_mod.inverseClosedIdeal.restype = c_int
    id = api_mod.inverseClosedIdeal(byref(dianaPose),lock_robot_arm_angle,refJointsPosition, byref(arrActiveTcp), bytes(ipAddress.encode('utf-8')))
    return id

def getInverseClosedIdealResultSize(id, ipAddress=''):
    api_mod.getInverseClosedIdealResultSize.argtypes = [c_int, c_char_p]
    api_mod.getInverseClosedIdealResultSize.restype = c_int
    size = api_mod.getInverseClosedIdealResultSize(id, bytes(ipAddress.encode('utf-8')))
    return size

def getInverseClosedIdealJoints(id, index, joints, ipAddress=''):
    dianaJoints = DIANA_JOINTS_POSITION()
    dianaJoints.values = (c_double * 7)()
    api_mod.getInverseClosedIdealJoints.argtypes = [c_int, c_int, POINTER(DIANA_JOINTS_POSITION), c_char_p]
    api_mod.getInverseClosedIdealJoints.restype = c_int
    size = api_mod.getInverseClosedIdealJoints(id, index, dianaJoints, bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(joints)):
        joints[index] = dianaJoints.values[index]
    return size

def destoryInverseClosedIdealItems(id, ipAddress=''):
    api_mod.destoryInverseClosedIdealItems.argtypes = [c_int, c_char_p]
    api_mod.destoryInverseClosedIdealItems.restype = c_int
    ret = api_mod.destoryInverseClosedIdealItems(id, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def getWayPoint(waypointName, dblTcppos, dblJoints, strIpAddress=''):
    tcpPose = DIANA_TCP_POSE()
    tcpPose.values = (c_double * 6)()
    joints = DIANA_JOINTS_POSITION()
    joints.values = (c_double * 7)()
    api_mod.getWayPoint.argtypes = [c_char_p, POINTER(DIANA_TCP_POSE), POINTER(DIANA_JOINTS_POSITION), c_char_p]
    api_mod.getWayPoint.restype = c_int
    ret = api_mod.getWayPoint(bytes(waypointName.encode('utf-8')), tcpPose, joints, bytes(strIpAddress.encode('utf-8')))
    for index in range(0, len(dblTcppos)):
        dblTcppos[index] = tcpPose.values[index]
    for index in range(0, len(dblJoints)):
        dblJoints[index] = joints.values[index]
    return ret

def setWayPoint(waypointName, dblTcppos, dblJoints, strIpAddress=''):
    tcpPose = DIANA_TCP_POSE()
    tcpPose.values = (c_double * 6)()
    for index in range(0, len(dblTcppos)):
        tcpPose.values[index] = dblTcppos[index]
    joints = DIANA_JOINTS_POSITION()
    joints.values = (c_double * 7)()
    for index in range(0, len(dblJoints)):
        joints.values[index] = dblJoints[index]
    api_mod.setWayPoint.argtypes = [c_char_p, POINTER(DIANA_TCP_POSE), POINTER(DIANA_JOINTS_POSITION), c_char_p]
    api_mod.setWayPoint.restype = c_int
    ret = api_mod.setWayPoint(bytes(waypointName.encode('utf-8')), tcpPose, joints, bytes(strIpAddress.encode('utf-8')))
    return ret

def addWayPoint(waypointName, dblTcppos, dblJoints, ipAddress=''):
    dianaTcpPose = DIANA_TCP_POSE()
    dianaTcpPose.values = (c_double * 6)()
    for index in range(0, len(dblTcppos)):
        dianaTcpPose.values[index] = dblTcppos[index]
    dianaJointPos = DIANA_JOINTS_POSITION()
    dianaJointPos.values = (c_double * 7)()
    for index in range(0, len(dblJoints)):
        dianaJointPos.values[index] = dblJoints[index]
    api_mod.addWayPoint.restype = c_int
    api_mod.addWayPoint.argtypes = [
        c_char_p, POINTER(DIANA_TCP_POSE), POINTER(DIANA_JOINTS_POSITION), c_char_p]
    ret = api_mod.addWayPoint(
        bytes(waypointName.encode('utf-8')), dianaTcpPose, dianaJointPos, bytes(ipAddress.encode('utf-8')))
    return message(ret)


def deleteWayPoint(waypointName, ipAddress=''):
    api_mod.deleteWayPoint.argtypes = [c_char_p, c_char_p]
    api_mod.deleteWayPoint.restype = c_int
    ret = api_mod.deleteWayPoint(
        bytes(waypointName.encode('utf-8')), bytes(ipAddress.encode('utf-8')))
    return message(ret)

def getSixAxisZeroOffset(offset, ipAddress=''):
    dianaSixAxisZeroOffset = DIANA_SIX_AXIS_ZERO_OFFSET()
    dianaSixAxisZeroOffset.values = (c_double * 10)()
    api_mod.getSixAxisZeroOffset.argtypes = [POINTER(DIANA_SIX_AXIS_ZERO_OFFSET), c_char_p]
    api_mod.getSixAxisZeroOffset.restype = c_int
    ret = api_mod.getSixAxisZeroOffset(dianaSixAxisZeroOffset, bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(dianaSixAxisZeroOffset.values)):
        offset[index] = dianaSixAxisZeroOffset.values[index]
    return message(ret)

def setSixAxisZeroOffset(offset, ipAddress=''):
    dianaSixAxisZeroOffset = DIANA_SIX_AXIS_ZERO_OFFSET()
    dianaSixAxisZeroOffset.values = (c_double * 10)()
    for index in range(0, len(offset)):
        dianaSixAxisZeroOffset.values[index] = offset[index]
    api_mod.setSixAxisZeroOffset.argtypes = [POINTER(DIANA_SIX_AXIS_ZERO_OFFSET), c_char_p]
    api_mod.setSixAxisZeroOffset.restype = c_int
    ret = api_mod.setSixAxisZeroOffset(dianaSixAxisZeroOffset, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def setDefaultActiveWorkpiece(defaultWorkpiece, ipAddress=''):
    defaultWop = DIANA_DEFAULT_WOP()
    defaultWop.values = (c_double*16)()
    for index in range(0, len(defaultWop.values)):
        defaultWop.values[index] = defaultWorkpiece[index]
    api_mod.setDefaultActiveWorkpiece.argtypes = [
        POINTER(DIANA_DEFAULT_WOP), c_char_p]
    api_mod.setDefaultActiveWorkpiece.restype = c_int
    ret = api_mod.setDefaultActiveWorkpiece(
        defaultWop, bytes(ipAddress.encode('utf-8')))
    if(ret == 0):
        print("setDefaultActiveWorkpiece succeeded")
        return True
    else:
        print("setDefaultActiveWorkpiece failed")
        return False

def setDefaultActiveWorkpiecePose(defaultWorkpiecePose, ipAddress = ''):
    defaultWopPose = DIANA_WOP_VECTOR()
    defaultWopPose.values = (c_double * 6)()
    for index in range(0, len(defaultWopPose.values)):
        defaultWopPose.values[index] = defaultWorkpiecePose[index]
    api_mod.setDefaultActiveWorkpiecePose.argtypes = [POINTER(DIANA_WOP_VECTOR), c_char_p]
    api_mod.setDefaultActiveWorkpiecePose.restype = c_int
    ret = api_mod.setDefaultActiveWorkpiecePose(defaultWopPose, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def getDefaultActiveWorkpiece(defaultWorkpiece, ipAddress=''):
    defaultWop = DIANA_DEFAULT_WOP()
    defaultWop.values = (c_double*16)()
    api_mod.getDefaultActiveWorkpiece.argtypes = [
        POINTER(DIANA_DEFAULT_WOP), c_char_p]
    api_mod.getDefaultActiveWorkpiece.restype = c_int
    ret = api_mod.getDefaultActiveWorkpiece(
        defaultWop, bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(defaultWop.values)):
        defaultWorkpiece[index] = defaultWop.values[index]
    return message(ret)

def getDefaultActiveWorkpiecePose(defaultWorkpiecePose, ipAddress = ''):
    defaultWopPose = DIANA_WOP_POSE()
    defaultWopPose.values = (c_double * 6)()
    api_mod.getDefaultActiveWorkpiecePose.argtypes = [POINTER(DIANA_WOP_POSE), c_char_p]
    api_mod.getDefaultActiveWorkpiecePose.restype = c_int
    ret = api_mod.getDefaultActiveWorkpiecePose(byref(defaultWopPose), bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(defaultWopPose.values)):
        defaultWorkpiecePose[index] = defaultWopPose.values[index]
    return message(ret)

def freeDriving_ex(enable, frame_type, force_direction, ipAddress = ''):
    dianaForceDirection = DIANA_FORCE_FULL_DIRECTION()
    dianaForceDirection.values = (c_double * 6)()
    for index in range(0, len(dianaForceDirection.values)):
        dianaForceDirection.values[index] = force_direction[index]
    api_mod.freeDriving_ex.argtypes = [c_bool, c_int, POINTER(DIANA_FORCE_FULL_DIRECTION), c_char_p]
    api_mod.freeDriving_ex.restype = c_int
    ret = api_mod.freeDriving_ex(enable, frame_type, byref(dianaForceDirection), bytes(ipAddress.encode('utf-8')))
    return message(ret)

def setControllerFeatureCode(feature_code, enable, ipAddress=''):
    api_mod.setControllerFeatureCode.argtypes = [c_int, c_bool, c_char_p]
    api_mod.setControllerFeatureCode.restype = c_int
    ret = api_mod.setControllerFeatureCode(feature_code.value, enable, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def testControllerFeature(feature_code, ipAddress=''):
    dianaFeatureCodeState = DIANA_FEATURE_CODE_STATE()
    dianaFeatureCodeState.value = False
    api_mod.testControllerFeature.argtypes = [c_int, POINTER(DIANA_FEATURE_CODE_STATE), c_char_p]
    api_mod.testControllerFeature.restype = c_int
    ret = api_mod.testControllerFeature(feature_code.value, byref(dianaFeatureCodeState), bytes(ipAddress.encode('utf-8')))
    return dianaFeatureCodeState.value

def enableSixAxis(six_axis_in_mode, enable, ipAddress=''):
    dianaSixAxisState = DIANA_SIX_AXIS_STATE()
    dianaSixAxisState.value = False
    api_mod.enableSixAxis.argtypes = [c_int, POINTER(DIANA_SIX_AXIS_STATE), c_char_p]
    api_mod.enableSixAxis.restype = c_int
    ret = api_mod.enableSixAxis(six_axis_in_mode.value, byref(dianaSixAxisState), bytes(ipAddress.encode('utf-8')))
    return dianaSixAxisState.value

def isSixAxisEnabled(six_axis_in_mode, ipAddress=''):
    api_mod.isSixAxisEnabled.argtypes = [c_int, c_char_p]
    api_mod.isSixAxisEnabled.restype = c_bool
    return api_mod.isSixAxisEnabled(six_axis_in_mode.value, bytes(ipAddress.encode('utf-8')))

def getMechanicalJointsPositionRange(arrMin, arrMax, ipAddress = ''):
    jointsMin = DIANA_JOINTS_POSITION()
    jointsMin.values = (c_double*7)()
    jointsMax = DIANA_JOINTS_POSITION()
    jointsMax.values = (c_double*7)()
    api_mod.getMechanicalJointsPositionRange.argtypes = [POINTER(DIANA_JOINTS_POSITION), POINTER(DIANA_JOINTS_POSITION), c_char_p]
    api_mod.getMechanicalJointsPositionRange.restype = c_int
    ret = api_mod.getMechanicalJointsPositionRange(byref(jointsMin), byref(jointsMax), bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(arrMin)):
        arrMin[index] = jointsMin.values[index]
    for index in range(0, len(arrMax)):
        arrMax[index] = jointsMax.values[index]
    return message(ret)

def getMechanicalMaxJointsVel(arrVel, ipAddress = ''):
    jointsVel = DIANA_JOINT_ANGULAR_VEL()
    jointsVel.values = (c_double*7)()
    api_mod.getMechanicalMaxJointsVel.argtypes = [POINTER(DIANA_JOINT_ANGULAR_VEL), c_char_p]
    api_mod.getMechanicalMaxJointsVel.restype = c_int
    ret = api_mod.getMechanicalMaxJointsVel(byref(jointsVel), bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(arrVel)):
        arrVel[index] = jointsVel.values[index]
    return message(ret)

def getMechanicalMaxJointsAcc(arrAcc, ipAddress = ''):
    jointsAcc = DIANA_JOINT_ACC()
    jointsAcc.values = (c_double*7)()
    api_mod.getMechanicalMaxJointsAcc.argtypes = [POINTER(DIANA_JOINT_ACC), c_char_p]
    api_mod.getMechanicalMaxJointsAcc.restype = c_int
    ret = api_mod.getMechanicalMaxJointsAcc(byref(jointsAcc), bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(arrAcc)):
        arrAcc[index] = jointsAcc.values[index]
    return message(ret)

def getMechanicalMaxCartVelAcc(ipAddress = ''):
    cartTranslationVel = c_double()
    cartRotationVel = c_double()
    cartTranslationAcc = c_double()
    cartRotationAcc = c_double()
    api_mod.getMechanicalMaxCartVelAcc.argtypes = [POINTER(c_double), POINTER(c_double), POINTER(c_double), POINTER(c_double), c_char_p]
    api_mod.getMechanicalMaxCartVelAcc.restype = c_int
    ret = api_mod.getMechanicalMaxCartVelAcc(byref(cartTranslationVel), byref(cartRotationVel), byref(cartTranslationAcc), byref(cartRotationAcc), bytes(ipAddress.encode('utf-8')))
    return message(ret),cartTranslationVel.value,cartRotationVel.value,cartTranslationAcc.value,cartRotationAcc.value

def getJointsPositionRange(arrMin, arrMax, ipAddress = ''):
    jointsMin = DIANA_JOINTS_POSITION()
    jointsMin.values = (c_double*7)()
    jointsMax = DIANA_JOINTS_POSITION()
    jointsMax.values = (c_double*7)()
    api_mod.getJointsPositionRange.argtypes = [POINTER(DIANA_JOINTS_POSITION), POINTER(DIANA_JOINTS_POSITION), c_char_p]
    api_mod.getJointsPositionRange.restype = c_int
    ret = api_mod.getJointsPositionRange(byref(jointsMin), byref(jointsMax), bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(arrMin)):
        arrMin[index] = jointsMin.values[index]
    for index in range(0, len(arrMax)):
        arrMax[index] = jointsMax.values[index]
    return message(ret)

def getMaxJointsVel(arrVel, ipAddress = ''):
    jointsVel = DIANA_JOINT_ANGULAR_VEL()
    jointsVel.values = (c_double*7)()
    api_mod.getMaxJointsVel.argtypes = [POINTER(DIANA_JOINT_ANGULAR_VEL), c_char_p]
    api_mod.getMaxJointsVel.restype = c_int
    ret = api_mod.getMaxJointsVel(byref(jointsVel), bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(arrVel)):
        arrVel[index] = jointsVel.values[index]
    return message(ret)

def getMaxJointsAcc(arrAcc, ipAddress = ''):
    jointsAcc = DIANA_JOINT_ACC()
    jointsAcc.values = (c_double*7)()
    api_mod.getMaxJointsAcc.argtypes = [POINTER(DIANA_JOINT_ACC), c_char_p]
    api_mod.getMaxJointsAcc.restype = c_int
    ret = api_mod.getMaxJointsAcc(byref(jointsAcc), bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(arrAcc)):
        arrAcc[index] = jointsAcc.values[index]
    return message(ret)

def getMaxCartTranslationVel(ipAddress = ''):
    cartTranslationVel = c_double()
    api_mod.getMaxCartTranslationVel.argtypes = [POINTER(c_double), c_char_p]
    api_mod.getMaxCartTranslationVel.restype = c_int
    ret = api_mod.getMaxCartTranslationVel(byref(cartTranslationVel), bytes(ipAddress.encode('utf-8')))
    return message(ret),cartTranslationVel.value

def getMaxCartRotationVel(ipAddress = ''):
    cartRotationVel = c_double()
    api_mod.getMaxCartRotationVel.argtypes = [POINTER(c_double), c_char_p]
    api_mod.getMaxCartRotationVel.restype = c_int
    ret = api_mod.getMaxCartRotationVel(byref(cartRotationVel), bytes(ipAddress.encode('utf-8')))
    return message(ret),cartRotationVel.value

def getMaxCartTranslationAcc(ipAddress = ''):
    cartTranslationAcc = c_double()
    api_mod.getMaxCartTranslationAcc.argtypes = [POINTER(c_double), c_char_p]
    api_mod.getMaxCartTranslationAcc.restype = c_int
    ret = api_mod.getMaxCartTranslationAcc(byref(cartTranslationAcc), bytes(ipAddress.encode('utf-8')))
    return message(ret),cartTranslationAcc.value

def getMaxCartRotationAcc(ipAddress = ''):
    cartRotationAcc = c_double()
    api_mod.getMaxCartRotationAcc.argtypes = [POINTER(c_double), c_char_p]
    api_mod.getMaxCartRotationAcc.restype = c_int
    ret = api_mod.getMaxCartRotationAcc(byref(cartRotationAcc), bytes(ipAddress.encode('utf-8')))
    return message(ret),cartRotationAcc.value

def setJointsPositionRange(arrMinPos, arrMaxPos, ipAddress = ''):
    jointMin = DIANA_JOINTS_POSITION()
    jointMin.values = (c_double*7)()
    for index in range(0, len(arrMinPos)):
        jointMin.values[index] = arrMinPos[index]
    jointMax = DIANA_JOINTS_POSITION()
    jointMax.values = (c_double*7)()
    for index in range(0, len(arrMaxPos)):
        jointMax.values[index] = arrMaxPos[index]
    api_mod.setJointsPositionRange.argtypes = [POINTER(DIANA_JOINTS_POSITION), POINTER(DIANA_JOINTS_POSITION), c_char_p]
    api_mod.setJointsPositionRange.restype = c_int
    ret = api_mod.setJointsPositionRange(jointMin, jointMax, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def setMaxJointsVel(arrVel, ipAddress = ''):
    jointVel = DIANA_JOINT_ANGULAR_VEL()
    jointVel.values = (c_double*7)()
    for index in range(0, len(arrVel)):
        jointVel.values[index] = arrVel[index]
    api_mod.setMaxJointsVel.argtypes = [POINTER(DIANA_JOINT_ANGULAR_VEL), c_char_p]
    api_mod.setMaxJointsVel.restype = c_int
    ret = api_mod.setMaxJointsVel(jointVel, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def setMaxJointsAcc(arrAcc, ipAddress = ''):
    jointAcc = DIANA_JOINT_ACC()
    jointAcc.values = (c_double*7)()
    for index in range(0, len(arrAcc)):
        jointAcc.values[index] = arrAcc[index]
    api_mod.setMaxJointsAcc.argtypes = [POINTER(DIANA_JOINT_ACC), c_char_p]
    api_mod.setMaxJointsAcc.restype = c_int
    ret = api_mod.setMaxJointsAcc(jointAcc, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def setMaxCartTranslationVel(TranslationVel, ipAddress = ''):
    api_mod.setMaxCartTranslationVel.argtypes = [c_double, c_char_p]
    api_mod.setMaxCartTranslationVel.restype = c_int
    ret = api_mod.setMaxCartTranslationVel(TranslationVel, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def setMaxCartRotationVel(RotationVel, ipAddress = ''):
    api_mod.setMaxCartRotationVel.argtypes = [c_double, c_char_p]
    api_mod.setMaxCartRotationVel.restype = c_int
    ret = api_mod.setMaxCartRotationVel(RotationVel, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def setMaxCartTranslationAcc(lineAcc, ipAddress = ''):
    api_mod.setMaxCartTranslationAcc.argtypes = [c_double, c_char_p]
    api_mod.setMaxCartTranslationAcc.restype = c_int
    ret = api_mod.setMaxCartTranslationAcc(lineAcc, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def setMaxCartRotationAcc(rotationAcc, ipAddress = ''):
    api_mod.setMaxCartRotationAcc.argtypes = [c_double, c_char_p]
    api_mod.setMaxCartRotationAcc.restype = c_int
    ret = api_mod.setMaxCartRotationAcc(rotationAcc, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def calcRobotArmAngle(joints, ipAddress = ''):
    dianaJointsPosition = DIANA_JOINTS_POSITION()
    dianaJointsPosition.values = (c_double*7)()
    for index in range(0, len(joints)):
        dianaJointsPosition.values[index] = joints[index]
    api_mod.calcRobotArmAngle.argtypes = [
        POINTER(DIANA_JOINTS_POSITION), POINTER(c_double), c_char_p]
    api_mod.calcRobotArmAngle.restype = c_bool
    dblAngle = c_double()
    ret = api_mod.calcRobotArmAngle(
        byref(dianaJointsPosition), byref(dblAngle), bytes(ipAddress.encode('utf-8')))
    return ret, dblAngle.value

def freeDrivingWithLockedJoint(enable, indexLockedJoint = -1, ipAddress = ''):
    api_mod.freeDrivingWithLockedJoint.argtypes = [c_bool, c_int, c_char_p]
    api_mod.freeDrivingWithLockedJoint.restype = c_int
    ret = api_mod.freeDrivingWithLockedJoint(enable, indexLockedJoint, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def freeDrivingWithLockedJoint_ex(enable, frame_type, force_direction, indexLockedJoint = -1, ipAddress = ''):
    dianaForceDirection = DIANA_FORCE_FULL_DIRECTION()
    dianaForceDirection.values = (c_double * 6)()
    for index in range(0, len(dianaForceDirection.values)):
        dianaForceDirection.values[index] = force_direction[index]
    api_mod.freeDrivingWithLockedJoint_ex.argtypes = [c_bool, c_int, POINTER(DIANA_FORCE_FULL_DIRECTION), c_int, c_char_p]
    api_mod.freeDrivingWithLockedJoint_ex.restype = c_int
    ret = api_mod.freeDrivingWithLockedJoint_ex(enable, frame_type, byref(dianaForceDirection), indexLockedJoint, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def freeDrivingForCurrentLoop(enable : bool, ipAddress = '') -> bool:
    api_mod.freeDrivingForCurrentLoop.argtypes = [c_bool, c_char_p]
    api_mod.freeDrivingForCurrentLoop.restype = c_int
    ret = api_mod.freeDrivingForCurrentLoop(enable, bytes(ipAddress.encode('utf-8')))
    return message(ret)

def getCurrentLoopFreeDrivingState(ipAddress = '') -> int:
    api_mod.getCurrentLoopFreeDrivingState.argtypes = [c_char_p]
    api_mod.getCurrentLoopFreeDrivingState.restype = c_int
    ret = api_mod.getCurrentLoopFreeDrivingState(bytes(ipAddress.encode('utf-8')))
    return ret

def enterSafetyIdle(ipAddress = '') -> bool:
    api_mod.enterSafetyIdle.argtypes = [c_char_p]
    api_mod.enterSafetyIdle.restype = c_int
    ret = api_mod.enterSafetyIdle(bytes(ipAddress.encode('utf-8')))
    return message(ret)

def leaveSafetyIdle(ipAddress = '') -> bool:
    api_mod.leaveSafetyIdle.argtypes = [c_char_p]
    api_mod.leaveSafetyIdle.restype = c_int
    ret = api_mod.leaveSafetyIdle(bytes(ipAddress.encode('utf-8')))
    return message(ret)

def identifyTcpPayload(result, fnIsStop=None, is_mass_valid=False, mass=0.0, waypoints=list(list()), vels=list(), ipAddress=''):
    if fnIsStop == None:
        fnIsStop = FNCSTOP()
    param = DIANA_LOAD_IDENTIFICATION_PARAM()
    param.bIsMassValid = is_mass_valid
    param.dblMass = mass
    sizeWP = len(waypoints)
    sizeVel = len(vels)
    if sizeWP != sizeVel:
        return load_identification_message(-13)
    param.arrWaypoints = (DIANA_LOAD_IDENTIFICATION_WAYPOINT*sizeWP)()
    param.arrWaypointsSize = sizeWP
    if sizeWP > 0: 
        for indexWP in range(0, sizeWP):
            for indexJNT in range(0, len(waypoints[0])):
                param.arrWaypoints[indexWP].joints[indexJNT] = waypoints[indexWP][indexJNT]
            param.arrWaypoints[indexWP].vel = vels[indexWP]
    arrResult = DIANA_LOAD_IDENTIFICATION_RESULT()
    arrResult.values = (c_double*10)()
    api_mod.identifyTcpPayload.argtypes = [POINTER(DIANA_LOAD_IDENTIFICATION_RESULT), FNCSTOP, POINTER(DIANA_LOAD_IDENTIFICATION_PARAM), c_char_p]
    api_mod.identifyTcpPayload.restype = c_int
    ret = api_mod.identifyTcpPayload(byref(arrResult), fnIsStop, byref(param), bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(arrResult.values)) :
        result[index] = arrResult.values[index]
    return load_identification_message(ret)

def getRgbLedState(rgbLedState : list, ipAddress=''):
    dianaGetRgbLedState = DIANA_RGB_LED_ALL_JOINTS()
    api_mod.getRgbLedState.argtypes = [POINTER(DIANA_RGB_LED_ALL_JOINTS), c_char_p]
    api_mod.getRgbLedState.restype = c_int
    ret = api_mod.getRgbLedState(byref(dianaGetRgbLedState), bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(dianaGetRgbLedState.color)): 
        rgbLedState.append([dianaGetRgbLedState.color[index].red,dianaGetRgbLedState.color[index].green,dianaGetRgbLedState.color[index].blue])
    return message(ret)

def setRgbLedState(rgbLedState : list, ipAddress = ''):
    dianaGetRgbLedState = DIANA_RGB_LED_ALL_JOINTS()
    for index in range(0, len(rgbLedState)):
        dianaGetRgbLedState.color[index].red   = rgbLedState[index][0]
        dianaGetRgbLedState.color[index].green = rgbLedState[index][1]
        dianaGetRgbLedState.color[index].blue  = rgbLedState[index][2]
    api_mod.setRgbLedState.argtypes = [POINTER(DIANA_RGB_LED_ALL_JOINTS), c_char_p]
    api_mod.setRgbLedState.restype = c_int
    ret = api_mod.setRgbLedState(byref(dianaGetRgbLedState), bytes(ipAddress.encode('utf-8')))
    return message(ret)

def setJointImpeda(arrStiff, arrDampRatio, ipAddress=''):
    jointStiff = DIANA_JOINT_STIFF()
    jointStiff.values = (c_double*7)()
    for index in range(0, len(arrStiff)):
        jointStiff.values[index] = arrStiff[index]
    api_mod.setJointImpeda.argtypes = [
        POINTER(DIANA_JOINT_STIFF), c_double, c_char_p]
    api_mod.setJointImpeda.restype = c_int
    ret = api_mod.setJointImpeda(
        jointStiff, arrDampRatio[0], bytes(ipAddress.encode('utf-8')))
    return message(ret)


def getJointImpeda(arrStiff, arrDampRatio, ipAddress=''):
    jointStiff = DIANA_JOINT_STIFF()
    jointStiff.values = (c_double*7)()
    jointDampRatio = c_double()
    api_mod.getJointImpeda.argtypes = [
        POINTER(DIANA_JOINT_STIFF), POINTER(c_double), c_char_p]
    api_mod.getJointImpeda.restype = c_int
    ret = api_mod.getJointImpeda(byref(jointStiff), byref(
        jointDampRatio), bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(arrStiff)):
        arrStiff[index] = jointStiff.values[index]
    arrDampRatio[0] = jointDampRatio.value
    return message(ret)

def setCartImpeda(arrStiff, arrDampRatio, ipAddress=''):
    cartStiff = DIANA_CART_STIFF()
    cartStiff.values = (c_double*6)()
    for index in range(0, len(cartStiff.values)):
        cartStiff.values[index] = arrStiff[index]
    api_mod.setCartImpeda.argtypes = [
        POINTER(DIANA_CART_STIFF), c_double, c_char_p]
    api_mod.setCartImpeda.restype = c_int
    ret = api_mod.setCartImpeda(
        cartStiff, arrDampRatio[0], bytes(ipAddress.encode('utf-8')))
    return message(ret)


def getCartImpeda(arrStiff, arrDampRatio, ipAddress=''):
    cartStiff = DIANA_CART_STIFF()
    cartStiff.values = (c_double*6)()
    cartDampRatio = c_double()
    api_mod.getCartImpeda.argtypes = [
        POINTER(DIANA_CART_STIFF), POINTER(c_double), c_char_p]
    api_mod.getCartImpeda.restype = c_int
    ret = api_mod.getCartImpeda(byref(cartStiff), byref(
        cartDampRatio), bytes(ipAddress.encode('utf-8')))
    for index in range(0, len(cartStiff.values)):
        arrStiff[index] = cartStiff.values[index]
    arrDampRatio[0] = cartDampRatio.value
    return message(ret)

def getRobotNetworkInfo(robotNetworkInfo: list, ipAddress=''):
    api_mod.getRobotNetworkInfo.argtypes = [POINTER(c_char * 256), c_char_p]
    api_mod.getRobotNetworkInfo.restype = c_int
    info = (c_char * 256)()
    ret = api_mod.getRobotNetworkInfo(info, bytes(ipAddress.encode('utf-8')))
    robotNetworkInfo.append(info.value.decode('utf-8'))
    return message(ret)

def setRobotNetworkInfo(currentNetworkInfo, targetNetworkInfo, ipAddress=''):
    api_mod.setRobotNetworkInfo.argtypes = [
        c_char_p, c_char_p, c_char_p]
    api_mod.setRobotNetworkInfo.restype = c_int
    ret = api_mod.setRobotNetworkInfo(bytes(currentNetworkInfo.encode('utf-8')), bytes(
        targetNetworkInfo.encode('utf-8')), bytes(ipAddress.encode('utf-8')))
    return message(ret)

def getFunctionOptI4(funtion_index:function_index_e, opt_name:function_opt_name_e, ipAddress=''):
    opt_value = c_int()
    api_mod.getFunctionOptI4.argtypes = [c_int, c_int, POINTER(c_int), c_char_p]
    api_mod.getFunctionOptI4.restype = c_int
    ret = api_mod.getFunctionOptI4(funtion_index.value, opt_name.value, byref(opt_value), bytes(ipAddress.encode('utf-8')))
    if ret == 0:
        return True, opt_value.value
    else:
        return False, 0

def setFunctionOptI4(funtion_index:function_index_e, opt_name:function_opt_name_e, opt_value, ipAddress=''):
    api_mod.setFunctionOptI4.argtypes = [c_int, c_int, c_int, c_char_p]
    api_mod.setFunctionOptI4.restype = c_int
    ret = api_mod.setFunctionOptI4(funtion_index.value, opt_name.value, opt_value, bytes(ipAddress.encode('utf-8')))
    if ret == 0:
        return True
    else:
        return False

def getFunctionOptR8(funtion_index:function_index_e, opt_name:function_opt_name_e, ipAddress=''):
    opt_value = c_double()
    api_mod.getFunctionOptR8.argtypes = [c_int, c_int, POINTER(c_double), c_char_p]
    api_mod.getFunctionOptR8.restype = c_int
    ret = api_mod.getFunctionOptR8(funtion_index.value, opt_name.value, byref(opt_value), bytes(ipAddress.encode('utf-8')))
    if ret == 0:
        return True, opt_value.value
    else:
        return False, 0

def setFunctionOptR8(funtion_index:function_index_e, opt_name:function_opt_name_e, opt_value, ipAddress=''):
    api_mod.setFunctionOptR8.argtypes = [c_int, c_int, c_double, c_char_p]
    api_mod.setFunctionOptR8.restype = c_int
    ret = api_mod.setFunctionOptR8(funtion_index.value, opt_name.value, opt_value, bytes(ipAddress.encode('utf-8')))
    if ret == 0:
        return True
    else:
        return False