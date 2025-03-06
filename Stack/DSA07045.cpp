#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()

    string str;
    cin >> str;

    deque<char> leftShift;
    stack<char> rightShift;
    for (char c : str) {
        if (isalnum(c)) {
            leftShift.push_back(c);
        } else if (c == '<') {
            if (leftShift.empty()) continue;
            rightShift.push(leftShift.back());
            leftShift.pop_back();
        } else if (c == '>') {
            if (rightShift.empty()) continue;
            leftShift.push_back(rightShift.top());
            rightShift.pop();
        } else if (c == '-') {
            if (leftShift.empty()) continue;
            leftShift.pop_back();
        }
    }

    while (!rightShift.empty()) {
        leftShift.push_back(rightShift.top());
        rightShift.pop();
    }

    while (!leftShift.empty()) {
        cout << leftShift.front();
        leftShift.pop_front();
    }
    return 0;
}