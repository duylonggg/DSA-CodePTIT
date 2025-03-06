#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

void minNum(int N, int S) {
    stack<int> stk;

    --S;
    while (N--) {
        stk.push(min(9, S));
        S -= stk.top();
    }

    ++stk.top();

    while (stk.size()) {
        cout << stk.top();
        stk.pop();
    }
    cout << ' ';
}

void maxNum(int N, int S) {
    while (N--) {
        int num = min(9, S);
        cout << num;
        S -= num;
    }
}

int main() {
    fastio()
    int N, S;
    cin >> N >> S;

    if (S > N * 9 or S == 0) {
        cout << -1 << ' ' << -1 << endl;
        return 0;
    }

    minNum(N, S);
    maxNum(N, S);
    return 0;
}