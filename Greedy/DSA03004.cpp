#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int main() {
    tests() {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int& i : v) cin >> i;
        sort(v.begin(), v.end());

        long long num1 = 0, num2 = 0;
        for (int i = 0; i < n; ++i) {
            if (i & 1) num1 = num1 * 10ll + v[i];
            else num2 = num2 * 10ll + v[i];
        }

        cout << num1 + num2 << endl;
    }
    return 0;
}