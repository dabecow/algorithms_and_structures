//
// Created by Andrew on 31.10.2021.
//

#ifndef ALGORITHMS_AND_STRUCTURES_LINKEDLIST_H
#define ALGORITHMS_AND_STRUCTURES_LINKEDLIST_H

#include "List.h"

template<class T>
class LinkedList : List<T> {
private:

    struct Node{
        T data;
        Node* next;
    };

    Node* HEAD;
    Node* TAIL;

public:
    LinkedList(): List<T>()  {
        this->HEAD = nullptr;
        this->TAIL = nullptr;
    }

    using List<std::string>::getSize;

    void clear() override {
        if (TAIL == nullptr)
            return;

        Node* iterator = HEAD;

        while (iterator != nullptr){
            Node* objectToDelete = iterator;
            iterator = iterator->next;
            delete objectToDelete;
        }

        HEAD = nullptr;
        TAIL = nullptr;

        this->size = 0;
    }

    int add(T t) override {
        Node* node = new Node;
        node->data = t;

        node->next = nullptr;

        if (HEAD == nullptr)
            HEAD = node;

        TAIL = node;

        this->size++;

        return 0;
    }

    Node *getHead() const {
        return HEAD;
    }

    Node *getTail() const {
        return TAIL;
    }


};


#endif //ALGORITHMS_AND_STRUCTURES_LINKEDLIST_H
