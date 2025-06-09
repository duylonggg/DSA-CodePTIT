#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 20000 + 5;

int N, M;
vector<int> adj[MAXN];

int disc[MAXN], low[MAXN], parentArr[MAXN];
bool visited[MAXN];

int pieces[MAXN], child_cut_count[MAXN], root_children[MAXN];
int timer_dfs;
int orig_cc; 

int currentRoot;

void dfs_art(int u) {
    visited[u] = true;
    disc[u] = low[u] = ++timer_dfs;

    for (int v : adj[u]) {
        if (!visited[v]) {
            parentArr[v] = u;
            if (u == currentRoot) {
                root_children[u]++;
            }

            dfs_art(v);

            low[u] = min(low[u], low[v]);

            if (u != currentRoot && low[v] >= disc[u]) {
                child_cut_count[u]++;
            }
        }
        else if (v != parentArr[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (u != currentRoot) {
        pieces[u] = child_cut_count[u] + 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        adj[i].clear();
        visited[i] = false;
        parentArr[i] = -1;
        child_cut_count[i] = 0;
        root_children[i] = 0;
        pieces[i] = 0;
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    timer_dfs = 0;
    orig_cc = 0;

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            orig_cc++;
            currentRoot = i;
            root_children[i] = 0;
            parentArr[i] = -1;
            dfs_art(i);
            pieces[i] = root_children[i];
        }
    }

    for (int u = 1; u <= N; u++) {
        int ans = orig_cc + (pieces[u] - 1);
        cout << ans << "\n";
    }

    return 0;
}
