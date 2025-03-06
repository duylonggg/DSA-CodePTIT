#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;

        vector<int> A(n1), B(n2), C(n3);
        for (int& a : A) cin >> a;
        for (int& b : B) cin >> b;
        for (int& c : C) cin >> c;

        queue<int> res;
        int i = 0, j = 0, k = 0;
        while (i < n1 and j < n2 and k < n3) {
            if (A[i] == B[j] and A[i] == C[k]) {
                res.push(A[i]);
                ++i, ++j, ++k;
            } else if (A[i] < B[j]) {
                ++i;
            } else if (B[j] < C[k]) {
                ++j;
            } else {
                ++k;
            }
        }

        if (res.empty()) {
            cout << -1 << endl;
            continue;
        }
        while (!res.empty()) {
            cout << res.front() << ' ';
            res.pop();
        }
        cout << endl;
    }
    return 0;
}