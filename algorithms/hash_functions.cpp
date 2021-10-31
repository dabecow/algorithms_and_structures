//
// Created by Andrew on 31.10.2021.
//

#include "hash_functions.h"
#include <cmath>

int stringToIntSum(const std::string& value){
    int integerValue = 0;

    for (char i : value) {
        integerValue+=(int) i;
    }

    return integerValue;
}

int divisionHashFunction(int value, int M){
    return value / M;
}

int multiplyingHashFunction(int value, int M, float A){
    float dummy;
    return (int) ( (float) M * modf(((float) value * A), &dummy));
}

int divisionHashFunction(const std::string& value, int M){
    return divisionHashFunction(stringToIntSum(value), M);
}

int multiplyingHashFunction(const std::string& value, int M, float A){
    return multiplyingHashFunction(stringToIntSum(value), M, A);
}

int xorHashFunction(const std::string& value, int *r){
    int sum = 0;

    for (int i = 0; i < value.size(); ++i) {
        sum += (int) value[i] ^ r[i];
    }
}