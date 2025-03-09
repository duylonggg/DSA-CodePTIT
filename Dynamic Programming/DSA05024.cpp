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

        vector<int> v(n);
        for (int& _: v) cin >> _;

        vector<int> dp(k + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= k; ++i)
            for (int num : v)
                if (i >= num)
                    (dp[i] += dp[i - num]) %= MOD;

        cout << dp[k] << endl;
    }
    return 0;
}