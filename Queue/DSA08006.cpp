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

        queue<int> q;
        q.push(9);
        while (q.front() % n) {
            int num = q.front();
            q.pop();
            
            q.push(num * 10);
            q.push(num * 10 + 9);
        }
        
        cout << q.front() << endl;
    }
    return 0;
}