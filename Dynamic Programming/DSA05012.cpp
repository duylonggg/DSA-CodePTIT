#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

const int MOD = 1e9 + 7;

int C(int n, int k) {
    vector<int> dp(k + 1, 0);
    dp[0] = 1;  

    for (int i = 1; i <= n; ++i) 
        for (int j = min(i, k); j > 0; --j) 
            dp[j] = (dp[j] + dp[j - 1]) % MOD;


    return dp[k];
}

int main() {
    fastio();
    tests() {
        int n, k;
        cin >> n >> k;
        cout << C(n, k) << endl; // C(n, k) = C(n - 1, k - 1) + C(n - 1, k)
    }
    return 0;
}
