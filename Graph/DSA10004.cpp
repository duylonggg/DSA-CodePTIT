#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int V, E;
vector<int> adj[1001];

inline int checkEuler() {
    int odd_degree = 0;
    for (int i = 1; i <= V; ++i) 
        if (adj[i].size() % 2 != 0) odd_degree++;

    if (odd_degree == 0) return 2;  
    if (odd_degree == 2) return 1;  
    return 0;  
}


int main() {
    fastio()
    tests() {
        cin >> V >> E;

        for (int i = 1; i <= V; ++i) adj[i].clear();

        while (E--) {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << checkEuler() << endl;
    }
    return 0;
}