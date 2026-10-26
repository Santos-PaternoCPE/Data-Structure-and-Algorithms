#include <iostream>
#include "queueLL.h"

int main(){
    qNode<char>* front = nullptr;
    qNode<char>* back = nullptr;

    enqueue('S', &front, &back);
    std::cout << front->data << " " << back->data << std::endl;
    enqueue('A', &front, &back);
    std::cout << front->data << " " << back->data << std::endl;
    enqueue('N', &front, &back);
    std::cout << front->data << " " << back->data << std::endl;
    enqueue('T', &front, &back);
    std::cout << front->data << " " << back->data << std::endl;
    enqueue('O', &front, &back);
    std::cout << front->data << " " << back->data << std::endl;
    enqueue('S', &front, &back);
    std::cout << front->data << " " << back->data << std::endl;

    dequeue(&front, &back);
    std::cout << front->data << " " << back->data << std::endl;
    dequeue(&front, &back);
    std::cout << front->data << " " << back->data << std::endl;

    Front(&front);
    Back(&back);
    displayAll(&front, &back);

    return 0;
}