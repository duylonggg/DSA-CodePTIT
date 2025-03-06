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

        int cnt = 1;
        stack<int> stk;
        stk.push(cnt);
        for (char c : str) {
            if (c == 'I') {
                while (!stk.empty()) {
                    cout << stk.top();
                    stk.pop();
                }
            } 
            stk.push(++cnt);
        }
        while (!stk.empty()) {
            cout << stk.top();
            stk.pop();
        }
        
        cout << endl;
    }
    return 0;
}