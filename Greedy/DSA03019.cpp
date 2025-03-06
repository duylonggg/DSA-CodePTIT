#include <bits/stdc++.h>
using namespace std;

#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

void egyptianFraction(long long P, long long Q) {
    vector<long long> fractions;
    
    while (P != 0) {
        long long x = (Q + P - 1) / P; 
        fractions.push_back(x);

        P = P * x - Q;
        Q *= x;

        long long gcd = __gcd(P, Q);
        P /= gcd;
        Q /= gcd;
    }

    for (size_t i = 0; i < fractions.size(); ++i) {
        if (i > 0) cout << " + ";
        cout << "1/" << fractions[i];
    }
    cout << endl;
}

int main() {
    fastio();
    
    int T;
    cin >> T;
    while (T--) {
        long long P, Q;
        cin >> P >> Q;
        egyptianFraction(P, Q);
    }
    
    return 0;
}
