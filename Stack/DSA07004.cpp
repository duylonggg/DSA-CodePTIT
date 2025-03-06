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

        stack<char> stk;
        for (char c : str) {
            if (c == '(')
                stk.push(c);
            else {
                if (!stk.empty() and stk.top() == '(') stk.pop();
                else stk.push(c);
            }
        }

        if (stk.empty()) {
            cout << 0 << endl;
            continue;
        }

        int ans = 0;
        char tmp = stk.top();
        stk.pop();
        while (!stk.empty()) {
            if (stk.top() == tmp) ans += 1;
            else ans += 2;

            stk.pop();

            if (!stk.empty()) {
                tmp = stk.top();
                stk.pop();
            }
        }

        cout << ans << endl;
    }
    return 0;
}