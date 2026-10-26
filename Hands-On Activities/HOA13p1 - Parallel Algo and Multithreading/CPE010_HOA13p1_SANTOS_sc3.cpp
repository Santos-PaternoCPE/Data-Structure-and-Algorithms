#include <iostream>
#include <vector>
#include <thread>

int total = 0;

void add(int value) {
    total += value;
}

int main() {
    std::thread T1(add, 5);
    std::thread T2(add, 10);
    std::thread T3(add, 20);

    std::cout << "Initial value: " << total << std::endl;

    T1.join();
    std::cout << "After T1.join(): " << total << std::endl;

    T2.join();
    std::cout << "After T2.join(): " << total << std::endl;

    T3.join();
    std::cout << "After T3.join(): " << total << std::endl;

    return 0;
}
