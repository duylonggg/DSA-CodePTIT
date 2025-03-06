#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int V, E;

class DSU {
private: 
    vector<int> par, siz;

public:
    DSU(int V) {
        par.resize(V + 1);
        siz.assign(V + 1, 1);
        for (int i = 1; i <= V; ++i) par[i] = i;
    }

    int find_par(int u) {
        if (u == par[u])
            return u;
        return par[u] = find_par(par[u]);
    }

    void unite(int u, int v) {
        u = find_par(u);
        v = find_par(v);
        
        if (u != v) {
            if (siz[u] < siz[v]) swap(u, v);

            par[v] = u;
            siz[u] += siz[v];
        }
    }

    bool same_set(int u, int v) {
        return find_par(u) == find_par(v);
    }
};

int main() {
    fastio()
    tests() {
        cin >> V >> E;

        DSU dsu(V);

        while (E--) {
            int u, v;
            cin >> u >> v;

            dsu.unite(u, v);
        }

        int countCC = 0;
        for (int i = 1; i <= V; ++i)
            countCC += (i == dsu.find_par(i));
        cout << countCC << endl;
    }
    return 0;
}