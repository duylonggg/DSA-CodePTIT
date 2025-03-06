#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int n;
vector<int> v, ori;

void gen(int cnt = 1) {
    if (v == ori) {
        cout << cnt << endl;
        return;
    }

    int pos = -1, swap_pos = -1;
    for (int i = n - 2; i >= 0; --i) {
        if (ori[i] < ori[i + 1]) {
            pos = i;
            break;
        }
    }

    for (int i = n - 1; i > pos; --i) {
        if (ori[i] > ori[pos]) {
            swap_pos = i;
            break;
        }
    }

    swap(ori[pos], ori[swap_pos]);
    reverse(ori.begin() + pos + 1, ori.end());

    gen(cnt + 1);
}

int main() {
    tests() {
        cin >> n;
        v.resize(n);
        ori.resize(n);

        for (int i = 0; i < n; ++i) cin >> v[i];
        iota(ori.begin(), ori.end(), 1); 

        gen();
    }
    return 0;
}
