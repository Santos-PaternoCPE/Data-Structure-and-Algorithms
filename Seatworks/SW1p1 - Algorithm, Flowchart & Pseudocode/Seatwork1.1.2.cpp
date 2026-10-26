#include <iostream>

int main() {
    int grades[3];
    int total = 0;
    float average;

    for (int i = 0; i < 3; i++) {
        std::cout << "Input quiz " << i + 1 << " score: ";
        std::cin >> grades[i];
    }

    for (int i = 0; i < 3; i++) {
        total += grades[i];
    }

    average = static_cast<float>(total) / 3;


    std::cout << "\nTotal of 3 quizzes: " << total << std::endl;
    std::cout << "Average quiz score: " << average << std::endl;

    return 0;
}
