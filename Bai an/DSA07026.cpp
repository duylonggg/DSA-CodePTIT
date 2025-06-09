#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

struct FenwixMaxSuffix {
    int N;
    vector<int> fenw; 
    FenwixMaxSuffix(int _N) : N(_N), fenw(_N + 1, 0) {}

    inline int toRev(int i) const {
        return (N - 1) - i;
    }

    void update(int i, int val) {
        int ri = toRev(i);
        int x = ri + 1;
        while (x <= N) {
            fenw[x] = max(fenw[x], val);
            x += x & -x;
        }
    }

    int querySuffix(int i) const {
        int ri = toRev(i);
        int res = 0;
        int x = ri + 1;
        while (x > 0) {
            res = max(res, fenw[x]);
            x -= x & -x;
        }
        return res;
    }
};

int main() {
    fastio;

    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;

        if (n == 0) {
            for (int _ = 0; _ < q; _++) {
                int tmp; 
                cin >> tmp;
            }
            cout << "\n";
            continue;
        }

        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }

        vector<int> all = A;
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());
        int M = (int)all.size();  

        FenwixMaxSuffix fenw(M);

        vector<int> dp(n, 0);

        for (int i = n - 1; i >= 0; --i) {
            int idx = int(lower_bound(all.begin(), all.end(), A[i]) - all.begin());
            int best = 0;
            if (idx + 1 < M) {
                best = fenw.querySuffix(idx + 1);
            }
            dp[i] = 1 + best;
            fenw.update(idx, dp[i]);
        }

        while (q--) {
            int k;
            cin >> k;
            if (0 <= k && k < n) {
                cout << (dp[k] - 1) << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
