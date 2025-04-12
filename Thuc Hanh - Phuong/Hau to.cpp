#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int n;
        cin >> n;

        stack<string> stk;
        unordered_map<string, function<int64_t(int64_t, int64_t)>> ops = {
            {"+", plus<int64_t>()},
            {"-", minus<int64_t>()},
            {"*", multiplies<int64_t>()},
            {"/", divides<int64_t>()}
        };
        for (int i = 1; i <= n; ++i) {
            string exp;
            cin >> exp;

            if (ops.count(exp)) {
                int64_t num2 = stoll(stk.top()); stk.pop();
                int64_t num1 = stoll(stk.top()); stk.pop();

                stk.push(to_string(ops[exp](num1, num2)));
            } else {
                stk.push(exp);
            }
        }

        cout << stk.top() << endl;
    }
    return 0;
}