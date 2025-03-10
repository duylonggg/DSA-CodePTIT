#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int n, m;
        cin >> n >> m;

        vector<vector<int64_t>> dp(26, vector<int64_t>(26, 0));
        for (int i = 0; i <= 25; ++i)
            dp[0][i] = dp[i][0] = 1;

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
        cout << dp[n][m] << endl;
    }
    return 0;
}