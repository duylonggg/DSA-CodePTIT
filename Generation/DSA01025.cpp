#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int n, k;
string str;

void gen() {
    cout << str << endl;
    
    int pos = -1;
    for (int i = k - 1; ~i; --i) {
        if (str[i] - 'A' != n - k + i) {
            pos = i;
            break;
        }
    }

    if (pos == -1) return;

    ++str[pos];
    for (int i = pos + 1; i < k; ++i)
        str[i] = char(str[i - 1] + 1);

    gen();
}

int main() {
    tests() {
        cin >> n >> k;
        str = "";

        for (int i = 0; i < k; ++i)
            str += char('A' + i);

        gen();
    }
    return 0;
}