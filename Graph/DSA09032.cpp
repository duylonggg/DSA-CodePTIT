#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

class DSU {
private:
    vector<int> par, siz;

public: 
    DSU(int N) {
        par.resize(N + 1); 
        siz.assign(N + 1, 1);
        for (int u = 1; u <= N; ++u) par[u] = u;
    }

    int find_par(int u) {
        if (u == par[u]) return u;
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

    int getMaxSize() {
        int maxSize = 0;
        for (int i = 1; i < par.size(); i++) {
            if (par[i] == i) {
                maxSize = max(maxSize, siz[i]);
            }
        }
        return maxSize;
    }
};

int main() {
    fastio()
    tests() {
        int N, M;
        cin >> N >> M;

        DSU dsu(N);

        while (M--) {
            int u, v;
            cin >> u >> v;

            dsu.unite(u, v);
        }

        cout << dsu.getMaxSize() << endl;
    }
    return 0;
}
