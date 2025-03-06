#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int find(const vector<int>& a, const vector<int>& b, int l, int r) {
    if (l == r) return l + 1; 

    int mid = (l + r) / 2;
    
    if (a[mid] != b[mid]) 
        return find(a, b, l, mid); 

    return find(a, b, mid + 1, r); 
}

int main() {
    fastio();
    tests() {
        int n;
        cin >> n;

        vector<int> a(n), b(n - 1);
        for (int& _: a) cin >> _;
        for (int& _: b) cin >> _;

        cout << find(a, b, 0, n - 1) << endl;
    }
    return 0;
}
