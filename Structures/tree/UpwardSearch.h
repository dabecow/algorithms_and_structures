#ifndef UPWARDSEARCH_H
#define UPWARDSEARCH_H

#include "BinaryTree.h"

struct Node{
    Root* root;
    Node* next;
};

static Node* mainHead;
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

void find(Root* root){
    
}

#endif