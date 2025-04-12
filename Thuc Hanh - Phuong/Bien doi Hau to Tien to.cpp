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
        
        stack<string> stk;
        for (char c : str) {
            if (isalnum(c)) {
                stk.push(string(1, c));
            } else {
                string ope1 = stk.top(); stk.pop();
                string ope2 = stk.top(); stk.pop();

                string ope = string(1, c) + ope2 + ope1;

                stk.push(ope);
            }
        }

        cout << stk.top() << endl;
    }
    return 0;
}