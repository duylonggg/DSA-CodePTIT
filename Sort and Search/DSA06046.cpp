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
        for (int& _: arr) cin >> _;
        sort(arr, arr + n);

        int minDif = INT_MAX;
        for (int i = 0; i < n - 1; ++i)
            minDif = min(arr[i + 1] - arr[i], minDif);
        cout << minDif << endl;
    }
    return 0;
}