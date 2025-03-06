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
        
        int arr[n];
        for (int i = 0; i < n; ++i) 
            cin >> arr[i];
        
        stack<int> stk, ans;
        ans.push(-1);
        stk.push(arr[n - 1]);
        
        for (int i = n - 2; ~i; --i) {
            if (arr[i] < stk.top()) {
                ans.push(stk.top());
            } else {
                while (!stk.empty() and arr[i] >= stk.top()) {
                    stk.pop();
                }
                if (stk.empty()) {
                    ans.push(-1);
                } else {
                    ans.push(stk.top());
                }
            }
            stk.push(arr[i]);
        }

        while (!ans.empty()) {
            cout << ans.top() << " ";
            ans.pop();
        }
        cout << endl;
    }
    return 0;
}