#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int V, E, countCC;
vector<int> adj[1003], vis;

void BFS(int u) {
    ++countCC;
    vis[u] = 1;
    queue<int> q;
    q.push(u);

    while (!q.empty()) {
        u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}

int main() {
    fastio()
    tests() {
        cin >> V >> E;

        countCC = 0;
        vis.assign(V + 1, 0);
        for (int i = 1; i <= V; ++i) adj[i].clear();

        while (E--) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int u = 1; u <= V; ++u)
            if (!vis[u]) 
                BFS(u);
        
        cout << countCC << endl;
    }
    return 0;
}