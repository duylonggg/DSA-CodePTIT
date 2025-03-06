#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int countZero(const vector<int>& v, int l, int r) {
    if (l == r) return !v[l];
    int countL = 0, countR = 0;

    int mid = (l + r) / 2;
    countL += countZero(v, l, mid);
    countR += countZero(v, mid + 1, r);
    
    return countL + countR;
}

int main() {
    fastio()
    tests() {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int& _: v) cin >> _;
        cout << countZero(v, 0, n - 1) << endl;
    }
    return 0;
}