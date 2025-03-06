#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

string subArray(const vector<int>& v, const int n, const int s) {
    vector<int> dp(s + 1, 0);

    for (int i = 0; i < n; ++i) {
        dp[v[i]] = 1;
        for (int j = s; j >= v[i]; --j) {
            dp[j] |= dp[j - v[i]];
            if (dp[s]) return "YES";
        }
    }
    return "NO";
}

int main() {
    fastio()
    tests() {
        int n, s;
        cin >> n >> s;

        vector<int> v(n);
        for (int& _: v) cin >> _;

        cout << subArray(v, n, s) << endl;
    }
    return 0;
}