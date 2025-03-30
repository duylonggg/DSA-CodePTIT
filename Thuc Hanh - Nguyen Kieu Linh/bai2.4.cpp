#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100;
int n;
int adj[MAX_N][MAX_N];
bool visited[MAX_N];
vector<vector<int>> components;

void dfs(int u, vector<int>& component) {
    visited[u] = true;
    component.push_back(u + 1);
    for (int v = 0; v < n; ++v) {
        if (adj[u][v] && !visited[v]) {
            dfs(v, component);
        }
    }
}

int main() {
    // freopen("TK.INP", "r", stdin);
    // freopen("TK.OUT", "w", stdout);
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adj[i][j];
        }
    }
    
    memset(visited, false, sizeof(visited));
    
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, component);
            sort(component.begin(), component.end());
            components.push_back(component);
        }
    }
    
    cout << components.size() << "\n";
    for (const auto& comp : components) {
        for (int v : comp) {
            cout << v << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
