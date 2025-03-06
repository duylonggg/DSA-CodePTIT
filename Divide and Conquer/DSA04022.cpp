#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int Try(int n, long long k) {
    long long mid = (1LL << (n - 1));

    if (k == mid) return n;
    if (k < mid) return Try(n - 1, k);
    return Try(n - 1, k - mid);
}

int main() {
    fastio()
    tests() {
        int N;
        long long K;
        cin >> N >> K;
        cout << char('@' + Try(N, K)) << endl;
    }
    return 0;
}