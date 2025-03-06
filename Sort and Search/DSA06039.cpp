#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

string solve(int n) {
    unordered_map<int, int> index_map;
    int arr[n + 1], min_idx = INT_MAX;

    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];

        if (index_map.count(arr[i])) {
            min_idx = min(min_idx, index_map[arr[i]]);
        } else {
            index_map[arr[i]] = i;
        }
    }

    return (min_idx != INT_MAX ? to_string(arr[min_idx]) : "NO");
}

int main() {
    fastio()
    tests() {
        int n;
        cin >> n;

        cout << solve(n) << endl;
    }
    return 0;
}