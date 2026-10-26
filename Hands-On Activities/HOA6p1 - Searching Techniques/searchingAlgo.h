#include "node.h"

#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

// Procedure:

template <class T>
void linearSearchArr(int arrSize, T dataFind, T list[]){
	
	// Step 1: I = 0
	
	// Repeat while I <= n
	for(int i = 0; i < arrSize; i++){
		if(dataFind == list[i]){
			// Print "Searching is successful"
			std::cout << "Searching is successful\n";
			return;
		}
	}
	
	// Print "Searching is unsuccessful"
	std::cout << "Searching is unsuccessful\n";
}

template <class T>
void linearSearchLL(Node<T>* head, T dataFind){
	while(head != NULL){
		if(head->data == dataFind){
			std::cout << "Searching is successful\n";
			return;
		}
		head = head->next;
	}
	std:: cout << "Searching is unsuccessful\n";
}

template <class T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last){
	Node<T>* slow = start;
	Node<T>* fast = start;
	
	while(fast != last && fast->next != last){
		
		// Move slow one step
		slow = slow->next;
		
		// Move fast two steps
		fast = fast->next->next;
	}
	return slow;
}

template <class T>
void binarySearchLL(Node<T>* start, T dataFind){
	
	// Step 1: Set start head of the list, set last to null
	Node<T>* last = NULL;
	
	// Continue search while search range is valid (Not yet last)
	while(start != last){
		
	// Step 2: Finding middle using getMiddle
	Node<T>* middle = getMiddle(start, last);
		
	// Step 3: Data is found
	if(middle->data == dataFind){
		std::cout << "Searching is successful\n";
		return;
	}
		
	// Step 4: Searching left
	else if(middle->data > dataFind){
		last = middle;
	}
		
	// Step 5: Searching right
	else{
		start = middle->next;
	}
}
	// Step 6: Print display
	std::cout << "Searching is unsuccessful\n";
}

template <class T>
void binarySearchArr(int arrSize, T dataFind, T list[]){
	// Define low, up and middle
	int low = 0, up = arrSize-1, middle;
	
	// Loop while low is <= up
	while(low <= up){
		
		// Compute middle
		middle = (int)((low+up)/2);
		
		// If data found is middle -> data found -> return
		if(dataFind == list[middle]){
			std::cout << "Search element is found!\n";
			return;
		}
		
		// If data find < data middle -> new high
		else if(dataFind < list[middle]){
		up = middle-1;
		}
		else{
			// Else update low = middle + 1
			low = middle + 1;
		}
	}
	std::cout << "Search element is not found! \n";
}

// Supplementary Task:

template <class T>
int lSLLCount(Node<T>* head, T dataFind){
	int comp = 0;
	
	while(head != NULL){
		comp++;
		
		if(head->data == dataFind){
			return comp;
		}
		
		head = head->next;
	}
	
	return comp;
}

template <class T>
int bSRecursive(int low, int up, T dataFind, T list[]){
	
	// If low is greater than up, element is not found
	if(low > up){
		return 0;
	}
	int middle = (low + up) / 2;
	
	// If data found is middle
	if(dataFind == list[middle]){
		return 1;
	}
	
	// // If data find is less than data middle then search left
	else if(dataFind < list[middle]){
		return bSRecursive(low, middle - 1, dataFind, list);
	}
	
	else{
		// Search right
		return bSRecursive(middle + 1, up, dataFind, list);
	}
}
#endif
