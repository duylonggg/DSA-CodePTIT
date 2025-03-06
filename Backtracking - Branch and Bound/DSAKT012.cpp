#include <bits/stdc++.h>
using namespace std;

int n, S, minMoney = INT_MAX;
vector<int> money;

void Try(int start, int total = 0, int cnt = 0) {
    if (minMoney != INT_MAX) return;
    
    if (total > S) return;
    if (total == S) {
        minMoney = cnt;
        return;
    }

    for (int i = start; i < n; ++i) {
        if (total + money[i] > S) continue;
        Try(i + 1, total + money[i], cnt + 1);
    }
}

int main() {
    cin >> n >> S;

    money.resize(n);
    for (int& val : money) cin >> val;
    sort(money.rbegin(), money.rend());

    Try(0);

    cout << (minMoney == INT_MAX ? -1 : minMoney);

    return 0;
}