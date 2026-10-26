#ifndef BST_H
#define BST_H

template<typename T>
class  BinarySearchTree{
    private:
        T key;
        BinarySearchTree<T>* root;
        BinarySearchTree<T>* children;
    
    public:
        // Constructor:
        BinarySearchTree(T value);
        Node(int val) : key(val) {};
         
        // Insertion:
        void insert(T value);

        /* Traversal:
           Pre Order Traversal: */
        void preOrder(T key);

        // In Order Traversal:
        void inOrder();

        // Post Order Traversal:
        void postOrder();
};

template<typename T>
BinarySearchTree<T>::BinarySearchTree(T value){
    key = value;
    children = nullptr;
}

template<typename T>
void BinarySearchTree<T>::insert(T value){
    // Go to left if: value < key
    if(value < key){
        if(left==nullptr){
            left = new BinarySearchTree<T>(value);
        }else{
            left->insert(value);
        }
    }

    // Go to right if: value > key
    else if(value > key){
        if(right==nullptr){
            right = new BinarySearchTree<T>(value);
        }else{
            right->insert(value);
        }  
    }
}

template<typename T>
void BinarySearchTree<T>::preOrder(T root){
    if(root == nullptr) return;

    // Print current node
    std::cout << root->key << " ";

    // Recursive print all child subtrees
    for(child : root->children){
        printPre(child);
    }
}

template<typename T>
void BinarySearchTree<T>::inOrder(){
    if(left != nullptr){
        left->inOrder();
    }
    std::cout << key << " ";

    if(right != nullptr){
        right->inOrder();
    }
}

template<typename T>
void BinarySearchTree<T>::postOrder(){
    if(left != nullptr){
        left->postOrder();
    }

    if(right != nullptr){
        right->postOrder();
    }
    std::cout << key << " ";
}


#endif