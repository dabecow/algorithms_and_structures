//
// Created by Andrew on 25.09.2021.
//

#ifndef ALGORITHMS_AND_STRUCTURES_LIST_H
#define ALGORITHMS_AND_STRUCTURES_LIST_H

template<class T>
class List {

protected:

    int size;

public:
    explicit List() {
        size = 0;
    }

    int getSize() {
        return this->size;
    }

    virtual void clear() = 0;

    virtual int add(T t) = 0;

    bool empty(){
        return this->size == 0;
    };

};
#endif //ALGORITHMS_AND_STRUCTURES_LIST_H
