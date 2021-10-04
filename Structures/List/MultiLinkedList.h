//
// Created by Andrew on 25.09.2021.
//

#ifndef ALGORITHMS_AND_STRUCTURES_MULTILINKEDLIST_H
#define ALGORITHMS_AND_STRUCTURES_MULTILINKEDLIST_H

#include "List.h"
#include "ArrayList.h"
template<class T>
class MultiLinkedList : public List<T>{

private:
    Node<T> *head;
    Node<T> *tail;
    ArrayList<Node<T>*> indexesHeads;
    ArrayList<Node<T>*> indexesTails;


public:
    MultiLinkedList(): List<T>() {}

    Iterator<T> *getHead() const {
        return head;
    }

    Iterator<T> *getTail() const {
        return tail;
    }


    void clear() override {
        for (Iterator<T> i = begin; i != end; ++i) {
            //todo: check for bugs
            delete i.getNode();
        }
    }

    int add(T t) override {
        Node<T> *node = new Node<T>(t);

        Node<T> *prevNode = this->iterator->getNode();

        prevNode->setNext(node);
        node->setPrev(prevNode);

//        ->getNext() = new Node(t);
//        return List::addAfter(t);
    }

    int addIndex(){
        Node<T> *indexHead = new Node<T>();

        this->indexesHeads.add(indexHead);
    }

    void addToIndex(int indexHead, T t){

    }
};


#endif //ALGORITHMS_AND_STRUCTURES_MULTILINKEDLIST_H
