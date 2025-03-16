#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

vector<int> result;
void gen() {
    queue<int> q;

    for (int i = 1; i <= 5; ++i) q.push(i);

    while (!q.empty()) {
        int num = q.front();
        q.pop();

        result.push_back(num);

        if (num >= 10000) continue;

        for (int d = 0; d <= 5; ++d) 
            if (to_string(num).find(char(d + '0')) == string::npos) 
                q.push(num * 10 + d);
    }
}

int main() {
    fastio();
    gen();
    tests() {
        int L, R;
        cin >> L >> R;

        int ans = 0;
        for (int num : result) {
            if (num < L) continue;
            if (num > R) break;
            ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}
