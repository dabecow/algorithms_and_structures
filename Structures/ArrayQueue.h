//
// Created by Andrew on 21.09.2021.
//

#ifndef ALGORITHMS_AND_STRUCTURES_ARRAYQUEUE_H
#define ALGORITHMS_AND_STRUCTURES_ARRAYQUEUE_H

#include "Queue.h"

template<class T> class ArrayQueue : public Queue<T>{

    private:
        T *_data;

        int head;
        int tail;

    public:
        /**
         * @param t – the object
         * @return -1 if is full
         */
        int push(T t);
        T* data();

    public:
        ArrayQueue<T>(int size, int max);

};


#endif //ALGORITHMS_AND_STRUCTURES_ARRAYQUEUE_H
