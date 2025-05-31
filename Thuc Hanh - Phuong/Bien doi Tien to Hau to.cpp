#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define test   int testcase; cin >> testcase; while(testcase--)

int main() {
    fastio;
    test {
        string prefix;
        cin >> prefix;
        
        reverse(prefix.begin(), prefix.end());

        stack<string> postfix;
        for (char c : prefix) {
            if (c != '+' and c != '-' and c != '*' and c != '/') {
                postfix.push(string(1, c));
            } else {
                string num1 = postfix.top(); postfix.pop();
                string num2 = postfix.top(); postfix.pop();

                string ope = num1 + num2 + string(1, c);

                postfix.push(ope);
            }
        }

        cout << postfix.top() << endl;
    }
    return 0;
}