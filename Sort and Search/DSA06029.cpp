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

    stack<string> res;
    for (int i = 0; i < n; ++i) {
        string tmp = "";
        int key = arr[i];

        int j = i - 1;
        while (j >= 0 and arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;

        tmp = "Buoc " + to_string(i) + ": ";
        for (int k = 0; k <= i; ++k) tmp += to_string(arr[k]) + " ";
        res.push(tmp);
    }

    while (!res.empty()) {
        cout << res.top() << endl;
        res.pop();
    }
    return 0;
}   