#include <iostream>
#include <time.h>
#include <thread>
#include <vector>

int main() {
    // Generate random values
    int a[100];
    srand(time(0));
    for(int i = 0; i < 100; i++) {
        a[i] = rand();
    }

    // Multithreading setup
    const int numThreads = 4;
    bool foundDuplicate[4] = {false, false, false, false};
    std::vector<std::thread> threads;

    for(int t = 0; t < numThreads; t++) {
        threads.push_back(std::thread([t, &a, &foundDuplicate]() {
            int start = t * 100 / numThreads;
            int end = (t + 1) * 100 / numThreads;
            
            for(int i = start; i < end; i++) {
                for(int j = i + 1; j < 100; j++) {
                    if(a[i] == a[j]) {
                        foundDuplicate[t] = true;
                        return;
                    }
                }
            }
        }));
    }

    // Wait for all threads to finish
    for(int i = 0; i < numThreads; i++) {
        threads[i].join();
    }

    // Check results
    for(int i = 0; i < numThreads; i++) {
        if(foundDuplicate[i]) {
            std::cout << "Returned True\n";
            return true;
        }
    }

    std::cout << "Returned False\n";
    return false;
}
