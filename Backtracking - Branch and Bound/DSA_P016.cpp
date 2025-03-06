#include <bits/stdc++.h>
using namespace std;

int matrix[8][8], maxPoint;
vector<bool> col, diag, sec_diag;

void gen(int r, int point = 0) {
    if (r == 8) {  
        maxPoint = max(maxPoint, point);
        return;
    }

    for (int c = 0; c < 8; ++c) {  
        if (!col[c] and !diag[r + c] and !sec_diag[r - c + 7]) {
            col[c] = diag[r + c] = sec_diag[r - c + 7] = true;
            gen(r + 1, point + matrix[r][c]);  
            col[c] = diag[r + c] = sec_diag[r - c + 7] = false; 
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        maxPoint = 0;

        for (int r = 0; r < 8; ++r)  
            for (int c = 0; c < 8; ++c)
                cin >> matrix[r][c];

        col.assign(8, false);
        diag.assign(16, false);
        sec_diag.assign(16, false); 

        gen(0); 

        cout << "Test " << i << ": " << maxPoint << endl;
    }
    return 0;
}
