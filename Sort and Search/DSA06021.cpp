#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int n, x, num, pos;
        cin >> n >> x;

        for (int i = 1; i <= n; ++i) {
            cin >> num;
            pos = (num == x ? i : pos);
        }
        cout << pos << endl;
    }
    return 0;
}