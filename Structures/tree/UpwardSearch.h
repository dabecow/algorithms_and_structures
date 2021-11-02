#ifndef UPWARDSEARCH_H
#define UPWARDSEARCH_H

#include <math.h>
#include "BinaryTree.h"

struct Node{
    Root* root;
    Node* next;
};

Node* mainHead;
static Node* mainTail;

void append(Root* root){
    Node* node = new Node();
    node->next = nullptr;
    node->root = root;

    if(mainHead == nullptr){
        mainHead = node;
        mainTail = node;
    }else{
        mainTail->next = node;
        mainTail = node;
    }
}

void clear(Node* head){
    if(head != nullptr){
        clear(head->next);
        delete head;
    }

    if(head == mainHead){
        mainHead = nullptr;
        mainTail = nullptr;
    }
}

// не совсем верно, я не правильно понимал как работатет дерево
//теперь поправил, но опять же это может работать не стабильно (наверное), 
//кароче кто нибудь в здравом уме почитайте

/** @brief Восходящий поиск поддеревьев у которых разница количества потомков на поддеревьях равна 1
 * @param root передать сюда главный корень дерева
 * @return колличество поддеревьев у корня, т.е. у всего дерева
 */ 
int ufind(Root* root){
    if(root != nullptr){
        int left = -1;
        int right = -1;
        if(root->left != nullptr){
            left = ufind(root->left); //1
        }
        if(root->right != nullptr){
            right = ufind(root->right); //0
        }
        if(abs(left - right) == 1){
            append(root);
        }
        if(left == -1 && right == -1)
            return 0;
        else if(left == -1)
            return right + 1;
        else if(right == -1)
            return left + 1;
        else
            return left + right + 2;
    }
    return -1;
}

#endif