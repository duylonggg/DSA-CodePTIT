#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

const int INF = 1e9;
int N, M;
int A[501][501];
int dist[501][501];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void Dijkstra() {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            dist[i][j] = INF;
    
    dist[1][1] = A[1][1];
    pq.push({A[1][1], 1, 1}); 

    while (!pq.empty()) {
        auto [cost, x, y] = pq.top();
        pq.pop();

        if (x == N && y == M) return;

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            
            if (nx >= 1 && nx <= N && ny >= 1 && ny <= M) {
                int newCost = cost + A[nx][ny];

                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push({newCost, nx, ny});
                }
            }
        }
    }
}

int main() {
    fastio();
    tests() {
        cin >> N >> M;

        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= M; ++j)
                cin >> A[i][j];

        Dijkstra();

        cout << dist[N][M] << endl;
    }
    return 0;
}
