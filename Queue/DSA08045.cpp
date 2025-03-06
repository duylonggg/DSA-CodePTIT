#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int x[3010], y[3010], t[3010], xz, yz, gz;
char arr[6010][6010];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
stack<int> sx, sy;

int compress(int a[], int n) {
    memcpy(t, a, sizeof(int) * n);
    sort(t, t + n);
    int nz = unique(t, t + n) - t;
    for (int i = 0; i < n; ++i)
        a[i] = (lower_bound(t, t + nz, a[i]) - t) * 2;
    return nz * 2;
}

void put(int x, int y) {
    if (x < 0 || x >= xz || y < 0 || y >= yz || arr[x][y] == 'X')
        return;
    gz += (arr[x][y] == 'C');
    arr[x][y] = 'X';
    sx.push(x), sy.push(y);
}

void DFS(int startx, int starty) {
    put(startx, starty);
    while (!sx.empty()) {
        int x = sx.top(), y = sy.top();
        sx.pop(), sy.pop();
        for (int i = 0; i < 4; ++i)
            put(x + dx[i], y + dy[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int z = 0;
        x[z] = y[z] = -INF, ++z;
        x[z] = y[z] = INF, ++z;
        for (int i = 0; i < 2 * n; ++i)
            cin >> x[z] >> y[z], ++z;
        for (int i = 0; i < m; ++i)
            cin >> x[z] >> y[z], ++z;

        xz = compress(x, z);
        yz = compress(y, z);
        memset(arr, '.', sizeof(arr));

        for (int i = 0; i < n; ++i) {
            int a = i * 2 + 2, b = i * 2 + 3;
            int x1 = x[a], y1 = y[a], x2 = x[b], y2 = y[b];
            if (x1 == x2) {
                if (y1 > y2) swap(y1, y2);
                for (; y1 <= y2; ++y1) arr[x1][y1] = 'X';
            } else {
                if (x1 > x2) swap(x1, x2);
                for (; x1 <= x2; ++x1) arr[x1][y1] = 'X';
            }
        }

        for (int i = 0; i < m; ++i)
            arr[x[i + 2 * n + 2]][y[i + 2 * n + 2]] = 'C';

        int ans = 0;
        for (int i = 0; i < m; ++i) {
            gz = 0;
            DFS(x[i + 2 * n + 2], y[i + 2 * n + 2]);
            ans = max(ans, gz);
        }
        cout << ans << '\n';
    }
    return 0;
}
