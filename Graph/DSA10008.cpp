#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int V, E, start;
vector<pair<int, int>> adj[1001];
vector<int> dist;

void clear() {
    for (int u = 1; u <= V; ++u) adj[u].clear();
    dist.assign(V + 1, INT_MAX); 
}

void Dijkstra(int start) {
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});  

    while (!pq.empty()) {
        auto [len, u] = pq.top(); 
        pq.pop();

        if (len > dist[u]) continue;

        for (auto [v, w] : adj[u]) { 
            if (len + w < dist[v]) {
                dist[v] = len + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    fastio()
    tests() {
        cin >> V >> E >> start;

        clear();
        
        while (E--) {
            int u, v, w;
            cin >> u >> v >> w;

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        Dijkstra(start);
        for (int u = 1; u <= V; ++u)
            cout << (dist[u] == INT_MAX ? -1 : dist[u]) << ' ';
        cout << endl;
    }
    return 0;
}
