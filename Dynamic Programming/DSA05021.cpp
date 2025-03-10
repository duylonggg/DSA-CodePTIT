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

        vector<pair<int, int>> v(n);
        for (auto& [x, y] : v) cin >> x >> y;

        sort(v.begin(), v.end());
        
        vector<int64_t> dp(n, 1);
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                auto [a, b] = v[j];
                auto [c, d] = v[i];
                if (b < c)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        cout << *max_element(dp.begin(), dp.end()) << endl;
    }
    return 0;
}