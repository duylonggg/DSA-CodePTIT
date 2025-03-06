#include <bits/stdc++.h>
using namespace std;

#define tests()     int16_t test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int16_t R, C, unvis;
int16_t matrix[501][501];

constexpr int16_t dx[] = {1, -1, 0, 0};
constexpr int16_t dy[] = {0, 0, 1, -1};

queue<pair<int16_t, int16_t>> q;

inline void BFS() {
    int16_t res = 0;
    
    while (!q.empty()) {
        size_t size = q.size();
        ++res;

        while (size--) {
            auto [x, y] = q.front();
            q.pop();

            for (int8_t i = 0; i < 4; ++i) {
                int16_t nx = x + dx[i], ny = y + dy[i];

                if (nx >= 0 && nx < R && ny >= 0 && ny < C && matrix[nx][ny]) {
                    --unvis;
                    matrix[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }
    }

    cout << (unvis ? -1 : res - 1) << endl;
}

int main() {
    fastio();
    tests() {
        cin >> R >> C;
        
        unvis = 0;
        while (!q.empty()) q.pop();

        for (int16_t r = 0; r < R; ++r) {
            for (int16_t c = 0; c < C; ++c) {
                cin >> matrix[r][c];
                if (matrix[r][c] == 1) ++unvis;
                else if (matrix[r][c] == 2) {
                    matrix[r][c] = 0;
                    q.push({r, c});
                }
            }
        }

        BFS();
    }
    return 0;
}
