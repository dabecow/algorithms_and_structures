//
// Created by Andrew on 03.11.2021.
//

#ifndef ALGORITHMS_AND_STRUCTURES_LINEARPROBINGDIVISIONHASHTABLE_H
#define ALGORITHMS_AND_STRUCTURES_LINEARPROBINGDIVISIONHASHTABLE_H

#include "HashTable.h"
#include "../../../algorithms/hash_functions.h"

class LinearProbingDivisionHashTable : public HashTable {

private:
    int constValue;



public:

    LinearProbingDivisionHashTable(int numberOfBuckets, int iMaxValue, int constValue) :
        HashTable(numberOfBuckets, iMaxValue), constValue(constValue) {}

    int add(std::string value) override {
        int hashResult = divisionHashFunction(stringToIntSumByXor(value, r), numberOfBuckets);

        for (int i = 0; i < iMaxValue; ++i) {
            if (insert(hashResult + constValue * i, value) % numberOfBuckets == 0)
                return 0;
        }

        return -1;
    }
};


#endif //ALGORITHMS_AND_STRUCTURES_LINEARPROBINGDIVISIONHASHTABLE_H
