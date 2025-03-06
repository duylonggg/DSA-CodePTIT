#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

vector<int64_t> bin(100);

void binaryString() {
    bin[1] = 1;
    bin[2] = 1;
    for (int i = 3; i < 100; ++i)
        bin[i] = bin[i - 1] + bin[i - 2];
}

char binary(int n, int64_t k) {
    if (n == 1) return '0';
    if (n == 2) return '1';

    if (k <= bin[n - 2]) return binary(n - 2, k);
    return binary(n - 1, k - bin[n - 2]);
}

int main() {
    fastio();
    binaryString();
    tests() {
        int n;
        int64_t k;
        cin >> n >> k;
        cout << binary(n, k) << endl;
    }
    return 0;
}
