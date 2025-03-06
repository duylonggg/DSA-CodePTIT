#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll p[] = {2, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}, res;
int d;

void dfs(int i, ll num = 1, ll div = 1) {
    if (div > d) return;
    if (div == d) res = min(res, num);

    ll exp = 1;
    while (num * p[i] <= res) {
        num *= p[i];
        dfs(i + 1, num, div * (exp + 1));
        ++exp;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> d;
        res = 1e18;
        dfs(1);
        cout << res << endl;
    }
    return 0;
}
