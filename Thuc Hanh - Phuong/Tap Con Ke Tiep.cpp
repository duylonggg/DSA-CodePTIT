#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

void gen(vector<int>& v, int n, int k) {
    int pos = -1;
    for (int i = k - 1; ~i; --i) {
        if (v[i] != n - k + i + 1) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        for (int i = 1; i <= k; ++i) cout << i << ' ';
    }

    ++v[pos];
    while (++pos < k) v[pos] = v[pos - 1] + 1;
    for (int _: v) cout << _ << ' ';
}

int main() {
    fastio()
    tests() {
        int n, k;
        cin >> n >> k;

        vector<int> v(k);
        for (int& _: v) cin >> _;
        
        gen(v, n, k);
        cout << endl;
    }
    return 0;
}