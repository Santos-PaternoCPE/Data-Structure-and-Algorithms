#include <iostream>
#include <time.h>

int main(){
	// Generate random values (Assume that 100 is n for space complexity)
	int a[100];
	srand(time(0));
    for(int i = 0; i < 100; i++){
		a[i] = rand();
	}

    // Time complexity here:
    for(int i = 0; i < 100; i++){
        for(int j = i+1; j < 100; j++){
            if (a[i] == a[j]){
            std::cout << "Returned False \n"; // If both values stays the same, then worst case.
            return false;
            }
        }
    }
    std::cout << "Returned True \n"; // If only return true is printed, then best case.
    return true;
}