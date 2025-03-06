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
        vector<int> arr(n);
        for (int& x : arr) cin >> x;

        int minSum = INT_MAX;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int sum = arr[i] + arr[j];
                if (abs(sum) < abs(minSum)) minSum = sum;
            }
        }

        cout << minSum << '\n';
    }
    return 0;
}