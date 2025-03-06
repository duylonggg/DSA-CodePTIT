#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int MOD = 1e9 + 7;

int main() {
    fastio()
    tests() {
        int n;
        long long numb;
        cin >> n;

        priority_queue<long long, vector<long long>, greater<>> pq;
        while (n--) {
            cin >> numb;
            pq.push(numb);
        }

        long long totalCost = 0;
        while (pq.size() > 1) {
            long long num1 = pq.top(); pq.pop();
            long long num2 = pq.top(); pq.pop();

            totalCost += (num1 % MOD + num2 % MOD) % MOD;
            pq.push((num1 % MOD + num2 % MOD) % MOD);
        }

        cout << totalCost % MOD << endl;
    }
    return 0;
}