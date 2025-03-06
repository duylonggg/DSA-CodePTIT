#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int N, M;
        cin >> N >> M;

        int matrix[501][501];
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                cin >> matrix[i][j];

        for (int i = 1; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (matrix[i][j])
                    matrix[i][j] += matrix[i - 1][j];
        
        int res = 0;
        for (int i = 0; i < N; ++i) {
            stack<int> stk;
            int x[M], y[M];

            stk.push(-1);
            for (int j = 0; j < M; ++j) {
                while (stk.top() != -1 && matrix[i][stk.top()] >= matrix[i][j])
                    stk.pop();
                x[j] = stk.top() + 1;
                stk.push(j);
            }

            while (!stk.empty()) stk.pop(); 
            stk.push(M);
            for (int j = M - 1; j >= 0; --j) {
                while (stk.top() != M && matrix[i][stk.top()] >= matrix[i][j])
                    stk.pop();
                y[j] = stk.top() - 1;
                stk.push(j);
            }
            
            for (int j = 0; j < M; ++j)
                res = max(res, (y[j] - x[j] + 1) * matrix[i][j]);
        }

        cout << res << endl;
    }
    return 0;
}
