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

        vector<int> v(n);
        for (int& x : v) cin >> x;
        sort(v.begin(), v.end());

        int mid = n / 2; 
        int idx1 = 0, idx2 = mid, cnt = 0;

        while (idx1 < mid && idx2 < n) {
            if (v[idx1] * 2 <= v[idx2]) {
                ++idx1;
            }
            ++idx2;
            ++cnt;
        }

        cnt += (mid - idx1) + (n - idx2); 
        cout << cnt << endl;
    }
    return 0;
}
