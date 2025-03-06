#include <bits/stdc++.h>
using namespace std;

#define tests() int test_cases; cin >> test_cases; while (test_cases--)
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

string change(const string& math) {
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

    string res = "";
    while (!stk.empty()) {
        if (stk.top() != '(' && stk.top() != ')') res += stk.top();
        stk.pop();
    }

    return res;
}

int main() {
    fastio();
    tests() {
        string math1, math2;
        cin >> math1 >> math2;

        math1 = change(math1);
        math2 = change(math2);

        cout << (math1 == math2 ? "YES" : "NO") << endl;
    }
    return 0;
}