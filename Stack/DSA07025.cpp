#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio();
    tests() {
        int n;
        string str;
        cin >> n;
        cin.ignore(); 
        getline(cin >> ws, str);

        queue<string> postfix;
        stack<string> exp;
        stringstream ss(str);
        string word;
        while (ss >> word) postfix.push(word);

        unordered_map<string, function<int64_t(int64_t, int64_t)>> ops = {
            {"+", plus<int64_t>()}, {"-", minus<int64_t>()},
            {"*", multiplies<int64_t>()}, {"/", divides<int64_t>()}
        };

        while (!postfix.empty()) {
            string ope = postfix.front();
            postfix.pop();

            if (ops.count(ope)) {
                int64_t num2 = stoll(exp.top()); exp.pop();
                int64_t num1 = stoll(exp.top()); exp.pop();

                exp.push(to_string(ops[ope](num1, num2)));
            } else {
                exp.push(ope);
            }
        }

        cout << exp.top() << endl;
    }
    return 0;
}
