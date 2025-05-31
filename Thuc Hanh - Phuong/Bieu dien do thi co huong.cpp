#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define test   int testcase; cin >> testcase; while(testcase--)

int main() {
    fastio;
    test {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V + 1] = {};

        while (E--) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
        }

        for (int i = 1; i <= V; ++i) {
            cout << i << ": ";
            sort(begin(adj[i]), end(adj[i]));
            for (int v : adj[i])
                cout << v << ' ';
            cout << endl;
        }
    }
    return 0;
}