#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int n;
string str;
set<string> res;

void Try() {
    int totalSubsets = 1 << n;

    for (int mask = 0; mask < totalSubsets; ++mask) {
        string subset = "";
        for (int i = 0; i < n; ++i) 
            if (mask & (1 << i))
                subset += str[i];
        
        res.insert(subset);
    }

    for (auto s : res) cout << s << ' ';
    cout << endl;
}

int main() {
    tests() {
        cin >> n >> str;

        Try();
    }
    return 0;
}