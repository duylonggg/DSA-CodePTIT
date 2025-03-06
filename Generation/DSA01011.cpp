#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

string str;

string gen() {
    size_t pos = -1;
    for (size_t i = str.size() - 2; ~i; --i) {
        if (str[i] < str[i + 1]) {
            pos = i;
            break;
        }
    }

    if (pos == -1) return "BIGGEST";

    size_t swap_pos;
    for (int i = str.size() - 1; ~i; --i) {
        if (str[i] > str[pos]) {
            swap_pos = i;
            break;
        }
    }

    swap(str[pos], str[swap_pos]);
    reverse(str.begin() + pos + 1, str.end());
    return str;
}

int main() {
    tests() {
        int t;
        cin >> t >> str;

        cout << t << ' ' << gen() << endl;
    }
    return 0;
}