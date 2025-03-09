#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio();
    tests() {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> v(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; ++i) 
            for (int j = 1; j <= m; ++j) 
                cin >> v[i][j];

        vector<vector<int64_t>> dp(n + 1, vector<int64_t>(m + 1, 0));
        dp[1][1] = v[1][1];

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (i == 1 && j == 1) continue; 

                int64_t fromTop = (i > 1) ? dp[i - 1][j] : LLONG_MAX;
                int64_t fromLeft = (j > 1) ? dp[i][j - 1] : LLONG_MAX;
                int64_t fromDiagonal = (i > 1 && j > 1) ? dp[i - 1][j - 1] : LLONG_MAX;

                dp[i][j] = min({fromTop, fromLeft, fromDiagonal}) + v[i][j];
            }
        }

        cout << dp[n][m] << endl;
    }
    return 0;
}
