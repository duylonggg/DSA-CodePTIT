#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio();
    int n;
    cin >> n;

    int arr[n];
    for (int& i : arr) cin >> i;

    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;

        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) { 
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) break; 

        cout << "Buoc " << i + 1 << ": ";
        for (int x : arr) cout << x << ' ';
        cout << endl;
    }
    return 0;
}
