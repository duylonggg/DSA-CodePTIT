#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()

    deque<int> dq;
    tests() {
        string query;
        int num;
        cin >> query;

        if (query == "PUSHFRONT") {
            cin >> num;
            dq.push_front(num);
        }
        else if (query == "PRINTFRONT") {
            if (dq.empty()) cout << "NONE" << endl;
            else cout << dq.front() << endl;
        }
        else if (query == "POPFRONT") {
            if (!dq.empty()) dq.pop_front();
        }
        else if (query == "PUSHBACK") {
            cin >> num;
            dq.push_back(num);
        }
        else if (query == "PRINTBACK") {
            if (dq.empty()) cout << "NONE" << endl;
            else cout << dq.back() << endl;
        }
        else if (query == "POPBACK") {
            if (!dq.empty()) dq.pop_back();
        }
    }
    return 0;
}