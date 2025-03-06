#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio();
    tests() {
        int64_t n, k;
        cin >> n >> k;

        vector<int64_t> arr(n);
        for (int64_t &x : arr) cin >> x;

        sort(arr.begin(), arr.end()); 
        int64_t res = 0;

        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int64_t sum = arr[i] + arr[left] + arr[right];
                if (sum < k) {
                    res += (right - left);
                    ++left;
                } else {
                    --right;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
