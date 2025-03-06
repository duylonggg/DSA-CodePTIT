#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    tests() {
        int n;
        cin >> n;
        
        vector<pair<int, int>> work(n);
        for (auto& [end, start] : work) 
            cin >> start >> end;
        
        sort(work.begin(), work.end());

        int ans = 0, prev = 0;
        for (const auto& [end, start] : work) {
            if (start >= prev) {
                ++ans;
                prev = end;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
