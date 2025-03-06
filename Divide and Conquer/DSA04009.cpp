#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

const int MOD = 1e9 + 7;

struct Matrix {
    vector<vector<int64_t>> mat;
    int n;

    Matrix(int n) : n(n) {
        mat.assign(n, vector<int64_t>(n, 0));
    }

    friend istream& operator >> (istream& is, Matrix& A) {
        for (int i = 0; i < A.n; ++i)
            for (int j = 0; j < A.n; ++j) 
                is >> A.mat[i][j];
        return is;
    }

    friend ostream& operator << (ostream& os, Matrix A) {
        for (int i = 0; i < A.n; ++i) {
            for (int j = 0; j < A.n; ++j)
                os << A.mat[i][j] << ' ';
            os << endl;
        }
        return os;
    }

    Matrix operator * (const Matrix& other) {
        int n = other.n;
        Matrix res(n);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    (res.mat[i][j] += this->mat[i][k] * other.mat[k][j]) %= MOD;

        return res;
    }

    Matrix binPow(int exp) {
        if (exp == 1) return *this;

        Matrix base = *this, res = binPow(exp >> 1);
        res = res * res;

        if (exp & 1) return res * base;
        return res;
    }
};

int main() {
    fastio()
    tests() {
        int n, k;
        cin >> n >> k;

        Matrix A(n);
        cin >> A;
        cout << A.binPow(k);
    }
    return 0;
}