#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

vector<int> v(5);
bool flag;

void Try(int idx, int sum) {
    if (flag) return;
    if (idx == 5) {
        if (sum == 23) flag = true;
        return;
    }

    Try(idx + 1, sum + v[idx]);
    Try(idx + 1, sum - v[idx]);
    Try(idx + 1, sum * v[idx]);
}

int main() {
    tests() {
        flag = false;
        for (int& i : v) cin >> i;
        
        sort(v.begin(), v.end());
        do {
            Try(1, v[0]);
        } while (!flag and next_permutation(v.begin(), v.end()));

        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}