//
// Created by Andrew on 31.10.2021.
//

#ifndef ALGORITHMS_AND_STRUCTURES_HASH_FUNCTIONS_H
#define ALGORITHMS_AND_STRUCTURES_HASH_FUNCTIONS_H

#include <string>

int stringToIntSum(const std::string& value);

int divisionHashFunction(int value, int M);

int multiplyingHashFunction(int value, int M, float A);

int divisionHashFunction(const std::string& value, int M);

int multiplyingHashFunction(const std::string& value, int M, float A);

int xorHashFunction(const std::string& value, int *r);

#endif //ALGORITHMS_AND_STRUCTURES_HASH_FUNCTIONS_H
