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
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int maxLen = 1;

        for (int i = 0; i < n; ++i)
            dp[i][i] = true;

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                
                if (str[i] == str[j]) {
                    if (len == 2) dp[i][j] = true;
                    else dp[i][j] = dp[i + 1][j - 1];
                }

                if (dp[i][j]) maxLen = max(maxLen, len);
            }
        }

        cout << maxLen << endl;
    }
    return 0;
}