#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int const MOD = 1e9 + 7;

struct Matrix {
    vector<vector<int64_t>> mat;

    Matrix() {
        mat.assign(2, vector<int64_t>(2, 0));
    }

    Matrix operator*(Matrix other) {
        Matrix tmp;

        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                for (int k = 0; k < 2; ++k)
                    (tmp.mat[i][j] += this->mat[i][k] * other.mat[k][j]) %= MOD;

        return tmp;
    }

    Matrix binPow(int exp) {
        if (exp == 1) return *this;

        Matrix base = *this, res = binPow(exp >> 1);
        res = res * res;

        if (exp & 1) return res * base;
        return res;
    }
};

int fibo(int n) {
    Matrix F;
    F.mat = {{1, 1}, {1, 0}};

    Matrix Fibo = F.binPow(n - 1);
    return Fibo.mat[0][0];
}

int main() {
    fastio()
    tests() {
        int n;
        cin >> n;
        cout << fibo(n) << endl;
    }
    return 0;
}