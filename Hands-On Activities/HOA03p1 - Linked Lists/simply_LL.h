#ifndef SIMPLY_LL_H
#define SIMPLY_LL_H

#include <iostream>

template <typename T>
class SimplyList {
public:
    T data;
    SimplyList<T>* next;
};

// 1. Traversal Function
template <typename T>
void listTraversal(SimplyList<T>* head) {
    if (head == nullptr) {
        std::cout << "List is empty" << std::endl;
        return;
    }
    
    while (head != nullptr) {
        std::cout << head->data;
        if (head->next != nullptr) {
            std::cout << " -> ";
        }
        head = head->next;
    }
    std::cout << std::endl;
}

// 2. Insert Head Function
template <typename T>
void sllInsertHead(T newData, SimplyList<T>** currentHead) {
    // 1. Allocate memory for the new node
    SimplyList<T>* newNode = new SimplyList<T>;
    // 2. Put data into new node
    newNode->data = newData;
    // 3. Set Next of new node to point to previous head
    newNode->next = *currentHead;
    // 4. Reset Head to point to new node
    *currentHead = newNode;
}

// 3. General Insert Function (Insert after a given node)
template <typename T>
void sllGeneralInsert(T newData, SimplyList<T>* prevNode) {
    if (prevNode == nullptr) {
        std::cout << "Previous Node cannot be Null" << std::endl;
        return;
    }
    // Allocate a new node
    SimplyList<T>* newNode = new SimplyList<T>;
    // Store data in the new node
    newNode->data = newData;
    // Point new node to the node previous node was pointing to
    newNode->next = prevNode->next;
    // Point previous node to the new node
    prevNode->next = newNode;
}

// 4. Insert End Function
template <typename T>
void sllInsertEnd(T newData, SimplyList<T>** head) {
    // 1. Allocate new node
    SimplyList<T>* newNode = new SimplyList<T>;
    newNode->data = newData;
    newNode->next = nullptr;

    // If list is empty, make new node the head
    if (*head == nullptr) {
        *head = newNode;
        return;
    }

    // 2. Dereference to the head node
    SimplyList<T>* currentNode = *head;

    // 5. Traverse to the last node
    while (currentNode->next != nullptr) {
        currentNode = currentNode->next;
    }

    // 6. Point the next of the current node to the new node
    currentNode->next = newNode;
}

// 5. Delete Specific Node Function
template <typename T>
void sllDeleteNode(T findData, SimplyList<T>** head) {
    // Check if no list to be deleted
    if (*head == nullptr) return;

    SimplyList<T>* currNode = *head;
    SimplyList<T>* prevNode = nullptr;

    // Searching loop
    while (currNode != nullptr && currNode->data != findData) {
        prevNode = currNode;
        currNode = currNode->next;
    }

    // Data was not found:
    if (currNode == nullptr) return;

    // If node to delete is the head node
    if (prevNode == nullptr) {
        *head = currNode->next;
    } else {
        prevNode->next = currNode->next;
    }

    // Delete node
    delete currNode;
}

// 6. Delete Entire List Function
template <typename T>
void sllDeleteList(SimplyList<T>** head) {
    SimplyList<T>* current = *head;

    while (current != nullptr) {
        SimplyList<T>* temp = current;
        current = current->next;
        delete temp;
    }
    *head = nullptr;
}

#endif
