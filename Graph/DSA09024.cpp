#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int V, E, start;
vector<int> adj[1001];

void BFS(int u) {
    int vis[V + 1] = {};
    vis[u] = 1;
    queue<int> q;
    q.push(u);

    while (q.size()) {
        u = q.front();
        q.pop();

        cout << u << ' ';

        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}

int main() {
    tests() {
        cin >> V >> E >> start;

        for (int i = 1; i <= V; ++i) adj[i].clear();
        
        while (E--) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
        }

        BFS(start);

        cout << endl;
    }
    return 0;
}