#include <iostream>
using namespace std;

int c(int N) {
    int dp[501][501] = {0};

    for (int j = 0; j <= N; ++j) {
        dp[0][j] = 1;
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            dp[i][j] = dp[i][j - 1];
            if (i >= j) {
                dp[i][j] += dp[i - j][j - 1];
            }
        }
    }

    return dp[N][N - 1];
}

int main() {
    int N;
    cin >> N;

    if (N < 5 || N > 500) {
        cout << "Invalid " << endl;
        return 1;
    }

    cout << c(N) << endl;
    return 0;
}
