#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int binarySearch(int arr[], int key, int l, int r, int k) {
    int tmp = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] - key >= k) {
            r = mid - 1;
        } else if (arr[mid] - key < k) {
            tmp = mid;
            l = mid + 1;
        }
    }
    return tmp;
}

int main() {
    fastio()
    tests() {
        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int& _: arr) cin >> _;
        sort(arr, arr + n);

        int64_t res = 0;
        for (int i = 0; i < n - 1; ++i) {
            int pos = binarySearch(arr, arr[i], i + 1, n, k);

            if (pos != -1) res += pos - i;
        }
        cout << res << endl;
    }
    return 0;
}