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
        tail = 0;
    };

        /**
         * @param t – the object
         * @return -1 if is full
         */

        int push(T t) override {
            if(this->size == this->max){
                return -1;
            }

            _data[tail] = t;
            tail++;
            this->size++;

            if(tail == this->max)
                tail = 0;
            return 0;
        }

        void pop() override {
            if(this->size > 0){
                T t = _data[head];
                head++;

                if(head == this->max)
                    head = 0;

//                if(head == tail)
//                    head--;

                this->size--;

            }

        }

        T* data() override {
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

            } else if (tail == head && this->size > 0){

                int j = 0;

                for (int i = 0; i < this->max; ++i) {
                    data[j] = _data[i];
                    j++;
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

        bool empty() override {
            return this->size == 0;
        }

        T* first() override {

            T* value =
                    this-> size == 0 ? nullptr : _data + head;

            return value;

        }

};

#endif //ALGORITHMS_AND_STRUCTURES_ARRAYQUEUE_H

