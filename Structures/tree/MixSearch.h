#ifndef MIXSEARCH_H
#define MIXSEARCH_H

#include "BinaryTree.h"

static int _pos = 0;
static int _reqPos;

Root* _mfind(Root* root){
    if(root == nullptr)
        return nullptr;

    Root* returned;

    _mfind(root->left);
    if(_pos == _reqPos)
        return root;
    _pos++;
    _mfind(root->right);

    return nullptr;
}

Root* mfind(Root* root, int reqPos){
    reqPos = reqPos;
    return _mfind(root);
}

#endif