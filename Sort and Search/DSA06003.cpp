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

        int arr[n];
        for (int& i : arr) cin >> i;

        int cnt = 0;
        for (int i = 0; i < n - 1; ++i) {
            int minIdx = i;

            for (int j = i + 1; j < n; ++j)
                if (arr[j] < arr[minIdx])
                    minIdx = j;

            if (minIdx != i) {
                ++cnt;
                swap(arr[minIdx], arr[i]);
            }
        }

        cout << cnt << endl;
    }
    return 0;
}