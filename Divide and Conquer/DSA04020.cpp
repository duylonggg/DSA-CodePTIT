#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

string binarySearch(const vector<int>& v, int l, int r, int k) {
    while (l <= r) {
        int mid = (l + r) / 2;
        if (v[mid] == k)
            return to_string(mid + 1);
        if (v[mid] < k)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return "NO";
}

int main() {
    fastio()
    tests() {
        int n, k;
        cin >> n >> k;

        vector<int> v(n);
        for (int& _: v) cin >> _;

        cout << binarySearch(v, 0, n - 1, k) << endl;
    }
    return 0;
}