#include <iostream>
#include <stack>

int main(){

    std::stack<int> newStack; // Created object
    std::stack<int> swapStack; // For swapping

    // Testing the empty() function to check if stack is empty
    std::cout << "Is the stack empty? " << newStack.empty() << std::endl;

    // Insert 10 elements in a for loop
    for(int i = 0; i < 10; i++){
        newStack.push(i);
        swapStack.push(i);
    }

    // Prints out the first top
    std::cout << "Top of the stack: " << newStack.top() << std::endl;

    swapStack.swap(newStack);
    std::cout << "newStack new top value: " << newStack.top() << std::endl;

    newStack.emplace(10);

    // Prints out the stack size
    std::cout << "Size of the stack is: " << newStack.size() << std::endl;

    // Removing elements in a for loop
    while(!newStack.empty()){
        std::cout << "Remaining elements of the stack is: " << newStack.size() << std::endl;
        newStack.pop();
    }

    std::cout << "No more elements remaining \n";
}
