//
// Created by Andrew on 21.09.2021.
//

#include "ArrayQueue.h"

template<class T>
ArrayQueue<T>::ArrayQueue(int size, int max) : Queue<T>(size, max){
    data = new T[size];
}

template<class T>
int ArrayQueue<T>::push(T t){
    if(tail == this->size)
        tail = 0;

    if(tail == head){
        return -1;
    }

    data[tail] = t;
    tail++;
}