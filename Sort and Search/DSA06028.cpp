#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio();
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int& i : arr) cin >> i;

    stack<string> res;

    for (int i = 0; i < n - 1; ++i) {
        string tmp = "";
        int pos = i;

        for (int j = i + 1; j < n; ++j)
            if (arr[j] < arr[pos])
                pos = j;

        swap(arr[i], arr[pos]);

        for (int x : arr) tmp += to_string(x) + " ";
        res.push("Buoc " + to_string(i + 1) + ": " + tmp);
    }

    while (!res.empty()) {
        cout << res.top() << endl;
        res.pop();
    }
    return 0;
}
