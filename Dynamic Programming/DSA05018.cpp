#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

string preprocess(const string &s) {
    string t = "#";
    for (char c : s) {
        t += c;
        t += "#";
    }
    return t;
}

size_t Manacher(const string &s) {
    string t = preprocess(s);
    int n = t.size();
    vector<int> P(n, 0);

    int center = 0, right = 0, maxLen = 0, start = 0;

    for (int i = 0; i < n; ++i) {
        int mirror = 2 * center - i;
        if (i < right) {
            P[i] = min(P[mirror], right - i);
        }

        while (i - P[i] - 1 >= 0 && i + P[i] + 1 < n && t[i - P[i] - 1] == t[i + P[i] + 1]) {
            P[i]++;
        }

        if (i + P[i] > right) {
            center = i;
            right = i + P[i];
        }

        if (P[i] > maxLen) {
            maxLen = P[i];
            start = (i - P[i]) / 2; 
        }
    }

    return s.substr(start, maxLen).size();
}

size_t DP(const string& s) {
    size_t n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    size_t max_len = 1; 
    for (int i = 0; i < n; ++i) dp[i][i] = true;

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (s[i] == s[j] && (len == 2 || dp[i + 1][j - 1])) {
                dp[i][j] = true;
                max_len = len;
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
        cout << DP(s) << endl;
    }    
    return 0;
}
