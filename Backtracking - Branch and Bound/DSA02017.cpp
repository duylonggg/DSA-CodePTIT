#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int matrix[8][8], maxPoint;
vector<bool> col(8), diag(16), sec_diag(16);

void Try(int r, int point = 0) {
    if (r == 8) {
        maxPoint = max(maxPoint, point);
        return;
    }

    for (int c = 0; c < 8; ++c) {
        if (!col[c] and !diag[r + c] and !sec_diag[r - c + 7]) {
            col[c] = diag[r + c] = sec_diag[r - c + 7] = true;
            Try(r + 1, point + matrix[r][c]);
            col[c] = diag[r + c] = sec_diag[r - c + 7] = false;
        }
    }
}

int main() {
    tests() {
        for (int r = 0; r < 8; ++r)
            for (int c = 0; c < 8; ++c)
                cin >> matrix[r][c];

        maxPoint = 0;
        col.clear();
        diag.clear();
        sec_diag.clear();

        Try(0);

        cout << maxPoint << endl;
    }
    return 0;
}