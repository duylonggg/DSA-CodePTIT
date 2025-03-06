#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        string str;
        cin >> str;

        size_t res = 0;
        stack<int> stk;
        stk.push(-1);
        for (size_t i = 0; i < str.size(); ++i) {
            if (str[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (!stk.empty()) {
                    res = max(res, i - stk.top());
                } else {
                    stk.push(i);
                }
            }
        }

        cout << res << endl;
    }
    return 0;
}