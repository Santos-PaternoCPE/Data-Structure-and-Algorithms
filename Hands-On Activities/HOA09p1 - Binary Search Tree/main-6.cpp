#include <iostream>
#include "BST.h"

int main(){

    BinarySearchTree<int>* tree = new BinarySearchTree(20);

    tree->insert(10);
    tree->insert(15);
    tree->insert(40);
    tree->insert(70);
    tree->insert(80);
    tree->insert(60);

    std::cout << "Pre order output: ";
    tree->preOrder();
    std::cout << "\n";

    std::cout << "In order output: ";
    tree->inOrder();
    std::cout << "\n";

    std::cout << "Post order output: ";
    tree->postOrder();
    std::cout << "\n";


    return 0;
}

