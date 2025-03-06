#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

short precedence(char c) {
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    fastio()
    tests() {
        string infix;
        cin >> infix;

        stack<char> stk;
        queue<string> postfix;
        string num = "";
        
        for (char c : infix) {
            if (isdigit(c)) {
                num += c;
            } else {
                if (!num.empty()) {
                    postfix.push(num);
                    num = "";
                }
                if (c == '(') {
                    stk.push(c);
                } else if (c == ')') {
                    while (!stk.empty() && stk.top() != '(') {
                        postfix.push(string(1, stk.top()));
                        stk.pop();
                    }
                    stk.pop();
                } else {
                    while (!stk.empty() && precedence(c) <= precedence(stk.top())) {
                        postfix.push(string(1, stk.top()));
                        stk.pop();
                    }
                    stk.push(c);
                }
            }
        }
        
        if (!num.empty()) {
            postfix.push(num);
        }
        
        while (!stk.empty()) {
            postfix.push(string(1, stk.top()));
            stk.pop();
        }
        
        stack<int64_t> math;
        while (!postfix.empty()) {
            string ope = postfix.front();
            postfix.pop();
            
            if (isdigit(ope[0])) { 
                math.push(stoll(ope));
            } else { 
                int64_t num2 = math.top(); math.pop();
                int64_t num1 = math.top(); math.pop();
                int64_t num = 0;

                if (ope == "+") num = num1 + num2;
                else if (ope == "-") num = num1 - num2;
                else if (ope == "*") num = num1 * num2;
                else if (ope == "/") num = num1 / num2;

                math.push(num);
            }
        }

        cout << math.top() << endl;
    }
    return 0;
}
