#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int S, T;

int BFS() {
    int vis[10001] = {};
    vis[S] = 1;
    queue<pair<int, int>> q;
    q.push({S, 0});

    while (!q.empty()) {
        auto [S, steps] = q.front();
        q.pop();

        if (S == T) return steps;

        if ((S << 1) < 10000 and !vis[(S << 1)]) {
            vis[(S << 1)] = 1;
            q.push({S << 1, steps + 1});
        }
        if (S - 1 > 0 and !vis[S - 1]) {
            vis[S - 1] = 1;
            q.push({S - 1, steps + 1});
        }
    }
}

int main() {
    fastio()
    tests() {
        cin >> S >> T;
        cout << BFS() << endl;
    }
    return 0;
}