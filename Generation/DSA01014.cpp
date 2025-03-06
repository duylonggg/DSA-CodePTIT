#include <bits/stdc++.h>
using namespace std;

int n, k, s, total, cnt;
vector<int> v;

void gen(int start) {
    if (total > s) return;
    if (v.size() > k) return;

    if (v.size() == k and total == s) {
        ++cnt;
        return;
    }
    
    for (int i = start; i <= n; ++i) {
        v.push_back(i);
        total += i;
        gen(i + 1);
        total -= i;
        v.pop_back();
    }
}

int main() {
    while (cin >> n >> k >> s, n || k || s) {
        v.clear();
        cnt = 0;
        total = 0;
        gen(1);

        cout << cnt << endl;
    }
    return 0;
}