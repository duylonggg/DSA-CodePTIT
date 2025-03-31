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

        stack<string> prefix, exp;
        for (int i = 1; i <= n; ++i) {
            string str;
            cin >> str; 
            prefix.push(str);
        }

        unordered_map<string, function<int64_t(int64_t, int64_t)>> ops = {
            {"+", plus<int64_t>()},
            {"-", minus<int64_t>()},
            {"*", multiplies<int64_t>()},
            {"/", divides<int64_t>()}
        };

        while (!prefix.empty()) {
            string ope = prefix.top();
            prefix.pop();

            if (ops.count(ope)) {
                int64_t num1 = stoll(exp.top()); exp.pop();
                int64_t num2 = stoll(exp.top()); exp.pop();

                exp.push(to_string(ops[ope](num1, num2)));
            } else {
                exp.push(ope);
            }
        }

        cout << exp.top() << endl;
    }
    return 0;
}