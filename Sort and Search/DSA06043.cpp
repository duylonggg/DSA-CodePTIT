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

        int arr[n], prefix_sum[n + 1] = {};
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            prefix_sum[i + 1] = prefix_sum[i] + arr[i];
        }

        int pos = -1;
        for (int i = 2; i < n; ++i) {
            if (prefix_sum[i - 1] == prefix_sum[n] - prefix_sum[i]) {
                pos = i;
                break;
            }
        }
        cout << pos << endl;
    }
    return 0;
}