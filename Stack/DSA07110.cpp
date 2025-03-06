#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

bool check(const string& str) {
    stack<char> stk;
    for (char c : str) {
        if (c == '(' | c == '[' | c == '{') {
            stk.push(c);
        } else {
            if (c == '}') {
                if (!stk.empty() and stk.top() == '{') {
                    stk.pop();
                } else {
                    return false;
                }
            } else if (c == ')') {
                if (!stk.empty() and stk.top() == '(') {
                    stk.pop();
                } else {
                    return false;
                }
            } else {
                if (!stk.empty() and stk.top() == '[') {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    fastio()
    tests() {
        string str;
        cin >> str;

        cout << (check(str) ? "YES" : "NO") << endl;
    }
    return 0;
}