#include <bits/stdc++.h>
using namespace std;

#define tests()     int16_t test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int16_t A, B, C;
char rec[31][31][31];

constexpr int dx[] = {-1, 1, 0, 0, 0, 0};
constexpr int dy[] = {0, 0, -1, 1, 0, 0};
constexpr int dz[] = {0, 0, 0, 0, -1, 1};

inline bool is_valid(int8_t x, int8_t y, int8_t z) {
    return (z >= 0 and z < A) and (x >= 0 and x < B) and (y >= 0 and y < C);
}

inline int16_t BFS(int8_t z, int8_t x, int8_t y) {
    queue<array<int8_t, 4>> q;
    q.push({z, x, y, 0});
    rec[z][x][y] = '#';

    while (!q.empty()) {
        auto [z, x, y, steps] = q.front();
        q.pop();

        for (int i = 0; i < 6; ++i) {
            int8_t nz = z + dz[i];
            int8_t nx = x + dx[i];
            int8_t ny = y + dy[i];

            if (is_valid(nx, ny, nz)) {
                if (rec[nz][nx][ny] == 'E') return steps + 1;
                if (rec[nz][nx][ny] == '.') {
                    rec[nz][nx][ny] = '#';
                    q.push({nz, nx, ny, steps + 1});
                }
            }            
        }
    }

    return -1;
}

int main() {
    fastio()
    tests() {
        cin >> A >> B >> C;
        int8_t x, y, z;

        for (int8_t a = 0; a < A; ++a) 
            for (int8_t b = 0; b < B; ++b) 
                for (int8_t c = 0; c < C; ++c) {
                    cin >> rec[a][b][c];
                    if (rec[a][b][c] == 'S') 
                        z = a, x = b, y = c;
                }

        cout << BFS(z, x, y) << endl;
    }
    return 0;
}