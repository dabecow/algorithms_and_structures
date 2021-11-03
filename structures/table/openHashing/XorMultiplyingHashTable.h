//
// Created by Andrew on 02.11.2021.
//

#ifndef ALGORITHMS_AND_STRUCTURES_XORMULTIPLYINGHASHTABLE_H
#define ALGORITHMS_AND_STRUCTURES_XORMULTIPLYINGHASHTABLE_H

#include "HashTable.h"

class XorMultiplyingHashTable : public HashTable {

private:
    int* r;

public:
    explicit XorMultiplyingHashTable(int numberOfBuckets, int stringLength) : HashTable(numberOfBuckets) {
        r = new int[stringLength];
        for (int i = 0; i < numberOfBuckets; ++i) {
            r[i] = rand() % 127 + 64;
        }
    }

    void addValue(std::string value) override {
        double A = (sqrt(5) - 1)/2;
        int index = multiplyingHashFunction(stringToIntSumByXor(value, r), numberOfBuckets, A);

        this->array[index].add(value);
    }
};


#endif //ALGORITHMS_AND_STRUCTURES_XORMULTIPLYINGHASHTABLE_H
