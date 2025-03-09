#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int N, X, Y, Z;
        cin >> N >> X >> Y >> Z;
       
        vector<int> dp(N + 1);
        dp[0] = 0;
        for (int i = 1; i <= N; ++i) {
            dp[i] = dp[i - 1] + X;

            if (i & 1)
                dp[i] = min(dp[i], dp[(i + 1) >> 1] + Y + Z);
            else
                dp[i] = min(dp[i], dp[i >> 1] + Z);
        }

        cout << dp[N] << endl;
    }
    return 0;
}
