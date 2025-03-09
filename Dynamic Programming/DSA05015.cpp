#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAX_N 1000

int64_t dp[MAX_N + 1][MAX_N + 1];

void computeDP() {
    for (int n = 0; n <= MAX_N; n++) {
        dp[n][0] = 1;
        for (int k = 1; k <= n; k++) {
            dp[n][k] = (dp[n - 1][k] + k * dp[n - 1][k - 1] % MOD) % MOD; // P(n, k) = P(n − 1, k) + k.P(n − 1, k − 1)
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    computeDP();

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << dp[n][k] << '\n';
    }
    return 0;
}
