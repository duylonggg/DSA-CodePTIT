#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()

    int n;
    string str;
    cin >> n >> str;

    int64_t total = (n * (n - 1LL)) >> 1;

    int similiar = 1;
    vector<int> v;
    for (int i = 1; i < n; ++i) {
        if (str[i] == str[i - 1]) {
            ++similiar;
        } else {
            v.push_back(similiar);
            similiar = 1;
        }
    }

    v.push_back(similiar);
    for (size_t i = 1; i < v.size(); ++i)
        total -= (v[i] + v[i - 1] - 1LL);
    cout << total;
    
    return 0;
}