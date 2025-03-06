#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int n, k;
vector<int> v, ori;

void gen(int cnt = 1) {
    if (v == ori) {
        cout << cnt << endl;
        return;
    }

    int pos;
    for (int i = k - 1; ~i; --i) {
        if (ori[i] != n - k + i + 1) {
            pos = i;
            break;
        }
    }

    ++ori[pos];
    for (int i = pos + 1; i < k; ++i)
        ori[i] = ori[i - 1] + 1;

    gen(cnt + 1);
}

int main() {
    tests() {
        cin >> n >> k;
        v.resize(k);
        ori.resize(k);

        for (int& i : v) cin >> i;
        iota(ori.begin(), ori.end(), 1);

        gen();
    }
    return 0;
}