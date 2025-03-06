#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

const int MOD = 1e9 + 7;

long long binPow(long long num, long long pow) {
    if (pow == 0) return 1;
    if (pow == 1) return num % MOD;

    long long res = binPow(num, pow >> 1);
    res = (res * res) % MOD;

    if (pow & 1) res = (res * num) % MOD;
    return res;
}

int main() {
    fastio()
    tests() {
        string num;
        cin >> num;
        cout << binPow(stoll(num), stoll(string(rbegin(num), rend(num)))) << endl;
    }
    return 0;
}
