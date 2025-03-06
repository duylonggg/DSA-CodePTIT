#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int V, E, timeDFS;
vector<int> adj[1001], low, num, vis;
vector<bool> joint;

void clear() {
    timeDFS = 0;
    for (int u = 1; u <= V; ++u) adj[u].clear();
    low.resize(V + 1);
    num.resize(V + 1);
    vis.assign(V + 1, 0);
    joint.assign(V + 1, false);
}

void DFS(int u, int par) {
    int child = 0;
    low[u] = num[u] = ++timeDFS;
    vis[u] = 1;

    for (int v : adj[u]) {
        if (v == par) continue;
        if (vis[v]) {
            low[u] = min(low[u], num[v]);
        } else {
            DFS(v, u);
            low[u] = min(low[u], low[v]);

            ++child;
            if (par == -1) {
                if (child > 1) joint[1] = true;
            } else if (low[v] >= num[u]) {
                joint[u] = true;
            }
        }
    }
}

int main() {
    fastio()
    tests() {
        cin >> V >> E;

        clear();

        while (E--) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        DFS(1, -1);

        for (int u = 1; u <= V; ++u)
            if (joint[u])
                cout << u << ' ';
        cout << endl;
    }
    return 0;
}