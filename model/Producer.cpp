//
// Created by Andrew on 22.09.2021.
//

#include "Producer.h"
#include <thread>
#include "iostream"

using namespace std::chrono_literals;

Queue<Detail *>* Producer::queue = nullptr;

bool Producer::isRunning = true;

int Producer::timer = 0;

int Producer::putDetailInQueue(Detail *detail) {

    int result = queue->push(detail);

    if (result < 0)
        return result;

    return 0;
}

int Producer::dropDetailFromQueue() {

    Detail* currentDetail = *queue->first();

    if (currentDetail == nullptr){
        return -1;
    }

    timer = 0;

    std::cout << currentDetail->getName() << " was removed" << std::endl;

    queue->pop();

    return 0;
}

std::string Producer::detailsToString() {

    std::string result;

    Detail** array = queue->data();

    Detail* currentDetail;

    for (int i = 0; i < queue->getSize(); ++i) {

        currentDetail = array[i];

        result += currentDetail->getName() + '\n';

    }

    return result;

}

int Producer::reset() {

    isRunning = false;

    Detail** array = queue->data();

    Detail* currentDetail;

    for (int i = 0; i < queue->getSize(); ++i) {

        currentDetail = array[i];

        std::cout << currentDetail->getName() + " was on the production line" << std::endl;

    }

    delete queue;
    delete array;

    return 0;
}

int Producer::firstDetailThread() {

    while (isRunning){

        if (queue->empty()){
            std::this_thread::sleep_for(std::chrono::microseconds(TIMETOWAIT));
        } else {

            timer++;

            Detail* currentDetail = *queue->first();

            std::this_thread::sleep_for(std::chrono::microseconds(TIMETOWAIT));

            if (currentDetail->getTimeToProduce() <= timer){
                queue->pop();
                std::cout << currentDetail->getName() << " is finished." << std::endl;
//                delete currentDetail;

                timer = 0;
            }

            //delete the statement below is menu is implemented
            if (queue->empty()){
                isRunning = false;
            }
        }

    }

    std::cout << "The thread was stopped." << std::endl;

    return 0;
}

void Producer::init(Queue<Detail *> *pQueue) {
    queue = pQueue;

    auto *thread = new std::thread(firstDetailThread);
}



