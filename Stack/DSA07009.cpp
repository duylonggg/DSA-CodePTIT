#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

bool is_ope(char c) {
    return c == '+' | c == '-' | c == '*' | c == '/';
}

int main() {
    fastio()
    tests() {
        string prefix;
        cin >> prefix;

        stack<string> infix;
        for (size_t i = prefix.length() - 1; ~i; --i) {
            if (is_ope(prefix[i])) {
                string ope1 = infix.top(); infix.pop();
                string ope2 = infix.top(); infix.pop();

                string ope = '(' + ope1 + prefix[i] + ope2 + ')';

                infix.push(ope);
            }
            else
                infix.push(string(1, prefix[i]));
        }

        cout << infix.top() << endl;
    }
    return 0;
}