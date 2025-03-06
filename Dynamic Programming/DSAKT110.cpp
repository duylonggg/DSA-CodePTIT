#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int N;
        cin >> N;

        vector<int> v(N);
        for (int& _: v) cin >> _;

        vector<int64_t> dp(N + 1, 0);
        dp[1] = v[0];
        for (int i = 2; i <= N; ++i) 
            dp[i] = max(dp[i - 1], dp[i - 2] + v[i - 1]);
        cout << dp[N] << endl;
    }
    return 0;
}