#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
vector<int> adj[MAXN + 1];
vector<pair<int, int>> edges;
bool visited[MAXN + 1];
vector<pair<int, int>> oriented_edges;

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            oriented_edges.emplace_back(u, v);
            dfs(v);
        } else if (find(oriented_edges.begin(), oriented_edges.end(), make_pair(v, u)) == oriented_edges.end()) {
            oriented_edges.emplace_back(u, v);
        }
    }
}

bool is_connected(int n) {
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(1);
    visited[1] = true;
    int count = 1;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                ++count;
            }
        }
    }
    return count == n;
}

int main() {
    int t, n, m;
    cin >> t >> n >> m;
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges.emplace_back(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    if (t == 1) {
        cout << (is_connected(n) ? 1 : 0) << "\n";
    } else if (t == 2) {
        if (!is_connected(n)) return 0;
        memset(visited, false, sizeof(visited));
        dfs(1);
        sort(oriented_edges.begin(), oriented_edges.end());
        cout << n << " " << m << "\n";
        for (auto [u, v] : oriented_edges) {
            cout << u << " " << v << "\n";
        }
    }
    return 0;
}
