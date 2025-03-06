#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int V, E;
vector<int> adj[1003], vis;

void DFS(int u) {
    vis[u] = 1;
    
    for (int v : adj[u])
        if (!vis[v])
            DFS(v);
}

string StrongConnectivity() {
    for (int u = 1; u <= V; ++u)
        if (!vis[u])
            return "NO";
    return "YES";
}

int main() {
    fastio()
    tests() {
        cin >> V >> E;

        for (int i = 1; i <= V; ++i) adj[i].clear();
        vis.assign(V + 1, 0);
        
        while (E--) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
        }

        DFS(1);

        cout << StrongConnectivity() << endl;
    }
    return 0;
}