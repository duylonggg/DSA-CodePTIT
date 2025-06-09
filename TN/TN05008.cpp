#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define test   int testcase; cin >> testcase; while(testcase--)

int enx, eny, n;
bool vis[2001][2001];
int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

int BFS(int stx, int sty) {
    if (vis[enx][eny]) return -1;

    vis[stx][sty] = true;
    queue<array<int, 3>> q;
    q.push({stx, sty, 0});

    while (!q.empty()) {
        auto [x, y, step] = q.front();
        q.pop();

        for (int i = 0; i <= 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx == enx and ny == eny) return step + 1;

            if (!vis[nx][ny] and nx >= 0 and nx <= 2000 and ny >= 0 and ny <= 2000) {
                vis[nx][ny] = true;
                q.push({nx, ny, step + 1});
            }
        }
    }

    return -1;
}

int main() {
    fastio;
    test {
        cin >> enx >> eny >> n;
        enx += 1000;
        eny += 1000;

        while (n--) {
            int u, v;
            cin >> u >> v;
            
            u += 1000;
            v += 1000;

            vis[u][v] = true;
        }

        cout << BFS(1000, 1000) << endl;
    }
    return 0;
}