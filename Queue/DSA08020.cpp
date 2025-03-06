#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int S, T;

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 or n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 or n % (i + 2) == 0)
            return false;
    return true;
}

int BFS() {
    int vis[10000] = {};
    vis[S] = 1;
    queue<pair<int, int>> q;
    q.push({S, 0});

    while (!q.empty()) {
        auto [S, steps] = q.front();
        q.pop();

        if (S == T) return steps;

        string s = to_string(S);
        for (int i = 0; i <= 3; ++i) {
            for (char j = '0'; j <= '9'; ++j) {
                string tmp = s;
                tmp[i] = j;
                if (tmp[0] != '0') {
                    int p = stoi(tmp);
                    if (!vis[p] and is_prime(p)) {  
                        if (p == T) return steps + 1;
                        vis[p] = 1;
                        q.push({p, steps + 1});
                    }
                }
            }
        }
    }
    return -1;  
}

int main() {
    fastio()
    tests() {
        cin >> S >> T;
        cout << BFS() << endl;
    }
    return 0;
}
