#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int main() {
    tests() {
        int n;
        cin >> n;

        priority_queue<long long, vector<long long>, greater<>> pq;
        while (n--) {
            int num;
            cin >> num;
            pq.emplace(num);
        }

        long long res = 0;
        while (pq.size() > 1) {
            long long num1 = pq.top(); pq.pop();
            long long num2 = pq.top(); pq.pop();

            res += num1 + num2;
            pq.emplace(num1 + num2);
        }

        cout << res << endl;
    }
    return 0;
}
