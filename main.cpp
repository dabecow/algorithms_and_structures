#include <iostream>
#include "Structures/queue/Queue.h"
#include "Structures/queue/LinkedQueue.h"
#include "model/Detail.h"
#include "model/Producer.h"
#include <thread>
#include "Structures/tree/BinaryTree.h"
#include "Structures/tree/MixSearch.h"
#include "Structures/tree/UpwardSearch.h"
#include "Structures/tree/DownwardSearch.h"

using namespace std::chrono_literals;

const std::string MAIN_MENU = "1. Add detail\n2. Remove detail\n3. Print details\n4. Reset the producer\n>>>";

char printMenuGetChoice(){
    std::cout << MAIN_MENU;

    char choice;

    std::cin >> choice;

    return choice;
}

int main() {

    int keys[] = {7, 10, 5, 1, 4, 11, 9, 6, 2, 3, 0};

    BinaryTree* tree = new BinaryTree();
    Root* root = tree->fill(keys, 11);

    Root* mroot = mfind(root, 3);
    ufind(root);
    int depth = dfind(root);

    Node* roots = mainHead;

    // tree->remove(1);

    return 0;
}
