#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w; 
    }
};

class DSU {
private:
    vector<int> par, siz;

public:
    DSU(int V) {
        par.resize(V + 1);
        siz.assign(V + 1, 1);
        for (int u = 1; u <= V; ++u) par[u] = u;
    }

    int find_par(int u) {
        if (u == par[u])
            return u;
        return par[u] = find_par(par[u]); 
    }

    bool unite(int u, int v) {
        u = find_par(u);
        v = find_par(v);

        if (u != v) {
            if (siz[u] < siz[v]) swap(u, v);

            par[v] = u;
            siz[u] += siz[v];

            return true;
        }
        return false;
    }
};

int main() {
    fastio();
    tests() {
        int V, E;
        cin >> V >> E;

        vector<Edge> edges;
        while (E--) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
        }

        sort(edges.begin(), edges.end()); 

        DSU dsu(V);
        int totalCost = 0, countEdges = 0;

        for (const auto& [u, v, w] : edges) {
            if (dsu.unite(u, v)) {
                totalCost += w;
                ++countEdges;
                if (countEdges == V - 1) break; 
            }
        }

        cout << totalCost << endl;
    }
    return 0;
}
