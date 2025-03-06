#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int n;
        cin >> n;

        int64_t num;
        short freq[10] = {};
        while (n--) {
            cin >> num;
            
            while (num) {
                ++freq[num % 10];
                num /= 10;
            }
        }

        for (int i = 0; i < 10; ++i)
            if (freq[i])
                cout << i << ' ';
        cout << endl;
    }
    return 0;
}