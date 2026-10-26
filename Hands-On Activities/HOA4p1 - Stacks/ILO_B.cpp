#include <iostream>

const size_t maxCap = 100;
int stack[maxCap];
int top = -1, newData, elements;

// Prototyping
void push();
void pop();
void Top();
bool isFull();
bool isEmpty();
void displayAll();

int main(){
    int choice;

    std::cout << "Enter number of max element for new stack (max: 100)\n";
    std::cin >> elements;

    while(true){
        std::cout << "Stack operations: \n";
        std::cout << "1. Push \n2. Pop \n3. Top \n4. isEmpty \n5. isFull \n6. Display All \n";
        std::cin >> choice;

        switch(choice){
            case 1: push();
            break;

            case 2: pop();
            break;

            case 3: Top();
            break;

            case 4: std::cout << isEmpty() << std::endl;
            break;

            case 5: std::cout << isFull() << std::endl;
            break;

            case 6: displayAll();
            break;

            default: std::cout << "Invalid Choice" << std::endl;
            break;
        }
    }
    return 0;
}

bool isEmpty(){
    // Top is -1
    if(top == -1) return true;
    return false;
}

bool isFull(){
    // != maxCap
    if(top >= elements){
        std::cout << "Stack Overflow";
        return true;
    }
    return false;
}

void push(){
    // Check if stack is full, if yes return error
    if(isFull())return;

    // Ask user for value to be pushed in stack
    std::cout<<"What number do you want to add to the stack? ";
    std::cin>> newData;

    // Store inside stack
    stack[++top] = newData;
}

void pop(){
    // Check if there are no more elements inside the stack
    if(isEmpty()) return;

    // Display element to be popped:
    std::cout<<"Popping: "<< stack[top];

    // Decrement top
    --top;
}

void Top(){
    // Error check
    if(isEmpty()) return;

    // Display top element
    std::cout << "The top element is: " << stack[top] << std::endl;
}

void displayAll(){
    // Error check
    if(isEmpty()) return;

    std::cout << "Values inside the stack: \n";
    for(int i = 0; i < elements; i++){
        std::cout << stack[i] << std::endl;
    }
}
