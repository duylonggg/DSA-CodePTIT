#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio();
    tests() {
        string str;
        cin >> str;

        size_t ans = 0;
        int cnt = 0;
        for (size_t i = 0; i < str.size() - 1; ++i) {
            cnt += (str[i] == '[' ? 1 : -1);

            if (cnt < 0) { 
                for (size_t j = i + 1; j < str.size(); ++j) {
                    if (str[j] == '[') {
                        ans += j - i;
                        swap(str[i], str[j]);
                        cnt = 1;  
                        break; 
                    }
                }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
