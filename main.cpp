#include <random>
#include <iostream>
#include "structures/table/HashTable.h"
#include "structures/table/DivisionHashTable.h"
#include "structures/table/MultiplyingHashTable.h"
#include "structures/table/XorDivisionHashTable.h"
#include "structures/table/XorMultiplyingHashTable.h"
#define STRINGS 100
#define BUCKETS 6
#define CHARS_IN_STRING 6

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

    HashTable *divisionTable = new DivisionHashTable(BUCKETS);
    HashTable *multiplyingTable = new MultiplyingHashTable(BUCKETS);
    HashTable *xorDivisionTable = new XorDivisionHashTable(BUCKETS, CHARS_IN_STRING);
    HashTable *xorMultiplying = new XorMultiplyingHashTable(BUCKETS, CHARS_IN_STRING);

    for (int i = 0; i < STRINGS; ++i) {
        std::string str = random_string(CHARS_IN_STRING);
        divisionTable->addValue(str);
        multiplyingTable->addValue(str);
        xorDivisionTable->addValue(str);
        xorMultiplying->addValue(str);
    }

    std::cout << "Collisions in tables by buckets:\n" <<
              "Division table: \n" << intArrToStr(divisionTable->countCollisions(), BUCKETS) << '\n' <<
              "Multiplying table: \n" << intArrToStr(multiplyingTable->countCollisions(), BUCKETS) << '\n' <<
              "Xor division table: \n" << intArrToStr(xorDivisionTable->countCollisions(), BUCKETS) << '\n' <<
              "Xor multiplying table: \n" << intArrToStr(xorMultiplying->countCollisions(), BUCKETS);

    return 0;
}
