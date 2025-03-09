#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

inline bool isValid(int prev_mask, int mask) {
    for (int i = 0; i < 3; ++i) {
        if ((mask & (1 << i)) && (mask & (1 << (i + 1)))) return false;
    }
    if (mask & prev_mask) return false; 
    return true;
}

int getScore(int j, int mask, vector<vector<int>>& mat) {
    int score = 0;
    for (int i = 0; i < 4; i++) {
        if (mask & (1 << i)) score += mat[i][j];
    }
    return score;
}

int main() {
    fastio()
    tests() {
        int n;
        cin >> n;

        int mx = INT_MIN;
        vector<vector<int>> mat(4, vector<int>(n + 1));
        for (int i = 0; i < 4; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> mat[i][j];
                mx = max(mx, mat[i][j]);
            }
        }

        if (mx < 0) {
            cout << mx << endl;
            continue;
        }

        vector<vector<int>> dp(n + 1, vector<int>(16, INT_MIN));
        dp[0][0] = 0;

        for (int col = 1; col <= n; ++col) {
            for (int mask = 0; mask < 16; ++mask) {
                if (!isValid(0, mask)) continue;

                for (int prev_mask = 0; prev_mask < 16; ++prev_mask)
                    if (isValid(prev_mask, mask) && dp[col - 1][prev_mask] != INT_MIN)
                        dp[col][mask] = max(dp[col][mask], dp[col - 1][prev_mask] + getScore(col, mask, mat));
            }
        }

        int result = *max_element(dp[n].begin(), dp[n].end());
        cout << result << endl;
    }
    return 0;
}