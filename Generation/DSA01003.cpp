#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v;

void print() {
    for (int i : v) cout << i << ' ';
    cout << endl;
}

void gen() {
    int pos = -1;   
    for (int i = n - 2; ~i; --i) {
        if (v[i] < v[i + 1]) {
            pos = i;
            break;
        }
    }

    if (pos == -1) 
        sort(v.begin(), v.end());
    else {
        int swap_pos;
        for (int i = n - 1; ~i; --i) {
            if (v[i] > v[pos]) {
                swap_pos = i;
                break;
            }
        }

        swap(v[swap_pos], v[pos]);

        sort(v.begin() + pos + 1, v.end());
    }

    print();
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;

        v.resize(n);
        for (int& i : v) cin >> i;

        gen();
    }
    return 0;
}