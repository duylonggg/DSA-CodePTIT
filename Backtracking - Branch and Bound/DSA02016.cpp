#include <bits/stdc++.h>
using namespace std;

#define tests() int test_cases; cin >> test_cases; while (test_cases--)

int n, cnt;
vector<bool> col, diag, sec_diag;

void Try(int r) {
    if (r == n) { 
        ++cnt;  
        return;
    }

    for (int c = 0; c < n; ++c) {
        if (!col[c] and !diag[r + c] and !sec_diag[r - c + n - 1]) {
            col[c] = diag[r + c] = sec_diag[r - c + n - 1] = true;
            Try(r + 1);
            col[c] = diag[r + c] = sec_diag[r - c + n - 1] = false;
        }
    }
}

int main() {
    tests() {
        cin >> n;
        cnt = 0;

        col.assign(n, false);
        diag.assign(n << 1, false);
        sec_diag.assign(n << 1, false);

        Try(0); 
        cout << cnt << endl;
    }
    return 0;
}
