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

        vector<int> arr(n);
        for (int &x : arr) cin >> x;

        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0); 
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return arr[i] < arr[j];  
        });

        int minPos = n, maxDist = -1;
        for (int i : idx) {
            maxDist = max(maxDist, i - minPos);
            minPos = min(minPos, i);
        }

        cout << maxDist << endl;
    }
    return 0;
}
