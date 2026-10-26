#include <iostream>
#include <vector>

int M, N;
std::vector<std::vector<int>> matrix;
std::vector<std::vector<std::vector<int>>> memo;

int countPaths(int row, int col, int remainingCost) {
    // Outside the matrix or impossible remaining cost
    if (row >= M || col >= N || remainingCost < 0) {
        return 0;
    }

    // Destination reached
    if (row == M - 1 && col == N - 1) {
        return (remainingCost == matrix[row][col]) ? 1 : 0;
    }

    // Include the current cell's cost
    remainingCost -= matrix[row][col];
    if (remainingCost < 0) {
        return 0;
    }

    // Return a previously calculated result
    if (memo[row][col][remainingCost] != -1) {
        return memo[row][col][remainingCost];
    }

    // Explore moving right and moving down
    int rightPaths = countPaths(row, col + 1, remainingCost);
    int downPaths = countPaths(row + 1, col, remainingCost);

    return memo[row][col][remainingCost] = rightPaths + downPaths;
}

int main() {
    std::cout << "Enter rows and columns: ";
    std::cin >> M >> N;
    matrix.resize(M, std::vector<int>(N));
    std::cout << "Enter matrix elements:\n";
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> matrix[i][j];
        }
    }

    int targetCost;
    std::cout << "Enter target cost: ";
    std::cin >> targetCost;
    if (targetCost < 0) {
        std::cout << "Number of valid paths: 0\n";
        return 0;
    }

    // Initialize memoization table with -1
    memo.assign(M, std::vector<std::vector<int>>(N, std::vector<int>(targetCost + 1, -1)));

    int result = countPaths(0, 0, targetCost);
    std::cout << "Number of valid paths: " << result << std::endl;

    return 0;
}
