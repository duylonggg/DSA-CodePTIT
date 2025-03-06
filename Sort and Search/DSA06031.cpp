#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)
#define fastio()    ios::sync_with_stdio(false); cin.tie(nullptr);
#define endl        '\n'

int main() {
    fastio();
    tests() {
        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int& x : arr) cin >> x;

        deque<int> dq; 

        for (int i = 0; i < n; ++i) {
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            while (!dq.empty() && arr[dq.back()] <= arr[i])
                dq.pop_back();

            dq.push_back(i);

            if (i >= k - 1)
                cout << arr[dq.front()] << ' ';
        }
        cout << endl;
    }
    return 0;
}
