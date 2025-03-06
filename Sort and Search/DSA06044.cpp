#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()

    int n, num;
    cin >> n;

    priority_queue<int> even;
    priority_queue<int, vector<int>, greater<>> odd;
    for (int i = 1; i <= n; ++i) {
        cin >> num;
        if (i & 1) odd.push(num);
        else even.push(num);
    }

    for (int i = 1; i <= n; ++i) {
        if (i & 1) {
            cout << odd.top() << ' '; 
            odd.pop();
        } else {
            cout << even.top() << ' ';
            even.pop();
        }
    }   
    return 0;
}