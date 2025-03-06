#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int N;
        cin >> N;
        
        vector<int> v(N);
        for (int& _: v) cin >> _;

        vector<int> dp(N, 1);
        for (int i = 1; i < N; ++i) 
            for (int j = 0; j < i; ++j) 
                if (v[i] >= v[j]) 
                    dp[i] = max(dp[i], dp[j] + 1);

        cout << N - *max_element(dp.begin(), dp.end()) << endl;
    }
    return 0;
}