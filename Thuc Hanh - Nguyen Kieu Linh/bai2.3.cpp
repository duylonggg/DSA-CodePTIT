#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
int n, m, u, v, t;

int count_paths_of_length_2(int u, int v) {
    int count = 0;
    for (int mid : adj[u]) {
        for (int end : adj[mid]) {
            if (end == v) ++count;
        }
    }
    return count;
}

vector<int> bfs_path(int u, int v) {
    queue<int> q;
    vector<int> parent(n + 1, -1);
    vector<bool> visited(n + 1, false);
    
    q.push(u);
    visited[u] = true;
    
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        if (curr == v) break;
        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = curr;
                q.push(neighbor);
            }
        }
    }
    
    if (parent[v] == -1) return {0};
    
    vector<int> path;
    for (int node = v; node != -1; node = parent[node]) {
        path.push_back(node);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    // freopen("TK.INP", "r", stdin);
    // freopen("TK.OUT", "w", stdout);
    
    cin >> t >> n >> m >> u >> v;
    
    for (int i = 0; i < m; ++i) {
        int ui, vi;
        cin >> ui >> vi;
        adj[ui].push_back(vi);
        adj[vi].push_back(ui);
    }
    
    if (t == 1) {
        cout << count_paths_of_length_2(u, v) << "\n";
    } else {
        vector<int> path = bfs_path(u, v);
        for (int node : path) {
            cout << node << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
