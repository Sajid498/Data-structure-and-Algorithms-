//fibo
#include <iostream>
using namespace std;

int fibonacci(int n) {
    // Base cases
    if (n <= 1) {
        return n;
    }

    // Variables to store the previous two Fibonacci numbers
    int prev1 = 1, prev2 = 0, current;

    // Compute Fibonacci numbers from 2 to n
    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return current; // The nth Fibonacci number
}

int main() {
    int n;
    cout << "Enter a number to find the Fibonacci number: ";
    cin >> n;

    cout << "The Fibonacci number at position " << n << " is: " << fibonacci(n) << endl;

    return 0;
}

