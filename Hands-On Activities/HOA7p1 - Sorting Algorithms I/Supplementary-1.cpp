#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.h"

const int maxSize = 100;

int main() {

    int votes[maxSize];
    std::srand(std::time(0));
    rngVotes(votes, maxSize);
    std::cout << "Unsorted:\n";
    for (int i = 0; i < maxSize; i++) {
        std::cout << votes[i] << " ";
    }

    insertionSort(votes, maxSize);
    std::cout << "\n\nSorted:\n";
    for (int i = 0; i < maxSize; i++) {
        std::cout << votes[i] << " ";
    }

    int candA = voteCount(votes, maxSize, 1);
    int candB = voteCount(votes, maxSize, 2);
    int candC = voteCount(votes, maxSize, 3);
    int candD = voteCount(votes, maxSize, 4);
    int candE = voteCount(votes, maxSize, 5);

    std::cout << "\n\nAlgorithm Count:\n";
    std::cout << "Candidate 1 (Bo Dalton Capistrano): " << candA << std::endl;
    std::cout << "Candidate 2 (Cornelius Raymon Agustin): " << candB << std::endl;
    std::cout << "Candidate 3 (Deja Jayla Banaga): " << candC << std::endl;
    std::cout << "Candidate 4 (Lalla Brielle Yabut): " << candD << std::endl;
    std::cout << "Candidate 5 Franklin Relano Castro: " << candE << std::endl;
    
    finalRes<int>(candA, candB, candC, candD, candE);

    return 0;
}
