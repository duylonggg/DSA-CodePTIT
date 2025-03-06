#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

long long FLOOR(const vector<long long>& v, long long x) {
    long long tmp = -2, l = 0, r = v.size() - 1;
    
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (v[mid] <= x) {
            tmp = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return tmp + 1;
}

int main() {
    fastio()
    tests() {
        long long n, x;
        cin >> n >> x;
        vector<long long> v(n);
        for (long long& _: v) cin >> _;
        cout << FLOOR(v, x) << endl;
    }
    return 0;
}