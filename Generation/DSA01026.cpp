#include <bits/stdc++.h>
using namespace std;

int n;

bool isValid(const string &s) {
    if (s[0] != '8' || s.back() != '6') return false;
    if (s.find("88") != string::npos) return false;
    if (s.find("6666") != string::npos) return false;
    return true;
}

void gen(string str = "") {
    if (str.size() == n) {
        if (isValid(str))
            cout << str << endl;
        return;
    }

    gen(str + '6'); 
    gen(str + '8');
}

int main() {
    cin >> n;

    gen();

    return 0;
}