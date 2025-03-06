#include <bits/stdc++.h>
using namespace std;

#define tests() int test_cases; cin >> test_cases; while (test_cases--)

vector<int> dp;

int Try(int numb) {
    if (numb == 1) return 0;
    if (dp[numb] != -1) return dp[numb];
    return dp[numb] = min({
        Try(numb - 1) + 1,
        (numb % 2 == 0) ? Try(numb / 2) + 1 : INT_MAX,
        (numb % 3 == 0) ? Try(numb / 3) + 1 : INT_MAX
    });
}

int main() {
    tests() {
        int n;
        cin >> n;
        dp.assign(n + 1, -1); 
        cout << Try(n) << endl;
    }
    return 0;
}
