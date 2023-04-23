#include "test_base.h"
#include "DianaAPI.h"



static int order = 0;
static double frequency = 0;
static double damping = -100;


// int order = 0;
// double frequency = 0;
// double damping = 10;


// int order = 0;
// double frequency = 0;
// double damping = 0.6;


void testMove1()
{
    printf("开始测试输入整形默认功能.\n");
    double joints1[7] = { to_rad(0.207),to_rad(-18.868),to_rad(0.422),to_rad(143.074),to_rad(-3.144),to_rad(-55.220),to_rad(-42.312) };
    double vel = 0.4;
    double acc = 0.4;
    int ret = moveJToTarget(joints1, vel, acc, order, frequency, damping);
    if (ret < 0)
    {
    	printf("moveJToTarget failed!Return value = %d\n", ret);
    }
      else
    {
        std::cout <<"moveJToTarget moving..."<<std::endl;
        //sleepMilliseconds(1000);
        wait_move();
        std::cout <<"moveJToTarget done."<<std::endl;
    }
    

    double joints2[7] = { to_rad(0.216),to_rad(30.758),to_rad(0.278),to_rad(80.966),to_rad(-3.091),to_rad(-67.682),to_rad(-43.086) };
    ret = moveLToTarget(joints2, vel, acc, order, frequency, damping);
    if (ret < 0)
    {
    	printf("moveLToTarget failed!Return value = %d\n", ret);
    }
    else
    {
        std::cout <<"moveLToTarget moving..."<<std::endl;
        //sleepMilliseconds(1000);
        wait_move();
        std::cout <<"moveLToTarget done."<<std::endl;
    }
   

    double firstpose[6] = { 0.600,0.600,0.600,0,0,0 };
    ret = moveJToPose(firstpose, vel, acc, nullptr, order, frequency, damping);
    if (ret < 0)
    {
    	printf("moveJToPose failed!Return value = %d\n", ret);
    }
    else
    {
        std::cout <<"moveJToPose moving..."<<std::endl;
        //sleepMilliseconds(1000);
        wait_move();
        std::cout <<"moveJToPose done."<<std::endl;
    }
    

    firstpose[0]-= 0.3;
    firstpose[1]-= 0.3;
    firstpose[2]-= 0.3;
    vel = 0.28;
    acc = 0.28;
    ret = moveLToPose(firstpose, vel, acc, nullptr, order, frequency, damping);
    if (ret < 0)
    {
    	printf("moveLToPose failed!Return value = %d\n", ret);
    }
    else
    {
        std::cout <<"moveLToPose moving..."<<std::endl;
        //sleepMilliseconds(1000);
        wait_move();  
        std::cout <<"moveLToPose done."<<std::endl;
    }
        

}

