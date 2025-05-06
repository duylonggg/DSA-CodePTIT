#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
#define int64 long long

string encode(int x, int y) {
    return to_string(x) + "," + to_string(y);
}

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

int bfs(int xA, int yA, int xB, int yB, unordered_set<string>& valid) {
    queue<pair<pii, int>> q;
    unordered_set<string> visited;

    q.push({{xA, yA}, 0});
    visited.insert(encode(xA, yA));

    while (!q.empty()) {
        auto [pos, d] = q.front(); q.pop();
        int x = pos.first, y = pos.second;

        if (x == xB && y == yB) return d;

        for (int i = 0; i < 8; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            string code = encode(nx, ny);

            if (valid.count(code) && !visited.count(code)) {
                visited.insert(code);
                q.push({{nx, ny}, d + 1});
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int xA, yA, xB, yB, N;
        cin >> xA >> yA >> xB >> yB >> N;

        unordered_set<string> valid;

        for (int i = 0; i < N; ++i) {
            int x, y1, y2;
            cin >> x >> y1 >> y2;
            for (int y = y1; y <= y2; ++y) {
                valid.insert(encode(x, y));
            }
        }

        int result = bfs(xA, yA, xB, yB, valid);
        cout << result << '\n';
    }

    return 0;
}
