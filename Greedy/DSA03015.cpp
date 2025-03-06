#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int main() {
    tests() {
        int N, S, M;
        cin >> N >> S >> M;
        cout << ((S - S / 7) * N < S * M ? -1 : (M * S + N - 1) / N) << endl;
    }
    return 0;
}