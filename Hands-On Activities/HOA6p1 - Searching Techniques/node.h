#ifndef NODE_H
#define NODE_H

#include <iostream>

template <class T>
class Node {
public:
    T data;
    Node<T> *next;
};

template <class T>
Node<T>* new_node(T newData) {
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = NULL;
    return newNode;
}

#endif
