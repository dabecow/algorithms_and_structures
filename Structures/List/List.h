//
// Created by Andrew on 25.09.2021.
//

#ifndef ALGORITHMS_AND_STRUCTURES_LIST_H
#define ALGORITHMS_AND_STRUCTURES_LIST_H

#include "Node.h"
#include "Iterator.h"

template<class T>
class List {

protected:

    int size;

public:
    explicit List() {
        size = 0;
    }

    Iterator<T> *getIterator() const {
        return iterator;
    }

    int getSize() const {
        return size;
    }

    virtual void clear() = 0;

    virtual int add(T t) = 0;

    bool empty(){
        return this->size == 0;
    };

};
#endif //ALGORITHMS_AND_STRUCTURES_LIST_H
