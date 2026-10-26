#include <iostream>
#include "binaryTree.h"

int main(){
	BinaryTree<char>* root = new BinaryTree<char>('A');
	
	std::cout << "The root is: " << root->getRootVal();
	std::cout << std::endl;
	
	root->insertLeft('B');
	std::cout << "The left child of root A: " << root->getLeftChild()->getRootVal() << std::endl;
	
	root->getLeftChild()->insertLeft('D');
	std::cout << "The left child of root B: " << root->getLeftChild()->getLeftChild()->getRootVal() << std::endl;
	
	root->getLeftChild()->insertRight('E');
	std::cout << "The right child of root B: " << root->getLeftChild()->getRightChild()->getRootVal() << std::endl;
	
	root->insertRight('C');
	std::cout << "The right child of root A: " << root->getRightChild()->getRootVal() << std::endl;
	
	root->getRightChild()->insertLeft('F');
	std::cout << "The left child of root C: " << root->getRightChild()->getLeftChild()->getRootVal() << std::endl;
	
	root->getRightChild()->insertRight('G');
	std::cout << "The right child of root C: " << root->getRightChild()->getRightChild()->getRootVal() << std::endl;
	
	// Setting root value
	root->setRootVal('Z');
	std::cout << "The new root is: " << root->getRootVal() << std::endl;
	
	// Testing isLeaf()
	std::cout << "Is A a leaf? " << root->isLeaf() << std::endl;
	
	std::cout << "Is D a leaf? " << root->getLeftChild()->getLeftChild()->isLeaf() << std::endl;
	return 0;
}	
