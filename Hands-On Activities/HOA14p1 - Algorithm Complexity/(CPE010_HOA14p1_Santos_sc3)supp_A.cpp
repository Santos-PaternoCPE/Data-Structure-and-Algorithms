#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>

int main() {
    int sizes[] = {1000, 10000, 100000};
    for (int s = 0; s < 3; s++){
        int n = sizes[s];
        std::vector<int> arr(n);

        for (int i = 0; i < n; i++){
            arr[i] = i;
        }
        int target = n;

        // Binary Search
        auto start = std::chrono::high_resolution_clock::now();
        std::binary_search(arr.begin(), arr.end(), target);
        auto end = std::chrono::high_resolution_clock::now();
        double binaryTime = std::chrono::duration<double>(end - start).count();

        // Linear Search
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < n; i++){
            if (arr[i] == target){
                break;
            }
        }
        end = std::chrono::high_resolution_clock::now();
        double linearTime = std::chrono::duration<double>(end - start).count();

        std::cout << "Input Size: " << n << '\n';
        std::cout << "Binary Search: " << binaryTime << " seconds\n";
        std::cout << "Linear Search: " << linearTime << " seconds\n\n";
    }

    return 0;
}