#include <iostream>
#include <queue>

void display(std::queue<char> copyQ);

int main(){
    // Create an object
    std::queue<char> myQ;

    myQ.push('S');
    myQ.push('A');
    myQ.push('N');
    myQ.push('T');
    myQ.push('O');
    myQ.push('S');
    display(myQ);
    
    /* Try all member functions:
       Empty */
    std::cout << "The queue is ";
    if(myQ.empty()){
        std:: cout << "empty\n";
    }else{
        std:: cout << "not empty\n";
    }

    // Size
    std::cout << "The size of the queue is " << myQ.size() << std::endl;

    // Front
    std::cout << "The front of the queue is " << myQ.front() << std::endl;
    // Back
    std::cout << "The back of the queue is " << myQ.back() << std::endl;

    // Pop
    while(!myQ.empty()){
        myQ.pop();
    }

    // Display
    std::cout << "Entire queue has been popped!\n";
    std::cout << "Current queue: ";
    if(myQ.empty()){
        std::cout << "None \n";
    }

    // Push
    myQ.push('P');
    myQ.push('A');
    myQ.push('T');
    myQ.push('E');
    myQ.push('R');
    myQ.push('N');
    myQ.push('O');

    // Display
    std::cout << "The queue has been filled! \n";
    std::cout << "Current queue: ";
    display(myQ);

    return 0;
}

void display(std::queue<char> copyQ){
    // Creates a copy of the passed queue

    std::queue<char> c = copyQ;
    while(!c.empty()){
        std::cout << " " << c.front();
        c.pop();
    }
    std::cout<< "\n";
}