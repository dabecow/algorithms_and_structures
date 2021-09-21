#include <iostream>
#include "Structures/Queue.h"
#include "Structures/ArrayQueue.h"

int main() {

    ArrayQueue<int> queue(5);

    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);


    std::cout << *queue.first() << std::endl;
    queue.pop();
    std::cout << *queue.first() << std::endl;
    queue.pop();
    std::cout << *queue.first() << std::endl;
    queue.pop();
    std::cout << *queue.first() << std::endl;
    queue.pop();
    std::cout << *queue.first() << std::endl;
    queue.pop();

    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);

    int *arr = queue.data();

    std::cout << arr[0] << std::endl;
    std::cout << arr[1] << std::endl;
    std::cout << arr[2] << std::endl;
    std::cout << arr[3] << std::endl;
    std::cout << arr[4] << std::endl;



    return 0;
}
