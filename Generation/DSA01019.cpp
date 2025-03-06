#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define all(v)      v.begin(), v.end()

int n;

bool check(string str) {
    if (str[0] != 'H' or str.back() != 'A') return false;

    if (str.find("HH") != string::npos) return false;

    return true;
}

void gen(string str = "") {
    if (str.size() == n) {
        if (check(str)) cout << str << endl;
        return;
    }

    gen(str + "A");
    gen(str + "H");
}

int main() {    
    tests() {
        cin >> n;

        gen();
    }
    return 0;
}