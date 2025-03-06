#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int countPairs(int x, const vector<int>& Y, const vector<int>& countY) {
    if (x == 0) return 0; 
    if (x == 1) return countY[0]; 

    int idx = upper_bound(Y.begin(), Y.end(), x) - Y.begin();
    int count = Y.size() - idx;

    count += countY[0] + countY[1]; 
    if (x == 2) count -= (countY[3] + countY[4]); 
    if (x == 3) count += countY[2]; 

    return count;
}

int main() {
    fastio()
    tests() {
        int n, m;
        cin >> n >> m;

        vector<int> X(n), Y(m), countY(5, 0);

        for (int& x : X) cin >> x;
        for (int& y : Y) {
            cin >> y;
            if (y < 5) ++countY[y];
        }

        sort(Y.begin(), Y.end());

        int64_t res = 0;
        for (int x : X) {
            res += countPairs(x, Y, countY);
        }
        cout << res << endl;
    }
    return 0;
}