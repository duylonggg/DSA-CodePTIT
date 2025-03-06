#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio();
    tests() {
        int S, D;
        cin >> S >> D;

        if (S > 9 * D) {
            cout << -1 << endl;
            continue;
        }

        stack<int> stk;
        while (S > 0) {
            stk.push(min(9, S));
            S -= stk.top();
        }

        if (stk.size() != D) {
            --stk.top();
            while (stk.size() != D - 1) stk.push(0);
            stk.push(1);
        }

        while (!stk.empty()) {
            cout << stk.top();
            stk.pop();
        }
        cout << endl;
    }
    return 0;
}
