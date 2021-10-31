//
// Created by Andrew on 31.10.2021.
//

#ifndef ALGORITHMS_AND_STRUCTURES_MULTIPLYINGHASHTABLE_H
#define ALGORITHMS_AND_STRUCTURES_MULTIPLYINGHASHTABLE_H

#include <string>
#include "HashTable.h"
#include <cmath>
class MultiplyingHashTable : public HashTable{

public:
    explicit MultiplyingHashTable(int numberOfBuckets) : HashTable(numberOfBuckets) {}

    void addValue(std::string value) override {
        double A = (sqrt(5) - 1)/2;
        int index = multiplyingHashFunction(value, numberOfBuckets, A);
        this->array[index].add(value);
    }
};


#endif //ALGORITHMS_AND_STRUCTURES_MULTIPLYINGHASHTABLE_H
