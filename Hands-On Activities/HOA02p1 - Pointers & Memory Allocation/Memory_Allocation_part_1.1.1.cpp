#include <iostream>
#include <string>

// Problem 1.1: Fruit class
class Fruit {
public:
    std::string name; int price; int amount;
    
    // Constructor
    Fruit(std::string n, int p, int a) {name = n; price = p; amount = a;}
    
    // Copy Constructor
    Fruit(const Fruit& x) {name = x.name; price = x.price; amount = x.amount;}
    
	// Copy Assignment
	void operator=(const Fruit& x) {name = x.name; price = x.price; amount = x.amount;}
    
	// Destructor
	~Fruit(){std::cout << name << " is deleted\n";}
	
    int sum(){return price * amount;}
};

// Problem 1.2: Vegetable class
class Vegetable {
public:
    std::string name; int price; int amount;
    
    // Constructor
    Vegetable(std::string n, int p, int a) {name = n; price = p; amount = a;}
    
    // Copy Constructor
	Vegetable(const Vegetable& x) {name = x.name; price = x.price; amount = x.amount;}
    
    // Copy Assignment
	void operator=(const Vegetable& x) {name = x.name; price = x.price; amount = x.amount;}
	
	// Destructor
	~Vegetable() {std::cout << name << " is deleted\n";}
	int sum() {return price * amount;}
};

// Problem 3.1: TotalSum func.
int TotalSum(Fruit* fruits[], Vegetable* vegetables[]) {
    int total = 0;
    
    total = total + fruits[0]->sum();
    total = total + fruits[1]->sum();
    total = total + vegetables[0]->sum();
    total = total + vegetables[1]->sum();

    return total;
}

int main() {
    // Problem 2: GroceryList array
    void* GroceryList[4];
    Fruit* apple = new Fruit("Apple", 10, 7);
    Fruit* banana = new Fruit("Banana", 10, 8);
    Vegetable* broccoli = new Vegetable("Broccoli", 60, 12);
    Vegetable* lettuce = new Vegetable("Lettuce", 50, 10);

    GroceryList[0] = apple;
    GroceryList[1] = banana;
    GroceryList[2] = broccoli;
    GroceryList[3] = lettuce;
    Fruit* fruits[2];
    Vegetable* vegetables[2];
    fruits[0] = apple;
    fruits[1] = banana;
    vegetables[0] = broccoli;
    vegetables[1] = lettuce;

	// Display of Grocery List
    std::cout << "Grocery List\n\n" << apple->name << " "
              << apple->price << " x "  << apple->amount << " = "
              << apple->sum() << "\n" << banana->name << " "
              << banana->price << " x "<< banana->amount << " = "
              << banana->sum() << "\n" << broccoli->name << " "
              << broccoli->price << " x " << broccoli->amount << " = "
              << broccoli->sum() << "\n" << lettuce->name << " "
              << lettuce->price << " x " << lettuce->amount << " = "
              << lettuce->sum() << "\n";

    // Problem 3.2: Output
    std::cout << "\nTotal price: " << TotalSum(fruits, vegetables) << "\n";

    // Problem 4: Deleting Lettuce
    std::cout << "\nDeleting Lettuce\n";
    delete lettuce; vegetables[1] = 0;

    std::cout << "Updated total price: " << apple->sum() + banana->sum() + broccoli->sum() << "\n";

    delete apple; fruits[0] = 0;
    delete banana; fruits[1] = 0;
    delete broccoli; vegetables[0] = 0;

    return 0;
}
