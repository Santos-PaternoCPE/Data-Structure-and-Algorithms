#ifndef SORTING_H
#define SORTING_H
#include <iostream>
#include <ctime>
#include <cstdlib>


// Procedure:
template <class T>
void bubbleSort(T arr[], int maxSize){
	for(int i = 0; i < maxSize; i++){
		for(int j = i + 1; j < maxSize; j++){
			if(arr[j] < arr[i]){
				std::swap(arr[i],arr[j]);
			}
		}
	}
}

template <class T>
int routine_smallest(T arr[], int k, int arrSize){
	int position;
	
	T smallestElement = arr[k];
	
	for(int j = k + 1; j < arrSize; j++ ){
		if(arr[j] < smallestElement){
			smallestElement = arr[j];
			position = j;
		}
	}
	return position;
}

template <class T>
void selectionSort(T arr[], int arrSize){
	int min, temp;
	
	for(int i = 0; i < arrSize - 1; i++){
		min = routine_smallest(arr, i, arrSize);
		std::swap(arr[i], arr[min]);
	}
}

template <class T>
void insertionSort(T arr[], int arrSize) {
	// int k changed to int x due to function routine_smallest giving an error
    int x = 1, j;
    T temp;
    while (x < arrSize) {
        temp = arr[x];
        j = x - 1;
        while (j >= 0 && temp < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
        x++;
    }
}

// Supplementary Task:
template <class T>
void rngVotes(T arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        arr[i] = std::rand() % 5 + 1; // Only allows 1-5 rng
    }
}

template <class T>
int voteCount(T arr[], int arrSize, int candidate) {
    int count = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == candidate) {
            count++;
        }
    }
    return count;
}

template <class T>
void finalRes(int a, int b, int c, int d, int e) {
    int highest = a;
    if(b > highest) {
        highest = b;
    }
    if(c > highest) {
        highest = c;
    }
    if(d > highest) {
        highest = d;
    }
    if(e > highest) {
        highest = e;
    }
    
    std::cout << "\nWinners:\n";
    if(a == highest) {
        std::cout << "Bo Dalton Capistrano has " << highest << " votes\n";
    }
    if(b == highest) {
        std::cout << "Cornelius Raymon Agustin has " << highest << " votes\n";
    }
    if(c == highest) {
        std::cout << "Deja Jayla Banaga has " << highest << " votes\n";
    }
    if(d == highest){
        std::cout << "Lalla Brielle Yabut has " << highest << " votes\n";
    }
    if(e == highest){
        std::cout << "Franklin Relano Castro has " << highest << " votes\n";
    }
}
#endif
