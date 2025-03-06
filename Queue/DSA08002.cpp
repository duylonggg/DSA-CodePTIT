#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio();
    
    queue<int> q;
    tests() {
        string query;
        cin >> query;
        
        if (query == "PUSH") {
            int num;
            cin >> num;
            q.push(num);
        } 
        else if (query == "PRINTFRONT") {
            if (q.empty()) cout << "NONE" << endl;
            else cout << q.front() << endl;
        } 
        else if (query == "POP") 
            if (!q.empty()) q.pop();
    }
    
    return 0;
}
