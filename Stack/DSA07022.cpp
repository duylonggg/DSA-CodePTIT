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
        unordered_map<int, int> freq;
        for (int& i : arr) {
            cin >> i;
            ++freq[i];
        }

        stack<int> stk, res;
        for (int i = n - 1; ~i; --i) {
            while (!stk.empty() and freq[arr[i]] >= freq[stk.top()]) {
                stk.pop();
            }
            res.push((stk.empty() ? -1 : stk.top()));
            stk.push(arr[i]);
        }

        while (!res.empty()) {
            cout << res.top() << ' ';
            res.pop();
        }
        cout << endl;
    }
    return 0;
}