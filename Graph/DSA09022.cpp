#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int V, E, start;
vector<int> adj[1001];
vector<bool> vis;

void DFS(int u) {
    cout << u << ' ';
    vis[u] = 1;

    for (int v : adj[u])
        if (!vis[v])
            DFS(v);
}

int main() {
    tests() {
        cin >> V >> E >> start;

        vis.assign(V + 1, false);
        for (int i = 1; i <= V; ++i) adj[i].clear();

        while (E--) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        DFS(start);

        cout << endl;
    }
    return 0;
}