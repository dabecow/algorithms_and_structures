//
// Created by Andrew on 21.09.2021.
//

#include "ArrayQueue.h"

template<class T>
int ArrayQueue<T>::push(T t){
    if(tail == this->size)
        tail = 0;

    if(tail == head){
        return -1;
    }

    
}