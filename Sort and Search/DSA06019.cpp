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

        int arr[n], freq[100001] = {};
        for (int& _: arr) {
            cin >> _;
            ++freq[_];
        }
        sort(arr, arr + n, [&] (int a, int b) {
            if (freq[a] == freq[b]) return a < b;
            return freq[a] > freq[b];
        });

        for (int _: arr) cout << _ << ' ';
        cout << endl;
    }
    return 0;
}