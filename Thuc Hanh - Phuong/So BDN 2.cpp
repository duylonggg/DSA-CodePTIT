#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define test   int testcase; cin >> testcase; while(testcase--)

int64_t findBDN(int n) {
    queue<int64_t> BDN;
    BDN.push(1);

    while (BDN.front() % n != 0) {
        int64_t num = BDN.front();
        BDN.pop();

        if (num * 10 % n == 0) {
            return num * 10;
        } 
        if ((num * 10 + 1) % n == 0) {
            return num * 10 + 1;
        }
        
        BDN.push(num * 10);
        BDN.push(num * 10 + 1);
    }

    return BDN.front();
}

int main() {
    fastio;
    test {
        int n;
        cin >> n;
        cout << findBDN(n) << endl;
    }
    return 0;
}