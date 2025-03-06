#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int N, x, y, u, v;
char matrix[101][101];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int BFS() {
    queue<tuple<int, int, int>> q;  
    q.push({x, y, 0}); 
    matrix[x][y] = 'X';

    while (!q.empty()) {
        auto [x, y, steps] = q.front();
        q.pop();

        if (x == u and y == v) return steps;

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            while (nx >= 0 and nx < N and matrix[nx][y] == '.') {
                if (nx == u and y == v) return steps + 1;
                if (matrix[nx][y] == '.') { 
                    matrix[nx][y] = 'X'; 
                    q.push({nx, y, steps + 1});
                }
                nx += dx[i]; 
            }

            while (ny >= 0 and ny < N and matrix[x][ny] == '.') {
                if (x == u and ny == v) return steps + 1;
                if (matrix[x][ny] == '.') { 
                    matrix[x][ny] = 'X'; 
                    q.push({x, ny, steps + 1});
                }
                ny += dy[i]; 
            }
        }
    }

    return -1;  
}

int main() {
    fastio()
    tests() {
        cin >> N;

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                cin >> matrix[i][j];

        cin >> x >> y >> u >> v;

        cout << BFS() << endl;
    }
    return 0;
}
