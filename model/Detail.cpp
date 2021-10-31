//
// Created by Andrew on 22.09.2021.
//

#include "Detail.h"


Detail::Detail(std::string name, int timeToProduce) : name(name), timeToProduce(timeToProduce) {}

const std::string &Detail::getName() const {
    return name;
}

int Detail::getTimeToProduce() const {
    return timeToProduce;
}
