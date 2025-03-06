#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

const int MOD = 1e9 + 7;

long long binPow(int n, int k) {
    if (k == 0) return 1;

    long long res = binPow(n, k >> 1) % MOD;
    res = (res % MOD * res % MOD) % MOD;

    if (k & 1) return (res % MOD * n % MOD) % MOD;
    return res % MOD;
}

int main() {
    fastio()
    tests() {
        int n, k;
        cin >> n >> k;
        cout << binPow(n, k) << endl;
    }
    return 0;
}