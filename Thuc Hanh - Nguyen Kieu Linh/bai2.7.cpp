#include <bits/stdc++.h>
using namespace std;

int nodes, edges;
vector<int> adj[1005];
vector<pair<int, int>> edgeList, bridges;
bool visited[1005];

void dfs(int u) {
	visited[u] = true;
	for (int v : adj[u]) {
		if (!visited[v]) dfs(v);
	}
}

void dfs2(int u, int s, int t) {
	visited[u] = true;
	for (int v : adj[u]) {
		if ((u == s && v == t) || (u == t && v == s)) continue;
		if (!visited[v]) dfs2(v, s, t);
	}
}

void findBridges() {
	int initialComponents = 0;
	for (int i = 1; i <= nodes; i++) {
		if (!visited[i]) {
			++initialComponents;
			dfs(i);
		}
	}

	for (pair<int, int> it : edgeList) {
		int x = it.first, y = it.second;
		memset(visited, 0, sizeof(visited));
		int newComponents = 0;
		for (int j = 1; j <= nodes; j++) {
			if (!visited[j]) {
				++newComponents;
				dfs2(j, x, y);
			}
		}
		if (newComponents > initialComponents) bridges.push_back({x, y});
	}

	cout << bridges.size() << endl;
	for (pair<int, int> x : bridges) cout << x.first << " " << x.second << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> nodes >> edges;
	while (edges--) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		edgeList.push_back({x, y});
	}

	findBridges();
	return 0;
}
