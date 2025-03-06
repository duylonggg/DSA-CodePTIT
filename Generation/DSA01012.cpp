#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int n;

void gray() {
    int total = 1 << n;
    for (int i = 0; i < total; ++i) {
        int gray = i ^ (i >> 1);
        cout << bitset<16>(gray).to_string().substr(16 - n) << ' ';
    }
    cout << endl;
}

int main() {
    tests() {
        cin >> n;
        gray();
    }
    return 0;
}