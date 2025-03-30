#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, s, t;
vector<int> adj[1005], cutPoints;
bool vis[1005];

void dfs(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) dfs(v);
    }
}

void findCutPoints() {
    int initComp = 0, cnt = 0;
    memset(vis, 0, sizeof(vis));
    
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            ++initComp;
            dfs(i);
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        memset(vis, 0, sizeof(vis));
        vis[i] = true;
        int newComp = 0;
        
        for (int j = 1; j <= n; ++j) {
            if (!vis[j]) {
                ++newComp;
                dfs(j);
            }
        }
        if (newComp > initComp) cutPoints.push_back(i);
    }
    
    cout << cutPoints.size() << "\n";
    for (int v : cutPoints) cout << v << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m >> s >> t;
    while (m--) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    findCutPoints();
    
    return 0;
}
