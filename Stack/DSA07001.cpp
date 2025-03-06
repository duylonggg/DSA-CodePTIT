#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);

int main() {
    fastio();

    string str;
    stack<int> stk;

    while (cin >> str) {
        if (str == "push") {
            int x;
            cin >> x;
            stk.push(x);
        } 
        else if (str == "pop") {
            if (!stk.empty()) stk.pop();
        } 
        else {
            if (stk.empty()) {
                cout << "empty\n";
                continue;
            }

            stack<int> tmp;
            stack<int> stk2 = stk;
            while (!stk2.empty()) {
                tmp.push(stk2.top());
                stk2.pop();
            }
            while (!tmp.empty()) {
                cout << tmp.top() << ' ';
                tmp.pop();
            }
            cout << '\n';
        }
    }
    return 0;
}
