//
// Created by Andrew on 31.10.2021.
//

#ifndef ALGORITHMS_AND_STRUCTURES_XORHASHTABLE_H
#define ALGORITHMS_AND_STRUCTURES_XORHASHTABLE_H

#include "HashTable.h"
class xorHashTable : HashTable{

private:
    int* r;

public:
    explicit xorHashTable(int numberOfBuckets) : HashTable(numberOfBuckets) {
        r = new int[numberOfBuckets];
        for (int i = 0; i < numberOfBuckets; ++i) {
            r[i] = rand() % 540 + 288;
        }
    }

    void addValue(std::string value) override {
        int index = xorHashFunction(value, r);

        this->array[index].add(value);
    }
};


#endif //ALGORITHMS_AND_STRUCTURES_XORHASHTABLE_H
