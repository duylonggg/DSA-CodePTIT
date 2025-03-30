#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int V, E;
vector<int> adj[1003], rev_adj[1003]; 
vector<int> order, component;
vector<bool> vis;

void DFS1(int u) {
    vis[u] = true;
    for (int v : adj[u])
        if (!vis[v])
            DFS1(v);
    order.push_back(u); 
}

void DFS2(int u) {
    vis[u] = true;
    component.push_back(u);
    for (int v : rev_adj[u])
        if (!vis[v])
            DFS2(v);
}

int main() {
    fastio();
    cin >> V >> E;
    vis.assign(V + 1, false);

    for (int i = 1; i <= V; ++i) {
        adj[i].clear();
        rev_adj[i].clear();
    }

    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u); 
    }

    for (int i = 1; i <= V; ++i)
        if (!vis[i])
            DFS1(i);

    vis.assign(V + 1, false);
    reverse(order.begin(), order.end()); 

    vector<vector<int>> SCCs;
    for (int u : order) {
        if (!vis[u]) {
            component.clear();
            DFS2(u);
            sort(component.begin(), component.end());
            SCCs.push_back(component);
        }
    }

    cout << SCCs.size() << endl;
    for (auto &scc : SCCs) {
        for (int v : scc) cout << v << " ";
        cout << endl;
    }

    return 0;
}
