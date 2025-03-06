#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int V, E;
vector<int> adj[1001], vis;
bool hasCycle;

void DFS(int u, int par) {
    vis[u] = 1;
    
    for (int v : adj[u]) {
        if (!vis[v]) {
            DFS(v, u);
        } else if (v != par) {
            hasCycle = true;
            return;
        }
    }
}

int main() {
    fastio()
    tests() {
        cin >> V >> E;

        for (int u = 1; u <= V; ++u) adj[u].clear();
        vis.assign(V + 1, 0);
        
        while (E--) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        hasCycle = false;
        for (int u = 1; u <= V; ++u) 
            if (!vis[u]) {
                if (hasCycle) break;
                DFS(u, u);
            }

        cout << (hasCycle ? "YES" : "NO") << endl;
    }
    return 0;
}