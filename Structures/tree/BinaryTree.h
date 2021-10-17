#ifndef BINARYTREE_H
#define BINARYTREE_H

class BinaryTree{
private:
    struct Root{
        Root* left;
        Root* right;
        int data;
    };

    Root* mainRoot;

public:
    BinaryTree(){

    }
};

#endif