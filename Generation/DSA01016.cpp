#include <bits/stdc++.h>
using namespace std;

#define tests()     int test_cases; cin >> test_cases; while (test_cases--)

int n;
vector<int> numb;

void print() {
    cout << '(' << numb[0];
    for (size_t i = 1; i < numb.size(); ++i) cout << ' ' << numb[i];
    cout << ") ";
}

void gen(int start, int total = 0) {
    if (total == n) {
        print();
        return;
    }

    for (int i = start; i > 0; --i) {
        if (total + i > n) continue;
        numb.push_back(i);
        gen(i, total + i);
        numb.pop_back();
    }
}

int main() {
    tests() {
        cin >> n;
        gen(n);
        cout << endl;
    }
    return 0;
}