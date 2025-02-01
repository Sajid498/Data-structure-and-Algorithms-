// House Robber Problem using Recursion
#include <iostream>
#include <vector>
using namespace std;

int maxLootRec(vector<int> &hval, int n) {

    if (n <= 0)  return 0;

    if (n == 1)  return hval[0];


    int pick = hval[n - 1] + maxLootRec(hval, n - 2);
    int notPick = maxLootRec(hval, n - 1);
    return max(pick, notPick);
}

int maxLoot(vector<int>& hval) {
    int n = hval.size();
      return maxLootRec(hval, n);
}

int main() {
    vector<int> hval = {6, 7, 1, 3, 8, 2, 4};
    cout << maxLoot(hval);
    return 0;
}
