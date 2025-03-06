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

        vector<vector<int>> mat(n, vector<int>(n, 0));
        for (auto& row : mat)
            for (auto& cell : row)
                cin >> cell;

        vector<int> dp(1 << n, INT_MIN);
        dp[0] = 0;
        for (int mask = 0; mask < (1 << n); ++mask) {
            int row = __builtin_popcount(mask);

            if (row >= n) continue;

            for (int col = 0; col < n; ++col) {
                if (!(mask & (1 << col))) {
                    int new_mask = mask | (1 << col);
                    dp[new_mask] = max(dp[new_mask], dp[mask] + mat[row][col]);
                }
            }
        }

        cout << dp[(1 << n) - 1] << endl;
    }
    return 0;
}