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

    int add(std::string value) override {
        double A = (sqrt(5) - 1)/2;
        int hashResult = multiplyingHashFunction(stringToIntSumByXor(value, r), numberOfBuckets, A);

        for (int i = 0; i < iMaxValue; ++i) {
            if (insert(hashResult + constValue * i, &value) % numberOfBuckets == 0)
                return 0;
        }

        return -1;
    }
};


#endif //ALGORITHMS_AND_STRUCTURES_LINEARPROBINGMULTIPLYINGHASHTABLE_H
