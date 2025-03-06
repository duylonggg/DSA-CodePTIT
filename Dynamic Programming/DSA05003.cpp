#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int64_t LCS(const string& str1, const string& str2, const string& str3, const int& l1, const int& l2, const int& l3) {
    vector<vector<vector<int64_t>>> dp(l1 + 1, vector<vector<int64_t>>(l2 + 1, vector<int64_t>(l3 + 1, 0)));

    for (int i = 1; i <= l1; ++i) {
        for (int j = 1; j <= l2; ++j) {
            for (int k = 1; k <= l3; ++k) {
                if (str1[i - 1] == str2[j - 1] && str3[k - 1] == str1[i - 1]) {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                } else {
                    dp[i][j][k] = max({dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]});
                }
            }
        }
    }
    return dp[l1][l2][l3];
}

int main() {
    fastio();
    tests() {
        int l1, l2, l3;
        string str1, str2, str3;
        cin >> l1 >> l2 >> l3 >> str1 >> str2 >> str3;
        cout << LCS(str1, str2, str3, l1, l2, l3) << endl;
    }
    return 0;
}
