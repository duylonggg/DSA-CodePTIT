#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int V, E, start;
vector<int> adj[1001];
vector<pair<int, int>> tree_edges;
vector<bool> vis;

void BFS(int u) {
    vis[u] = 1;
    queue<int> q;
    q.push(u);

    while (!q.empty()) {
        u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                tree_edges.emplace_back(u, v); 
                q.push(v);
            }
        }
    }
}

int main() {
    fastio();
    tests() {
        cin >> V >> E >> start;

        for (int i = 1; i <= V; ++i) adj[i].clear();
        vis.assign(V + 1, false);
        tree_edges.clear();

        for (int i = 0; i < E; ++i) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        BFS(start);

        if ((int)tree_edges.size() != V - 1) {
            cout << -1 << endl;
        } else {
            for (auto [u, v] : tree_edges) 
                cout << u << " " << v << endl;
        }
    }
    return 0;
}
