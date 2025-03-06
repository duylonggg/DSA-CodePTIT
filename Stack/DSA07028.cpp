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

        int arr[n];
        for (int& i : arr) cin >> i;

        queue<int> q;
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            int res = 1;
            while (!stk.empty() and arr[i] >= arr[stk.top()]) 
                stk.pop();
            if (stk.empty()) 
                res = max(res, i + 1);
            else
                res = max(res, i - stk.top());
            q.push(res);
            stk.push(i);
        }

        while (!q.empty()) {
            cout << q.front() << ' ';
            q.pop();
        }
        cout << endl;
    }
    return 0;
}