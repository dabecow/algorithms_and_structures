#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stdio.h>

struct Root{
    Root* left;
    Root* right;
    int key;
};

class BinaryTree{
private:
    Root* mainRoot;

private:
    Root* allocRoot(int key){
        Root* root = new Root();
        root->left = nullptr;
        root->right = nullptr;
        root->key = key;
        return root;
    }

    Root* rAppend(Root* root, int key){
        if(root == nullptr){
            root = allocRoot(key);
            return root;
        }

        if(root->key < key){
            return rAppend(root->left, key);
        }else{
            return rAppend(root->right, key);
        }
    }

    Root* rFind(Root* root, int key){
        if(root == nullptr)
            return nullptr;

        if(root->key == key)
            return root;
        
        if(root->key < key){
            if(root->left == nullptr){
                return nullptr;
            }else{
                return rFind(root->left, key);
            }
        }else{
            if(root->right == nullptr){
                return nullptr;
            }else{
                return rFind(root->right, key);
            }
        }
    }

public:
    BinaryTree(){
        mainRoot = nullptr;
    }

    Root* find(int key){
        return rFind(mainRoot, key);
    }

    void append(int key){
        Root* root = find(key);
        if(root == nullptr){
            Root* newRoot = rAppend(mainRoot, key);
            if(mainRoot == nullptr)
                mainRoot = newRoot;
            printf("Done!");
        }else{
            printf("Allready in tree!");
        }
    }

    Root* fill(int* data, int lenght){
        for(int i = 0; i < lenght; i++){
            append(data[i]);
        }

        return mainRoot;
    }
};

#endif