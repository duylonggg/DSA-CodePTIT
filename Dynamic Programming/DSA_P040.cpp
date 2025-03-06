#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

const int MAXN = 10005;
int A[4][MAXN];

inline bool isValid(int prev_mask, int mask) {
    for (int i = 0; i < 3; ++i) {
        if ((mask & (1 << i)) && (mask & (1 << (i + 1)))) return false;
    }
    if (mask & prev_mask) return false; 
    return true;
}

int getScore(int j, int mask) {
    int score = 0;
    for (int i = 0; i < 4; i++) {
        if (mask & (1 << i)) score += A[i][j];
    }
    return score;
}

int main() {
    fastio();
    tests() {
        int N;
        cin >> N;

        int mx = INT_MIN;
        for (int i = 0; i < 4; ++i) {
            for (int j = 1; j <= N; ++j) {
                cin >> A[i][j];
                mx = max(mx, A[i][j]);
            }
        }

        if (mx < 0) {
            cout << mx << endl;
            continue;
        }

        vector<vector<int>> dp(N + 1, vector<int>(16, INT_MIN));
        dp[0][0] = 0;

        for (int j = 1; j <= N; ++j) {
            for (int mask = 0; mask < 16; ++mask) {
                if (!isValid(0, mask)) continue; 

                for (int prev_mask = 0; prev_mask < 16; ++prev_mask) 
                    if (isValid(prev_mask, mask) && dp[j - 1][prev_mask] != INT_MIN) 
                        dp[j][mask] = max(dp[j][mask], dp[j - 1][prev_mask] + getScore(j, mask));
            }
        }

        int result = *max_element(dp[N].begin(), dp[N].end());
        cout << result << endl;
    }
    return 0;
}
