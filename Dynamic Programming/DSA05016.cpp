#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
#define MOD 1000000007

long long findUglyNumber(int N) {
    vector<long long> dp(N);
    dp[0] = 1; 

    int i2 = 0, i3 = 0, i5 = 0;
    long long next2 = 2, next3 = 3, next5 = 5;

    for (int i = 1; i < N; ++i) {
        dp[i] = min({next2, next3, next5});

        if (dp[i] == next2) next2 = dp[++i2] * 2;
        if (dp[i] == next3) next3 = dp[++i3] * 3;
        if (dp[i] == next5) next5 = dp[++i5] * 5;
    }

    return dp[N - 1]; 
}

int main() {
    fastio();
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        cout << findUglyNumber(N) << endl;
    }
    return 0;
}
