#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int K, N, M;
vector<int> adj[1001], guests;
bitset<1001> vis;

void DFS(int u) {
    vis[u] = 1;

    for (int v : adj[u])
        if (!vis[v])
            DFS(v);
}

bool check(int u) {
    vis.reset();

    DFS(u);
    for (int u : guests)
        if (!vis[u])
            return false;
    return true;
}

int main() {
    fastio()
    cin >> K >> N >> M;

    int u, v;
    while (K--) {
        cin >> u;

        guests.push_back(u);
    }

    while (M--) {
        cin >> u >> v;

        adj[u].push_back(v);
    }

    int cnt = 0;
    for (int u = 1; u <= N; ++u)
        cnt += check(u);
    cout << cnt;
    return 0;
}