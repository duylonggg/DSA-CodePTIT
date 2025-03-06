#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

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

        if (u == v) return true;

        if (siz[u] < siz[v]) swap(u, v);
        par[v] = u;
        siz[u] += siz[v];
        return false;
    }
};

int main() {
    fastio()
    tests() {
        int V, E;
        cin >> V >> E;

        DSU dsu(V);

        string has_cycle = "NO";
        while (E--) {
            int u, v;
            cin >> u >> v;

            if (dsu.unite(u, v)) has_cycle = "YES"; 
        }

        cout << has_cycle << endl;
    }
    return 0;
}