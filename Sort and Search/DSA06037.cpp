#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio();
    tests() {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        vector<int> left_max(n), right_min(n);
        
        left_max[0] = a[0];
        for (int i = 1; i < n; ++i)
            left_max[i] = max(left_max[i - 1], a[i]);

        right_min[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; --i)
            right_min[i] = min(right_min[i + 1], a[i]);

        vector<int> res;
        for (int i = 0; i < n - 1; ++i) 
            if (left_max[i] <= right_min[i + 1])
                res.push_back(i + 1);

        cout << res.size() << endl;
        for (int x : res) cout << x << " ";
        cout << endl;
    }
    return 0;
}
