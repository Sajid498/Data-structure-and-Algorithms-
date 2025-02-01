// count permutations with exactly
#include <iostream>
using namespace std;

int countPermWithkInversions(int n, int k) {

    // Base cases
    // no permutations possible with 0 elements
    if (n == 0) return 0;

     // Only one way to have 0 inversions: sorted order
    if (k == 0) return 1;

    // Initialize result for this recursive step
    int result = 0;

    // Recursively sum up all valid counts
    // by placing the nth largest element
    // in positions that create the
    // required inversion counts
    for (int i = 0; i <= min(k, n - 1); i++) {
        result += countPermWithkInversions(n - 1, k - i);
    }

    return result;
}

int main() {

    int n = 4;
    int k = 2;

    cout << countPermWithkInversions(n, k);

    return 0;
}
