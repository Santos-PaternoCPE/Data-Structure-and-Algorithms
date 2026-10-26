#include <iostream>
#include <string>

class Node {
public:
    char data;
    Node* next; // Node points to next

    Node(char x) {
        data = x; // Storing char
        next = NULL; // Pointer set to null
    }
};

class StackLL { // Stack commands remaking
private:
    Node* top; // Will always point to top

public:
    StackLL() {
        top = NULL; // Set to null to be an empty stack at first
    }

    bool isEmpty() {
        return top == NULL;
    }

    void push(char ch) {
        Node* newNode = new Node(ch);
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (isEmpty()) return '\0'; // Null char

        // Using temp to do replicate pop command
        Node* temp = top;
        char value = temp->data;
        top = top->next;
        delete temp;
        return value;
    }
};

// Prototyping
bool pairSymbols(char open, char close);
bool balSymbols(std::string expr);

int main() {
    // Declare string expr for input
    std::string expr;
    std::cout << "Enter an expression: ";

    // Output and input here
    std::getline(std::cin, expr);

    // Check for balancing
    if (balSymbols(expr))
        std::cout << "Symbols are balanced." << std::endl;
    else
        std::cout << "Symbols are NOT balanced." << std::endl;

    return 0;
}

// Pairing and checking
bool pairSymbols(char open, char close) {
    return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');
}

bool balSymbols(std::string expr) {
    StackLL s;
    // for Loop for checking expressions, then push the character
    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        // For closing symbols, push it on top and check for conditions:
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) return false;

            // Put closing symbol on top
            char top = s.pop();

            // If not matching opening, reject
            if (!pairSymbols(top, ch)) return false;
        }
    }
    return s.isEmpty();
}
