#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string& s) {
    size_t l = 0, r = s.size() - 2;
    
    while (l < r) {
        if (__builtin_expect(s[l] != s[r], 0)) return false;
        ++l, --r;
    }
    return true;
}

void gen(int n, string bits = "", int len = 0) {
    if (len == n) {
        if (isPalindrome(bits))
            cout << bits << endl;
        return;
    }

    gen(n, bits + "0 ", len + 1);
    gen(n, bits + "1 ", len + 1);
}

int main() {
    int n;
    cin >> n;
    gen(n);
    return 0;
}