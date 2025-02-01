#include <iostream>
using namespace std;

int fibonacci(int n) {
    // Create an array to store Fibonacci numbers
    int dp[n + 1];

    // Base cases
    dp[0] = 0;
    dp[1] = 1;

    // Fill the dp array using the bottom-up approach
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // Return the nth Fibonacci number
    return dp[n];
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Fibonacci number at position " << n << " is: " << fibonacci(n) << endl;

    return 0;
}
