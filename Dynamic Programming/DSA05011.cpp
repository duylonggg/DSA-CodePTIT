#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'
#define MOD         1000000007

int main() {
    fastio()
    tests() {
        int n, k;
        cin >> n >> k;

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int d = 1; d <= 9 && d <= k; ++d) 
            dp[1][d] = 1;

        for (int i = 2; i <= n; ++i) 
            for (int s = 0; s <= k; ++s)
                for (int d = 0; d <= 9 and s - d >= 0; ++d)
                    (dp[i][s] += dp[i - 1][s - d]) %= MOD;
        cout << dp[n][k] << endl;
    }
    return 0;
}