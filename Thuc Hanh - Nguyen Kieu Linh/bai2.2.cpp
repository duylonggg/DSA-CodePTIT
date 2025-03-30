#include <bits/stdc++.h>
using namespace std;

int n, m, start, endNode, parent[101], countPaths, pathLen;
vector<int> adj[101];
bool visited[101];

void dfs(int u, int v) {
    if (pathLen == 2) return;
    
    visited[u] = true;
    for (int x : adj[u]) {
        if (!visited[x]) {
            if (x == v && pathLen == 1) {
                ++countPaths;
                continue;
            }
            ++pathLen;
            dfs(x, v);
            --pathLen;
        }
    }
    visited[u] = false;
}

void dfs2(int u) {
    visited[u] = true;
    for (int x : adj[u]) {
        if (!visited[x]) {
            parent[x] = u;
            dfs2(x);
        }
    }
}

void findPath(int u, int v) {
    vector<int> path;
    while (v != -1) {
        path.push_back(v);
        v = parent[v];
    }
    reverse(path.begin(), path.end());
    for (int node : path) cout << node << " ";
    cout << endl;
}

void bai1() {
    cin >> n >> m >> start >> endNode;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(start, endNode);
    cout << countPaths << endl;
}

void bai2() {
    cin >> n >> m >> start >> endNode;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    dfs2(start);
    findPath(start, endNode);
}

int main() {
    int t;
    cin >> t;
    if (t == 1)
        bai1();
    else
        bai2();
    return 0;
}