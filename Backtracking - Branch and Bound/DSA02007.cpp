#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int k;
string str, res;

void Try(size_t pos, int time) {
    res = max(res, str);

    if (time == k) {
        res = max(res, str);
        return;
    }

    for (size_t i = 0; i < str.size(); ++i) {
        for (size_t j = pos; j < str.size(); ++j) {
            swap(str[i], str[j]);
            Try(j + 1, time + 1);
            swap(str[i], str[j]);
        }
    }
}

int main() {
    tests() {
        cin >> k >> str;
        res.clear();

        Try(0, 0);

        cout << res << endl;
    }
    return 0;
}