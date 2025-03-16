#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

string ST, EN;
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {-2, -1, 1, 2, 2, -1, 1, -2};

int BFS(int x, int y) {
    int vis[8][8] = {};
    vis[x][y] = 1;
    queue<array<int, 3>> q;
    q.push({x, y, 0});

    while (!q.empty()) {
        auto [x, y, steps] = q.front();
        q.pop();

        if (x == EN[0] - 'a' and y == EN[1] - '1')
            return steps;

        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 and nx < 8 and ny >= 0 and ny < 8 and !vis[nx][ny]) {
                vis[nx][ny] = 1;
                q.push({nx, ny, steps + 1});
            }
        }
    }
}

int main() {
    fastio()
    tests() {
        cin >> ST >> EN;
        cout << BFS(ST[0] - 'a', ST[1] - '1') << endl;
    }
    return 0;
}