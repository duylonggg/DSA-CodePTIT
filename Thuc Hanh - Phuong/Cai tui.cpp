#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int N, V;
        cin >> N >> V;

        vector<int> A(N), C(N);

        for (int& _: A) cin >> _;
        for (int& _: C) cin >> _;

        vector<int64_t> dp(V + 1, 0);

        for (int i = 0; i < N; ++i) 
            for (int j = V; j >= A[i]; --j) 
                dp[j] = max(dp[j], dp[j - A[i]] + C[i]);

        cout << dp[V] << endl;
    }
    return 0;
}