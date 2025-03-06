#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int binarySearch(vector<int>& v, int pos, int l, int r, int k) {
    int tmp = pos;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (v[mid] - v[pos] < k) {
            tmp = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return tmp;
}

int main() {
    fastio()
    tests() {
        int n, k;
        cin >> n >> k;

        vector<int> v(n);
        for (int& _: v) cin >> _;
        sort(v.begin(), v.end());

        int64_t cnt = 0;
        for (int i = 0; i < n; ++i) {
            int pos = binarySearch(v, i, i, n - 1, k);
            cnt += pos - i;
        }
        cout << cnt << endl;
    }
    return 0;
}