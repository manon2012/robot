
 double zero[7] = { to_rad(0.12),to_rad(33.62),to_rad(-8.51),to_rad(87.64),to_rad(4.73),to_rad(-64.06),to_rad(-42.31) };
    ret = moveJToTarget(zero, vel, acc, order, frequency, damping);
    wait_move();
    printf("go to home zero done.\n");

    
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



poseTransform(srcPose,srcMatrixPose,dstMatrixPose,dstPose);

double Targetjoints[7]={0};
inverse_ext(zero, dstPose, Targetjoints);

moveJToTarget(Targetjoints, vel, acc, order, frequency, damping);
wait_move();
printf("go to target done.\n");

moveJToTarget(zero, vel, acc, order, frequency, damping);
wait_move();
printf("go to home zero done.\n");