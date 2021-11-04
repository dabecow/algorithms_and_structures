#include <stdio.h>
#include <MultiPathSort.h>
#include <timer/Timer.h>

int main() {

    startTimer();
    mp_sort("./input.txt", 2);
    loopTimer();

    return 0;
}
