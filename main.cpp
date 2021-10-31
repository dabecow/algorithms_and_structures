#include <iostream>
#include "Structures/queue/Queue.h"
#include "model/Detail.h"
#include "model/Producer.h"
#include <thread>

using namespace std::chrono_literals;

const std::string MAIN_MENU = "1. Add detail\n2. Remove detail\n3. Print details\n4. Reset the producer\n>>>";

char printMenuGetChoice(){
    std::cout << MAIN_MENU;

    char choice;

    std::cin >> choice;

    return choice;
}

int main() {

    Queue<Detail*> *detailsQueue = new ArrayQueue<Detail*>(5);

    Detail firstDetail("first", 2000);
    Detail secondDetail("second", 2000);
    Detail thirdDetail("third", 2000);

    detailsQueue->push(&firstDetail);
    detailsQueue->push(&secondDetail);
    detailsQueue->push(&thirdDetail);

    Producer::init(detailsQueue);

    std::cout << Producer::detailsToString();

    bool deletedOne = false;
//
//    Producer::reset();
//
    while (Producer::isRunning){
        std::this_thread::sleep_for(200ms);
//        if (!deletedOne){
//            Producer::dropDetailFromQueue();
//            deletedOne = true;
//        }
    }

    return 0;
}
