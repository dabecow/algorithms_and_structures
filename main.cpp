#include <stdio.h>
#include <MultiPathSort.h>
#include <Generator.h>
#include <timer/Timer.h>

int main() {

    // create_file("./input.txt", 1, 100, 1000);

    startTimer();
    mp_sort("./input.txt", 8);
    loopTimer();

    return 0;
}
