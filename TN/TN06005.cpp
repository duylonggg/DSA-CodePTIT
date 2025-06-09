#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define test   int testcase; cin >> testcase; while(testcase--)

int V, E;
vector<int> adj[21];
bool vis[25];

int BFS(int u, int fin) {
    vis[u] = true;
    queue<array<int, 2>> q;
    q.push({u, 0});

    while (!q.empty()) {
        auto [u, step] = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (v == fin) return step;
            vis[v] = true;
            q.push({v, step + 1});
        }
    }
}

int main() {
    fastio;
    test {
        cin >> V >> E;

        for (int i = 1; i <= V; ++i) {
            adj[i].clear();
            vis[i] = false;
        }

        while (E--) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 2;

        ans += BFS(1, 2);
        vis[1] = vis[2] = false;
        ans += BFS(2, 1);

        cout << ans << endl;
    }
    return 0;
}