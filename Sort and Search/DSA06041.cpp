#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int n, num, key = 0;
        cin >> n;

        unordered_map<int, int> freq;
        int pivot = (n >> 1);
        while (n--) {
            cin >> num;
            ++freq[num];

            if (freq[num] > pivot) key = num;
        }

        cout << (key ? to_string(key) : "NO") << endl;
    }
    return 0;
}