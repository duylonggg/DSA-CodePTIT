#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    
    int n;
    cin >> n;
    
    int arr[n];
    for (int& _: arr) cin >> _;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j)
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);
        
        cout << "Buoc " << i + 1 << ": ";
        for (int _: arr) cout << _ << ' ';
        cout << endl;
    }
    return 0;
}