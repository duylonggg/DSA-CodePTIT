#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio();
    tests() {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int &x : arr) cin >> x;

        unordered_map<int, int> freq;
        int64_t count = 0;

        for (int x : arr) {
            count += freq[k - x];  
            ++freq[x];  
        }

        cout << count << endl;
    }
    return 0;
}
