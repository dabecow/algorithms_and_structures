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
        
        if(root->key < key) {
            return rFind(root->left, key);

        } else {

            return rFind(root->right, key);
        }

    }

    Root* rFindParent(Root* baseRoot, int key){
        if (baseRoot == nullptr)
            return baseRoot;

        if (key < baseRoot->key){
            if (baseRoot->left != nullptr){
                if (baseRoot->left->key == key)
                    return baseRoot;
                else
                    return rFindParent(baseRoot->left, key);
            }
        } else {
            if (baseRoot->right != nullptr){
                if (baseRoot->right->key == key)
                    return baseRoot;
                else
                    return rFindParent(baseRoot->right, key);
            }
        }

        if
    }

    bool isLeaf(Root* root){
        return root->left == nullptr && root->right == nullptr;
    }

    int rHeight(Root* root){

        if (isLeaf(root))
            return 1;

        if (root->right == nullptr) {
            return 1 + getHeight(root->left);
        } else if (root->left == nullptr) {
            return 1 + getHeight(root->right);
        }

        return 1 + std::max(getHeight(root->left, root->right));
    }

    int rRemove(Root* baseRoot, int key){
        Root* rootToRemove = rFind(baseRoot, key);

        if (rootToRemove == nullptr){
            return -1;
        }

        Root* parentRoot = rFindParent(rootToRemove, key);

        bool derivedRootIsLeft = rootToRemove->key < parentRoot->key;

        if (rootToRemove->left == nullptr){

            if (rootToRemove->right == nullptr){
                if (derivedRootIsLeft)
                    parentRoot->left = nullptr;
                else
                    parentRoot->right = nullptr;
            } else {
                if (derivedRootIsLeft)
                    parentRoot->left = rootToRemove->right;
                else
                    parentRoot->right = rootToRemove->right;
            }

        } else {

            if (rootToRemove->right == nullptr){
                if (derivedRootIsLeft)
                    parentRoot->left = rootToRemove->left;
                else
                    parentRoot->right = rootToRemove->left;
            } else {

                Root* rootToReplace = rootToRemove;

                parentRoot = rootToRemove;
                rootToRemove = rootToRemove->right;

                while (rootToRemove->left != nullptr) {
                    parentRoot = rootToRemove;
                    rootToRemove = rootToRemove->left;
                }

                rootToReplace->key = rootToRemove->key;
                parentRoot->left = nullptr;
            }

        }

        delete rootToRemove;
        return 0;
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

        if(root == nullptr) {
            Root* newRoot = rAppend(mainRoot, key);

            if(mainRoot == nullptr)
                mainRoot = newRoot;

            printf("Key added: %d", key);
        } else {
            printf("Key already exist: %d", key);
        }
    }

    Root* fill(int* data, int lenght){
        for(int i = 0; i < lenght; i++){
            append(data[i]);
        }

        return mainRoot;
    }

    int height(){
        return rHeight(mainRoot);
    }


    int remove(int key){
        rRemove(mainRoot, key);
    }
};

#endif