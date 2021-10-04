//
// Created by Andrew on 25.09.2021.
//

#ifndef ALGORITHMS_AND_STRUCTURES_NODE_H
#define ALGORITHMS_AND_STRUCTURES_NODE_H

template<class T>
class Node {

private:

    Node<T> *next = nullptr;
    Node<T> *prev = nullptr;

    T t;

public:

    Node() {}

    Node(Node<T> *next, Node<T> *prev, T t) : next(next), prev(prev), t(t) {}

    Node(T t) : t(t) {
        this->prev = nullptr;
        this->next = nullptr;
    }

    Node<T> *getNext() const {
        return next;
    }

    void setNext(Node<T> *next) {
        Node::next = next;
    }

    Node<T> *getPrev() const {
        return prev;
    }

    void setPrev(Node<T> *prev) {
        Node::prev = prev;
    }

    T getT() const {
        return t;
    }

    void setT(T t) {
        Node::t = t;
    }
};


#endif //ALGORITHMS_AND_STRUCTURES_NODE_H
