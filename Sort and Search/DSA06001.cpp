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
        sort(arr, arr + n);

        for (int i = 0; i < (n >> 1); ++i) 
            cout << arr[n - i - 1] << ' ' << arr[i] << ' ';
        if (n & 1) cout << arr[(n >> 1)];
        cout << endl;
    }
    return 0;
}