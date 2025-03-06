#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
#define tests()  int test_cases; cin >> test_cases; while (test_cases--)

int V, E;
vector<int> adj[1001];
vector<int> in_degree;

bool Kahn() {
    queue<int> q;
    int count = 0;

    for (int u = 1; u <= V; ++u) 
        if (in_degree[u] == 0) q.push(u);
    

    while (!q.empty()) {
        int u = q.front(); q.pop();
        ++count;  

        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) q.push(v);
        }
    }

    return count < V;
}

int main() {
    fastio();
    tests() {
        cin >> V >> E;

        for (int i = 1; i <= V; i++) adj[i].clear();
        in_degree.assign(V + 1, 0);

        while (E--) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            ++in_degree[v];
        }

        cout << (Kahn() ? "YES" : "NO") << endl;
    }
    return 0;
}
