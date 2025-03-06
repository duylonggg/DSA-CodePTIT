#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio();
    tests() {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int& i : arr) cin >> i;

        stack<string> res; 

        for (int i = 0; i < n - 1; ++i) {
            bool is_swap = false;
            
            for (int j = 0; j < n - i - 1; ++j) { 
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    is_swap = true;
                }
            }

            if (!is_swap) break;

            string tmp = "Buoc " + to_string(i + 1) + ": ";
            for (int x : arr) tmp += to_string(x) + " ";
            res.push(tmp); 
        }
        
        while (!res.empty()) {
            cout << res.top() << endl;
            res.pop();
        }
    }
    return 0;
}