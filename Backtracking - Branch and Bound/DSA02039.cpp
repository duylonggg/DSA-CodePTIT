#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int n;
vector<int> numb;
vector<vector<int>> res;

void Try(int start, int total = 0) {
    if (total > n) return;
    if (total == n) {
        res.push_back(numb);
        return;
    }

    for (int i = start; i >= 1; --i) {
        if (total + i > n) continue;
        numb.push_back(i);
        Try(i, total + i);
        numb.pop_back();
    }
}

int main() {
    tests() {
        cin >> n;

        res.clear();
        Try(n);

        cout << res.size() << endl;
        for (size_t i = 0; i < res.size(); ++i) {
            cout << '(' << res[i][0];
            for (size_t j = 1; j < res[i].size(); ++j) cout << ' ' << res[i][j];
            cout << ')' << ' ';
        }
        cout << endl;
    }
    return 0;
}