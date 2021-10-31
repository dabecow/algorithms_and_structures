//
// Created by Andrew on 25.09.2021.
//

#ifndef ALGORITHMS_AND_STRUCTURES_MULTILINKEDLIST_H
#define ALGORITHMS_AND_STRUCTURES_MULTILINKEDLIST_H

#include "List.h"
#include "ArrayList.h"

template<class T>
class Node {

public:

    Node<T> **nextPtrs;

    T data;

    Node(T data, int indexesSize) : data(data) {
        nextPtrs = new Node<T>*[indexesSize];
    }

};

template<class T>
class MultiLinkedList {

private:

    Node<T>** heads;
    Node<T>** tails;
    int indexesSize;

public:

    explicit MultiLinkedList(int size) {
        heads = new int[size];
        tails = new int[size];

        for (int i = 0; i < size; ++i) {
                heads[i] = nullptr;
                tails[i] = nullptr;
        }

        this->indexesSize = size;
    }



    int add(T t, const int* indexes, int size) {
        auto *node = new Node<T>(t);

        for (int i = 0; i < size; ++i) {

            if (heads[indexes[i]] == nullptr){
                heads[indexes[i]] = node;
                tails[indexes[i]] = node;
            } else {
                tails[indexes[i]]->nextPtrs[indexes[i]] = node;
                tails[indexes[i]] = node;
            }
        }

        return 0;
    }

    Node<T>* find(T data){
        Node<T>* iterator = heads[0];

        Node<T>* exactNode = nullptr;

        while (iterator != nullptr){

            if (iterator->data == data) {
                exactNode = iterator;
                break;
            }

            iterator = iterator->nextPtrs[0];
        }

        return exactNode;
    }

    /**
     * Метод для ситуации, когда удаляемое звено в конце, либо в середине списка.
     * @param nodeToRemove - звено, которое нужно удалить
     * @param previousNode - предыдущее звено
     * @param index - индекс списка
     * @return код выполнения
     */
    int remove(Node<T>* nodeToRemove, Node<T>* previousNode, int index){
        if (tails[index] == nodeToRemove){
            tails[index] = previousNode;
        } else {
            previousNode->nextPtrs[index] = nodeToRemove->nextPtrs[index];
        }
    }

    int remove(Node<T>* node){

        if (node == nullptr) {
            return -1;
        }

        for (int i = 0; i < indexesSize; ++i) {

            if (heads[i] == nullptr){
                continue;
            }

            if (node == heads[i]){
                if (node->nextPtrs[i] == nullptr){
                    heads[i] = nullptr;
                    tails[i] = nullptr;
                } else {
                    heads[i] = node->nextPtrs[i];
                }
            } else if (heads[i] != tails[i]){

                Node<T>* iterator = heads[i];

                while (iterator->nextPtrs[i] != node || iterator->nextPtrs != nullptr){
                    iterator = iterator->nextPtrs[i];
                }

                if (iterator->nextPtrs == nullptr)
                    continue;

                remove(node, iterator, i);

            }
        }

        delete node;

        return 0;
    }

    void clear() {

        Node<T>* previousNode = heads[0];

        if (previousNode == nullptr)
            return;

        Node<T>* iterator = previousNode->nextPtrs[0];

        if (iterator == nullptr){
            delete previousNode;
            return;
        }

        do {
            delete previousNode;
            previousNode = iterator;
            iterator = iterator->nextPtrs[0];
        } while (iterator != nullptr);

        for (int i = 0; i < indexesSize; ++i) {
            heads[i] = nullptr;
            tails[i] = nullptr;
        }
    }


    Node<T>* getListHeadByIndex(int index){
        return heads[index];
    }

};


#endif //ALGORITHMS_AND_STRUCTURES_MULTILINKEDLIST_H
