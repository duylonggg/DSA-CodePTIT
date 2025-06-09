#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define test   int testcase; cin >> testcase; while(testcase--)

int V, E, st, en;
vector<int> adj[1001];
bool vis[1001];

string BFS() {
    vis[st] = true;
    queue<pair<int, string>> q;
    q.push({st, to_string(st)});

    while (!q.empty()) {
        auto [u, path] = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (v == en) return path + "->" + to_string(en);
            vis[v] = true;
            q.push({v, path + "->" + to_string(v)});
        }
    }
}

int main() {
    fastio;
    test {
        cin >> V >> E >> st >> en;

        for (int u = 1; u <= V; ++u) {
            adj[u].clear();
            vis[u] = false;
        }

        while (E--) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        cout << BFS() << endl;
    }
    return 0;
}