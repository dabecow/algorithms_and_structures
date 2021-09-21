//
// Created by Andrew on 21.09.2021.
//

#include "ArrayQueue.h"

template<class T>
ArrayQueue<T>::ArrayQueue(int max) : Queue<T>(max){
    _data = new T[max];
    head = 0;
    tail = 1;
}

template<class T>
int ArrayQueue<T>::push(T t){
    if(tail == head){
        return -1;
    }

    _data[tail] = t;
    tail++;
    this->size++;

    if(tail == this->max)
        tail = 0;
    return 0;
}

template<class T>
T ArrayQueue<T>::pop(){
    if(this->size > 0){
        T t = data[head];
        head++;

        if(head == this->max)
            head = 0;

        if(head == tail)
            head--;

        this->size--;
        
        return t;
    }

    return nullptr;
}

template<class T>
T* ArrayQueue<T>::data(){

}