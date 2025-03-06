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

    for (int i = 0; i < n; ++i) {
        int key = arr[i];  
        int j = i - 1;

        while (j >= 0 and arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;

        cout << "Buoc " << i << ": ";
        for (int k = 0; k <= i; ++k) 
            cout << arr[k] << ' ';
        cout << endl;
    }
    return 0;
}
