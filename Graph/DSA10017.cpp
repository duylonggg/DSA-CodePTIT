#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

const int INF = 1e9;
int V, E;
vector<tuple<int, int, int>> edges; 

bool BellmanFord() {
    vector<int> dist(V + 1, INF);
    dist[1] = 0;

    for (int i = 1; i <= V - 1; ++i) 
        for (auto [u, v, w] : edges) 
            if (dist[u] + w < dist[v]) 
                dist[v] = dist[u] + w;

    for (auto [u, v, w] : edges) 
        if (dist[u] + w < dist[v]) 
            return true; 

    return false;
}

int main() {
    fastio();
    tests() {
        cin >> V >> E;
        edges.clear();

        while (E--) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.emplace_back(u, v, w);
        }

        cout << BellmanFord() << endl;
    }
    return 0;
}
