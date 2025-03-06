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
        cnt = k;
        return;
    }

    ++v[pos];
    cnt += !mp[v[pos]];
    for (int i = pos + 1; i < k; ++i) {
        v[i] = v[i - 1] + 1;
        cnt += !mp[v[i]];
    }
}

int main() {
    tests() {
        cin >> n >> k;
        cnt ^= cnt;

        v.resize(k);
        mp.clear();
        for (int& i : v) {
            cin >> i;
            ++mp[i];
        }

        gen();

        cout << cnt << endl;
    }
    return 0;
}