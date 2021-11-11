//
// Created by Andrew on 03.11.2021.
//

#ifndef ALGORITHMS_AND_STRUCTURES_LINEARPROBINGMULTIPLYINGHASHTABLE_H
#define ALGORITHMS_AND_STRUCTURES_LINEARPROBINGMULTIPLYINGHASHTABLE_H
#include "HashTable.h"
#include "../../../algorithms/hash_functions.h"

class LinearProbingMultiplyingHashTable : public HashTable{
private:

    int constValue;

public:

    LinearProbingMultiplyingHashTable(int numberOfBuckets, int iMaxValue, int stringLength, int constValue) : HashTable(
            numberOfBuckets, iMaxValue, stringLength), constValue(constValue) {}

    int addValue(std::string value) override {
        double A = (sqrt(5) - 1)/2;
        int hashResult = multiplyingHashFunction(stringToIntSumByXor(value, r), numberOfBuckets, A);

        int i;

        for (i = 0; i < iMaxValue; ++i) {
            if (insert((hashResult + constValue * i) % numberOfBuckets, &value) == 0)
                break;
        }

        return i;
    }
};


#endif //ALGORITHMS_AND_STRUCTURES_LINEARPROBINGMULTIPLYINGHASHTABLE_H
