//
// Created by Andrew on 21.09.2021.
//

#include "ArrayQueue.h"

template<class T>
ArrayQueue<T>::ArrayQueue(int max) : Queue<T>(max){
    _data = new T[max];
}

template<class T>
int ArrayQueue<T>::push(T t){
    if(tail == this->max)
        tail = 0;

    if(tail == head){
        return -1;
    }

    _data[tail] = t;
    tail++;
    this->size++;
    return 0;
}

template<class T>
T* ArrayQueue<T>::data(){

    if (this->empty())
        return nullptr;

    T* data = new T[this->size];

    if (tail < head) {
        int j = 0;

        //от головы до максимума
        for (int i = head; i < this->max; ++i) {
            data[j] = _data[i];
            j++;
        }
        //от первого до хвоста
        for (int i = 0; i < tail; ++i) {
            data[j] = _data[i];
        }

    } else {
        int j = 0;

        for (int i = head; i < tail; ++i) {
            data[j] = _data[i];
            j++;
        }
    }

    return data;
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