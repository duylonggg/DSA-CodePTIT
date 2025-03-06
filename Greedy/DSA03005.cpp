#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int main() {
    tests() {
        int n, k, total = 0, total_k = 0;
        cin >> n >> k;

        vector<int> v(n);
        for (int& i : v) {
            cin >> i;
            total += i;
        }
        sort(v.begin(), v.end());

        k = min(k, n - k);
        for (int i = 0; i < k; ++i) total_k += v[i];

        cout << total - (total_k << 1) << endl;
    }
    return 0;
}