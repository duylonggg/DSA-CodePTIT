#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio();
    tests() {
        int n;
        cin >> n;

        array<short, 3> freq = {};
        for (short i = 0; i < n; ++i) {
            short num;
            cin >> num;
            ++freq[num];
        }

        for (short i = 0; i < 3; ++i) {
            short num = freq[i];
            while (num--) {
                cout << i << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}
