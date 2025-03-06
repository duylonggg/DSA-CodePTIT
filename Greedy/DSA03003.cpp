#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int main() {
    tests() {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int& i : v) cin >> i;
        sort(v.begin(), v.end());

        long long ans = 0;
        for (int i = 0; i < n; ++i) 
            ans += (v[i] * i) % 1000000007;

        cout << ans % 1000000007 << endl;
    }
    return 0;
}