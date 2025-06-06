#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    list<char> l;
    auto it = l.begin();  

    for (char c : str) {
        if (c == '<') {
            if (it != l.begin()) --it;
        }
        else if (c == '>') {
            if (it != l.end()) ++it;
        }
        else if (c == '-') {
            if (it != l.begin()) l.erase(prev(it));
        }
        else {
            l.insert(it, c);
        }
    }

    for (char c : l) {
        cout << c;
    }
    return 0;
}
