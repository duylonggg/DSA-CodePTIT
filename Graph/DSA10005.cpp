#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int V, E;
vector<int> indegree, outdegree;

bool checkEulerCycle() {
    for (int i = 1; i <= V; ++i)
        if (indegree[i] != outdegree[i])
            return false;
    return true;
}

int main() {
    fastio()
    tests() {
        cin >> V >> E;

        indegree.assign(V + 1, 0);
        outdegree.assign(V + 1, 0);

        while (E--) {
            int u, v;
            cin >> u >> v;

            ++outdegree[u];
            ++indegree[v];
        }

        cout << checkEulerCycle() << endl;
    }
    return 0;
}