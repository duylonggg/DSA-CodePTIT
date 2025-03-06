#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int n, k, cnt;
vector<int> v;
map<int, int> mp;

void gen() {
    int pos = -1;
    for (int i = k - 1; ~i; --i) {
        if (v[i] != n - k + i + 1) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << k << endl;
        return;
    }

    ++v[pos];
    cnt += !mp[v[pos]];
    for (int i = pos + 1; i < k; ++i) {
        v[i] = v[i - 1] + 1;
        cnt += !mp[v[i]];
    }

    cout << cnt << endl;
}

int main() {
    tests() {
        cin >> n >> k;
        v.resize(k);
        mp.clear();
        cnt = 0;
        for (int& i : v) {
            cin >> i;
            ++mp[i];
        }

        gen();
    }
    return 0;
}