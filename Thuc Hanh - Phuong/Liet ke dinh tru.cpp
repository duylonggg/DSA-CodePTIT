#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

const int MAXN = 1005;
vector<int> adj[MAXN];
int low[MAXN], num[MAXN], vis[MAXN], joint[MAXN];
int V, E, timeDFS;

void clear() {
    for (int i = 1; i <= V; ++i) {
        adj[i].clear();
        low[i] = num[i] = vis[i] = joint[i] = 0;
    }
    timeDFS = 0;
}

void DFS(int u, int par) {
    low[u] = num[u] = ++timeDFS;
    vis[u] = 1;
    int child = 0;

    for (int v : adj[u]) {
        if (v == par) continue;
        if (vis[v]) {
            low[u] = min(low[u], num[v]);
        } else {
            DFS(v, u);
            low[u] = min(low[u], low[v]);

            if (par == -1) { 
                if (++child > 1) joint[u] = 1;
            } else if (low[v] >= num[u]) { 
                joint[u] = 1;
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
            if (joint[u]) cout << u << ' ';
        cout << endl;
    }
    return 0;
}
