#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int N, M;
char matrix[505][505];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

string BFS(int x, int y) {
    queue<tuple<int, int, int>> q;
    q.push({x, y, 0});
    
    while (!q.empty()) {
        auto [cx, cy, turn] = q.front();
        q.pop();
        
        if (turn > 2) continue; 

        for (int i = 0; i < 4; ++i) {
            int nx = cx, ny = cy;

            while (true) {
                nx += dx[i];
                ny += dy[i];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M || matrix[nx][ny] == '*') 
                    break; 

                if (matrix[nx][ny] == 'T') 
                    return "YES";

                if (matrix[nx][ny] == '.') {
                    matrix[nx][ny] = '*'; 
                    q.push({nx, ny, turn + 1});
                }
            }
        }
    }
    return "NO"; 
}

int main() {
    fastio()
    tests() {
        cin >> N >> M;

        int sx, sy;
        for (int i = 0; i < N; ++i) { 
            for (int j = 0; j < M; ++j) {
                cin >> matrix[i][j];
                if (matrix[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
            }
        }

        cout << BFS(sx, sy) << endl;
    }
    return 0;
}
