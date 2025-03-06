#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int n;
        cin >> n;

        vector<int64_t> dp(n + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= min(3, i); ++j)
                dp[i] += dp[i - j];
        
        cout << dp[n] << endl;
    }
    return 0;
}