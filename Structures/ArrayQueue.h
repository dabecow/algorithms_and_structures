//
// Created by Andrew on 21.09.2021.
//

#ifndef ALGORITHMS_AND_STRUCTURES_ARRAYQUEUE_H
#define ALGORITHMS_AND_STRUCTURES_ARRAYQUEUE_H

#include "Queue.h"

template<class T> class ArrayQueue : public Queue<T>{
public:

    ArrayQueue<T>(int size, int max): Queue<T>(size, max) {};
};


#endif //ALGORITHMS_AND_STRUCTURES_ARRAYQUEUE_H
