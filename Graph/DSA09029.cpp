#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int V, E;
vector<int> adj[1001];
vector<int> path;
vector<bool> visited;

bool HamiltonianPath(int u, int cnt) {
    if (cnt == V) return true;

    for (int v : adj[u]) {
        if (!visited[v]) {
            visited[v] = true;
            if (HamiltonianPath(v, cnt + 1)) return true;
            visited[v] = false;
        }
    }

    return false;
}

bool hasHamilton() {
    for (int start = 1; start <= V; ++start) {
        visited.assign(V + 1, false);
        visited[start] = true;
        if (HamiltonianPath(start, 1)) return true;
    }
    return false;
}

int main() {
    fastio();
    tests() {
        cin >> V >> E;

        for (int u = 1; u <= V; ++u) adj[u].clear();

        while (E--) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }

        cout << hasHamilton() << endl;
    }
    return 0;
}
