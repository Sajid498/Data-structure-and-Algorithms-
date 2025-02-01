//find the minimum cost path
#include <bits/stdc++.h>
using namespace std;

int minCost(vector<vector<int>>& cost, int m, int n) {

    if (m < 0 || n < 0) {
        return INT_MAX;
    }
    if (m == 0 && n == 0) {
        return cost[m][n];
    }

    return cost[m][n] + min({minCost(cost, m, n - 1),
                             minCost(cost, m - 1, n),
                             minCost(cost, m - 1, n - 1)});
}

int main() {

    vector<vector<int>> cost = { { 1, 2, 3 },
                                 { 4, 8, 2 },
                                 { 1, 5, 3 } };

    int m = cost.size();
    int n = cost[0].size();

    cout << minCost(cost, m-1, n-1) << endl;

    return 0;
}
