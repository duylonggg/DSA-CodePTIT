#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

void luckyNumb(int n) {
    for (int y = n / 7; ~y; --y) {
        if ((n - 7 * y) % 4 == 0) {
            int x = (n - 7 * y) / 4;
            cout << string(x, '4') + string(y, '7');
            return;
        } 
    }
    cout << -1;
}

int main() {
    fastio()
    tests() {
        int n;
        cin >> n;
        luckyNumb(n);
        cout << endl;
    }
    return 0;
}