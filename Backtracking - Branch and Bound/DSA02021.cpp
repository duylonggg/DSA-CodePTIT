#include <bits/stdc++.h>
using namespace std;

#define tests() int t; cin >> t; while (t--)

char findNthChar(const string& s, long long N, long long len) {
    if (N <= len) return s[N - 1];

    long long prevLen = len;
    
    while (prevLen * 2 < N) 
        prevLen *= 2;

    if (N == prevLen + 1) 
        return findNthChar(s, N - 1, len); 

    return findNthChar(s, N - (prevLen + 1), len); 
}

int main() {
    tests() {
        string s;
        long long N;
        cin >> s >> N;
        cout << findNthChar(s, N, s.size()) << endl;
    }
    return 0;
}
