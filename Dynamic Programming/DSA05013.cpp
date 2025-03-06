#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

const int MOD = 1e9 + 7;

int main() {
    fastio()
    tests() {
        int n, k;
        cin >> n >> k;

        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) 
            for (int j = 1; j <= min(i, k); ++j)
                (dp[i] += dp[i - j]) %= MOD;
        
        cout << dp[n] << endl;
    }
    return 0;
}