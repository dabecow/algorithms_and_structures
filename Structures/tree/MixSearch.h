#ifndef MIXSEARCH_H
#define MIXSEARCH_H

#include "BinaryTree.h"

static int _pos = 0;
static int _reqPos;

static Root* _mfind(Root* root){
    if(root == nullptr)
        return nullptr;

    Root* returned = nullptr;

    returned = _mfind(root->left);
    if(returned)
        return returned;
    if(_pos == _reqPos)
        return root;
    _pos++;
    returned = _mfind(root->right);

    return returned;
}

Root* mfind(Root* root, int reqPos){
    _reqPos = reqPos;
    return _mfind(root);
}

#endif