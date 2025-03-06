#include <bits/stdc++.h>
using namespace std;

string s1, s2;

int fill5(const string& str) {
    int numb = 0;
    for (char c : str) {
        numb = numb * 10 + (c - '0');
        if (c == '6') --numb;
    }
    return numb;
}

int fill6(const string& str) {
    int numb = 0;
    for (char c : str) {
        numb = numb * 10 + (c - '0');
        if (c == '5') ++numb;
    }
    return numb;
}

int main() {
    cin >> s1 >> s2;

    cout << fill5(s1) + fill5(s2) << ' ' << fill6(s1) + fill6(s2);

    return 0;
}