#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        string line;
        
        stack<string> stk;
        getline(cin >> ws, line);
        stringstream ss(line);
        string str;
        while (ss >> str) { 
            stk.push(str);
        }

        while (!stk.empty()) {
            cout << stk.top() << " ";
            stk.pop();
        }
        cout << endl;
    }
    return 0;
}