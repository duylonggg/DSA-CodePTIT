#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

vector<int> Karatsuba(vector<int>& P, vector<int>& Q) {
    int m = P.size(), n = Q.size();
    vector<int> R(m + n - 1, 0);

    if (m <= 32 || n <= 32) {
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) 
                R[i + j] += P[i] * Q[j];
        return R;
    }

    int mid = max(m, n) / 2; 

    vector<int> P_low(P.begin(), P.begin() + min(mid, m));
    vector<int> P_high(P.begin() + min(mid, m), P.end());
    vector<int> Q_low(Q.begin(), Q.begin() + min(mid, n));
    vector<int> Q_high(Q.begin() + min(mid, n), Q.end());

    vector<int> P_sum(max(P_low.size(), P_high.size()), 0);
    vector<int> Q_sum(max(Q_low.size(), Q_high.size()), 0);

    for (size_t i = 0; i < P_low.size(); ++i) P_sum[i] += P_low[i];
    for (size_t i = 0; i < P_high.size(); ++i) P_sum[i] += P_high[i];
    for (size_t i = 0; i < Q_low.size(); ++i) Q_sum[i] += Q_low[i];
    for (size_t i = 0; i < Q_high.size(); ++i) Q_sum[i] += Q_high[i];

    vector<int> low = Karatsuba(P_low, Q_low);
    vector<int> high = Karatsuba(P_high, Q_high);
    vector<int> mid_prod = Karatsuba(P_sum, Q_sum);

    for (size_t i = 0; i < low.size(); ++i) R[i] += low[i];
    for (size_t i = 0; i < high.size(); ++i) R[i + 2 * mid] += high[i];

    for (size_t i = 0; i < mid_prod.size(); ++i) {
        if (i < low.size()) mid_prod[i] -= low[i];
        if (i < high.size()) mid_prod[i] -= high[i];
        if (i + mid < R.size()) R[i + mid] += mid_prod[i];
    }

    return R;
}

int main() {
    fastio()
    tests() {
        int M, N;
        cin >> M >> N;
        
        vector<int> P(M), Q(N);
        for (int &x : P) cin >> x;
        for (int &x : Q) cin >> x;

        vector<int> result = Karatsuba(P, Q);
        for (int x : result) cout << x << " ";
        cout << endl;
    }
    return 0;
}
