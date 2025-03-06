#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int n, x, num, freq = 0;
        cin >> n >> x;
        
        while (n--) cin >> num, freq += (num == x);

        cout << (freq ? freq : -1) << endl;
    }
    return 0;
}