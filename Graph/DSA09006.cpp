#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int V, E, s, t;
vector<int> adj[1001];
vector<int> vis;

string DFS(int u, string path) {
    vis[u] = 1;

    for (int v : adj[u]) {
        if (!vis[v]) {
            if (v == t) return path + " " + to_string(v); 
            string res = DFS(v, path + " " + to_string(v));
            if (res != "-1") return res;  
        }
    }

    return "-1";
}

int main() {
    fastio();
    tests() {
        cin >> V >> E >> s >> t;

        for (int i = 1; i <= V; ++i) adj[i].clear();
        vis.assign(V + 1, 0);

        while (E--) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << DFS(s, to_string(s)) << endl;
    }
    return 0;
}
