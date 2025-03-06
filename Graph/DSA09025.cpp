#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int V, E, start, finish;
vector<int> adj[1001], path;
vector<bool> vis;

void DFS(int u, int par) {
    vis[u] = 1;

    for (int v : adj[u])
        if (!vis[v]) {
            path[v] = u;
            DFS(v, u);
        }
}

int main() {
    tests() {
        cin >> V >> E >> start >> finish;

        vis.assign(V + 1, false);
        path.resize(V + 1);
        for (int i = 1; i <= V; ++i) adj[i].clear();

        while (E--) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        DFS(start, -1);

        if (!vis[finish])
            cout << -1;
        else {
            stack<int> stk;
            while (start != finish) {
                stk.push(finish);
                finish = path[finish];
            }
            stk.push(start);
            while (stk.size()) {
                cout << stk.top() << ' ';
                stk.pop();
            }
        }
        cout << endl;
    }
    return 0;
}