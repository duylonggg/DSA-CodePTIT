#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int V, E, M;
vector<vector<int>> adj;
vector<int> color;

bool isSafe(int u, int c) {
    for (int v = 1; v <= V; ++v) {
        if (adj[u][v] && color[v] == c) return false; 
    }
    return true;
}

bool graphColoring(int u) {
    if (u > V) return true;

    for (int c = 1; c <= M; ++c) {
        if (isSafe(u, c)) {
            color[u] = c; 
            if (graphColoring(u + 1)) return true; 
            color[u] = 0; 
        }
    }

    return false;
}

string solve() {
    color.assign(V + 1, 0);
    return graphColoring(1) ? "YES" : "NO"; 
}

int main() {
    fastio();
    tests() {
        cin >> V >> E >> M;
        adj.assign(V + 1, vector<int>(V + 1, 0));

        while (E--) {
            int u, v;
            cin >> u >> v;
            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        cout << solve() << endl;
    }
    return 0;
}
