#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        string str1, str2;
        cin >> str1 >> str2;
        size_t len1 = str1.size(), len2 = str2.size();

        str1 = '#' + str1;
        str2 = '#' + str2;

        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 0; i <= len1; ++i) dp[i][0] = i;
        for (int i = 0; i <= len2; ++i) dp[0][i] = i;
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (str1[i] == str2[j])
                    dp[i][j] = dp[i - 1][j - 1];
                else 
                    dp[i][j] = min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]}) + 1;
            }
        }
        cout << dp[len1][len2] << endl;
    }
    return 0;
}