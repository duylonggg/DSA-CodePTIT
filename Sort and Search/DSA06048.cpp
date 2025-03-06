#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio()
    tests() {
        int n, maxVal = INT_MIN, maxIdx = -1;
        cin >> n;

        int* arr = new int[n]; 

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            if (arr[i] > maxVal) { 
                maxVal = arr[i];
                maxIdx = i;
            }
        }

        cout << (maxIdx + 1 == n ? 0 : maxIdx + 1) << endl; 

        delete[] arr; 
    }
    return 0;
}
