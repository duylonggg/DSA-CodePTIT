#include <bits/stdc++.h>
using namespace std;

#define tests() int test_cases; cin >> test_cases; while (test_cases--)

int n, k, bit_1;
string bits;

void gen() {
    if (bits.size() == n) {
        if (bit_1 == k) cout << bits << endl;
        return;
    }

    if (bit_1 > k) return; 

    bits.push_back('0');
    gen();
    bits.pop_back();

    bits.push_back('1');
    ++bit_1;
    gen();
    --bit_1;
    bits.pop_back();
}

int main() {
    tests() {
        cin >> n >> k;
        bit_1 = 0;

        gen();
    }
    return 0;
}
