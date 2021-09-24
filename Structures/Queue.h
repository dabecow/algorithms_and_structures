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

    explicit Queue(int max){
        this->max = max;
        this->size = 0;
    }

    /**
     * @param t – the object
     * @return -1 if is full
     */
    virtual int push(T t) = 0;

    /**
     * Deletes the object from queue and from memory
     */
    virtual void pop() = 0;

    virtual bool empty() = 0;

    virtual T* first() = 0;

    /**
     *
     * @return an array of values in the queue
     */
    virtual T* data() = 0;

    int getSize(){
        return size;
    }

};
#endif //ALGORITHMS_AND_STRUCTURES_QUEUE_H
