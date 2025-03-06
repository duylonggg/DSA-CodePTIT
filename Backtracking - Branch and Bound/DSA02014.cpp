#include <bits/stdc++.h>
using namespace std;

#define tests() int test_cases; cin >> test_cases; while (test_cases--)

int m, n, k;
char matrix[4][4];
bool vis[4][4];
unordered_set<string> st, prefixSet;
vector<string> ans;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void Try(int x, int y, string s) {
    s += matrix[x][y];
    vis[x][y] = 1;

    if (st.count(s)) ans.push_back(s);

    if (!prefixSet.count(s)) {
        vis[x][y] = 0;
        return;
    }

    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 1 && nx <= m && ny >= 1 && ny <= n && !vis[nx][ny]) 
            Try(nx, ny, s);
    }

    vis[x][y] = 0;
}

int main() {
    tests() {
        cin >> k >> m >> n;
        st.clear();
        prefixSet.clear();
        ans.clear();

        for (int i = 0; i < k; ++i) {
            string str;
            cin >> str;
            st.insert(str);

            for (size_t j = 1; j <= str.size(); ++j) 
                prefixSet.insert(str.substr(0, j));
        }

        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
                cin >> matrix[i][j];

        memset(vis, 0, sizeof(vis));

        for (int i = 1; i <= m; ++i) 
            for (int j = 1; j <= n; ++j)
                Try(i, j, "");

        if (ans.empty()) cout << -1;
        else for (const string &str : ans) cout << str << ' ';
        cout << endl;
    }
    return 0;
}