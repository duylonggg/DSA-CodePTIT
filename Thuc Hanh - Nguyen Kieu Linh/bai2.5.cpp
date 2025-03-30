#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> res;
vector<int> path;
int n;

void dfs(int u, vector<vector<int>> &adj, vector<bool> &vis) {
    vis[u] = true;
    path.push_back(u);
    for (int v = 1; v <= n; ++v) {
        if (adj[u][v] && !vis[v]) {
            dfs(v, adj, vis);
        }
    }
}

void check(vector<vector<int>> &adj, vector<bool> &vis) {
    for (int i = 1; i <= n; ++i) {
        path.clear();
        if (!vis[i]) {
            dfs(i, adj, vis);
            res.push_back(path);
        }
    }
    cout << res.size() << '\n';
    for (auto &it : res) {
        for (int i : it) {
            cout << i << " ";
        }
        cout << '\n';
    }
}

int main() {
    cin >> n;
    vector<vector<int>> adj(n + 1, vector<int>(n + 1));
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> adj[i][j];
        }
    }
    check(adj, vis);
    return 0;
}
