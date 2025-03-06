#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int find_num(int n, long long k) {
    long long mid = (1LL << (n - 1));

    if (k == mid) return n;
    if (k < mid) return find_num(n - 1, k);
    return find_num(n - 1, k - mid);
}

int main() {
    fastio()
    tests() {
        int n;
        long long k;
        cin >> n >> k;
        cout << find_num(n, k) << endl;
    }
    return 0;
}