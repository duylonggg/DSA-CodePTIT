#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int N, M;
vector<int> adj[1001];
vector<int> depth; 

bool hasOddCycle(int u, int parent) {
    for (int v : adj[u]) {
        if (v == parent) continue; 

        if (depth[v] == -1) { 
            depth[v] = depth[u] + 1;
            if (hasOddCycle(v, u)) return true;
        } else if ((depth[u] - depth[v]) % 2 == 0) {
            return true; 
        }
    }
    return false;
}

bool isBipartite() {
    depth.assign(N + 1, -1);

    for (int i = 1; i <= N; ++i) {
        if (depth[i] == -1) { 
            depth[i] = 0; 
            if (hasOddCycle(i, -1)) return false;
        }
    }
    return true;
}

int main() {
    fastio();
    tests() {
        cin >> N >> M;
        for (int i = 1; i <= N; ++i) adj[i].clear();

        while (M--) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << (isBipartite() ? "YES" : "NO") << endl;
    }
    return 0;
}
