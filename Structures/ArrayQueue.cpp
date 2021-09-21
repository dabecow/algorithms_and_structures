//
// Created by Andrew on 21.09.2021.
//

#include "ArrayQueue.h"

template<class T>
ArrayQueue<T>::ArrayQueue(int size, int max) : Queue<T>(size, max){
    _data = new T[size];
}

template<class T>
int ArrayQueue<T>::push(T t){
    if(tail == this->size)
        tail = 0;

    if(tail == head){
        return -1;
    }

    _data[tail] = t;
    tail++;

    return 0;
}

template<class T>
T* ArrayQueue<T>::data(){

}

template<class T>
bool ArrayQueue<T>::empty(){
    if (size < max)
        return 0;
}

template<class T>
T ArrayQueue<T>::first(){
    return _data[head];
}