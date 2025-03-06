#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int n, x;
        cin >> n >> x;

        int arr[n];
        for (int& i : arr) cin >> i;
        stable_sort(arr, arr + n, [&] (int a, int b) {
            return abs(x - a) < abs(x - b);
        });

        for (int i : arr) cout << i << ' ';
        cout << endl;
    }
    return 0;
}