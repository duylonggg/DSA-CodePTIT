#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int n, x;
vector<int> v;
bool flag;

void Try(int start = 0, string str = "", int total = 0) {
    if (total > x) return;

    if (total == x) {
        str.pop_back();
        cout << '[' << str << ']';
        flag = true;
        return;
    }

    for (int i = start; i < n; ++i) {
        if (total + v[i] > x) continue;
        Try(i, str + to_string(v[i]) + ' ', total + v[i]);
    }
}

int main() {
    tests() {
        cin >> n >> x;
        flag = false;

        v.resize(n);
        for (int& i : v) cin >> i;

        Try();

        if (!flag) cout << -1;

        cout << endl;
    }
    return 0;
}