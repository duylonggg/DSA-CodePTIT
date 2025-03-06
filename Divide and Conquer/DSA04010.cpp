#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

vector<int> v;

int maxSumLR(int l, int r, int mid) {
    int sumL = 0, sumR = 0, maxL = INT_MIN, maxR = INT_MIN;
    for (int i = mid; i >= l; --i) {
        sumL += v[i];
        maxL = max(maxL, sumL);
    }
    for (int i = mid + 1; i <= r; ++i) {
        sumR += v[i];
        maxR = max(maxR, sumR);
    }
    return maxL + maxR;
}

int maxSum(int l, int r) {
    if (l == r) return v[l];

    int mid = (l + r) / 2;

    return max({maxSum(l, mid), maxSum(mid + 1, r), maxSumLR(l, r, mid)});
}

int main() {
    fastio()
    tests() {
        int n;
        cin >> n;
        v.resize(n);
        for (int& i : v) cin >> i;
        cout << maxSum(0, n - 1) << endl;
    }
    return 0;
}