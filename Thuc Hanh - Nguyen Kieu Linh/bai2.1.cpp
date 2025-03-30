#include<bits/stdc++.h>
using namespace std;

int n, u, v;
int a[101][101], par[101];
vector<int> adj[101];
bool used[101];

void dfs(int u) {
    used[u] = true;
    for (int x : adj[u]) {
        if (!used[x]) {
            par[x] = u;
            dfs(x);
        }
    }
}

void find(int u, int v){
    vector<int> path;
    if (!used[v]) {
        cout << "NO\n";
        return;
    }
    while (v != -1) {
        path.push_back(v);
        v = par[v];
    }
    reverse(path.begin(), path.end());
    for (int it : path) cout << it << " ";
    cout << endl;
}

void bai1() {
    int cnt = 0;
    cin >> n >> u >> v;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    }
    for (int i = 1; i <= n; ++i) {
        if (a[u][i] && a[i][v]) ++cnt;
    }
    cout << cnt << endl;
}

void bai2() {
    cin >> n >> u >> v;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
            if (a[i][j]) {
                adj[i].push_back(j);
            }
        }
    }
    memset(used, false, sizeof used);
    memset(par, -1, sizeof par);
    dfs(u);
    find(u, v);
}

int main() {
    int t;
    cin >> t;
    if (t == 1) {
        bai1();
    }
    else bai2();
    return 0;
}