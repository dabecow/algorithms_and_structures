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
    explicit ArrayQueue(int max) : Queue<T>(max){
        _data = new T[max];
        head = 0;
        tail = 1;
    };
        /**
         * @param t – the object
         * @return -1 if is full
         */
        int push(T t){
            if(tail == head){
                return -1;
            }

            _data[tail] = t;
            tail++;
            this->size++;

            if(tail == this->max)
                tail = 0;
            return 0;
        };

        T pop(){
            if(this->size > 0){
                T t = _data[head];
                head++;

                if(head == this->max)
                    head = 0;

                if(head == tail)
                    head--;

                this->size--;

                return t;
            }

//            return nullptr;
        };

        T* data(){
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
        };



        bool empty(){
            return this->size == 0;
        };
        
        T first(){
            return _data[head];
        };

//        ArrayQueue<T>(int size, int max): Queue<T>(size, max) {};



};

#endif //ALGORITHMS_AND_STRUCTURES_ARRAYQUEUE_H

