#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio();
    tests() {
        int n;
        cin >> n;
        vector<int> arr(n);

        for (int& i : arr) cin >> i;

        vector<int> greater(n), smaller(n);
        stack<int> stk;

        for (int i = n - 1; ~i; --i) {
            while (!stk.empty() && arr[i] >= arr[stk.top()]) {
                stk.pop();
            }
            greater[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        while (!stk.empty()) stk.pop();

        for (int i = n - 1; ~i; --i) {
            while (!stk.empty() && arr[i] <= arr[stk.top()]) {
                stk.pop();
            }
            smaller[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        for (int i = 0; i < n; ++i) {
            if (greater[i] == -1 || smaller[greater[i]] == -1) {
                cout << -1 << ' ';
            } else {
                cout << arr[smaller[greater[i]]] << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}
