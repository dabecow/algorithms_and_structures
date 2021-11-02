#ifndef DOWNWARDSEARCH_H
#define DOWNWARDSEARCH_H

#include "BinaryTree.h"
#include <stack>

using namespace std;

struct RootCell{
    int depth;
    Root* root;
};

static int depth = 0;
static stack<RootCell*> roots;

int dfind(Root* root){
    Root* iroot = root;
    int ldepth = 0;
    roots = stack<RootCell*>();
    while(iroot){
        if(iroot->left && iroot->right){
            ldepth++;
            roots.push(new RootCell({ldepth, iroot->right}));
            iroot = iroot->left;
        }else if(!iroot->left && !iroot->right){
            if(ldepth > depth)
                depth = ldepth;
            
            RootCell* cell = nullptr;
            if(roots.size() > 0)
                cell = roots.top();
            else
                return depth;

            if(cell){
                roots.pop();
                ldepth = cell->depth;
                iroot = cell->root;
                delete cell;
            }
        }else if(iroot->left || iroot->right){
            ldepth++;
            if(iroot->left)
                iroot = iroot->left;
            else
                iroot = iroot->right;
        }
    }

    return 0;
}



#endif