#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define ll          long long
#define pb          push_back

int N, K, M;
set<pair<pair<int, int>, pair<int, int>>> forbidden;
vector<pair<int, int>> sheeps;
bool vis[1005][1005];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int cnt;

bool canMove(int x, int y) {
    return x >= 1 and x <= N and y >= 1 and y <= N;
}

void DFS(pair<int, int> u) {
    auto [x, y] = u;
    vis[x][y] = true;

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (canMove(nx, ny) and !vis[nx][ny] and !forbidden.count({{x, y}, {nx, ny}}))
            DFS({nx, ny});
    }
}

int main() {
    cin >> N >> K >> M;

    while (M--) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;

        forbidden.insert({{u, v}, {x, y}});
        forbidden.insert({{x, y}, {u, v}});
    }

    while (K--) {
        int u, v;
        cin >> u >> v;

        sheeps.pb({u, v});
    }

    for (auto sheep : sheeps) {
        memset(vis, false, sizeof(vis));

        DFS(sheep);

        for (auto [x, y] : sheeps)
            if (!vis[x][y])
                ++cnt;
    }

    cout << (cnt >> 1);
    return 0;
}