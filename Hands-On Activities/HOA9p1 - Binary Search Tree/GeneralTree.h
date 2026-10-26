#include <iostream>
#include <vector>
#include <queue>

struct Node {
    int data;
    std::vector<Node*> children;

    Node(int val) : data(val) {}
};

// Depth-First Search: Pre-order Traversal (Root, then Children)
void printPreOrder(Node* root) {
    if (root == nullptr) return;

    // Print current node
    std::cout << root->data << " ";

    // Recursively print all child subtrees
    for (Node* child : root->children) {
        printPreOrder(child);
    }
}

// Breadth-First Search: Level-Order Traversal (Level by Level)
void printLevelOrder(Node* root) {
    if (root == nullptr) return;

    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        std::cout << current->data << " ";

        // Push all children of the current node into the queue
        for (Node* child : current->children) {
            q.push(child);
        }
    }
}

int main() {
    /* 
       Creating the following General Tree:
               1
            /  |  \
           2   3   4
          / \
         5   6
    */

    Node* root = new Node(1);
    
    // Add children to root
    root->children.push_back(new Node(2));
    root->children.push_back(new Node(3));
    root->children.push_back(new Node(4));

    // Add children to node '2'
    root->children[0]->children.push_back(new Node(5));
    root->children[0]->children.push_back(new Node(6));

    std::cout << "Pre-order Traversal: ";
    printPreOrder(root); // Output: 1 2 5 6 3 4
    std::cout << "\n";

    std::cout << "Level-order Traversal: ";
    printLevelOrder(root); // Output: 1 2 3 4 5 6
    std::cout << "\n";

    // Memory cleanup (Optional but recommended in production code)
    // A post-order deletion algorithm should ideally be implemented here.
    return 0;
}
