#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int main() {
    tests() {
        string gray;
        cin >> gray;
        
        cout << gray[0];
        int prev = (int) gray[0] - '0';

        for (size_t i = 1; i < gray.size(); ++i) {
            int cur = (int) gray[i] - '0';
            cout << (cur ^ prev);
            prev ^= cur;
        }
        
        cout << endl;
    }
    return 0;
}
