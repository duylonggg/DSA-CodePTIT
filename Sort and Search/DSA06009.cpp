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

        int16_t freq[101] = {};
        int64_t res = 0;

        while (n--) {
            int num;
            cin >> num;
            if (num <= 100) ++freq[num];

            int target = k - num;
            if (target >= 0 && target <= 100) res += freq[target];

            if (num * 2 == k) --res;
        }
        cout << res << endl;
    }
    return 0;
}