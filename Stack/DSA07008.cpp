#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

short precedence(char ope) {
    if (ope == '^') return 3;
    if (ope == '*' | ope == '/') return 2;
    if (ope == '+' | ope == '-') return 1;
    return 0;
}

int main() {
    fastio()
    tests() {
        string infix;
        cin >> infix;

        stack<char> stk;
        queue<char> postfix;
        for (char c : infix) {
            if (isalnum(c)) {
                postfix.push(c);
            } else if (c == '(') {
                stk.push(c);
            } else if (c == ')') {
                while (!stk.empty() and stk.top() != '(') {
                    postfix.push(stk.top());
                    stk.pop();
                }
                stk.pop();
            } else {
                while (!stk.empty() and precedence(c) <= precedence(stk.top())) {
                    postfix.push(stk.top());
                    stk.pop();
                }
                stk.push(c);
            }
        }
        while (!stk.empty()) {
            postfix.push(stk.top());
            stk.pop();
        }

        while (!postfix.empty()) {
            cout << postfix.front();
            postfix.pop();
        }
        cout << endl;
    }
    return 0;
}