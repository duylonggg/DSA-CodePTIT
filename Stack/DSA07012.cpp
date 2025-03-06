#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        string postfix;
        cin >> postfix;

        stack<string> prefix;
        for (char c : postfix) {
            if (isalnum(c)) prefix.push(string(1, c));
            else {
                string ope1 = prefix.top(); prefix.pop();
                string ope2 = prefix.top(); prefix.pop();

                string ope = '(' + ope2 + string(1, c) + ope1 + ')';

                prefix.push(ope);
            }
        }

        cout << prefix.top() << endl;
    }
    return 0;
}