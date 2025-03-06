#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

long long fibo[100];

void fibonacci() {
    fibo[0] = 0LL;
    fibo[1] = 1LL;
    for (int i = 2; i < 100; ++i)
        fibo[i] = fibo[i - 1] + fibo[i - 2];
}

char find_fibo(int n, long long k) {
    if (n == 1) return 'A';
    if (n == 2) return 'B';

    if (k <= fibo[n - 2]) return find_fibo(n - 2, k);
    return find_fibo(n - 1, k - fibo[n - 2]);
}

int main() {
    fastio()
    fibonacci();
    tests() {
        int n;
        long long k;
        cin >> n >> k;
        cout << find_fibo(n, k) << endl;
    }
    return 0;
}