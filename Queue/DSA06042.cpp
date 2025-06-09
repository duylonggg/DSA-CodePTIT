#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    ll D;
    cin >> N >> D;

    vector<pair<ll, ll>> cows(N);
    for (int i = 0; i < N; ++i)
        cin >> cows[i].first >> cows[i].second;
    sort(cows.begin(), cows.end());

    vector<ll> x(N), h(N);
    for (int i = 0; i < N; ++i) {
        x[i] = cows[i].first;
        h[i] = cows[i].second;
    }

    vector<bool> leftOK(N, 0), rightOK(N, 0);
    deque<int> dq;
    int l = 0;
    for (int i = 0; i < N; ++i) {
        while (l < i && x[l] < x[i] - D) {
            if (!dq.empty() && dq.front() == l)
                dq.pop_front();
            ++l;
        }
        if (!dq.empty() && h[dq.front()] >= 2 * h[i])
            leftOK[i] = 1;
        while (!dq.empty() && h[dq.back()] <= h[i])
            dq.pop_back();
        dq.push_back(i);
    }

    dq.clear();
    int r = N - 1;
    for (int i = N - 1; i >= 0; --i) {
        while (r > i && x[r] > x[i] + D) {
            if (!dq.empty() && dq.front() == r)
                dq.pop_front();
            --r;
        }
        if (!dq.empty() && h[dq.front()] >= 2 * h[i])
            rightOK[i] = 1;
        while (!dq.empty() && h[dq.back()] <= h[i])
            dq.pop_back();
        dq.push_back(i);
    }

    int cnt = 0;
    for (int i = 0; i < N; ++i)
        if (leftOK[i] && rightOK[i])
            ++cnt;
    cout << cnt;

    return 0;
}
