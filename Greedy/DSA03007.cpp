#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int n;
        cin >> n;
        
        vector<long long> A(n), B(n);
        for (long long& a : A) cin >> a;
        for (long long& b : B) cin >> b;
        sort(A.begin(), A.end());
        sort(B.rbegin(), B.rend());

        long long total = 0;
        for (int i = 0; i < n; ++i)
            total += A[i] * B[i];

        cout << total << endl;
    }
    return 0;
}