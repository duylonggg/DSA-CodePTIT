#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int n, k;
vector<int> v, numb;

void Try(int start = 0) {
    if (numb.size() == k) {
        for (int i : numb) cout << i << ' ';
        cout << endl;
        return;
    }

    for (int i = start; i < n; ++i) {
        numb.push_back(v[i]);
        Try(i + 1);
        numb.pop_back();
    }
}

int main() {
    tests() {
        cin >> n >> k;

        v.resize(n);
        for (int& i : v) cin >> i;
        sort(v.begin(), v.end());

        Try();
    }
    return 0;
}