#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

void print() {
    for (int i : v) cout << i;
    cout << ' ';
}

void gen() {
    print();
    
    int pos = -1;
    for (int i = n - 2; ~i; --i) {
        if (v[i] > v[i + 1]) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        reverse(v.begin(), v.end());
        cout << endl;
        return;
    }

    int swap_pos;
    for (int i = n - 1; ~i; --i) {
        if (v[i] < v[pos]) {
            swap_pos = i;
            break;
        }
    }

    swap(v[pos], v[swap_pos]);
    reverse(v.begin() + pos + 1, v.end());
    gen();
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;

        v.resize(n);
        for (int i = 0; i < n; ++i)
            v[i] = n - i;

        gen();
    }

    return 0;
}