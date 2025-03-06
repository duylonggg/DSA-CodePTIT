#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int decode(const string& str) {
    if (str[0] == '0') return 0;

    vector<int64_t> dp(str.size() + 1, 0);
    dp[0] = 1; 
    dp[1] = 1; 

    for (size_t i = 2; i <= str.size(); ++i) {
        if (str[i - 1] != '0') 
            dp[i] += dp[i - 1]; 

        int two_digit = stoi(str.substr(i - 2, 2));
        if (str[i - 2] != '0' && two_digit >= 10 && two_digit <= 26) 
            dp[i] += dp[i - 2];  
    }

    return dp[str.size()];
}

int main() {
    fastio();
    tests() {
        string str;
        cin >> str;
        cout << decode(str) << endl;
    }
    return 0;
}
