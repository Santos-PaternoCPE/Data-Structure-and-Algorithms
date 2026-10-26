#include <iostream>
#include <cstdlib>
#include <time.h>
#include "node.h"
#include "searchingAlgo.h"

const int max_size = 10;

int main (){
	
	// Problem 1
	int dataset[max_size] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};

	// Search for 18
	int comp = 0;	
	for(int i = 0; i < max_size; i++){
		comp++;
		
		if(dataset[i] == 18){
			break;
		}
	}
	std::cout << "Comparisons using Array: " << comp << "\n";
	
	// Create linked list
	Node<int>* int1 = new_node(15);
	Node<int>* int2 = new_node(18);
	Node<int>* int3 = new_node(2);
	Node<int>* int4 = new_node(19);
	Node<int>* int5 = new_node(18);
	Node<int>* int6 = new_node(0);
	Node<int>* int7 = new_node(8);
	Node<int>* int8 = new_node(14);
	Node<int>* int9 = new_node(19);
	Node<int>* int10 = new_node(14);
	
	int1->next = int2;
	int2->next = int3;
	int3->next = int4;
	int4->next = int5;
	int5->next = int6;
	int6->next = int7;
	int7->next = int8;
	int8->next = int9;
	int9->next = int10;
	
	// Ll search
	std::cout << "Comparisons using LL: ";
	std::cout << lSLLCount(int1, 18) << "\n\n";
	
	
	// Problem 2
	// Count repetetion in Array
	int count = 0;
	
	for(int i = 0; i < max_size; i++){
		if(dataset[i] == 18){
			count++;
		}
	}
	std::cout << "Array occurrences of 18: " << count << std::endl;
	
	// Counting repetition in LL
	count = 0;
	Node<int>* current = int1;
	
	while(current != NULL){
		if(current->data == 18){
			count++;
		}	
		current = current->next;
	}	
	std::cout << "Linked List occurrences of 18: " << count << "\n\n";
	
	
	// Problem 3
	int sorted[max_size] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
	std::cout << "Sorted Array: ";	
	for(int i = 0; i < max_size; i++){
		std::cout << sorted[i] << " ";
	}	
	std::cout << std::endl;
	
	// Binary Search for 8
	int low = 0; int up = max_size - 1; int middle; int rep_counter = 1;
	while(low <= up){
		
		// Compute middle
		middle = (int)((low + up) / 2);
		
		std::cout << "Repetition " << rep_counter << " - ";
		std::cout << " Low: " << low;
		std::cout << " Up: " << up;
		std::cout << " Middle: " << middle;
		std::cout << " Value: " << sorted[middle] << "\n";
		
		// If data found is middle
		if(8 == sorted[middle]){
			std::cout << "Search element is found\n";
			break;
		}
		
		// If data find is less than data middle, then set as new high
		else if(8 < sorted[middle]){
			std::cout << "Left side search:\n";
			up = middle - 1;
		}
		
		else{
			// Else update low to middle + 1
			std::cout << "Right side search:\n";
			low = middle + 1;
		}
		rep_counter++;
	}
	std::cout << std::endl;
	
	
	// Problem 4
	// Recursive Binary Search
	if(bSRecursive(0, max_size - 1, 8, sorted)){
		std::cout << "Search element is found\n";
	}
	else{
		std::cout << "Search element is not found\n";
	}
	
	return 0;
}
