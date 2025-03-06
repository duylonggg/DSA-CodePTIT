#include <bits/stdc++.h>
using namespace std;

#define tests() int test_cases; cin >> test_cases; while (test_cases--)
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int main() {
    fastio();
    tests() {
        string math;
        cin >> math;

        stack<char> stk, tmp;
        for (int i = math.size() - 1; i >= 0; --i) {
            if ((math[i] == '-' || math[i] == '+') && !stk.empty() && stk.top() == '(') {
                char op = math[i];
                stk.pop();
                while (!stk.empty() && stk.top() != ')') {
                    char c = stk.top();
                    stk.pop();
                    tmp.push((op == '-' && (c == '+' || c == '-')) ? (c == '+' ? '-' : '+') : c);
                }
                if (!stk.empty()) stk.pop(); 
                while (!tmp.empty()) stk.push(tmp.top()), tmp.pop();
                stk.push(op);
            } else {
                stk.push(math[i]);
            }
        }

        while (!stk.empty()) {
            if (stk.top() != '(' && stk.top() != ')') cout << stk.top();
            stk.pop();
        }
        cout << endl;
    }
    return 0;
}
