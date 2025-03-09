#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio();
    tests() {
        string str;
        cin >> str;

        vector<long long> dp(str.size(), 0);
        dp[0] = str[0] - '0'; 

        for (size_t i = 1; i < str.size(); ++i) {
            dp[i] = dp[i - 1];  
            for (size_t j = 0; j <= i; ++j) 
                dp[i] += stoll(str.substr(j, i - j + 1));
        }

        cout << dp[str.size() - 1] << endl;
    }
    return 0;
}
