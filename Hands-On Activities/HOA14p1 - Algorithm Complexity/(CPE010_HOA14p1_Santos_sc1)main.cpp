#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.h"

int main(){
    const int size = 100;

    int arr[size], insert_best_case[size], insert_worst_case[size], merge[size];
    int comparisons = 0;
    std::srand(std::time(0));
    std::cout << "Sample Array: \n";

    for(int i = 0; i < size; i++){
        arr[i] = std::rand() % 100 + 1;
        insert_worst_case[i] = arr[i];
        merge[i] = arr[i];
        std::cout << arr[i] << " ";
    };
    std::cout << std::endl;

    // Insertion Best Case Scenario:
    for(int j = 0; j < size; j++){
        insert_best_case[j] = j+1;
    }

    std::cout << "\nMerge Sort \n";
    mergeSort(merge, 0, size-1, comparisons);
    std::cout << "Number of comparisons: " << comparisons << "\n";

    std::cout << "\nWorst Case: Insertion Sort \n";
    insertionSort(insert_worst_case, size);

    std::cout << "\nBest Case: Insertion Sort \n";
    insertionSort(insert_best_case, size);

}