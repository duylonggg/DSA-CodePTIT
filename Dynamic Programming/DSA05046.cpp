#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'
#define MOD         1000000007

int64_t binPow(int64_t base, int64_t exp) {
    if (exp == 0) return 1;
    if (exp == 1) return base % MOD;
    
    int64_t res = binPow(base, exp >> 1);
    (res *= res) %= MOD;
    
    return (exp & 1) ? (res * base) % MOD : res;
}

vector<vector<int64_t>> C(1005, vector<int64_t>(1005, 0));
void Combi() {
    for (int i = 0; i < 1005; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 or i == j) C[i][j] = 1;
            else C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
        }
    }
}

int64_t Faul(int64_t n, int64_t k) {
    if (k == 0) return n % MOD;

    vector<int64_t> dp(k + 1, 0);
    dp[0] = n % MOD;
    n %= MOD;

    int64_t tmp = (n + 1) % MOD;
    for (int i = 1; i <= k; ++i) {
        tmp = (tmp * (n + 1)) % MOD;
        dp[i] = (tmp - 1 + MOD) % MOD;

        int64_t sum = 0;
        for (int j = 0; j < i; ++j) 
            sum = (sum + (dp[j] * C[i + 1][i - j + 1]) % MOD) % MOD;

        dp[i] = (dp[i] - sum + MOD) % MOD;
        dp[i] = (dp[i] * binPow(i + 1, MOD - 2)) % MOD;
    }
    return dp[k];
}

int main() {
    fastio();
    Combi();
    tests() {
        int64_t n, k;
        cin >> n >> k;
        cout << Faul(n, k) << endl;
    }
    return 0;
}
