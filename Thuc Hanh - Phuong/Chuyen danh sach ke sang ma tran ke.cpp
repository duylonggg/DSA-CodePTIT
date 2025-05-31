#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define test   int testcase; cin >> testcase; while(testcase--)

int main() {
    fastio;
    int V;
    cin >> V;
    
    int matrix[V + 1][V + 1] = {};

    for (int u = 1; u <= V; ++u) {
        string str;

        getline(cin >> ws, str);
        stringstream ss(str);
        string word;
        while (ss >> word) {
            matrix[u][stoi(word)] = matrix[stoi(word)][u] = 1;
        }
    }

    for (int i = 1; i <= V; ++i) {
        for (int j = 1; j <= V; ++j)
            cout << matrix[i][j] << ' ';
        cout << endl;
    }
    return 0;
}