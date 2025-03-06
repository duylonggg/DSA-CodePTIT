#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int N;

struct Edge {
    int u, v;
    double w;

    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

vector<Edge> edges;

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
    fastio()
    tests() {
        cin >> N;

        vector<pair<double, double>> points(N);
        edges.clear(); 

        for (int i = 0; i < N; ++i) 
            cin >> points[i].first >> points[i].second;

        for (int u = 0; u < N - 1; ++u) {
            for (int v = u + 1; v < N; ++v) {
                auto [x1, y1] = points[u];
                auto [x2, y2] = points[v];
                double w = hypot(x2 - x1, y2 - y1);
                
                edges.push_back({u, v, w});
            }
        }

        sort(edges.begin(), edges.end());

        DSU dsu(N);
        double totalCost = 0.0;
        int countEdges = 0;

        for (const auto& [u, v, w] : edges) {
            if (dsu.unite(u, v)) {
                totalCost += w;
                if (++countEdges == N - 1) break;
            }
        }

        cout << fixed << setprecision(6) << totalCost << endl;
    }
    return 0;
}
