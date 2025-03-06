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
                matrixAdj[u][v] = min(matrixAdj[u][v], matrixAdj[u][k] + matrixAdj[k][v]);
}

int main() {
    fastio();
    tests() {
        cin >> N >> M;

        for (int u = 1; u <= N; ++u)
            for (int v = 1; v <= N; ++v)
                matrixAdj[u][v] = (u == v ? 0 : INF);

        while (M--) {
            int u, v;
            cin >> u >> v;
            matrixAdj[u][v] = 1; 
        }

        Floyd();

        int totalCost = 0;
        for (int u = 1; u <= N; ++u) 
            for (int v = 1; v <= N; ++v)
                if (matrixAdj[u][v] != INF) 
                    totalCost += matrixAdj[u][v];

        cout << fixed << setprecision(2) << (totalCost / (double)(N * (N - 1))) << endl;
    }
    return 0;
}
