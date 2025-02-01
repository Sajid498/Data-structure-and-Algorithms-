// profit from rod of size n
#include <bits/stdc++.h>
using namespace std;

int cutRodRecur(int i, vector<int> &price) {

    if (i==0) return 0;

    int ans = 0;

    for (int j=1; j<=i; j++) {
        ans = max(ans, price[j-1]+cutRodRecur(i-j, price));
    }

    return ans;
}

int cutRod(vector<int> &price) {
    int n = price.size();

    return cutRodRecur(n, price);
}

int main() {
    vector<int> price =  { 1, 5, 8, 9, 10, 17, 17, 20};
    cout << cutRod(price);
    return 0;
}
