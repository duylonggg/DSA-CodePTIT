#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int n, k;
vector<int> v, numb;
vector<vector<int>> res;

void gen(int start = 0, int total = 0) {
    if (total == k) {
        res.push_back(numb);
        return;
    }

    for (int i = start; i < n; ++i) {
        if (total + v[i] > k) continue;
        numb.push_back(v[i]);
        gen(i + 1, total + v[i]);
        numb.pop_back();
    }
}

int main() {
    tests() {
        cin >> n >> k;
        res.clear();
        v.resize(n);
        for (int& i : v) cin >> i;
        sort(v.begin(), v.end());

        gen();

        if (!res.size()) cout << -1;
        else {
            for (size_t i = 0; i < res.size(); ++i) {
                cout << '[' << res[i][0];
                for (size_t j = 1; j < res[i].size(); ++j) cout << ' ' << res[i][j];
                cout << ']' << ' ';
            }
        }

        cout << endl;
    }
    return 0;
}