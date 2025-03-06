#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

const long long MOD = 123456789;

long long binPow(long long n, long long pow) {
    if (pow == 1) return n % MOD;

    long long res = binPow(n, pow >> 1);
    res = (res * res) % MOD;

    if (pow & 1) return (res * n) % MOD;
    return res % MOD;
}

int main() {
    fastio()
    tests() {
        long long n;
        cin >> n;
        cout << binPow(2, n - 1) << endl;
    }
    return 0;
}