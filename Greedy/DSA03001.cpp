#include <bits/stdc++.h>
using namespace std;

#define tests() int t; cin >> t; while (t--)

int money[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
int total, cnt;

void Try(int idx) {
    if (total == 0 or idx < 0) { 
        cout << cnt << endl;
        return;
    }

    int num = total / money[idx]; 
    cnt += num;
    total -= num * money[idx]; 

    Try(idx - 1);
}

int main() {
    tests() {
        cin >> total;
        cnt = 0;
        Try(9);
    }
    return 0;
}
