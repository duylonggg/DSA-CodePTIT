#include <bits/stdc++.h>
using namespace std;

int matrixAdj[1001][1001];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        string str;
        getline(cin >> ws, str);   
        stringstream ss(str);
        int num;
        while (ss >> num) matrixAdj[i][num] = matrixAdj[num][i] = 1;
    }

    for (int u = 1; u <= n; ++u) {
        for (int v = 1; v <= n; ++v)
            cout << matrixAdj[u][v] << ' ';
        cout << endl;
    }

    return 0;
}