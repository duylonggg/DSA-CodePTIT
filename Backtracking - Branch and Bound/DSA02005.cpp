#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

string str;

void gen() {
    cout << str << ' ';
    
    size_t len = str.size();

    size_t pos = -1;
    for (size_t i = len - 2; ~i; --i) {
        if (str[i] < str[i + 1]) {
            pos = i;
            break;
        }
    }

    if (pos == -1) return;

    size_t swap_pos;
    for (size_t i = len - 1; ~i; --i) {
        if (str[i] > str[pos]) {
            swap_pos = i;
            break;
        }
    }

    swap(str[pos], str[swap_pos]);
    reverse(str.begin() + pos + 1, str.end());

    gen();
}

int main() {
    tests() {
        cin >> str;

        gen();

        cout << endl;
    }
    return 0;
}