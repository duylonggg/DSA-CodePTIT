#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

string binaryToGray(const string& binary) {
    string gray = "";
    gray += binary[0]; 
    for (size_t i = 1; i < binary.size(); i++) {
        gray += (binary[i] - '0') ^ (binary[i - 1] - '0') + '0';
    }
    return gray;
}

int main() {
    tests() {
        string binary;
        cin >> binary;
        cout << binaryToGray(binary) << endl;
    }
    return 0;
}