#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

bool check(const string& str) {
    int ope = 0, hook = 0;
    for (char c : str) {
        ope += (c == '+' | c == '-');
        hook += (c == '(');
    }
    return ope != hook;
}

int main() {
    fastio()
    tests() {
        string str;
        getline(cin >> ws, str);

        cout << (check(str) ? "Yes" : "No") << endl;
    }
    return 0;
}