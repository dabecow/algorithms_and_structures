//
// Created by Andrew on 31.10.2021.
//

#ifndef ALGORITHMS_AND_STRUCTURES_HASHTABLE_H
#define ALGORITHMS_AND_STRUCTURES_HASHTABLE_H

#include "../list/LinkedList.h"
#include "../list/ArrayList.h"
#include "../../algorithms/hash_functions.h"

class HashTable {

protected:
    int numberOfBuckets;
    LinkedList<std::string> *array;

public:
    HashTable(int numberOfBuckets) {
        this->numberOfBuckets = numberOfBuckets;
        array = new LinkedList<std::string>[numberOfBuckets];
    }

    virtual void addValue(std::string value) = 0;

    int* countCollisions() {

        int* collisionsByIndexArr = new int[numberOfBuckets];

        for (int i = 0; i < numberOfBuckets; ++i) {
            collisionsByIndexArr[i] = array[i].getSize();
        }

        return collisionsByIndexArr;
    };

};


#endif //ALGORITHMS_AND_STRUCTURES_HASHTABLE_H
