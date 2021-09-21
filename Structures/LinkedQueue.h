//
// Created by Andrew on 21.09.2021.
//

#ifndef ALGORITHMS_AND_STRUCTURES_LINKEDQUEUE_H
#define ALGORITHMS_AND_STRUCTURES_LINKEDQUEUE_H


#include "Queue.h"

template<class T> class LinkedQueue : public Queue<T>{

    T* head;
    T* tail;

    LinkedQueue<T>(int size, int max): Queue<T>(size, max) {};

};


#endif //ALGORITHMS_AND_STRUCTURES_LINKEDQUEUE_H
