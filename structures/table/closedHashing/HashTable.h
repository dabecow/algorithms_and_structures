//
// Created by Andrew on 03.11.2021.
//


#ifndef ALGORITHMS_AND_STRUCTURES_HASHTABLE_H
#define ALGORITHMS_AND_STRUCTURES_HASHTABLE_H

#include <string>
#include <utility>

//the previous class HashTable was made as an abstract but we didn't know about the fifth lab where the hashtable has
//another structure and there are no much time for the lab sooo ladies and gentlemen

class HashTable {

protected:
    int* r;
    int numberOfBuckets;
    std::string** array;
    int iMaxValue;
    int stepsSum;
    int tries;
    int size;

    /**
     * The method which used by the other functions to try to add the value in the array
     *
     * @param idx – index in the array to insert the value
     * @param value
     * @return 0 if inserted, otherwise -1
     */
    int insert(int idx, std::string* value){
        if (array[idx] == nullptr){
            array[idx] = value;
            return 0;
        }

        return -1;
    }

    /**
     *
     * @param value
     * @return how many steps needed to add or -1 if couldn't add the value
     */
    virtual int addValue(std::string value) = 0;

public:


    explicit HashTable(int numberOfBuckets, int iMaxValue, int stringLength) : numberOfBuckets(numberOfBuckets), iMaxValue(iMaxValue) {
        array = new std::string*[numberOfBuckets];
        r = new int[stringLength];
        for (int i = 0; i < 6; ++i) {
            r[i] = rand() % 127 + 64;
        }

        for (int i = 0; i < numberOfBuckets; ++i) {
            array[i] = nullptr;
        }
        stepsSum = 0;
        tries = 0;
    }

    int add(std::string value) {
        int result = addValue(std::move(value));

        if (result == 10) {
            tries++;
            stepsSum+=10;
            return -1;
        }

        size++;

        tries++;
        stepsSum+=result;

        return 0;
    }

    float getAverageStepsToAdd() const{
        return (float) stepsSum / (float) tries;
    }

    int getSize() const {
        return size;
    }
};


#endif //ALGORITHMS_AND_STRUCTURES_HASHTABLE_H
