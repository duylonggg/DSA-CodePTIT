#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int n, k;
vector<int> v;

void print() {
    for (int i : v) cout << i << ' ';
    cout << endl;
}

void gen() {
    int pos = -1;
    for (int i = k - 1; ~i; --i) {
        if (v[i] > v[i - 1] + 1) {
            pos = i;
            break;
        }
    }

    if (pos == -1 and v[0] == 1) {
        for (int i = 0; i < k; ++i)
            v[i] = n - k + i + 1;
        print();
        return;
    }

    pos = (pos == -1 ? 0 : pos);
    --v[pos];
    for (int i = pos + 1; i < k; ++i)
        v[i] = n - k + i + 1;
    print();
}

int main() {
    tests() {
        cin >> n >> k;
        v.resize(k);
        for (int& i : v) cin >> i;
        gen();
    }
    return 0;
}