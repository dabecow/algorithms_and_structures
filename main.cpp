#include <iostream>
//#include "Structures/Queue.h"
#include "Structures/ArrayQueue.h"

int main() {

    ArrayQueue<int> *queue = new ArrayQueue<int>(5);

    queue->push(1);
    queue->push(2);
    queue->push(3);

    int value = queue->pop();

    std::cout << value << std::endl;
    return 0;
}
