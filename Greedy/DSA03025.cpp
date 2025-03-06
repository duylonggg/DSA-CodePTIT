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
        
        vector<pair<int, int>> point(n);
        for (auto& [end, start] : point) 
            cin >> start >> end;
        
        sort(point.begin(), point.end());

        int ans = 0, prev = 0;
        for (const auto& [end, start] : point) {
            if (start >= prev) {
                ++ans;
                prev = end;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}