#include <iostream>
#include "simply_LL.h"

int main() {
    // Creating initial list: J -> I -> M -> Q
    SimplyList<char>* head = new SimplyList<char>;
    SimplyList<char>* second = new SimplyList<char>;
    SimplyList<char>* third = new SimplyList<char>;
    SimplyList<char>* fourth = new SimplyList<char>;

    // Assign the data and links:
    head->data = 'J';
    head->next = second;

    second->data = 'I';
    second->next = third;

    third->data = 'M';
    third->next = fourth;

    fourth->data = 'Q';
    fourth->next = nullptr;

    // Initial traversal
    listTraversal(head);

    // Inserting a new node at the head
    std::cout << "\nInserting a new node at the head:\n";
    sllInsertHead('Q', &head);
    listTraversal(head);

    // Inserting a new node at the third position
    std::cout << "Inserting new node at the third:\n";
    sllGeneralInsert('X', head->next->next);
    listTraversal(head);

    // Inserting a new node at the end
    std::cout << "Inserting a new node at the end:\n";
    sllInsertEnd('U', &head);
    listTraversal(head);

    // Deleting a node
    std::cout << "Deleting a node:\n";
    sllDeleteNode('Q', &head);
    listTraversal(head);

    // Deleting all nodes
    std::cout << "Deleting all the nodes:\n";
    sllDeleteList(&head);
    listTraversal(head);

    return 0;
}
