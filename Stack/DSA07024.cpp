#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int& i : v) cin >> i;

        stack<int> stk;
        long long res = 0;
        int idx = 0;

        while (idx < n) {
            if (stk.empty() || v[idx] >= v[stk.top()]) {
                stk.push(idx++);
            } else {
                int h = v[stk.top()];
                stk.pop();
                int w = stk.empty() ? idx : idx - stk.top() - 1;
                int side = min(h, w);
                if (side == h) res = max(res, 1LL * side * side);
            }
        }

        while (!stk.empty()) {
            int h = v[stk.top()];
            stk.pop();
            int w = stk.empty() ? idx : idx - stk.top() - 1;
            int side = min(h, w);
            if (side == h) res = max(res, 1LL * side * side);
        }

        cout << sqrt(res) << endl;
    }
    return 0;
}
