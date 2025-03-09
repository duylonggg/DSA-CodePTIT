#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'
#define MOD         1000000007

int main() {
    fastio();
    tests() {
        int n;
        cin >> n;

        vector<vector<int>> dp(n + 1, vector<int>(10, 0));
        for (int i = 0; i <= 9; ++i) dp[1][i] = 1;

        for (int i = 2; i <= n; ++i) {
            vector<int> prefix_sum(10, 0);
            prefix_sum[9] = dp[i - 1][9]; 

            for (int j = 8; j >= 0; --j) 
                prefix_sum[j] = (dp[i - 1][j] + prefix_sum[j + 1]) % MOD;

            for (int j = 0; j <= 9; ++j) 
                dp[i][j] = prefix_sum[j];
        }

        cout << accumulate(dp[n].begin(), dp[n].end(), 0LL) % MOD << endl;
    }
    return 0;
}
