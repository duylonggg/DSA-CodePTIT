#include <bits/stdc++.h>
using namespace std;

#define tests() int test_cases; cin >> test_cases; while (test_cases--)

int n, k, numb, ans;
vector<int> sum;

void Try(int idx, int cnt) {
    if (cnt == k) {
        ans += (idx == n);
        return;
    }

    for (int j = idx + 1; j <= n; ++j) 
        if (sum[j] - sum[idx] == numb)
            Try(j, cnt + 1);
}

int main() {
    cin >> n >> k;

    sum.assign(n + 5, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> numb;
        sum[i] = sum[i - 1] + numb;
    }

    if (sum[n] % k) return cout << 0, 0;

    numb = sum[n] / k;
    Try(0, 0);

    cout << ans;

    return 0;
}
