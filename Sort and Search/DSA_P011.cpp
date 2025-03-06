#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;
int N, M;
char maze[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int dx[] = {-1, 1, 0, 0}; 
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && maze[nx][ny] == '#' && !visited[nx][ny]) {
            dfs(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> maze[i];
    }

    int count = 0; 
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (maze[i][j] == '#' && !visited[i][j]) {
                ++count;
                dfs(i, j);
            }
        }
    }

    cout << count << '\n';
    return 0;
}
