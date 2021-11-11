//
// Created by Andrew on 03.11.2021.
//

#ifndef ALGORITHMS_AND_STRUCTURES_QUADRATICPROBINGDIVISIONHASHTABLE_H
#define ALGORITHMS_AND_STRUCTURES_QUADRATICPROBINGDIVISIONHASHTABLE_H
#include "HashTable.h"
#include "../../../algorithms/hash_functions.h"

class QuadraticProbingDivisionHashTable : public HashTable {
private:
    int cValue;
    int dValue;

public:

    QuadraticProbingDivisionHashTable(int numberOfBuckets, int iMaxValue, int stringLength, int cValue, int dValue)
            : HashTable(numberOfBuckets, iMaxValue, stringLength), cValue(cValue), dValue(dValue) {}

    int addValue(std::string value) override {
        int hashResult = divisionHashFunction(stringToIntSumByXor(value, r), numberOfBuckets);

        int i;
        for  (i = 0; i < iMaxValue; ++i) {
            if (insert(hashResult + cValue * i + dValue * i * i, &value) % numberOfBuckets == 0)
                break;
        }

        return i;
    }
};


#endif //ALGORITHMS_AND_STRUCTURES_QUADRATICPROBINGDIVISIONHASHTABLE_H
