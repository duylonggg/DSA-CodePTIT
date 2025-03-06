#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int n;
        cin >> n;

        queue<string> q;
        q.push("1");
        while (n--) {
            string num = q.front();
            q.pop();

            cout << num << ' ';

            q.push(num + "0");
            q.push(num + "1");
        }
        cout << endl;
    }
    return 0;
}