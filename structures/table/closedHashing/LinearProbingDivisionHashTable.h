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

    LinearProbingDivisionHashTable(int numberOfBuckets, int iMaxValue, int stringLength, int constValue) : HashTable(
            numberOfBuckets, iMaxValue, stringLength), constValue(constValue) {}

    int addValue(std::string value) override {
        int hashResult = divisionHashFunction(stringToIntSumByXor(value, r), numberOfBuckets);

        int i;
        for (i = 0; i < iMaxValue; ++i) {
            if (insert(hashResult + constValue * i, &value) % numberOfBuckets == 0)
                break;
        }

        return i;
    }
};


#endif //ALGORITHMS_AND_STRUCTURES_LINEARPROBINGDIVISIONHASHTABLE_H
