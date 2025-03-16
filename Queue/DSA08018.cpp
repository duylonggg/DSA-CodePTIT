#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int n, cnt = 1;
        int64_t lim = 0;
        cin >> n;

        for (int i = 1; i <= n; ++i) lim = lim * 10 + 8;

        queue<int64_t> q;
        queue<int64_t> res;
        q.push(6);
        q.push(8);
        while (q.front() != lim) {
            int64_t num = q.front();
            q.pop();

            ++cnt;
            res.push(num);

            num *= 10;
            q.push(num + 6);
            q.push(num + 8);
        }

        cout << cnt << endl;
        res.push(lim);
        while (!res.empty()) {
            cout << res.front() << ' ';
            res.pop();
        }
        cout << endl;
    }
    return 0;
}