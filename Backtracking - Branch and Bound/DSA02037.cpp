#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int n, total;
vector<int> v, numb;
set<vector<int>> res;

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 or n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) 
        if (n % i == 0 or n % (i + 2) == 0)
            return false;

    return true;
}

void Try(int start) {
    for (int i = start; i < n; ++i) {
        total += v[i];
        numb.push_back(v[i]);

        if (is_prime(total)) 
            res.insert(numb);

        Try(i + 1);

        total -= v[i];
        numb.pop_back();
    }
}

int main() {
    tests() {
        cin >> n;
        total = 0;

        v.resize(n);
        res.clear();
        numb.clear();
        for (int& i : v) cin >> i;
        sort(v.rbegin(), v.rend());

        Try(0);

        for (auto vec : res) {
            for (auto num : vec) cout << num << ' ';
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}