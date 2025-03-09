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

        vector<int> dp_inc(v.begin(), v.end()), dp_dec(v.begin(), v.end());
        for (int i = 1; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (v[j] < v[i])
                    dp_inc[i] = max(dp_inc[i], dp_inc[j] + v[i]);
        
        for (int i = n - 2; ~i; --i)
            for (int j = n - 1; j > i; --j)
                if (v[j] < v[i])
                    dp_dec[i] = max(dp_dec[i], dp_dec[j] + v[i]);

        int res = INT_MIN;
        for (int i = 0; i < n; ++i)
            res = max(res, dp_inc[i] + dp_dec[i] - v[i]);
        cout << res << endl;
    }
    return 0;
}