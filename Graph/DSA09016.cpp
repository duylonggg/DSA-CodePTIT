#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int V, E;
vector<int> adj[1001];
vector<int> color;
bool hasCycle;

void DFS(int u) {
    color[u] = 1;

    for (int v : adj[u]) {
        if (color[v] == 0) {
            DFS(v);
        } else if (color[v] == 1) { 
            hasCycle = true;
            return;
        }
    }

    color[u] = 2;
}

int main() {
    fastio()
    tests() {
        cin >> V >> E;

        for (int u = 1; u <= V; ++u) adj[u].clear();
        color.assign(V + 1, 0);

        while (E--) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v); 
        }

        hasCycle = false;
        for (int u = 1; u <= V; ++u) {
            if (color[u] == 0) {
                DFS(u);
                if (hasCycle) break;
            }
        }

        cout << (hasCycle ? "YES" : "NO") << endl;
    }
    return 0;
}
