//
// Created by Andrew on 22.09.2021.
//

#ifndef ALGORITHMS_AND_STRUCTURES_DETAIL_H
#define ALGORITHMS_AND_STRUCTURES_DETAIL_H

#include <string>

class Detail {
private:
    std::string name;
    int timeToProduce;

public:
    Detail(std::string name, int timeToProduce);

    const std::string &getName() const;

    int getTimeToProduce() const;
};


#endif //ALGORITHMS_AND_STRUCTURES_DETAIL_H
