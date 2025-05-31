#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define test   int testcase; cin >> testcase; while(testcase--)

int main() {
    fastio;
    test {
        string str;
        cin >> str;

        int max_len = 0;
        stack<int> stk;
        stk.push(-1);

        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (!stk.empty()) {
                    max_len = max(max_len, i - stk.top());
                } else {
                    stk.push(i);
                }
            }
        }

        cout << max_len << endl;
    }
    return 0;
}