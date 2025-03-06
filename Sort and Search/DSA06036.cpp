#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

string check(int* arr, int n, int k) {
    sort(arr, arr + n); 

    for (int i = 0; i < n - 2; ++i) {
        for (int j = i + 1; j < n - 1; ++j) {
            int sum = arr[i] + arr[j];
            int* pos = lower_bound(arr + j + 1, arr + n, k - sum);

            if (pos != arr + n && *pos == k - sum) 
                return "YES";
        }
    }
    return "NO";
}

int main() {
    fastio()
    tests() {
        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int& _: arr) cin >> _;

        cout << check(arr, n, k) << endl;
    }
    return 0;
}
