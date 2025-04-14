#include <bits/stdc++.h>
using namespace std;

#define tests()     short test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

inline short longestPalindrome(string s) {
    if (s.length() <= 1) return s.length();

    short max_len = 1, len = s.length();
    vector<vector<bool>> dp(len, vector<bool>(len, false));

    for (short i = 0; i < len; ++i) {
        dp[i][i] = true;
        for (short j = 0; j < i; ++j) {
            if (s[j] == s[i] and (i - j <= 2 or dp[j + 1][i - 1])) {
                dp[j][i] = true;
                if (i - j + 1 > max_len) 
                    max_len = i - j + 1;
            }
        }
    }

    return max_len;
}

int main() {
    fastio();
    tests() {
        string s;
        cin >> s;
        cout << longestPalindrome(s) << endl;
    }    
    return 0;
}