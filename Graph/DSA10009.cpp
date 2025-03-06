#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

const int INF = 1e9;
int N, M;
int matrixAdj[101][101];

void Floyd() {
    for (int k = 1; k <= N; ++k)
        for (int u = 1; u <= N; ++u)
            for (int v = 1; v <= N; ++v)
                if (matrixAdj[u][v] > matrixAdj[u][k] + matrixAdj[k][v])
                    matrixAdj[u][v] = matrixAdj[u][k] + matrixAdj[k][v];
}

int main() {
    fastio();
    cin >> N >> M;

    for (int u = 1; u <= N; ++u)
        for (int v = 1; v <= N; ++v)
            matrixAdj[u][v] = (u == v ? 0 : INF);

    while (M--) {
        int u, v, w;
        cin >> u >> v >> w;
        matrixAdj[u][v] = matrixAdj[v][u] = w; 
    }

    Floyd();

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << (matrixAdj[u][v] == INF ? -1 : matrixAdj[u][v]) << endl;
    }
    return 0;
}
