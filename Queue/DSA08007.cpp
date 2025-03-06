#include <bits/stdc++.h>
using namespace std;

#define tests() int test_cases; cin >> test_cases; while (test_cases--)
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int main() {
    fastio();
    tests() {
        long long N;
        cin >> N;
        int ans = 0;

        queue<long long> q;
        q.push(1);

        while (!q.empty()) {
            long long num = q.front();
            q.pop();

            if (num > N) break;

            num *= 10;
            if (num == N or num + 1 == N) {
                ++ans;
                break;
            }

            ++ans;
            q.push(num);
            q.push(num + 1);
        }

        cout << ans << endl;
    }
    return 0;
}
