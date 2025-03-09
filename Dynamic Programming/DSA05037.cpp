#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'
#define MOD         1000000007

int main() {
    fastio();
    tests() {
        int N;
        cin >> N;

        vector<vector<int64_t>> dp(N + 1, vector<int64_t>(10, 0));
        for (int i = 0; i <= 9; ++i) dp[1][i] = 1;

        for (int i = 2; i <= N; ++i)
            for (int j = 0; j <= 9; ++j)
                for (int k = j; k <= 9; ++k)
                    (dp[i][j] += dp[i - 1][k]) %= MOD;

        cout << accumulate(dp[N].begin(), dp[N].end(), 0LL) % MOD << endl;
    }
    return 0;
}
