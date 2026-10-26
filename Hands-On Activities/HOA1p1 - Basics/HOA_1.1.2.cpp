//Header File Declaration Section
#include <iostream>

//Global Declaration Section
struct var{
    int num1, num2;
    bool a, b;
};

//Class Declaration and Method Definition Section
void sum(var v){
    std::cout << "Sum is " << v.num1 + v.num2 << std::endl;
}

void compare(var v){
    if(v.num1 > v.num2){
        std::cout << v.num1 << " is greater than " << v.num2 << std::endl;
    }
    else if(v.num1 < v.num2){
        std::cout << v.num1 << " is less than " << v.num2 << std::endl;
    }
    else{
        std::cout << v.num1 << " is equal to " << v.num2 << std::endl;
    }
}

void boolean(var v){
    bool and_gate = v.a && v.b;
    bool or_gate = v.a || v.b;

    std::cout << "Check for and: " << and_gate << std::endl;
    std::cout << "Check for or: " << or_gate << std::endl;
}

//Main Function
int main(){
    var v;
    int choice = 0;

//Method Definition
    while(choice != 4){
        std::cout << "\n1. Sum\n2. Compare\n3. Boolean\n4. Exit\nChoice: ";
        std::cin >> choice;

        switch(choice){
            case 1:
                std::cout << "Enter two numbers: ";
                std::cin >> v.num1 >> v.num2;
                sum(v);
                break;

            case 2:
                std::cout << "Enter two numbers: ";
                std::cin >> v.num1 >> v.num2;
                compare(v);
                break;

            case 3:
                std::cout << "Enter two Boolean values 0 or 1: ";
                std::cin >> v.a >> v.b;
                boolean(v);
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

