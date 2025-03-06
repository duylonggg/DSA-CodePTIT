#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

const int MOD = 1e9 + 7;

int64_t binPow(int base, int64_t exp) {
    if (exp == 0) return 1;
    if (exp == 1) return base % MOD; 

    int64_t res = binPow(base, exp >> 1);
    res = (res * res) % MOD; 

    if (exp & 1) res = (res * base) % MOD; 
    return res;
}

int main() {
    fastio();
    int base;
    int64_t exp;
    while (cin >> base >> exp and (base or exp)) {
        cout << binPow(base, exp) << endl;
    }
    return 0;
}
