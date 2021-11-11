#include "Timer.h"

thread timersThread;
bool isWork = false;

static void timer(void* work){
    bool w = static_cast<bool>(work);

    while(w){
        startTime++;
        _sleep(1);
    }
}

void startTimer(){
    isWork = true;
    timersThread = thread(timer, &isWork);
    printf("Timer started\n");
}

void loopTimer(){
    isWork = false;
    printf("Timer loop: %d\n", startTime);
}