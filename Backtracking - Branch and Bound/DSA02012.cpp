#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int n, m, cnt;
vector<vector<int>> matrix;

int dx[] = {0, 1};
int dy[] = {1, 0};

bool check(int x, int y) {
    return x >= 0 and x < m and y >= 0 and y < n;
}

void gen(int x, int y) {
    if (x == m - 1 and y == n - 1) {
        ++cnt;
        return;
    }

    for (int i = 0; i < 2; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx == m - 1 and ny == n - 1) {
            ++cnt;
            return;
        }

        if (check(nx, ny)) 
            gen(nx, ny);
    }
}

int main() {
    tests() {
        cin >> m >> n;
        cnt = 0;

        matrix.assign(m, vector<int>(n));
        for (auto& row : matrix)
            for (auto& cell : row)
                cin >> cell;

        gen(0, 0);

        cout << cnt << endl;
    }
    return 0;
}