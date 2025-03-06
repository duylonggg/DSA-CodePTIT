#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

string check(int64_t* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int64_t sum = arr[i] + arr[j];

            if (binary_search(arr + j + 1, arr + n, sum))
                return "YES";
        }
    }
    return "NO";
}

int main() {
    fastio()
    tests() {
        int n;
        cin >> n;

        int64_t arr[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            arr[i] *= arr[i];
        }

        sort(arr, arr + n);
        cout << check(arr, n) << endl;
    }
    return 0;
}
