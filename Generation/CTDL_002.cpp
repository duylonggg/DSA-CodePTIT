#include <bits/stdc++.h>
using namespace std;

int n, k, cnt;
vector<int> v, numb;
vector<vector<int>> res;

void print() {
    ++cnt;
    res.push_back(numb);
}

void gen(int start = 0, int total = 0) {
    if (total == k) {
        print();
        return;
    }
    for (int i = start; i < n; ++i) {
        if (total + v[i] > k) continue; 
        numb.push_back(v[i]);
        gen(i + 1, total + v[i]);
        numb.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    v.resize(n);
    for (int& i : v) cin >> i;

    gen(); 

    sort(res.rbegin(), res.rend());
    for (auto vec : res) {
        for (auto numb : vec)
            cout << numb << ' ';
        cout << endl;
    }
    cout << cnt;

    return 0;
}
