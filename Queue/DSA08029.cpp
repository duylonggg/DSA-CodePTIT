#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

class Matrix {
private:
    int matrix[2][3];

public:
    Matrix() {}

    void input() {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 3; ++j)
                cin >> this->matrix[i][j];
    }

    Matrix rotateRight() {
        Matrix temp;
        temp.matrix[0][0] = this->matrix[0][0];
        temp.matrix[0][1] = this->matrix[1][1];
        temp.matrix[0][2] = this->matrix[0][1];
        
        temp.matrix[1][0] = this->matrix[1][0];
        temp.matrix[1][1] = this->matrix[1][2];
        temp.matrix[1][2] = this->matrix[0][2];
        
        return temp;
    }

    Matrix rotateLeft() {
        Matrix temp;
        temp.matrix[0][0] = this->matrix[1][0];
        temp.matrix[0][1] = this->matrix[0][0];
        temp.matrix[0][2] = this->matrix[0][2];

        temp.matrix[1][0] = this->matrix[1][1];
        temp.matrix[1][1] = this->matrix[0][1];
        temp.matrix[1][2] = this->matrix[1][2];

        return temp;
    }

    bool compare(const Matrix& other) const {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 3; ++j)
                if (this->matrix[i][j] != other.matrix[i][j])
                    return false;
        return true;
    }
};

Matrix ST, EN;

int BFS() {
    queue<pair<Matrix, int>> q;
    q.push({ST, 0});

    while (!q.empty()) {
        auto [current, steps] = q.front();
        q.pop();

        if (current.compare(EN)) return steps;

        q.push({current.rotateRight(), steps + 1});
        q.push({current.rotateLeft(), steps + 1});
    }

    return -1;
}

int main() {
    fastio()
    tests() {
        ST.input();
        EN.input();
        cout << BFS() << endl;
    }
    return 0;
}
