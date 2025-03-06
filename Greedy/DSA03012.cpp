#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int check(const string& str) {
    int freq[26] = {};
    for (char c : str) {
        ++freq[c - 'a'];
        if ((freq[c - 'a'] << 1) - 1 > str.size())
            return -1;
    }

    return 1;
}

int main() {
    tests() {
        string str;
        cin >> str;

        cout << check(str) << endl;
    }
    return 0;
}