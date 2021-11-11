#ifndef TIMER_H
#define TIMER_H

#include <time.h>
#include <stdio.h>
#include <thread>

using namespace std;

static long long startTime = 0;

void startTimer();
void loopTimer();

#endif