#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int main() {
    tests() {
        int n;
        cin >> n;
        
        vector<int> S(n), F(n);
        for (int& s : S) cin >> s;
        for (int& f : F) cin >> f;

        vector<pair<int, int>> work;
        for (int i = 0; i < n; ++i)
            work.push_back({F[i], S[i]});
        sort(work.begin(), work.end());

        int cnt = 0, prev = 0;
        for (auto [end, start] : work) {
            if (start >= prev) {
                ++cnt;
                prev = end;
            }
        }

        cout << cnt << endl;
    }
    return 0;
}