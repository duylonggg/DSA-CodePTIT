#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int query;
        cin >> query;

        deque<int> dq;
        while (query--) {
            int q, num;
            cin >> q;

            switch (q) {
                case 1: 
                    cout << dq.size() << endl;
                    break;
                case 2:
                    cout << (dq.empty() ? "YES" : "NO") << endl;
                    break;
                case 3:
                    cin >> num;
                    dq.push_back(num);
                    break;
                case 4:
                    if (dq.size()) dq.pop_front();
                    break;
                case 5:
                    cout << (dq.empty() ? -1 : dq.front()) << endl;
                    break;
                case 6:
                    cout << (dq.empty() ? -1 : dq.back()) << endl;
                    break;
            }
        }
    }
    return 0;
}