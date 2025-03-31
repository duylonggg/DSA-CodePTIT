#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1000, MAX_M = 1000;
int N, M, K;
string S;

unordered_map<char, pair<int, int>> directions = {
    {'D', {1, 0}}, {'U', {-1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}
};

int count_valid_hole_positions() {
    int valid_hole_positions = 0;

    for (int hx = 0; hx < N; ++hx) {
        for (int hy = 0; hy < M; ++hy) {
            set<pair<int, int>> kangaroos;

            for (int x = 0; x < N; ++x) {
                for (int y = 0; y < M; ++y) {
                    if (x != hx || y != hy) {
                        kangaroos.insert({x, y});
                    }
                }
            }

            for (char move : S) {
                auto [dx, dy] = directions[move];
                set<pair<int, int>> new_positions;

                for (auto [x, y] : kangaroos) {
                    int nx = x + dx, ny = y + dy;

                    if (nx == hx && ny == hy) continue; 
                    if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

                    new_positions.insert({nx, ny});
                }

                kangaroos = new_positions;
            }

            if ((int)kangaroos.size() == K) {
                ++valid_hole_positions;
            }
        }
    }

    return valid_hole_positions;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> M >> K >> S;
        cout << count_valid_hole_positions() << "\n";
    }

    return 0;
}
