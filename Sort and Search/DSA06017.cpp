#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int n, m, num;
        cin >> n >> m;

        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n + m; ++i) {
            cin >> num;
            pq.push(num);
        }

        while (!pq.empty()) {
            cout << pq.top() << ' ';
            pq.pop();
        }
        cout << endl;
    }
    return 0;
}