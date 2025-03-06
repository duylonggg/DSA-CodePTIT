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

        stack<int> st;
        for (char c : postfix) {
            if (isdigit(c)) {
                st.push(c - '0');
            } else {
                int a = st.top(); st.pop();
                int b = st.top(); st.pop();
                switch (c) {
                    case '+': st.push(b + a); break;
                    case '-': st.push(b - a); break;
                    case '*': st.push(b * a); break;
                    case '/': st.push(b / a); break;
                }
            }
        }

        cout << st.top() << endl;
    }
    return 0;
}