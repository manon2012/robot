#pragma once
#include <cstring>  // necessary for strerror
#include <stdexcept>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>  // necessary for mlockall
#include <sys/types.h>
#include <sys/stat.h>  // necessary for struct stat s;

#ifndef REALTIME_ENV
#define REALTIME_ENV
#endif  // REALTIME_ENV

#ifdef REALTIME_ENV
const int MAX_SAFE_STACK = 8 * 1024;
// 『实时性』
//  实时任务运行前提前扩充栈空间
static void stack_prefault(void) {
    unsigned char dummy[MAX_SAFE_STACK];
    memset(dummy, 0, MAX_SAFE_STACK);
    return;
}
static bool setTaskRealtime(bool bRealTime) {
    if (bRealTime == true) {
        struct sched_param param;
        param.sched_priority = sched_get_priority_max(SCHED_FIFO) - 5;
        int sret = sched_setscheduler(0, SCHED_FIFO, &param);
        if (sret == -1) {
            printf("sched_setscheduler failed!(%d)", sret);
            return false;
        } else {
            // m_log.set("Using priority ", param.sched_priority);
            if (mlockall(MCL_CURRENT | MCL_FUTURE) == -1) {
                printf("memory lock failed!");
                return false;
            } else {
                stack_prefault();
                return true;
            }
        }
    } else {
        if (munlockall() == -1)
            return false;
        else
            return true;
    }
}

static bool installLatency(int &intLatencyTargetFd) {
    struct stat s;
    if (stat("/dev/cpu_dma_latency", &s) == 0) {
        int intLatencyTargetValue = 0;
        intLatencyTargetFd = open("/dev/cpu_dma_latency", O_RDWR);
        if (intLatencyTargetFd != -1) {
            if (write(intLatencyTargetFd, &intLatencyTargetValue, 4) == 0) {
                printf("error setting cpu_dma_latency to %d", intLatencyTargetValue);
                printf("cpu_dma_latency error msg: %s", strerror(errno));
                close(intLatencyTargetFd);
                intLatencyTargetFd = -1;
                return false;
            } else {
                printf("/dev/cpu_dma_latency set to(ns): %d", intLatencyTargetValue);
                return true;
            }
        }
    } else
        intLatencyTargetFd = -1;
    return false;
}

// 释放
static void uninstallLatency(int intLatencyTargetFd) {
    if (intLatencyTargetFd >= 0) {
        close(intLatencyTargetFd);
        intLatencyTargetFd = -1;
    }
}
#endif  // REALTIME_ENV
