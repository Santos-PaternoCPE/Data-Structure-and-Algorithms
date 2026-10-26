#include <iostream>
#include <cstdlib>
#include <time.h>
#include "node.h"
#include "searchingAlgo.h"

const int max_size = 50;

int main (){
	// Generate random values
	int dataset[max_size];
	srand(time(0));
	
	for(int i = 0; i < max_size; i++){
		dataset[i] = rand();
	}
	for(int i = 0; i < max_size; i++){
		std::cout << dataset[i] << " ";
	}
	std::cout << std::endl;
	
	int userInput;
	
	// Testing Array using LS
	std::cout << "What number to search?\n";
	std::cin >> userInput;
	std::cout << "Array result LS: ";
	
	linearSearchArr(max_size, userInput, dataset);
	
	// Create linked list: S A N T O S
	Node<char>* name1 = new_node('S');
	Node<char>* name2 = new_node('A');
	Node<char>* name3 = new_node('N');
	Node<char>* name4 = new_node('T');
	Node<char>* name5 = new_node('O');
	Node<char>* name6 = new_node('S');
	
	// Linking
	name1->next = name2;
	name2->next = name3;
	name3->next = name4;
	name4->next = name5;
	name5->next = name6;
	
	// Testing LL using LS
	std::cout << "Linked List result LS: \n";
	std::cout << "For 'R': ";
	linearSearchLL(name1, 'R');
	
	std::cout << "\n For 'O': ";
	linearSearchLL(name1, 'O');
	std::cout << std::endl;
	
	// Testing LL using BS
	std::cout << "Linked List result BS: \n";
	std::cout << "\n For 'S': ";
	binarySearchLL(name4, 'S');
	
	std::cout << "\n For 'E': ";
	binarySearchLL(name3, 'E');
	
	// Testing Array using BS
	int listArrBS[10] = {5, 12, 18, 23, 31, 42, 57, 64, 78, 91};
	
	std::cout << "\nBinary Search Array:\n";
	binarySearchArr(10, 42, listArrBS);
	binarySearchArr(10, 100, listArrBS);
	
	return 0;
}
