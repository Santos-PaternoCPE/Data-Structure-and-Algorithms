#ifndef SORTING_H
#define SORTING_H
#include <iostream>
#include <ctime>
#include <cstdlib>

template <class T>
void insertionSort(T arr[], int arrSize){
    int comparisons = 0;

    for (int x = 1; x < arrSize; x++){
        T temp = arr[x];
        int j = x - 1;

        while (j >= 0) {
            comparisons++;

            if (temp < arr[j]){
                arr[j + 1] = arr[j];
                j--;
            }
            else{
                break;
            }
        }
        arr[j + 1] = temp;
    }
    std::cout << "Number of comparisons: "<< comparisons << std::endl;
}

void merging(int arr[], int left, int middle, int right, int& comparisons){
    int i = left;
    int j = middle + 1;
    int k = 0;
    int temp[100];

    while (i <= middle && j <= right){
        comparisons++;

        if (arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
        }
        else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= middle){
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= right){
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (i = left, k = 0; i <= right; i++, k++){
        arr[i] = temp[k];
    }
}

void mergeSort(int arr[], int left, int right, int& comparisons){
    if (left < right){
        int middle = (left + right) / 2;

        mergeSort(arr, left, middle, comparisons);
        mergeSort(arr, middle + 1, right, comparisons);
        merging(arr, left, middle, right, comparisons);
    }
}

#endif
