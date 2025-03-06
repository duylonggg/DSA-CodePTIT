#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio();

    int n;
    string str;
    cin >> n >> str;

    int cnt_X = 0, cnt_T = 0, cnt_D = 0;
    for (char c : str) 
        (c == 'X' ? ++cnt_X : (c == 'T' ? ++cnt_T : ++cnt_D));

    int swaps = 0, mis_T = 0, mis_D = 0;

    for (int i = 0; i < cnt_X; ++i) 
        if (str[i] == 'T') ++mis_T;
        else if (str[i] == 'D') ++mis_D;

    swaps += mis_T + mis_D;

    for (int i = cnt_X; i < n && (mis_T || mis_D); ++i) {
        if (str[i] == 'X') {
            if (mis_T) str[i] = 'T', --mis_T;
            else if (mis_D) str[i] = 'D', --mis_D;
        }
    }

    mis_T = 0;
    for (int i = cnt_X; i < cnt_X + cnt_T; ++i) 
        if (str[i] != 'T') ++mis_T;

    swaps += mis_T;

    cout << swaps;

    return 0;
}
