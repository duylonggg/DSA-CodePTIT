#include <bits/stdc++.h>
using namespace std;

#define tests() int test_cases; cin >> test_cases; while (test_cases--)

int n;

void gen() {
    queue<long long> q;
    q.push(9);

    while (!q.empty()) {
        long long numb = q.front();
        q.pop();

        if (!(numb % n)) {
            cout << numb << endl;
            return;
        }
        if (!((numb * 10) % n)) {
            cout << numb * 10 << endl;
            return;
        }
        if (!((numb * 10 + 9) % n)) {
            cout << numb * 10 + 9 << endl;
            return;
        }

        q.push(numb * 10);
        q.push(numb * 10 + 9);
    }
}

int main() {
    tests() {
        cin >> n;
        gen();
    }
    return 0;
}
