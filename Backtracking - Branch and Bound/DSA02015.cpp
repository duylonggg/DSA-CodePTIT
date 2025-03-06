#include <bits/stdc++.h>
using namespace std;

#define tests() int test_cases; cin >> test_cases; while (test_cases--)

string str;
set<string> results; 

bool check(const string& s) {
    if (s.empty()) return 0;
    if (s.size() == 1 and isalpha(s[0])) return 0;
    int cnt = 0;
    for (char i : s) {
        if (i == '(') ++cnt;
        else if (i == ')') --cnt;
        if (cnt < 0) return 0;
    }
    return !cnt;
}

void Try(string cur, size_t start, int leftRemove, int rightRemove, int open) {
    if (start == str.size()) {
        if (leftRemove == 0 and rightRemove == 0 and open == 0 and check(cur)) 
            results.insert(cur);
        return;
    }

    char c = str[start];

    if (c == '(' and leftRemove > 0) 
        Try(cur, start + 1, leftRemove - 1, rightRemove, open);
    if (c == ')' and rightRemove > 0) 
        Try(cur, start + 1, leftRemove, rightRemove - 1, open);

    cur.push_back(c);
    
    if (c != '(' and c != ')') 
        Try(cur, start + 1, leftRemove, rightRemove, open);
    else if (c == '(') 
        Try(cur, start + 1, leftRemove, rightRemove, open + 1);
    else if (c == ')' and open > 0) 
        Try(cur, start + 1, leftRemove, rightRemove, open - 1);

    cur.pop_back();
}

int main() {
    tests() {
        cin >> str;

        int leftRemove = 0, rightRemove = 0;
        for (char c : str) {
            if (c == '(') ++leftRemove;
            else if (c == ')') {
                if (leftRemove > 0) --leftRemove;
                else ++rightRemove;
            }
        }

        results.clear();
        Try("", 0, leftRemove, rightRemove, 0);

        if (results.empty()) 
            cout << -1 << endl;
        else {
            for (const string &res : results) 
                cout << res << " ";
            cout << endl;
        }
    }
    return 0;
}
