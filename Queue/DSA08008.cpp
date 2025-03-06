#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int N;
        cin >> N;

        queue<long long> q;
        q.push(1);
        while (true) {
            long long num = q.front();
            q.pop();

            if (!(num % N)) {
                cout << num << endl;
                break;
            }

            num *= 10;
            q.push(num);
            q.push(num + 1);
        }
    }
    return 0;
}