void testAddMove1()
{   
    double acc=0.2;
    double vel=0.2;
    double blendradius=0.05;

    double joints[7] = { to_rad(0.207),to_rad(-18.868),to_rad(0.422),to_rad(143.074),to_rad(-3.144),to_rad(-55.220),to_rad(-42.312) };
    int ret = moveJToTarget(joints, vel, acc);
    if (ret < 0)
    {
    	printf("moveJToTarget failed!Return value = %d\n", ret);
    }
    wait_move();


     //ComplexPath指令
    double joints1[7] = { 0.0 };
    ret = getJointPos(joints1);
    if (ret < 0)
    {
        printf("getJointPos failed!Return value = %d\n", ret);
    }

    double firstpose[6] = { 0.0 };
    ret = forward(joints1, firstpose, nullptr);
    if (ret < 0)
    {
        printf("forward failed!Return value = %d\n", ret);
    }
    firstpose[1] += 0.4;
    double secondjoints[7] = { 0.0 };
    ret = inverse(firstpose, secondjoints, nullptr);
    if (ret < 0)
    {
        printf("inverse failed!Return value = %d\n", ret);
    }
    firstpose[1] -= 0.4;
    double thirdjoints[7] = { 0.0 };
    ret = inverse(firstpose, thirdjoints, nullptr);
    if (ret < 0)
    {
        printf("inverse failed!Return value = %d\n", ret);
    }
    firstpose[0] += 0.2;
    firstpose[1] += 0.2;
    double fourthjoints[7] = { 0.0 };
    ret = inverse(firstpose, fourthjoints, nullptr);
    if (ret < 0)
    {
        printf("inverse failed!Return value = %d\n", ret);
    }
    firstpose[0] -= 0.2;
    firstpose[1] += 0.2;
    double fifthjoints[7] = { 0.0 };
    ret = inverse(firstpose, fifthjoints, nullptr);
    if (ret < 0)
    {
        printf("inverse failed!Return value = %d\n", ret);
    }

    int complex_path_type = 0;
    unsigned int complex_path_id;
    bool ignore_rotation = true;

    std::cout<<"complex_path_type 0 :表示 NORMAL_JOINT,该模式下路径中可以添加";
    std::cout<<"moveL、moveJ、moveC 对应的路径点,路径点用 JOINT_NUM 个关节角度确定。"<<std::endl;
    sleepMilliseconds(1000);
    ret=createComplexPath(complex_path_type, complex_path_id);
    if (ret < 0)
    {
        printf("createComplexPath failed!Return value = %d\n", ret);
    }
    ret=addMoveJByTarget(complex_path_id, secondjoints, vel, acc, blendradius, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveJByTarget failed!Return value = %d\n", ret);
    }
    ret=addMoveLByTarget(complex_path_id, thirdjoints, vel, acc, blendradius, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveLByTarget failed!Return value = %d\n", ret);
    }
    ret=addMoveCByTarget(complex_path_id, fourthjoints, fifthjoints, vel, acc, blendradius, ignore_rotation, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveCByTarget failed!Return value = %d\n", ret);
    }
    ret=runComplexPath(complex_path_id);
    if (ret < 0)
    {
        printf("runComplexPath failed!Return value = %d\n", ret);
    }
    ret=destroyComplexPath(complex_path_id);
    if (ret < 0)
    {
        printf("destroyComplexPath failed!Return value = %d\n", ret);
    }
    wait_move(); 
 


    std::cout<<"complex_path_type 1 :表示 MOVEP_JOINT,该模式下机械臂关节做点对点的匀速运动,路径中可以添加";
    std::cout<<"moveL、moveC 对应的路径点,不可以添加 moveJ 对应的路径点,路径点用 JOINT_NUM个关节角度确定"<<std::endl;
    sleepMilliseconds(1000);
    complex_path_type = 1;
    ret=createComplexPath(complex_path_type, complex_path_id);
    if (ret < 0)
    {
        printf("createComplexPath failed!Return value = %d\n", ret);
    }
    firstpose[0] += 0.2;
    firstpose[1] -= 0.2;
    double sixthjoints[7] = { 0.0 };
    ret = inverse(firstpose, sixthjoints, nullptr);
    if (ret < 0)
    {
        printf("inverse failed!Return value = %d\n", ret);
    }
    firstpose[0] -= 0.2;
    firstpose[1] -= 0.2;
    double seventhjoints[7] = { 0.0 };
    ret = inverse(firstpose, seventhjoints, nullptr);
    if (ret < 0)
    {
        printf("inverse failed!Return value = %d\n", ret);
    }
    ret=addMoveCByTarget(complex_path_id, sixthjoints, seventhjoints, vel, acc, blendradius, ignore_rotation, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveCByTarget failed!Return value = %d\n", ret);
    }
    firstpose[1] -= 0.3;
    double eighthjoints[7] = { 0.0 };
    ret = inverse(firstpose, eighthjoints, nullptr);
    if (ret < 0)
    {
        printf("inverse failed!Return value = %d\n", ret);
    }
    ret=addMoveLByTarget(complex_path_id, eighthjoints, vel, acc, blendradius, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveLByTarget failed!Return value = %d\n", ret);
    }
    ret=runComplexPath(complex_path_id);
    if (ret < 0)
    {
        printf("runComplexPath failed!Return value = %d\n", ret);
    }
    ret=destroyComplexPath(complex_path_id);
    if (ret < 0)
    {
        printf("destroyComplexPath failed!Return value = %d\n", ret);
    }
    wait_move();  



    std::cout<<"complex_path_type 2 :NORMAL_POSE ,该模式下路径中可以添加";
    std::cout<<"moveL、moveJ、moveC 对应的路径点,路径点用末端 TCP 位姿数据确定"<<std::endl;
    sleepMilliseconds(2000);
    firstpose[0] += 0.3;
    firstpose[1] += 0.3;
    ret = moveLToPose(firstpose, vel, acc, nullptr,0,0,0);
    wait_move();
    firstpose[0] -= 0.3;
    ret = moveLToPose(firstpose, vel, acc, nullptr,0,0,0);
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
    ret = createComplexPath(complex_path_type, complex_path_id);
    if (ret < 0)
    {
        printf("创建路径失败!Return value = %d\n", ret);
    }
    ret=addMoveCByPose(complex_path_id, firstpose, targetpose, vel, acc, blendradius, ignore_rotation, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveCByPose failed!Return value = %d\n", ret);
    }
    targetpose[1] -= 0.6;
    ret=addMoveLByPose(complex_path_id, targetpose, vel, acc, blendradius, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveLByPose failed!Return value = %d\n", ret);
    }
    targetpose[1] += 0.6;
    ret=addMoveLByPose(complex_path_id, targetpose, vel, acc, blendradius, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveJByPose failed!Return value = %d\n", ret);
    }
    ret=runComplexPath(complex_path_id);
    if (ret < 0)
    {
        printf("runComplexPath failed!Return value = %d\n", ret);
    }
    ret=destroyComplexPath(complex_path_id);
    if (ret < 0)
    {
        printf("destroyComplexPath failed!Return value = %d\n", ret);
    }
    wait_move();  



    std::cout<<"complex_path_type 3 :表示 MOVEP_POSE,该模式下机械臂末端做点对点的匀速运动";
    std::cout<<"路径中可以添加moveL、moveC 对应的路径点,不可以添加 moveJ 对应的路径点,路径点用末端 TCP 位姿数据确定"<<std::endl;
    sleepMilliseconds(2000);
    complex_path_type = 3;
    ret = createComplexPath(complex_path_type, complex_path_id);
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
    ret=addMoveCByPose(complex_path_id, targetpose, targetpose2, vel, acc, blendradius, ignore_rotation, order, frequency, damping);
    if (ret < 0)
    {
        printf("addMoveCByPose failed!Return value = %d\n", ret);
    }
    targetpose2[1] -= 0.3;
    ret=addMoveLByPose(complex_path_id, targetpose2, vel, acc, blendradius, order, frequency, damping);
    runComplexPath(complex_path_id);
    destroyComplexPath(complex_path_id);
    wait_move();


}

