#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    int n, maxLen = 0;
    cin >> n;
    
    vector<int> v(n), seg(n + 1, 0);
    for (int& i : v) {
        cin >> i;
        seg[i] = seg[i - 1] + 1;
        maxLen = max(maxLen, seg[i]);
    }

    cout << n - maxLen;
    return 0;
}