#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.h"

int main() {
    const int maxSize = 100;
    int arrayBubble[maxSize];
    int arraySelection[maxSize];
    int arrayInsertion[maxSize];

    srand(time(0));
    
    std::cout << "Array for Bubble: \n";
    for (int i = 0; i < maxSize; i++) {
        arrayBubble[i] = rand() % 100;
        std::cout << arrayBubble[i] << " ";
    }
    
    std::cout << "\n\nArray for Selection: \n";
    for (int i = 0; i < maxSize; i++) {
        arraySelection[i] = rand() % 100;
        std::cout << arraySelection[i] << " ";
    }
    
    std::cout << "\n\nArray for Insertion: \n";
    for (int i = 0; i < maxSize; i++) {
        arrayInsertion[i] = rand() % 100;
        std::cout << arrayInsertion[i] << " ";
    }
    std::cout << "\n\n";

    std::cout << "Bubble Sorting:\n";
    bubbleSort(arrayBubble, maxSize);
    for (int i = 0; i < maxSize; i++) {
        std::cout << arrayBubble[i] << " ";
    }
    std::cout << "\n\n";
    
    std::cout << "Selection Sorting: \n";
    selectionSort(arraySelection, maxSize);
    for (int i = 0; i < maxSize; i++) {
        std::cout << arraySelection[i] << " ";
    } 
    std::cout << "\n\n";
    
	std::cout << "Insertion Sorting: \n";
    selectionSort(arrayInsertion, maxSize);
    for (int i = 0; i < maxSize; i++) {
        std::cout << arrayInsertion[i] << " ";
    }

    return 0;
}
