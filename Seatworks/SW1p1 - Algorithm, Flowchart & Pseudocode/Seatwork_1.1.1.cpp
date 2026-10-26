#include <iostream>

int main() {
    float prices[3] = {};
    float amount = 0, payment = 0, change = 0;
    int counter = 0;

    for (int i = 0; i != 3; i++) {
        std::cout << "Input item price: ";
        std::cin >> prices[i];
    }

    for (int j = 0; j != 3; j++) {
        amount += prices[j];

        std::cout << "\nItem " << j + 1 << ": " << prices[j] << std::endl;

        if (j == 2) {
            std::cout << "\nThe amount of the price is: " << amount;

            while (counter == 0) {
                std::cout << "\nPlease pay " << amount << ": ";
                float money;
                std::cin >> money;
                payment += money;

                if (payment < amount) {
                    std::cout << "\nInsufficient amount paid. Please add to your existing payment.";
                } else {
                    change = payment - amount;
                    std::cout << "\nYour change is: " << change;
                    counter = 1;
                }
            }
        }
    }

    return 0;
}

