#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()

    string str;
    int val;
    stack<int> stk;

    int Query;
    cin >> Query;
    while (Query--) {
        cin >> str;

        if (str == "PUSH") {
            cin >> val;
            stk.push(val);
        }
        else if (str == "POP") {
            if (!stk.empty()) stk.pop();
        }
        else if (str == "PRINT") {
            if (stk.empty()) cout << "NONE";
            else cout << stk.top();
            cout << endl;
        }
    }
    return 0;
}