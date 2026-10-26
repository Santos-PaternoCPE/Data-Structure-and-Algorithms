#ifndef QUEUELL_H
#define QUEUELL_H

// Create a class the node
template <typename T>
class qNode{
    public:
        T data;
        qNode<T>* next;
};

// Creates the new node
template <typename T>
qNode<T>* new_node(T newData){
    qNode<T>* newNode = new qNode<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

// Enqueue operation
template <typename T>
void enqueue(T newData, qNode<T>** frontPtr, qNode<T>** backPtr){
    // Create new node
    qNode<T>* newNode = new_node(newData);

    // Insertion to empty queue
    if((*frontPtr)==nullptr && (*backPtr)==nullptr){
        (*frontPtr) = newNode;
        (*backPtr) = newNode;
    }

    // Insertion of item in non empty queue
    (*backPtr)->next = newNode;
    (*backPtr) = newNode;
}

template <typename T>
void dequeue(qNode<T>** frontPtr, qNode<T>** backPtr){
    // Create temp node
    qNode<T>* deleteNode = nullptr; // temp var
    deleteNode = (*frontPtr);


    // Check if queue has only one node
    if((*frontPtr)->next == nullptr && (*backPtr)->next == nullptr){
        (*frontPtr) = nullptr;
        (*backPtr) = nullptr;
        delete deleteNode;
        return;
    }

    // Delete node
    (*frontPtr) = (*frontPtr)->next;
    deleteNode->next = nullptr;
    delete deleteNode;

}

// Check the front
template <typename T>
void Front(qNode<T>** frontPtr){
    if((*frontPtr) != nullptr){
        std::cout << "The front is " << (*frontPtr)->data << "\n";
    }
}

// Check the back
template <typename T>
void Back(qNode<T>** backPtr){
    if((*backPtr) != nullptr){
        std::cout << "The back is " << (*backPtr)->data << "\n";
    }
}


// Display All
template <typename T>
void displayAll(qNode<T>** frontPtr, qNode<T>** backPtr){
    if ((*frontPtr)==nullptr && (*backPtr)==nullptr) return;

    std::cout << "The current elements inside the queue: ";
    while ((*frontPtr) != nullptr) {
        std::cout << (*frontPtr)->data << " ";
        (*frontPtr) = (*frontPtr)->next;
    }
    std::cout << std::endl;

}



#endif