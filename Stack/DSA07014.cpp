#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        string prefix;
        cin >> prefix;

        stack<int> stk;
        for (int i = prefix.size() - 1; i >= 0; i--) {
            if (isdigit(prefix[i])) {
                stk.push(prefix[i] - '0');
            } else {
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.pop();
                switch (prefix[i]) {
                    case '+': stk.push(a + b); break;
                    case '-': stk.push(a - b); break;
                    case '*': stk.push(a * b); break;
                    case '/': stk.push(a / b); break;
                }
            }
        }

        cout << stk.top() << endl;
    }
    return 0;
}