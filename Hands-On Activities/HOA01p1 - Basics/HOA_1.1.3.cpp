#include <iostream>
#include <cmath>

struct var{
    double num1, num2;
    double kelvin;
    double x1, y1, x2, y2;
};

void swapping(var v){
    double temp = v.num1;
    v.num1 = v.num2;
    v.num2 = temp;

    std::cout << "Both swapped places: " << v.num1 << " " << v.num2 << std::endl;
}

void ktof(var v){
    std::cout << "Fahrenheit: " << (v.kelvin - 273.15) * 9 / 5 + 32 << std::endl;
}

void distance(var v){
    double d = sqrt((v.x2 - v.x1) * (v.x2 - v.x1) +
                    (v.y2 - v.y1) * (v.y2 - v.y1));

    std::cout << "The distance is " << d << std::endl;
}

int main(){
    var v;
    int choice = 0;

    while(choice != 4){
        std::cout << "\n1. Swap Numbers\n2. Kelvin to Fahrenheit\n3. Distance Between Points\n4. Exit\nInput: ";
        std::cin >> choice;
        std::cout << "\nInput numbers: ";

        switch(choice){
            case 1:
                std::cin >> v.num1 >> v.num2;
                swapping(v);
                break;

            case 2:
                std::cin >> v.kelvin;
                ktof(v);
                break;

            case 3:
                std::cin >> v.x1 >> v.y1 >> v.x2 >> v.y2;
                distance(v);
                break;

            case 4:
                std::cout << "Program ended.";
                break;

            default:
                std::cout << "Invalid choice.";
        }
    }
    return 0;
}