//定义测试用例的描述, 方便用户了解测试内容
void API_homework_001(){
    printf("测试函数输入整形默认值.\n");
}

// 定义测试实体，多个用例可以关联同一个实体
void api_homework() {
    srv_net_st net_info;
    initSrvNetInfo(&net_info);
    strcpy(net_info.SrvIp, "192.168.10.75");
    int connect_ret = initSrv(errorControl, nullptr, &net_info);
    if (connect_ret != 0) {
        printf("initSrv failed!Return value = %d\n", connect_ret);
    }
    releaseBrake();

    //初始位姿 回原
    // double init_joints[7] ={0.0};
    // double init_vel = 0.4;
    // double init_acc = 0.4;
    // moveJToTarget(init_joints, init_vel, init_acc);
    // wait_move();
    // std::cout <<"已回原"<<std::endl;

    
    printf("go to home pos...\n");
    double joints0[7] = { to_rad(0.207),to_rad(-18.868),to_rad(0.422),to_rad(143.074),to_rad(-3.144),to_rad(-55.220),to_rad(-42.312) };
    double vel = 0.4;
    double acc = 0.4;
    int ret = moveJToTarget(joints0, vel, acc, order, frequency, damping);
    wait_move();
    printf("go to home pos done.\n");

    
    
    double zero[7] = { to_rad(0.12),to_rad(33.62),to_rad(-8.51),to_rad(87.64),to_rad(4.73),to_rad(-64.06),to_rad(-42.31) };
    ret = moveJToTarget(zero, vel, acc, order, frequency, damping);
    wait_move();
    printf("go to zero zero done.\n");

    
    double srcPose[6] = {0,0,0,to_rad(-2.442),to_rad(0.780),to_rad(-133.151)};
    double srcMatrixPose[6] = {0.801,0.089,0.330,to_rad(2.7388),to_rad(-1.8624),to_rad(98.1542)};

    double dstMatrixPose[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
    double dstPose[6] = {0};



    // srcPose[0]+=0.2;
    // poseTransform(srcPose,srcMatrixPose,dstMatrixPose,dstPose);

    // double joints[7]={0};
    // inverse(dstPose, joints);
    
    // moveJToTarget(joints, vel, acc, order, frequency, damping);
    // wait_move();

    
    // srcPose[0]+=0.1;

    // poseTransform(srcPose,srcMatrixPose,dstMatrixPose,dstPose);

    // double joints[7]={0};
    // inverse(dstPose, joints);
    
    // moveJToTarget(joints, vel, acc, order, frequency, damping);
    // wait_move();


    for (int y=0;y<5;y++) 
    {

       for (int x=0; x<5; x++)
       {
            srcPose[0] = 0.05*(x+1);
            srcPose[1] = 0.05*(y+1);


            poseTransform(srcPose,srcMatrixPose,dstMatrixPose,dstPose);

            double Targetjoints[7]={0};
            inverse_ext(zero, dstPose, Targetjoints);
            
            moveJToTarget(Targetjoints, vel, acc, order, frequency, damping);
            wait_move();
            printf("go to target done.\n");

            moveJToTarget(zero, vel, acc, order, frequency, damping);
            wait_move();
            printf("go to home zero done.\n");

       }
    }

     
    moveJToTarget(zero, vel, acc, order, frequency, damping);
    wait_move();
    printf("go to home zero done.\n");

    // srcPose[1]+=0.2;
    // poseTransform(srcPose,srcMatrixPose,dstMatrixPose,dstPose);

    
    // inverse(dstPose, joints);
    
    // moveJToTarget(joints, vel, acc, order, frequency, damping);
    // wait_move();



    //testMove();
    //testAddMove();

    
    //开始测试moveTCP、rotationTCP
    //jog();

    if(read_input("测试输入整形的运动是否符合预期结果[是-y, 否-n]:") == 'y'){
        setCaseSucceed("API_SRZX_001");
    } else {
        setCaseFailed("API_SRZX_001");
    }
    printf("结束测试10个参数变化的函数功能.\n");
    sleepMilliseconds(1000);
    holdBrake();
    destroySrv();
    
}

// 注册测试用例及测试方法
REGIST_CASE_FUNCTION(api_homework);
REGIST_CASE(API_homework_001, api_homework, API_homework_001);
