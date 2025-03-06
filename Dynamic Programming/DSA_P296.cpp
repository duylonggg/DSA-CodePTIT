#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    
    int N, Q;
    cin >> N >> Q;

    vector<int64_t> v(N + 1), prefix_sum(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
        prefix_sum[i] = prefix_sum[i - 1] + (v[i] > 0 ? v[i] : 0);
    }

    while (Q--) {
        int L, R;
        cin >> L >> R;
        cout << prefix_sum[R] - prefix_sum[L - 1] << endl;
    }
    return 0;
}