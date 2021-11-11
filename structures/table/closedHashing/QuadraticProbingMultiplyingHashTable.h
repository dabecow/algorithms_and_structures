//
// Created by Andrew on 03.11.2021.
//

#ifndef ALGORITHMS_AND_STRUCTURES_QUADRATICPROBINGMULTIPLYINGHASHTABLE_H
#define ALGORITHMS_AND_STRUCTURES_QUADRATICPROBINGMULTIPLYINGHASHTABLE_H
#include "HashTable.h"
#include "../../../algorithms/hash_functions.h"

class QuadraticProbingMultiplyingHashTable : public HashTable{
private:
    int cValue;
    int dValue;

public:

    QuadraticProbingMultiplyingHashTable(int numberOfBuckets, int iMaxValue, int stringLength, int cValue, int dValue)
            : HashTable(numberOfBuckets, iMaxValue, stringLength), cValue(cValue), dValue(dValue) {}

    int addValue(std::string value) override {
        double A = (sqrt(5) - 1)/2;

        int hashResult = multiplyingHashFunction(stringToIntSumByXor(value, r), numberOfBuckets, A);

        int i;

        for (i = 0; i < iMaxValue; ++i) {
            if (insert((hashResult + cValue * i + dValue * i * i) % numberOfBuckets, &value) == 0)
                break;
        }

        return i;
    }
};


#endif //ALGORITHMS_AND_STRUCTURES_QUADRATICPROBINGMULTIPLYINGHASHTABLE_H
