#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        string str;
        cin >> str;

        stack<int> repeat;
        stack<string> current;
        string decode = "";
        int num = 0;

        for (char c : str) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                if (num == 0) num = 1;
                repeat.push(num);
                current.push(decode);
                num = 0;
                decode = "";
            } else if (c == ']') {
                string tmp = decode;
                int rep = repeat.top(); repeat.pop();
                decode = current.top(); current.pop();
                while (rep--) {
                    decode += tmp;
                }
            } else {
                decode += c;
            }
        }

        cout << decode << endl;
    }
    return 0;
}