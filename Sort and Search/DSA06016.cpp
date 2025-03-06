#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int n, m, minB = INT_MAX, maxA = INT_MIN;
        cin >> n >> m;

        int a[n], b[n];
        for (int& _ : a) {
            cin >> _;
            maxA = max(maxA, _);
        }
        for (int& _ : b) {
            cin >> _;
            minB = min(minB, _);
        }

        cout << 1ll * maxA * minB << endl;
    }
    return 0;
}