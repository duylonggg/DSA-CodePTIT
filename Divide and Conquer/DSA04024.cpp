#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

const int MOD = 1e9 + 7;

class Matrix {
private:
    vector<vector<long long>> matrix;
    int n;

public:
    Matrix() {}

    Matrix(int size) : n(size) {
        matrix.assign(n, vector<long long>(n, 0));
    }

    friend istream& operator >> (istream& is, Matrix& mat) {
        for (int i = 0; i < mat.n; ++i)
            for (int j = 0; j < mat.n; ++j) 
                is >> mat.matrix[i][j];
        return is;
    }

    friend ostream& operator << (ostream& os, Matrix& mat) {
        long long total = 0;
        for (int i = 0; i < mat.n; ++i)
            total += mat.matrix[i][mat.n - 1] % MOD;
        os << total % MOD << endl;
        return os;
    }

    friend Matrix operator * (const Matrix& a, const Matrix& b) {
        int n = a.n;
        Matrix tmp(n);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    tmp.matrix[i][j] = (tmp.matrix[i][j] + 1LL * a.matrix[i][k] * b.matrix[k][j]) % MOD;

        return tmp;
    }

    Matrix binPow(int k) {
        if (k == 1) return *this;

        Matrix base = *this, tmp = binPow(k >> 1);
        tmp = tmp * tmp;

        if (k & 1) return tmp * base;
        return tmp;
    }
};

int main() {
    fastio();
    tests() {
        int n, k;
        cin >> n >> k;

        Matrix mat(n);
        cin >> mat;

        Matrix res = mat.binPow(k);
        cout << res;
    }
    return 0;
}
