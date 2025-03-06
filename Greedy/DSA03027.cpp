#include <bits/stdc++.h>
using namespace std;

#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr);

int main() {
    fastio();
    
    int n, num;
    long long total = 0;

    cin >> n;
    while (n--) {
        cin >> num;
        total += (num > 0) * (num << 1LL);
    }

    cout << total;
    return 0;
}
