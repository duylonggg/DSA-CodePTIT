#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int& i : arr) cin >> i;
        sort(arr, arr + n);

        for (int i = n - 1; i > n - k - 1; --i) 
            cout << arr[i] << ' ';
        cout << endl;
    }
    return 0;
}