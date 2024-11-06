#include <iostream>
using namespace std;

int fibonacci_recursive(int n) {
    if (n <= 1)
        return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Fibonacci (Recursive) of " << n << " is: " << fibonacci_recursive(n) << endl;
    return 0;
}


#include <iostream>
using namespace std;

int fibonacci_iterative(int n) {
    if (n <= 1)
        return n;
    
    int prev = 0, curr = 1, next;
    for (int i = 2; i <= n; ++i) {
        next = prev + curr; // Calculate next Fibonacci number
        prev = curr;        // Move prev to curr
        curr = next;        // Move curr to next
    }
    return curr;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Fibonacci (Iterative) of " << n << " is: " << fibonacci_iterative(n) << endl;
    return 0;
}
