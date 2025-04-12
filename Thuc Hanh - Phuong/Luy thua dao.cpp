#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

const int64_t MOD = 1000000007;

int64_t rvNum(int64_t n) {
    string str = to_string(n);
    reverse(str.begin(), str.end());
    return stoll(str);
}

int64_t binPow(int64_t base, int64_t exp) {
    if (exp == 1) return base % MOD;

    int64_t tmp = binPow(base, exp >> 1) % MOD;
    tmp = (tmp * tmp) % MOD;

    if (exp & 1) return (tmp * base) % MOD;
    return tmp % MOD;
}

int main() {
    fastio()
    tests() {
        int64_t n;
        cin >> n;
        int64_t r = rvNum(n);

        cout << binPow(n, r) << endl;
    }
    return 0;
}