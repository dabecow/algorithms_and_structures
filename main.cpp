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

    HashTable *linearDivisionTable = new LinearProbingDivisionHashTable(BUCKETS, MAX_I_VALUE, C_VALUE);
    HashTable *linearMultiplyingTable = new LinearProbingMultiplyingHashTable(BUCKETS, MAX_I_VALUE, C_VALUE);
    HashTable *quadraticDivisionTable = new QuadraticProbingDivisionHashTable(BUCKETS, MAX_I_VALUE, C_VALUE, D_VALUE);
    HashTable *quadraticMultiplyingTable = new QuadraticProbingMultiplyingHashTable(BUCKETS, MAX_I_VALUE, C_VALUE, D_VALUE);

    for (int i = 0; i < STRINGS; ++i) {
        std::string str = random_string(CHARS_IN_STRING);
        linearDivisionTable->add(str);
        linearMultiplyingTable->add(str);
        quadraticDivisionTable->add(str);
        quadraticMultiplyingTable->add(str);
    }

    std::cout << "Collisions in tables by buckets:\n" <<
              "Division table: \n" << intArrToStr(divisionTable->countCollisions(), BUCKETS) << '\n' <<
              "Multiplying table: \n" << intArrToStr(multiplyingTable->countCollisions(), BUCKETS) << '\n' <<
              "Xor division table: \n" << intArrToStr(xorDivisionTable->countCollisions(), BUCKETS) << '\n' <<
              "Xor multiplying table: \n" << intArrToStr(xorMultiplying->countCollisions(), BUCKETS);

    return 0;
}
