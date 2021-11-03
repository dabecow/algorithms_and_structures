//
// Created by Andrew on 31.10.2021.
//

#include "hash_functions.h"
#include <cmath>

int stringToIntSumAdditive(const std::string& value){
    int integerValue = 0;

    for (char i : value) {
        integerValue+=(int) i;
    }

    return integerValue;
}

int stringToIntSumByXor(const std::string& value, const int *r){
    int sum = 0;

    for (int i = 0; i < value.size(); ++i) {
        sum += (int) value[i] ^ r[i];
    }
    return sum;
}

int divisionHashFunction(int value, int M){
    return value % M;
}

int multiplyingHashFunction(int value, int M, float A){
    double dummy;
    return (int) ( (float) M * modf(((float) value * A), &dummy));
}

