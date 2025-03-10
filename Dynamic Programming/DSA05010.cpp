#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int n, k;
        cin >> n >> k;

        vector<int> v(n);
        for (int& _: v) cin >> _;

        vector<int> dp(k, -1);
        dp[0] = 0;
        for (int x : v) {
            vector<int> new_dp = dp;
            for (int mod = 0; mod < k; ++mod) {
                if (dp[mod] != -1) {
                    int new_mod = (mod + x) % k;
                    new_dp[new_mod] = max(new_dp[new_mod], dp[mod] + 1);
                }
            }
            dp = new_dp;
        }

        cout << dp[0] << endl;
    }
    return 0;
}