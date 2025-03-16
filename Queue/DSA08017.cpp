#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int n;
        int64_t lim = 0;
        cin >> n;

        for (int i = 1; i <= n; ++i) lim = lim * 10 + 8;

        queue<int64_t> q;
        stack<int64_t> stk;
        q.push(6);
        q.push(8);
        while (q.front() != lim) {
            int64_t num = q.front();
            q.pop();

            stk.push(num);

            num *= 10;
            q.push(num + 6);
            q.push(num + 8);
        }

        stk.push(lim);
        while (!stk.empty()) {
            cout << stk.top() << ' ';
            stk.pop();
        }
        cout << endl;
    }
    return 0;
}