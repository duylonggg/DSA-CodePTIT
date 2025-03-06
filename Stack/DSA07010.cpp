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

        stack<string> postfix;
        for (size_t i = prefix.length() - 1; ~i; --i) {
            if (is_ope(prefix[i])) {
                string ope1 = postfix.top(); postfix.pop();
                string ope2 = postfix.top(); postfix.pop();

                string ope = ope1 + ope2 + prefix[i];

                postfix.push(ope);
            }
            else
                postfix.push(string(1, prefix[i]));
        }

        cout << postfix.top() << endl;
    }
    return 0;
}