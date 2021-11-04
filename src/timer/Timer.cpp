#include "Timer.h"

void startTimer(){
    timeval now;
    mingw_gettimeofday(&now, NULL);
    startTime = now.tv_usec;
    printf("Timer started\n");
}

void loopTimer(){
    timeval now;
    mingw_gettimeofday(&now, NULL);
    long long unow = now.tv_usec;
    printf("Timer loop: %d\n", unow - startTime);
}