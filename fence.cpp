//  Painting Fence Algorithm
#include <bits/stdc++.h>
using namespace std;

int countWays(int n, int k) {

    if (n == 1) return k;
    if (n == 2) return k*k;

    int cnt1 = countWays(n-1,k)*(k-1);

    int cnt2 = countWays(n-2,k)*(k-1);

    return cnt1 + cnt2;
}

int main() {

    int n = 3, k = 2;
    cout << countWays(n, k) << endl;
    return 0;
}
