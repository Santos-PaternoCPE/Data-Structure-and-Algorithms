#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.h"

int main(){
    const int size = 100;

    int arr[size], shell[size], merge[size], quick[size];
    std::srand(std::time(0));

    for (int i = 0; i < size; i++){
        arr[i] = std::rand() % 100 + 1;
        shell[i] = arr[i];
        merge[i] = arr[i];
        quick[i] = arr[i];
    }

    std::cout << "Array for sort testing: \n\n";
    for (int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Shell sorting algorithm: \n\n";
    std::cout << "Before sorting: \n";
    for (int i = 0; i < size; i++){
        std::cout << shell[i] << " ";
    }
    shellSort(shell, size);
    std::cout << std::endl;
    
    std::cout << "After sorting:" << std::endl;
    for (int i = 0; i < size; i++){
        std::cout << shell[i] << " ";
    }
    std::cout << "\n\n";

    std::cout << "Merge sorting algorithm: \n\n";
    std::cout << "Before sorting: \n";
    for (int i = 0; i < size; i++){
        std::cout << merge[i] << " ";
    }
    mergeSort(merge, 0, size - 1);
    std::cout << std::endl;
    
    std::cout << "After sorting: \n";
    for (int i = 0; i < size; i++){
        std::cout << merge[i] << " ";
    }
    std::cout << "\n\n";
    
    std::cout << "Quick sorting algorithm: \n\n";
    std::cout << "Before sorting: \n";
    for (int i = 0; i < size; i++)
    {
        std::cout << quick[i] << " ";
    }
    quickSort(quick, 0, size - 1);
    std::cout << std::endl;
    
    std::cout << "After sorting: \n";
    for (int i = 0; i < size; i++){
        std::cout << quick[i] << " ";
    }
    return 0;
}
