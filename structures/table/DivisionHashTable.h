//
// Created by Andrew on 31.10.2021.
//

#ifndef ALGORITHMS_AND_STRUCTURES_DIVISIONHASHTABLE_H
#define ALGORITHMS_AND_STRUCTURES_DIVISIONHASHTABLE_H

#include <string>
#include "HashTable.h"

class DivisionHashTable : HashTable {

public:
    explicit DivisionHashTable(int numberOfBuckets) : HashTable(numberOfBuckets) {}

    void addValue(std::string value) override {
        int index = divisionHashFunction(value, this->numberOfBuckets);

        this->array[index].add(value);
    }
};


#endif //ALGORITHMS_AND_STRUCTURES_DIVISIONHASHTABLE_H
