#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int64_t fibo[100];
void Fibonacci() {
    fibo[0] = 0LL;
    fibo[1] = 1LL;
    for (int i = 2; i < 100; ++i)
        fibo[i] = fibo[i - 1] + fibo[i - 2];
}

char findFibonacci(int64_t N, int64_t i) {
    if (N == 1) return 'A';
    if (N == 2) return 'B';

    if (i <= fibo[N - 2]) return findFibonacci(N - 2, i);
    return findFibonacci(N - 1, i - fibo[N - 2]);
}

int main() {
    fastio()
    Fibonacci();
    tests() {
        int64_t N, i;
        cin >> N >> i;
        cout << findFibonacci(N, i) << endl;
    }
    return 0;
}