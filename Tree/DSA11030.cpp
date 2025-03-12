#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int LOG = 10; 

vector<int> tree[MAXN];
int parent[MAXN][LOG]; 
int depth[MAXN];   

void dfs(int u, int p) {
    parent[u][0] = p;
    for (int v : tree[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

void preprocessLCA(int N) {
    for (int j = 1; (1 << j) <= N; ++j) {
        for (int i = 1; i <= N; ++i) {
            if (parent[i][j - 1] != -1)
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
}

int getLCA(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    int diff = depth[u] - depth[v];
    for (int j = LOG - 1; j >= 0; --j) {
        if ((1 << j) & diff)
            u = parent[u][j];
    }

    if (u == v) return u;

    for (int j = LOG - 1; j >= 0; --j) {
        if (parent[u][j] != -1 && parent[u][j] != parent[v][j]) {
            u = parent[u][j];
            v = parent[v][j];
        }
    }
    return parent[u][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;

        for (int i = 1; i <= N; ++i) {
            tree[i].clear();
            depth[i] = 0;
            memset(parent[i], -1, sizeof(parent[i]));
        }

        for (int i = 1; i < N; ++i) {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        dfs(1, -1);
        
        preprocessLCA(N);

        int Q;
        cin >> Q;
        while (Q--) {
            int u, v;
            cin >> u >> v;
            int lca = getLCA(u, v);
            cout << (depth[u] + depth[v] - 2 * depth[lca]) << "\n";
        }
    }
    return 0;
}
