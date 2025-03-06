#include <bits/stdc++.h>
using namespace std;

int n, k, cnt;
vector<int> numb, vis;
vector<vector<int>> v, ans;

void gen(int row = 0, int total = 0) {
    if (numb.size() == n) {
        if (total == k) {
            ans.push_back(numb);
            ++cnt;
        }
        return;
    }

    for (int i = row; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (total + v[i][j] > k) continue;
            if (!vis[j]) {
                numb.push_back(j + 1);
                vis[j] = 1;
                gen(i + 1, total + v[i][j]);
                vis[j] = 0;
                numb.pop_back();
            }
        }
    }
}

int main() {
    cin >> n >> k;
    v.resize(n, vector<int>(n)); 
    vis.resize(n);

    for (auto& row : v)
        for (auto& col : row)
            cin >> col;

    gen();
    
    cout << cnt << endl;
    for (auto vec : ans) {
        for (int num : vec)
            cout << num << ' ';
        cout << endl;
    }

    return 0;
}
