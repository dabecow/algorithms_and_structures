#include <iostream>
#include "Structures/Queue.h"
#include "Structures/ArrayQueue.h"

int main() {

    ArrayQueue<int> *queue = new ArrayQueue<int>(5);

    queue->push(1);
    queue->push(2);
    queue->push(3);


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
