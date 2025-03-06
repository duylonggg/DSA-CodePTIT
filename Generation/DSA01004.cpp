#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> v;

void print() {
    for (int i : v) cout << i;
    cout << ' '; 
}

void gen() {
    print();
    
    int pos = -1;
    for (int i = k - 1; ~i; --i) {
        if (v[i] != n - k + i + 1) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << endl;
        return;
    }

    ++v[pos];
    for (int i = pos + 1; i < k; ++i)
        v[i] = v[i - 1] + 1;
    
    gen();
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> k;

        v.resize(k);
        for (int i = 0; i < k; ++i)
            v[i] = i + 1;

        gen();
    }
    return 0;
}