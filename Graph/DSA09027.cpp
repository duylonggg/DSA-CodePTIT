#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

class DSU {
private:
    vector<int> par, siz;
public:
    DSU(int n) {
        par.resize(n + 1);
        siz.assign(n + 1, 1);
        for (int i = 1; i <= n; ++i) par[i] = i;
    }

    int find_par(int u) {
        if (par[u] != u) 
            par[u] = find_par(par[u]);
        return par[u];
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    tests() {
        int V, E;
        cin >> V >> E;

        DSU dsu(V);

        while (E--) {
            int u, v;
            cin >> u >> v;
            dsu.unite(u, v);
        }

        int q;
        cin >> q;
        while (q--) {
            int u, v;
            cin >> u >> v;
            cout << (dsu.same_set(u, v) ? "YES" : "NO") << '\n';
        }
    }
    return 0;
}
