#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio();
    tests() {
        int A, B;
        cin >> A >> B;

        vector<vector<int>> dp(A + 1, vector<int>(B + 1, 1e9));
        dp[0][0] = 0; 

        for (int i = 0; i <= A; ++i) 
            for (int j = 0; j <= B; ++j) 
                for (int d = 1; d <= 9; ++d) 
                    if (i >= d && j >= d * d && dp[i - d][j - d * d] < 1e9) 
                        dp[i][j] = min(dp[i][j], dp[i - d][j - d * d] + 1);

        if (dp[A][B] == 1e9) {
            cout << -1 << endl;
            continue;
        }

        while (A > 0 && B > 0) {
            for (int d = 1; d <= 9; ++d) {
                if (A >= d && B >= d * d && dp[A][B] == dp[A - d][B - d * d] + 1) {
                    cout << d;
                    A -= d;
                    B -= d * d;
                    break;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
