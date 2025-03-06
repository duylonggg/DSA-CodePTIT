#include <bits/stdc++.h>
using namespace std;

#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

bool check(int& k, vector<int>& A) {
    for (int a : A) 
        if (a / k == a / (k + 1))
            return false;
    return true;
}

int main() {
    fastio();
    int N, minNum = INT_MAX, res = 0;
    cin >> N;
    
    vector<int> A(N);
    for (int &i : A) {
        cin >> i;
        minNum = min(minNum, i);
    }

    vector<int> B(N);
    for (int k = minNum; ~k; --k) { 
        if (check(k, A)) {
            for (int i = 0; i < N; ++i) 
                B[i] = A[i] / (k + 1) + 1;
            break;
        }
    }
    
    res = accumulate(B.begin(), B.end(), 0);
    cout << res;
    return 0;
}
