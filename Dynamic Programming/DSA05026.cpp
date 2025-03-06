#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    
    int C, N;
    cin >> C >> N;

    vector<int> w(N);
    for (int& _: w) cin >> _;

    vector<int> dp(C + 1, 0);

    for (int i = 1; i <= N; ++i) 
        for (int j = C; j >= w[i - 1]; --j) 
            dp[j] = max(dp[j], dp[j - w[i - 1]] + w[i - 1]);
    
    cout << dp[C];
    return 0;
}
