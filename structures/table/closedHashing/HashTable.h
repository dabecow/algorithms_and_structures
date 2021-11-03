//
// Created by Andrew on 03.11.2021.
//


#ifndef ALGORITHMS_AND_STRUCTURES_HASHTABLE_H
#define ALGORITHMS_AND_STRUCTURES_HASHTABLE_H

#include <string>

//the previous class HashTable was made as an abstract but we didn't know about the fifth lab where the hashtable has
//another structure and there are no much time for the lab sooo ladies and gentlemen

class HashTable {

protected:
    int* r;
    int numberOfBuckets;
    std::string* array;
    int iMaxValue;

    int insert(int idx, const std::string& value){
        if (array[idx] == nullptr){
            array[idx] = value;
            return 0;
        }

        return -1;
    }

public:

    explicit HashTable(int numberOfBuckets, int iMaxValue) : numberOfBuckets(numberOfBuckets), iMaxValue(iMaxValue) {
        array = new std::string[numberOfBuckets];
        r = new int[stringLength];
        for (int i = 0; i < 6; ++i) {
            r[i] = rand() % 127 + 64;
        }

        for (int i = 0; i < numberOfBuckets; ++i) {
            array[i] = nullptr;
        }
    }

    virtual int add(std::string value) = 0;
};


#endif //ALGORITHMS_AND_STRUCTURES_HASHTABLE_H
