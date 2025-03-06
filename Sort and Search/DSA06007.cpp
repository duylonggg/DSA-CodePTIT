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

        vector<int> a(n);
        for (int& i : a) cin >> i;
        vector<int> b = a;
        sort(b.begin(), b.end());

        int start, end;
        for (int i = 0; i < n; ++i) {
            if (a[i] != b[i]) {
                start = i;
                break;
            }
        }
        for (int i = n - 1; ~i; --i) {
            if (a[i] != b[i]) {
                end = i;
                break;
            }
        }

        cout << ++start << ' ' << ++end << endl;
    }
    return 0;
}