#include <bits/stdc++.h>
using namespace std;

#define tests() int test_cases; cin >> test_cases; while (test_cases--)

int n;
int dx[] = {1, 0}; 
int dy[] = {0, 1};
vector<string> res;
string path;

bool check(int x, int y) {
    return x >= 0 and x < n and y >= 0 and y < n;
}

void Try(vector<vector<int>>& matrix, int x, int y) {
    if (!matrix[0][0] || !matrix[n - 1][n - 1]) return; 

    if (x == n - 1 and y == n - 1) {
        res.push_back(path);
        return;
    }

    for (int i = 0; i < 2; ++i) { 
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (check(nx, ny) and matrix[nx][ny]) { 
            path += (dx[i] ? 'D' : 'R'); 
            Try(matrix, nx, ny);
            path.pop_back(); 
        }
    }
}

int main() {
    tests() {
        cin >> n;
        res.clear();
        path = "";

        vector<vector<int>> matrix(n, vector<int>(n));

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                cin >> matrix[i][j];

        Try(matrix, 0, 0);

        if (res.empty()) cout << -1;
        else for (const string& path : res) cout << path << ' ';

        cout << endl;
    }
    return 0;
}
