#include <random>
#include <iostream>
#include "structures/table/closedHashing/HashTable.h"
#include "structures/table/closedHashing/LinearProbingDivisionHashTable.h"
#include "structures/table/closedHashing/LinearProbingMultiplyingHashTable.h"
#include "structures/table/closedHashing/QuadraticProbingDivisionHashTable.h"
#include "structures/table/closedHashing/QuadraticProbingMultiplyingHashTable.h"

#define STRINGS 10000
#define BUCKETS 100
#define CHARS_IN_STRING 6
#define MAX_I_VALUE 10
#define C_VALUE 4
#define D_VALUE 4

std::string intArrToStr(int* arr, int sizeOfArr){
    std::string str;
    for (int i = 0; i < sizeOfArr; ++i) {
        str+= std::to_string(i) + ':'  + std::to_string(arr[i]) + '\n';
    }

    return str;
}

std::string random_string(int length)
{
    std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

    std::random_device rd;
    std::mt19937 generator(rd());

    std::shuffle(str.begin(), str.end(), generator);

    return str.substr(0, length);
}

int main() {

    HashTable *linearDivisionTable = new LinearProbingDivisionHashTable(BUCKETS, MAX_I_VALUE, CHARS_IN_STRING, C_VALUE);
    HashTable *linearMultiplyingTable = new LinearProbingMultiplyingHashTable(BUCKETS, MAX_I_VALUE, CHARS_IN_STRING, C_VALUE);
    HashTable *quadraticDivisionTable = new QuadraticProbingDivisionHashTable(BUCKETS, MAX_I_VALUE, CHARS_IN_STRING, C_VALUE, D_VALUE);
    HashTable *quadraticMultiplyingTable = new QuadraticProbingMultiplyingHashTable(BUCKETS, MAX_I_VALUE, CHARS_IN_STRING, C_VALUE, D_VALUE);

    for (int i = 0; i < STRINGS; ++i) {
        std::string str = random_string(CHARS_IN_STRING);
        linearDivisionTable->add(str);
        linearMultiplyingTable->add(str);
        quadraticDivisionTable->add(str);
        quadraticMultiplyingTable->add(str);
    }

    std::cout << "Average steps to add in tables:\n\n" <<
              "Division table with linear probing: \n" << linearDivisionTable->getAverageStepsToAdd() <<
              "; its size: " << linearDivisionTable->getSize() << '\n' <<
              "Multiplying table with linear probing: \n" << linearMultiplyingTable->getAverageStepsToAdd() <<
              "; its size: " << linearMultiplyingTable->getSize() << '\n' <<
              "Division table with quadratic probing: \n" << quadraticDivisionTable->getAverageStepsToAdd() <<
              "; its size: " << quadraticDivisionTable->getSize() << '\n' <<
              "Multiplying table with quadratic probing: \n" << quadraticMultiplyingTable->getAverageStepsToAdd() <<
              "; its size: " << quadraticMultiplyingTable->getSize();

    return 0;
}
