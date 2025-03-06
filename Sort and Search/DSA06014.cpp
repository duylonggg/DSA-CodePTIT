#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int n;

bool is_prime(int n) {
    if (n < 2) return false;
    if (n == 2 or n == 3) return true;
    if (n % 2 == 0 or n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 or n % (i + 2) == 0)  
            return false;
    
    return true;
}


void solve() {
    if (n < 3) {
        cout << -1 << endl;
        return;
    }
    
    if (n & 1 and !is_prime(n - 2)) {
        cout << -1 << endl;
        return;
    }

    for (int i = 2; i <= (n >> 1); ++i) {
        if (is_prime(i) and is_prime(n - i)) {
            cout << i << ' ' << n - i << endl;
            return;
        }
    }
}

int main() {
    tests() {
        cin >> n;

        solve();
    }
    return 0;
}