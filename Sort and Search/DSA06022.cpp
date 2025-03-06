#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int n, x, min1 = INT_MAX, min2 = INT_MAX;
        cin >> n;
        
        for (int i = 0; i < n; ++i) {
            cin >> x;
            if (x < min1) {
                min2 = min1;
                min1 = x;
            } else if (x > min1 && x < min2) {
                min2 = x;
            }
        }

        if (min2 == INT_MAX)
            cout << -1 << endl;
        else
            cout << min1 << " " << min2 << endl;
    }
    return 0;
}
