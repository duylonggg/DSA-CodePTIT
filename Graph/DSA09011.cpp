#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int N, M;
int matrix[505][505];

int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

void DFS(int x, int y) {
    matrix[x][y] = 0;

    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 and nx < N and ny >= 0 and ny < M and matrix[nx][ny])
            DFS(nx, ny);
    }
}

int main() {
    fastio()
    tests() {
        cin >> N >> M;
        int island = 0;

        for (int i = 0; i < N; ++i) 
            for (int j = 0; j < M; ++j)
                cin >> matrix[i][j];
            
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (matrix[i][j]) {
                    ++island;
                    DFS(i, j);
                }
            
        cout << island << endl;
    }
    return 0;
}