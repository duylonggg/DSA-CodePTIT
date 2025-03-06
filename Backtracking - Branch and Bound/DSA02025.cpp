#include <bits/stdc++.h>
using namespace std;

int n, minDis = INT_MAX;
vector<string> v;
vector<vector<int>> dis;
vector<int> perm;

int toBitmask(const string &s) {
    int mask = 0;
    for (char c : s) mask |= (1 << (c - 'A')); 
    return mask;
}

int countCommon(int a, int b) {
    return __builtin_popcount(a & b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    v.resize(n);
    vector<int> masks(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        masks[i] = toBitmask(v[i]);
    }

    dis.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) 
        for (int j = i + 1; j < n; ++j) 
            dis[i][j] = dis[j][i] = countCommon(masks[i], masks[j]);

    perm.resize(n);
    iota(perm.begin(), perm.end(), 0);

    do {
        int curDis = 0;
        for (int i = 1; i < n; ++i)
            curDis += dis[perm[i - 1]][perm[i]];
        minDis = min(minDis, curDis);
    } while (next_permutation(perm.begin(), perm.end()));

    cout << minDis << '\n';
    return 0;
}
