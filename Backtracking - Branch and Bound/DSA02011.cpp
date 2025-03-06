#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int n, S, cnt;
vector<int> v;

void Try(int start, int total = 0, int count = 0) {
    if (cnt != -1) return;
    if (total == S) {
        cnt = count;
        return;
    }

    for (int i = start; i < n; ++i) {
        if (total + v[i] > S) continue;
        Try(i + 1, total + v[i], count + 1);
    }
}

int main() {
    tests() {
        cin >> n >> S;

        cnt = -1;
        v.resize(n);
        for (int& i : v) cin >> i;
        sort(v.rbegin(), v.rend());

        Try(0);

        cout << cnt << endl;
    }
    return 0;
}