#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

vector<map<int, int>> dp;

inline bool check(const int& mid, const int& x, const int& y) {
    auto it = dp[mid].lower_bound(x);
    if (it == dp[mid].begin())
        return false;
    --it;
    return (*it).second < y;
}

inline void add(const int& l, const int& x, const int& y) {
    auto it = dp[l].lower_bound(x);
    auto ori = it;

    while (it != dp[l].end() and (*it).second >= y)
        ++it;

    dp[l].erase(ori, it);
    dp[l].insert({x, y});
}

int main() {
    fastio()
    int n, x, y, res = 0, l, r, mid;
    cin >> n;

    dp.resize(n);
    add(0, INT_MIN, INT_MIN);

    while (n--) {
        cin >> x >> y;

        l = 0;
        r = res;

        while (l <= r) {
            mid = (l + r) / 2;

            if (check(mid, x, y))
                l = mid + 1;
            else
                r = mid - 1;
        }

        if (res == l - 1)
            res = l;

        add(l, x, y);
    }
    
    cout << res;
    return 0;
}