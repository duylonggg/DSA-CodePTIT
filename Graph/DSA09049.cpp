#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

vector<int> adj[200005];
long long val[200005], sum[200005];

void clear() {
    for (int i = 0; i < 200005; ++i)
        adj[i].clear();
    fill(val, val + 200005, 1LL); 
    fill(sum, sum + 200005, 0LL);
}

void DFS(int u) {
    for (int v : adj[u]) {
        DFS(v);
        sum[u] += sum[v] + 1;  
        val[u] += val[v];
    }
    val[u] += sum[u];
}

int main() {
    faster();
    clear();

    int n;
    cin >> n;
    
    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }

    DFS(1);
    for (int i = 1; i <= n; ++i)
        cout << val[i] << ' ';

    return 0;
}
