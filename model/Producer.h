//
// Created by Andrew on 22.09.2021.
//

#ifndef ALGORITHMS_AND_STRUCTURES_PRODUCER_H
#define ALGORITHMS_AND_STRUCTURES_PRODUCER_H


#include "Detail.h"
#include "../Structures/queue/Queue.h"
#include "../Structures/queue/ArrayQueue.h"
#include "../Structures/queue/LinkedQueue.h"

#define TIMETOWAIT 1000

class Producer {

public:

    static void init(Queue<Detail *> *pQueue);
    static int putDetailInQueue(Detail* detail);
    static int dropDetailFromQueue();
    static std::string detailsToString();
    static int reset();

    static bool isRunning;

private:
    static Queue<Detail*> *queue;


    static int timer;

    static int firstDetailThread();

};


#endif //ALGORITHMS_AND_STRUCTURES_PRODUCER_H
