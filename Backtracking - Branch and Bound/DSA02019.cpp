#include <bits/stdc++.h>
using namespace std;

#define tests() int test_cases; cin >> test_cases; while (test_cases--)

int N, M, maxLen;
vector<int> adj[21];
bool visitedEdges[21][21]; 

void DFS(int u, int len) {
    maxLen = max(maxLen, len);

    for (int v : adj[u]) {
        if (!visitedEdges[u][v]) { 
            visitedEdges[u][v] = visitedEdges[v][u] = true;

            DFS(v, len + 1);

            visitedEdges[u][v] = visitedEdges[v][u] = false;
        }
    }
}

int main() {
    tests() {
        cin >> N >> M;

        maxLen = 0;
        for (int i = 0; i < N; ++i) adj[i].clear();

        for (int i = 0; i < M; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < N; ++i) { 
            memset(visitedEdges, 0, sizeof(visitedEdges)); 
            DFS(i, 0);
        }

        cout << maxLen << endl;
    }
    return 0;
}
