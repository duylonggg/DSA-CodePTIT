#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        long long W, c;
        cin >> W >> c;

        if (W % 1000) {
            cout << 0 << endl;
            continue;
        }

        W /= 1000;
        long long money = 0, dif = 1;

        while (W and c--) {
            int tmp = W % 10;

            if (tmp == 1 or tmp == 2 or tmp == 3 or tmp == 5) 
                ++money;
            else if (tmp == 4 or tmp == 6)
                money += 2, dif <<= 1;
            else if (tmp == 7 or tmp == 8)
                money += 2;
            else if (tmp == 9)
                money += 3, dif *= 3;

            W /= 10;
        }

        if (W) {
            money += W / 5;

            if (W % 5 == 4)
                money += 2;
            else if (W % 5)
                ++money;
            
            if (W % 5 == 1 and W > 1 or W == 4)
                dif <<= 1;
            else if(W % 5 == 4 and W > 4)
                dif *= 3;
        }
        cout << money << ' ' << dif << endl;
    }
    return 0;
}