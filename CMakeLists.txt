cmake_minimum_required(VERSION 3.15)
project(algorithms_and_structures)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithms_and_structures main.cpp Structures/queue/LinkedQueue.h Structures/queue/Queue.h Structures/queue/ArrayQueue.h model/Detail.cpp model/Detail.h model/Producer.cpp model/Producer.h Structures/List/List.h Structures/List/MultiLinkedList.h Structures/List/ArrayList.h Structures/List/Container.h)