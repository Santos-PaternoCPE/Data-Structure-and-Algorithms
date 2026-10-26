#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>

template<class T>
class BinaryTree{
	private:
		// key
		T key;
		
		// pointer for left and right child.
		BinaryTree<T>* leftChild;
		BinaryTree<T>* rightChild;
		
		
	public:
		// Constructor
		BinaryTree(T rootObj);
		
		// Insert chidren insert left and right
		void insertLeft(T newNode);
		void insertRight(T newNode);
		
		// To access child nodes
		BinaryTree<T>* getLeftChild();
		BinaryTree<T>* getRightChild();
		
		// Get root value and set root node
		T getRootVal();
		void setRootVal(T obj);
		
		// Node checker if leaf
		bool isLeaf();
		
};

template<class T>
BinaryTree<T>::BinaryTree(T rootObj){
	key = rootObj;
	leftChild = NULL;
	rightChild = NULL;
	std::cout << "Root was created \n";
}

template<class T>
T BinaryTree<T>::getRootVal(){
	return key;
}

template<class T>
void BinaryTree<T>::insertLeft(T newNode){
	// Two types
	
	// If currently no child
	if(leftChild == NULL){
		leftChild = new BinaryTree<T>(newNode);
	}
	
	// If want to insert a certain node
	else{
		// Create new node:
		BinaryTree<T>* newChild = new BinaryTree<T>(newNode);
		
		// Move existing left child below new node
		newChild->leftChild = leftChild;
		
		// Make new node as left child
		leftChild = newChild;
	}
}

template<class T>
BinaryTree<T> *BinaryTree<T>::getLeftChild(){
	return leftChild;
}

template<class T>
BinaryTree<T>* BinaryTree<T>::getRightChild(){
	return rightChild;
}

template<class T>
void BinaryTree<T>::insertRight(T newNode){
	// If currently no right child
	if(rightChild == NULL){
		rightChild = new BinaryTree<T>(newNode);
	}
	
	// If there is already a right child
	else{
		// Create new node
		BinaryTree<T>* newChild = new BinaryTree<T>(newNode);
		
		// Move existing right child below new node
		newChild->rightChild = rightChild;
		
		// Make new node the right child
		rightChild = newChild;
	}
}

template<class T>
void BinaryTree<T>::setRootVal(T obj){
	key = obj;
}

template<class T>
bool BinaryTree<T>::isLeaf(){
	return leftChild == NULL && rightChild == NULL;
}

#endif
