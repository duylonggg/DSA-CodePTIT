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

        vector<vector<int>> mat(n + 2, vector<int>(m + 2, 0)); 
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                cin >> mat[i][j];

        vector<vector<int>> dp(n + 2, vector<int>(m + 2, 0));
        int max_val = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (mat[i][j] == 1) {
                    dp[i][j] = min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}) + 1;
                    max_val = max(max_val, dp[i][j]);
                }
            }
        }

        cout << max_val << endl;
    }
    return 0;
}
