#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define test   int testcase; cin >> testcase; while(testcase--)

int N, M, X;
vector<int> adj[301];
bool vis[301];

void DFS(int u) {
    vis[u] = true;

    for (int v : adj[u])
        if (!vis[v])
            DFS(v);
}

int main() {
    fastio;
    cin >> N >> M >> X;

    while (M--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(X);

    for (int i = 1; i <= N; ++i)
        if (!vis[i])
            cout << i << endl;
    return 0;
}