#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int N;
vector<int> v;

bool check() {
    vector<int> tmp = v;  
    sort(tmp.begin(), tmp.end());

    for (int i = 0; i < (N >> 1); ++i) 
        if (tmp[i] != v[i] and tmp[i] != v[N - i - 1])
            return false;

    return true;
}

int main() {
    tests() {
        cin >> N;

        v.resize(N);
        for (int & i : v) cin >> i;

        cout << (check() ? "Yes" : "No") << endl;
    }
    return 0;
}   