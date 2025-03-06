#include <bits/stdc++.h>
using namespace std;

int n, k, cnt;
vector<int> v, numb;

void Try(int start) {
    if (numb.size() == k) {
        ++cnt;
        return;
    }

    for (int i = start; i < n; ++i) {
        if (!numb.empty() and numb.back() > v[i]) continue; 
        numb.push_back(v[i]);
        Try(i + 1);
        numb.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    v.resize(n);

    for (int& i : v) cin >> i;

    Try(0);
    cout << cnt;
    
    return 0;
}
