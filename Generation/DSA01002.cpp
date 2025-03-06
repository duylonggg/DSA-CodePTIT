#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> v;

void print() {
    for (int i : v)
        cout << i << ' ';
    cout << endl;
}

void gen() {
    int pos = -1;
    for (int i = k - 1; ~i; --i) {
        if (v[i] != n - k + i + 1) {
            pos = i;
            break;
        }
    }

    if (pos == -1)
        for (int i = 0; i < k; ++i)
            v[i] = i + 1;
    else {
        ++v[pos];
        for (int i = pos + 1; i < k; ++i)
            v[i] = v[i - 1] + 1;
    }

    print();
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> k;

        v.resize(k);
        for (int& i : v) cin >> i;

        gen();
    }    
    return 0;
}