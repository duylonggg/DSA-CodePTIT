#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int K;
        string str;
        cin >> K >> str;

        int freq[26] = {};
        for (char c : str) ++freq[c - 'A'];

        priority_queue<int> pq;
        for (int i = 0; i < 26; ++i)
            if (freq[i])
                pq.push(freq[i]);

        while (K) {
            int num = pq.top(); pq.pop();
            --num;
            pq.push(num);
            --K;
        }

        long long ans = 0;
        while (pq.size()) {
            int num = pq.top(); pq.pop();
            ans += num * num;
        }

        cout << ans << endl;
    }
    return 0;
}