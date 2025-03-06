#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V;
    cin >> V;

    for (int u = 1; u <= V; ++u) {
        for (int v = 1; v <= V; ++v) {
            int x;
            cin >> x;
            if (x) cout << v << ' ';
        }
        cout << '\n'; 
    }

    return 0;
}
