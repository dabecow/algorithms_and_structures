//
// Created by Andrew on 27.09.2021.
//

#ifndef ALGORITHMS_AND_STRUCTURES_ARRAYLIST_H
#define ALGORITHMS_AND_STRUCTURES_ARRAYLIST_H

#include "List.h"
template<class T>
class ArrayList : List<T>{

    T *data;
    int allocatedSize;

private:

    bool validIndex(int i){
        return i >= 0 && i < this->size;
    }

    void reallocateMemory(){

        allocatedSize*=1.5;

        T* newAllocatedArray = new T[allocatedSize];

        for (int i = 0; i < this->size; ++i) {
            newAllocatedArray[i] = data[i];
        }

        delete data;

        data = newAllocatedArray;
    }

public:
    ArrayList(): List<T>() {
        this->allocatedSize = 0;
    }

    void clear() override {
        for (int i = 0; i < this->size; ++i) {
            delete data[i];
        }
    }

    int add(T t) override {

        if (allocatedSize < size + 1){
            reallocateMemory();
        }

        data[this->size] = t;

        this->size++;

        return 0;
    }

    int remove(int i){
        if (!validIndex(i))
            return -1;

        for (int j = i; j < this->size - 1; ++j) {
            data[j] = data[j + 1];
        }

        this->size--;

        return 0;
    }

    T* get(int i){
        if (!validIndex(i))
            return nullptr;

        return data[i];
    }
};


#endif //ALGORITHMS_AND_STRUCTURES_ARRAYLIST_H
