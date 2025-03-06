#include <bits/stdc++.h>
using namespace std;

#define tests() int test_cases; cin >> test_cases; while (test_cases--)
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl '\n'

int toDecimal(const string& num, int base) {
    int result = 0;
    for (char c : num) {
        result = result * base + (c - '0'); 
    }
    return result;
}

string fromDecimal(int num, int base) {
    if (num == 0) return "0"; 

    string result = "";
    while (num > 0) {
        result += (char)('0' + (num % base)); 
        num /= base;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    fastio();
    tests() {
        int K;
        string A, B;
        cin >> K >> A >> B;

        int A_dec = toDecimal(A, K);
        int B_dec = toDecimal(B, K);
        int sum = A_dec + B_dec;

        cout << fromDecimal(sum, K) << endl;
    }
    return 0;
}
