#include <bits/stdc++.h>
using namespace std;

int V, E;
vector<int> adj[1003], vis;
bool ok;

void DFS(int u, int par, string path = "1") {
    if (ok)
        return;
    vis[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v])
            DFS(v, u, path + " " + to_string(v));
        else if (v != par and v == 1) {
            path = path + " 1";
            cout << path;
            ok = true;
            return;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> V >> E;

        ok = false;
        vis.assign(V + 1, 0);
        for (int i = 1; i <= V; ++i)
            adj[i].clear();

        while (E--) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i <= V; ++i)
            sort(adj[i].begin(), adj[i].end());

        DFS(1, 1);
        if (!ok)
            cout << "NO";
        cout << endl;
    }
    return 0;
}