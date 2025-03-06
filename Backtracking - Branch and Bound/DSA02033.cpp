#include <bits/stdc++.h>
using namespace std;

#define tests() int test_cases; cin >> test_cases; while (test_cases--)

int n;
vector<int> k;
vector<bool> vis;

void gen(int len) {
    if (len == n) {
        for (int i : k) cout << i;
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (vis[i] || (len && abs(k[len - 1] - i) == 1)) continue;

        vis[i] = true;
        k[len] = i;
        gen(len + 1);
        vis[i] = false;
    }
}

int main() {
    tests() {
        cin >> n;
        k.resize(n);
        vis.assign(n + 1, false);

        gen(0);
        cout << endl;
    }
    return 0;
}
