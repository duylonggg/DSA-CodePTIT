#include <bits/stdc++.h>
using namespace std;

int main() {
    int V;
    cin >> V;

    vector<vector<int>> adj(V + 1, vector<int>(V + 1, 0));
    for (int i = 1; i <= V; ++i) {
        string str, u;
        getline(cin >> ws, str);
        stringstream ss(str);
        while (ss >> u) {
            adj[i][stoi(u)] = 1;
            adj[stoi(u)][i] = 1;
        }
    }

    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j) {
            if (adj[i][j]) {
                cout << i << ' ' << j << endl;;
                adj[j][i] = 0;
            }
        }
    }

    return 0;
}