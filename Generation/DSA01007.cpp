#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int n;

void gen(int len = 0, string str = "") {
    if (len == n) {
        cout << str << ' ';
        return;
    }

    gen(len + 1, str + "A");
    gen(len + 1, str + "B");
}

int main() {
    tests() {
        cin >> n;

        gen();

        cout << endl;
    }
    return 0;
}