#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int V, E, timeDFS;
vector<int> adj[1003], vis, low, num;
vector<pair<int, int>> bridges;

void DFS(int u, int par) {
    low[u] = num[u] = ++timeDFS;
    vis[u] = 1;

    for (int v : adj[u]) {
        if (!vis[v]) {
            DFS(v, u);
            low[u] = min(low[u], low[v]);

            if (low[v] > num[u])  
                bridges.push_back({min(u, v), max(u, v)});
        }
        else if (v != par)
            low[u] = min(low[u], num[v]);
    }
}

int main() {
    tests() {
        cin >> V >> E;

        timeDFS = 0;
        low.assign(V + 1, 0);
        num.assign(V + 1, 0);
        bridges.clear();
        vis.assign(V + 1, 0);
        for (int i = 1; i <= V; ++i) adj[i].clear();

        while (E--) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        DFS(1, -1);

        sort(bridges.begin(), bridges.end()); 
        for (auto [u, v] : bridges) cout << u << ' ' << v << ' ';
        cout << endl;
    }
    return 0;
}
