//
// Created by Andrew on 31.10.2021.
//

#ifndef ALGORITHMS_AND_STRUCTURES_XORDIVISIONHASHTABLE_H
#define ALGORITHMS_AND_STRUCTURES_XORDIVISIONHASHTABLE_H

#include "HashTable.h"
class XorDivisionHashTable : public HashTable{

private:
    int* r;

public:
    explicit XorDivisionHashTable(int numberOfBuckets, int stringLength) : HashTable(numberOfBuckets) {
        r = new int[stringLength];
        for (int i = 0; i < numberOfBuckets; ++i) {
            r[i] = rand() % 127 + 64;
        }
    }

    void addValue(std::string value) override {
        int index = divisionHashFunction(stringToIntSumByXor(value, r), numberOfBuckets);

        this->array[index].add(value);
    }
};


#endif //ALGORITHMS_AND_STRUCTURES_XORDIVISIONHASHTABLE_H
