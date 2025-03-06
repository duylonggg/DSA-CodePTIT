#include <bits/stdc++.h>
using namespace std;

set<string> results;
vector<pair<int, int>> brackets;
string expr;

void generate(int index, vector<bool>& remove) {
    if (index == brackets.size()) {
        string res;
        for (int i = 0; i < expr.size(); ++i) {
            bool skip = false;
            for (int j = 0; j < brackets.size(); j++) {
                if (remove[j] && (i == brackets[j].first || i == brackets[j].second)) {
                    skip = true;
                    break;
                }
            }
            if (!skip) res += expr[i];
        }
        if (res != expr) results.insert(res);
        return;
    }

    generate(index + 1, remove);

    remove[index] = true;
    generate(index + 1, remove);
    remove[index] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> expr;
    stack<int> stk;

    for (int i = 0; i < expr.size(); i++) {
        if (expr[i] == '(') stk.push(i);
        else if (expr[i] == ')') {
            if (!stk.empty()) {
                brackets.push_back({stk.top(), i});
                stk.pop();
            }
        }
    }

    vector<bool> remove(brackets.size(), false);
    generate(0, remove);

    for (const string& res : results) cout << res << '\n';
    return 0;
}
