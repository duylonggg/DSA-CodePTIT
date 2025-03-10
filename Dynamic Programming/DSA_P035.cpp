#include <bits/stdc++.h>
using namespace std;

const int64_t INF = 1e18;
const int MAXK = 15;

vector<int64_t> Dijkstra(int start, vector<vector<pair<int, int64_t>>>& graph, int N) {
    vector<int64_t> dist(N + 1, INF);
    dist[start] = 0;
    priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;

        for (auto [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> Points(K);
    for (int i = 0; i < K; ++i) cin >> Points[i];
    Points.insert(Points.begin(), 1);

    vector<vector<pair<int, int64_t>>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v;
        int64_t c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
    }

    vector<vector<int64_t>> dist(K + 1, vector<int64_t>(N + 1, INF));
    for (int i = 0; i <= K; i++) 
        dist[i] = Dijkstra(Points[i], graph, N);

    vector<vector<int64_t>> cost(K + 1, vector<int64_t>(K + 1, INF));
    for (int i = 0; i <= K; i++) {
        for (int j = 0; j <= K; j++) {
            if (dist[i][Points[j]] < INF) 
                cost[i][j] = dist[i][Points[j]];
        }
    }

    vector<vector<int64_t>> dp(1 << (K + 1), vector<int64_t>(K + 1, INF));
    dp[1][0] = 0;

    for (int mask = 1; mask < (1 << (K + 1)); mask++) {
        for (int i = 0; i <= K; i++) {
            if (!(mask & (1 << i))) continue;
            for (int j = 0; j <= K; j++) {
                if (i != j && (mask & (1 << j))) 
                    dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + cost[j][i]);
            }
        }
    }

    int64_t res = INF;
    for (int i = 1; i <= K; i++) {
        if (cost[i][0] < INF) 
            res = min(res, dp[(1 << (K + 1)) - 1][i] + cost[i][0]);
    }

    if (res >= INF) cout << -1 << endl;
    else cout << res << endl;

    return 0;
}
