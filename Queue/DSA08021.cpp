#include <bits/stdc++.h>
using namespace std;

#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int M, N;
int A[1001][1001];

int bfs() {
    queue<tuple<int, int, int>> q;  
    int vis[1001][1001] = {};

    q.push({0, 0, 0});
    vis[0][0] = 1;

    while (!q.empty()) {
        auto [x, y, steps] = q.front();
        q.pop();

        if (x == M - 1 and y == N - 1) return steps;

        int jump = A[x][y];

        if (y + jump < N and !vis[x][y + jump]) {
            vis[x][y + jump] = 1;
            q.push({x, y + jump, steps + 1});
        }
        if (x + jump < M and !vis[x + jump][y]) {
            vis[x + jump][y] = 1;
            q.push({x + jump, y, steps + 1});
        }
    }
    return -1;
}

int main() {
    fastio();
    int T;
    cin >> T;
    while (T--) {
        cin >> M >> N;

        for (int i = 0; i < M; ++i)
            for (int j = 0; j < N; ++j)
                cin >> A[i][j];

        cout << bfs() << endl;
    }
    return 0;
}