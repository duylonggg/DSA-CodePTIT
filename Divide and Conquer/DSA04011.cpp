#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int BinToDec(string bin) {
    int dec = 0;
    for (char c : bin) 
        dec = (dec << 1) + (c - '0');
    return dec;
}

int main() {
    fastio()
    tests() {
        string bin1, bin2;
        cin >> bin1 >> bin2;
        
        int num1 = BinToDec(bin1);
        int num2 = BinToDec(bin2);

        cout << (long long) num1 * num2 << endl;
    }
    return 0;
}