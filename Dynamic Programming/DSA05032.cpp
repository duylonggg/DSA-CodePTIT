#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        string str;
        cin >> str;

        size_t n = str.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (size_t i = 0; i <= n; ++i) dp[i][i] = 1;

        for (size_t len = 2; len <= n; ++len) {
            for (size_t i = 0; i <= n - len; ++i) {
                size_t j = i + len - 1;
                
                if (str[i] == str[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }

        cout << n - dp[0][n - 1] << endl;
    }
    return 0;
}