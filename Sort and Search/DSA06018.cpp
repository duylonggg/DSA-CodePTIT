#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int n, num, mn = INT_MAX, mx = INT_MIN, res = 0;
        cin >> n;

        bool freq[100005] = {}; 
        for (int i = 0; i < n; ++i) {
            cin >> num;
            freq[num] = true; 
            mn = min(mn, num);
            mx = max(mx, num);
        }

        for (int i = mn; i <= mx; ++i)
            res += (!freq[i]);

        cout << res << endl;
    }
    return 0;
}