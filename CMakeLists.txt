cmake_minimum_required(VERSION 3.15)
project(algorithms_and_structures)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithms_and_structures main.cpp structures/queue/LinkedQueue.h structures/queue/Queue.h structures/queue/ArrayQueue.h model/Detail.cpp model/Detail.h model/Producer.cpp model/Producer.h structures/list/List.h structures/list/MultiLinkedList.h structures/list/ArrayList.h structures/tree/BinaryTree.h structures/tree/UpwardSearch.h algorithms/hash_functions.cpp algorithms/hash_functions.h structures/table/HashTable.h structures/list/LinkedList.h structures/table/DivisionHashTable.h structures/table/MultiplyingHashTable.h structures/table/XorDivisionHashTable.h structures/table/XorMultiplyingHashTable.h)