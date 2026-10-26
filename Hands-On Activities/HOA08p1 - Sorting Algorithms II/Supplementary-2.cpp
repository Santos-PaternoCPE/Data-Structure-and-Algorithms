#include <iostream>
#include "sorting.h"

int main(){
    int arr1[10] = {34, 12, 45, 7, 23, 56, 18, 9, 41, 27};
    std::cout << "Original array: \n";
    dispArray(arr1, 10);

    int pivot = partition(arr1, 0, 9);
    
    std::cout << "After partition: \n";
    dispArray(arr1, 10);

    std::cout << "Pivot position is " << pivot << std::endl;
    insertionSort(arr1, 0, pivot - 1);
    insertionSort(arr1, pivot + 1, 9);

    std::cout << "Sorting sub lists: \n";
    dispArray(arr1, 10);
    std::cout << std::endl;
    
    int arr2[15] = {4, 34, 29, 48, 53, 87, 12, 30, 44, 25, 93, 67, 43, 19, 74};

    std::cout << "Original array: \n";
    dispArray(arr2, 15);
    quickSort(arr2, 0, 14);

    std::cout << "Quick Sorted: \n";
    dispArray(arr2, 15);
    return 0;
}
