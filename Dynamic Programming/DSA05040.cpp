#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int& _: v) cin >> _;

        vector<int> dp_inc(n + 1, 1), dp_dec(n + 1, 1);
        for (int i = 1; i < n; ++i) 
            if (v[i] > v[i - 1])
                dp_inc[i] = dp_inc[i - 1] + 1;
        for (int i = n - 2; i >= 0; --i)
            if (v[i] > v[i + 1])
                dp_dec[i] = dp_dec[i + 1] + 1;
        
        int res = 0;
        for (int i = 0; i < n; ++i)
            res = max(res, dp_inc[i] + dp_dec[i] - 1);
        cout << res << endl;
    }
    return 0;
}