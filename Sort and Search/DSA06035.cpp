#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int n, num, up = 0, down = 0;
        cin >> n;

        int arr[n];
        for (int& _: arr) cin >> _;

        int len = 1, maxLen = 0;
        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i - 1]) {
                ++len;
                up = 1;
                if (down) {
                    down = 0;
                    len = 2;
                }
            } else if (arr[i] < arr[i - 1]) {
                up = 0;
                down = 1;
                ++len;
            }
            maxLen = max(maxLen, len);
        }

        cout << maxLen << endl;
    }
    return 0;
}