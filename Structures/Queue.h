//
// Created by Andrew on 21.09.2021.
//

#ifndef ALGORITHMS_AND_STRUCTURES_QUEUE_H
#define ALGORITHMS_AND_STRUCTURES_QUEUE_H

template<class T> class Queue{

protected:

    int size;
    int max;

public:

    explicit Queue(int size, int max){
        this->size = size;
        this->max = max;
    }

    /**
     * @param t – the object
     * @return -1 if is full
     */
    int push(T t) = 0;

    T pop() = 0;

    bool empty() = 0;

    T first() = 0;

    T* data() = 0;

};
#endif //ALGORITHMS_AND_STRUCTURES_QUEUE_H
