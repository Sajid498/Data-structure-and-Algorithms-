 // Longest Common Substring
#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstr(string& s1, string& s2) {

    int m = s1.length();
    int n = s2.length();
    int result = 0;
    int dp[2][n];

    int currRow = 0;

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[currRow][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1]) {
                dp[currRow][j] = dp[1 - currRow][j - 1] + 1;
                result = max(result, dp[currRow][j]);
            }
            else {
                dp[currRow][j] = 0;
            }
        }

        currRow = 1 - currRow;
    }

    return result;
}

int main() {
    string s1 = "GeeksforGeeks";
    string s2 = "GeeksQuiz";

    cout << longestCommonSubstr(s1, s2);
    return 0;
}
