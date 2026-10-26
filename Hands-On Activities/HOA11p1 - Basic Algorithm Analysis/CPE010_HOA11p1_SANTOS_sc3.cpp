#include <iostream>

// Time complexity: T(n) = O(n), Space complexity: S(n) = n
int rpower(int x, int n){
    if (n == 0) return 1;
    else return x * rpower(x, n - 1);
}

// Time complexity: T(n) = O(log n), Space complexity: S(n) = log n
int brpower(int x, int n){
    if (n == 0) return 1;

    int y;
    if (n % 2 == 1){
        y = brpower(x, (n - 1) / 2);
        return x * y * y;
    }
    else{
        y = brpower(x, n / 2);
        return y * y;
    }
}

int main(){
    int x = 2;
    int n = 10;

    // Time complexity: T(n) = O(n), Space complexity: S(n) = 8n + 16
    std::cout << "rpower: " << rpower(x, n) << "\n";
    std::cout << "brpower: " << brpower(x, n) << "\n";

    return 0;
}
