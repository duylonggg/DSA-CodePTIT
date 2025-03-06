#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int n, x, seen = -1, num;
        cin >> n >> x;

        while (n--) {
            cin >> num;
            seen = (num == x ? 1 : seen);
        }

        cout << seen << endl;
    }
    return 0;
}