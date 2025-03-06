#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

void check(vector<int>& A, vector<int>& B, vector<int>& C) {
    vector<int> res;
    size_t i = 0, j = 0, k = 0;

    while (i < A.size() and j < B.size() and k < C.size()) {
        if (A[i] == B[j] and B[j] == C[k]) {
            res.push_back(A[i]);
            ++i;
            ++j;
            ++k;
        }
        else if (A[i] < B[j]) ++i;
        else if (B[j] < C[k]) ++j;
        else ++k;
    }

    if (res.empty()) {
        cout << "NO";
        return;
    }

    for (auto num : res) cout << num << ' ';
}

int main() {
    fastio();
    tests() {
        int N, M, K;
        cin >> N >> M >> K;

        vector<int> A(N), B(M), C(K);

        for (int& a : A) cin >> a;
        for (int& b : B) cin >> b;
        for (int& c : C) cin >> c;

        check(A, B, C);

        cout << endl;
    }
    return 0;
}
