#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int n;
vector<bool> vis;
vector<int> k;

void gen(int len = 0) {
    if (len == n) {
        for (int i : k) cout << i;
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (vis[i] or (len and abs(k[len - 1] - i) == 1)) continue;

        k[len] = i;
        vis[i] = true;
        gen(len + 1);
        vis[i] = false;
    }
}

int main() {
    tests() {
        cin >> n;

        k.resize(n);
        vis.assign(n + 1, false);

        gen();
    }
    return 0;
}