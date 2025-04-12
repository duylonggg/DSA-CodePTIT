#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        string bin1, bin2;
        cin >> bin1 >> bin2;

        cout << stoll(bin1, nullptr, 2) * stoll(bin2, nullptr, 2) << endl;
    }
    return 0;
}