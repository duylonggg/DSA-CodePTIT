#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int V, E, s, t, timeDFS;
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

set<int> res;
bool DFS2(int u, int end) {
    vis[u] = 1;
    if (joint[u]) res.insert(u);
    if (u == end) return true;

    for (int v : adj[u]) {
        if (!vis[v]) {
            if (DFS2(v, end))
                return true;
        }
    }
    // if (u != end and joint[u]) res.erase(u);
    return false;
}

int main() {
    fastio()
    freopen("TK.INP", "r", stdin);
    freopen("TK.OUT", "w", stdout);
    cin >> V >> E >> s >> t;

    clear();

    while (E--) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1, -1);

    int cntJoint = 0;
    for (int u = 1; u <= V; ++u)
        if (joint[u])
            ++cntJoint;
    
    vis.clear();
    DFS2(s, t);
    cout << cntJoint <<  endl;
    for (int u : res) cout << u << ' ';
    return 0;
}