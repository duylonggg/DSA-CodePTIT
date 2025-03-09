#include <bits/stdc++.h>
using namespace std;

string str;

void gen() {
    int pos = -1;
    for (size_t i = str.size() - 1; ~i; --i) {
        if (str[i] == '1') {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << string(str.size(), '1') << endl;
        return;
    }

    --str[pos];
    for (size_t i = pos + 1; i < str.size(); ++i)
        ++str[i];
    cout << str << endl;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> str;

        gen();
    }
    return 0;
}