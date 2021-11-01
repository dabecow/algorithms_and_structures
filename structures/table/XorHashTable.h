//
// Created by Andrew on 31.10.2021.
//

#ifndef ALGORITHMS_AND_STRUCTURES_XORHASHTABLE_H
#define ALGORITHMS_AND_STRUCTURES_XORHASHTABLE_H

#include "HashTable.h"
class XorHashTable : public HashTable{

private:
    int* r;

public:
    explicit XorHashTable(int numberOfBuckets, int stringLength) : HashTable(numberOfBuckets) {
        r = new int[stringLength];
        for (int i = 0; i < numberOfBuckets; ++i) {
            r[i] = rand() % 1023 + 540;
        }
    }

    void addValue(std::string value) override {
        int index = xorHashFunction(value, r);

        this->array[index % numberOfBuckets].add(value);
    }
};


#endif //ALGORITHMS_AND_STRUCTURES_XORHASHTABLE_H
