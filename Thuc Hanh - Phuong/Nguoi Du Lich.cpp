#include <bits/stdc++.h>
using namespace std;

int n, minCost = INT_MAX;
vector<vector<int>> matrix;
bitset<15> vis;

void Try(int prev, int cost, int cnt) {
    if (cnt == n) {
        cost += matrix[prev][0]; 
        if (cost < minCost) minCost = cost; 
        return;
    }

    for (int cur = 0; cur < n; ++cur) {
        if (vis[cur]) continue;
        if (cost + matrix[prev][cur] >= minCost) continue;
        vis[cur] = 1;
        Try(cur, cost + matrix[prev][cur], cnt + 1);
        vis[cur] = 0;
    }
}

int main() {
    cin >> n;
    
    matrix.resize(n, vector<int>(n));
    for (auto& row : matrix)
        for (auto& cell : row)
            cin >> cell;
    
    vis[0] = 1;
    Try(0, 0, 1);

    cout << minCost;

    return 0;
}
