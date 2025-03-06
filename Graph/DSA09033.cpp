#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

string isPerfect(vector<int> adj[], int V) {
    for (int u = 1; u <= V; ++u) 
        for (int v : adj[u])
            if (adj[v].size() != adj[u].size())
                return "NO";
    return "YES";
}

int main() {
    fastio()
    tests() {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V + 1];
        while (E--) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isPerfect(adj, V) << endl;        
    }
    return 0;
}