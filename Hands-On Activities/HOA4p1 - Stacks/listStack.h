#ifndef LIST_STACK_H
#define LIST_STACK_H

#include <iostream>

// Class node with data and next members
template <typename T>
class Node{
public:
    T data;
    Node<T>* next = nullptr;
};

template <typename T>
Node<T>* head = nullptr; // Create pointer

template <typename T>
void push(T newData){
    // Create new node
    Node<T>* newNode = new Node<T>;

    // Assign data to new node
    newNode->data = newData;

    // Pointer the new node next to current top
    newNode->next = head<T>;

    // Assign the new top to the new node
    head<T> = newNode;
}

template <typename T>
bool isEmpty(){
    return head<T> == nullptr;
}

template <typename T>
T pop(){
    // If stack is empty, error catch
    if(isEmpty<T>()){
        std::cout << "Stack Underflow \n";
    }

    // Saving current top node
    Node<T>* temp = head<T>;

    // Store data to temp variable
    T tempVal = temp->data;

    // Move head to next node
    head<T> = head<T>->next;

    // Deallocate and free memory
    delete temp;

    // Return temporary variable
    return tempVal;
}

template <typename T>
void Top(){
    if(isEmpty<T>()) return;
    std::cout << "The top is: " << head<T>->data;
}

template <typename T>
void displayAll(){
    if(isEmpty<T>()) return;

    while(head<T> != nullptr){
        std::cout << head<T>->data << " ";
        head<T> = head<T>->next;
    }
    std::cout << std::endl;
}

#endif
