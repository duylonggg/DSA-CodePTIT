#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int V, E, s, t;
vector<int> adj[1001], vis;

string BFS() {
    vis[s] = 1;
    queue<pair<int, string>> q;
    q.push({s, to_string(s)});

    while (!q.empty()) {
        auto [u, path] = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (!vis[v]) {
                if (v == t) return path + " " + to_string(v);
                vis[v] = 1;
                q.push({v, path + " " + to_string(v)});
            }
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

        cout << BFS() << endl;
    }
    return 0;
}
