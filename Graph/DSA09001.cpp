#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int V, E;
vector<int> adj[1001];

int main() {
    tests() {
        cin >> V >> E;

        for (int i = 1; i <= V; ++i) adj[i].clear();

        while (E--) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int u = 1; u <= V; ++u) {
            cout << u << ": ";
            for (int v : adj[u]) cout << v << ' ';
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}