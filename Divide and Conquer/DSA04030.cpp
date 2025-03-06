#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")

#define endl            '\n'
#define ll              long long
#define ull             unsigned long long

#define faster()        ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define tests()         int test_cases; cin >> test_cases; while (test_cases--)

const int64_t MOD = 1e15 + 7;

int64_t binMul(int64_t base, int64_t exp) {
    int64_t res = 0;
    while (exp) {
        if (exp & 1) res = (res + base) % MOD;
        base = (base + base) % MOD;
        exp >>= 1;
    }
    return res;
}

class Matrix {
private:
    vector<vector<int64_t>> mat;

public:
    Matrix() {
        mat.assign(4, vector<int64_t>(4, 0));
    }

    Matrix(vector<vector<int64_t>> values) {
        mat = values;
    }

    friend ostream& operator<<(ostream& os, const Matrix& other) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j)
                os << other.mat[i][j] << ' ';
            os << endl;
        }
        return os;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix res;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j)
                for (int k = 0; k < 4; ++k)
                    res.mat[i][j] = (res.mat[i][j] + binMul(this->mat[i][k], other.mat[k][j])) % MOD;

        return res;
    }

    Matrix binPow(int exp) {
        if (exp == 1) return *this;

        Matrix res = binPow(exp >> 1);
        res = res * res;

        if (exp & 1) res = res * (*this);
        return res;
    }

    int64_t sumTribonacci() {
        int base[] = {3, 2, 1, 6};
        int64_t total = 0;
        for (int i = 0; i < 4; ++i)
            total = (total + binMul(this->mat[3][i], base[i])) % MOD;
        return total;
    }
};

int main() {
    faster();
    tests() {
        int N;
        cin >> N;

        if (N <= 3) {
            cout << (1LL * N * (N + 1) / 2) % MOD << endl; 
            continue;
        }

        Matrix A({
            {1, 1, 1, 0}, 
            {1, 0, 0, 0}, 
            {0, 1, 0, 0}, 
            {1, 1, 1, 1} 
        });

        Matrix res = A.binPow(N - 3);
        cout << res.sumTribonacci() << endl;
    }
    return 0;
}