#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int check(const int& D, const string& str) {
    int freq[26] = {};
    for (char c : str) {
        ++freq[c - 'A'];
        if ((freq[c - 'A'] - 1) * (D - 1) > str.size() - freq[c - 'A']) return -1;
    }
    return 1;
}

int main() {
    tests() {
        int D;
        string str;
        cin >> D >> str;
        
        cout << check(D, str) << endl;
    }
    return 0;
}