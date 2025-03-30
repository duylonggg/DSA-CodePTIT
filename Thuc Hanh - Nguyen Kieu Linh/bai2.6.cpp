#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> low, num;
vector<bool> joint;
int n, timer, cnt;

void DFS(int u, int parent) {
    int children = 0;
    low[u] = num[u] = ++timer;
    for (int v : adj[u]) {
        if (v == parent) continue;
        if (num[v]) {
            low[u] = min(low[u], num[v]);
        } else {
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= num[u] && parent != -1) {
                ++cnt;
                joint[u] = true;
            }
            children++;
        }
    }
    if (parent == -1 && children > 1) {
        joint[u] = true;
    }
}

void findJoint() {
    low.assign(n + 1, 0);
    num.assign(n + 1, 0);
    joint.assign(n + 1, false);
    timer = 0;
    for (int i = 1; i <= n; ++i) {
        if (!num[i]) {
            DFS(i, -1);
        }
    }
    cout << cnt << '\n';
    for (int i = 1; i <= n; ++i) {
        if (joint[i]) cout << i << " ";
    }
    cout << endl;
}

int main() {
    cin >> n;
    adj.assign(n + 1, vector<int>());
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin >> ws, line);
        stringstream ss(line);
        int num;
        int flag = 0;
        while (ss >> num) {
            if (!flag) {
                flag = 1;
                continue;
            }
            adj[i + 1].push_back(num);
        }
    }
    findJoint();
    return 0;
}