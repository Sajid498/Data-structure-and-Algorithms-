#include <bits/stdc++.h>
using namespace std;

int minCoins(int coins[], int n, int amount) {
    int dp[amount + 1];

    // Initialize dp array
    for (int i = 0; i <= amount; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0; // 0 coins are needed to make amount 0

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < n; j++) {
            if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    int n, amount;
    cout << "Enter the number of coins: ";
    cin >> n;

    int coins[n];
    cout << "Enter the coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << "Enter the amount: ";
    cin >> amount;

    int result = minCoins(coins, n, amount);
    if (result == -1) {
        cout << "It is not possible to make the amount using the given coins.\n";
    } else {
        cout << "Minimum number of coins required: " << result << endl;
    }

    return 0;
}

