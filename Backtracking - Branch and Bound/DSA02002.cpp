#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

void Try(vector<int> v, int n) {
    if (n < 1) return;

    vector<int> tmp(n - 1, 0);
    for (int i = 0; i < n - 1; ++i)
        tmp[i] = v[i] + v[i + 1];

    Try(tmp, n - 1);

    cout << '[' << v[0];
    for (int i = 1; i < n; ++i) cout << ' ' << v[i];
    cout << ']' << ' ';
}

int main() {
    tests() {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int& i : v) cin >> i; 
        
        Try(v, n);

        cout << endl;
    }
    return 0;
}