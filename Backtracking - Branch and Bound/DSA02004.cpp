#include <bits/stdc++.h>
using namespace std;

#define tests() int test_cases; cin >> test_cases; while (test_cases--)

int n;
vector<vector<int>> matrix;
vector<vector<bool>> visited;
bool can_move;

vector<pair<int, int>> directions = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
string direction_chars = "DLRU";

bool check(int x, int y) {
    return x >= 0 and x < n and y >= 0 and y < n and matrix[x][y] == 1 and !visited[x][y];
}

void Try(int x, int y, string &path) {
    if (x == n - 1 and y == n - 1) {
        cout << path << ' ';
        can_move = true;
        return;
    }

    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + directions[i].first;
        int ny = y + directions[i].second;

        if (check(nx, ny)) {
            path.push_back(direction_chars[i]);
            Try(nx, ny, path);
            path.pop_back();
        }
    }

    visited[x][y] = false;
}

int main() {
    tests() {
        cin >> n;
        matrix.assign(n, vector<int>(n));
        visited.assign(n, vector<bool>(n, false));
        can_move = false;

        for (auto& row : matrix)
            for (auto& cell : row)
                cin >> cell;

        if (matrix[0][0] == 1 and matrix[n - 1][n - 1] == 1) {
            string path;
            Try(0, 0, path);
        }

        if (!can_move) cout << -1;
        cout << '\n';
    }
    return 0;
}
