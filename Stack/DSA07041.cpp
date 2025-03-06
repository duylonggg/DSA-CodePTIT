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
        int res = 0;
        for (char c : str) {
            if (c == '(')
                stk.push(c);
            else {
                if (!stk.empty() and stk.top() == '(') {
                    stk.pop();
                    res += 2;
                }
                else 
                    stk.push(c);
            }
        }

        cout << res << endl;
    }
    return 0;
}