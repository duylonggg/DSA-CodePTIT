#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);

int N, M;
char land[101][101];

int dx[] = {1, 1, -1, -1, 0, 0, 1, -1};
int dy[] = {1, -1, 1, -1, 1, -1, 0, 0};

void DFS(int x, int y) {
    land[x][y] = '.';

    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M && land[nx][ny] == 'W')
            DFS(nx, ny);
    }
}

int main() {
    fastio();
    cin >> N >> M;

    for (int u = 0; u < N; ++u)
        for (int v = 0; v < M; ++v)
            cin >> land[u][v];

    int pond = 0;
    for (int u = 0; u < N; ++u)
        for (int v = 0; v < M; ++v)
            if (land[u][v] == 'W') 
                DFS(u, v), ++pond;

    cout << pond;
    return 0;
}
