#include <bits/stdc++.h>
using namespace std;

string gen(string bits) {
    size_t pos = bits.rfind('0');
    if (pos == string::npos) return string(bits.size(), '0'); 

    ++bits[pos];
    fill(bits.begin() + pos + 1, bits.end(), '0');  
    
    return bits;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string bits;
        cin >> bits;
        cout << gen(bits) << endl;
    }
}
