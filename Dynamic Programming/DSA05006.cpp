#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int maxSumIncreasingSubsequence(vector<int>& A) {
    int N = A.size();
    vector<int> dp(A); 
    
    int res = A[0]; 
    
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) 
            if (A[j] < A[i]) 
                dp[i] = max(dp[i], dp[j] + A[i]);

        res = max(res, dp[i]);
    }
    
    return res;
}

int main() {
    fastio()
    tests() {
        int N;
        cin >> N;

        vector<int> v(N);
        for (int& _: v) cin >> _;

        cout << maxSumIncreasingSubsequence(v) << endl;
    }
    return 0;
}