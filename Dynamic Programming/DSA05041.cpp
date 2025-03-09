#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int LPS(const string& str) {
    int n = str.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
        dp[i][i] = 1;
    
    for (int len = 2; len <= n; ++len) {  
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (str[i] == str[j])
                dp[i][j] = dp[i + 1][j - 1] + 2; 
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]); 
        }
    }

    return dp[0][n - 1]; 
}

int main() {
    fastio()
    tests() {
        string str;
        cin >> str;
        
        int lps = LPS(str);
        cout << str.size() - lps << endl;
    }
    return 0;
}
