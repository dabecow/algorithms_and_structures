//
// Created by Andrew on 31.10.2021.
//

#ifndef ALGORITHMS_AND_STRUCTURES_HASH_FUNCTIONS_H
#define ALGORITHMS_AND_STRUCTURES_HASH_FUNCTIONS_H

#include <string>

int stringToIntSumAdditive(const std::string& value);

int stringToIntSumByXor(const std::string& value, const int *r);

int divisionHashFunction(int value, int M);

int multiplyingHashFunction(int value, int M, float A);




#endif //ALGORITHMS_AND_STRUCTURES_HASH_FUNCTIONS_H
